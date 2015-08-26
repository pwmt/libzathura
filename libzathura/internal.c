/* See LICENSE file for license and copyright information */

#define _DEFAULT_SOURCE
#define _POSIX_SOURCE

#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <stdio.h>
#include <gio/gio.h>
#include <sys/wait.h>

#ifdef WITH_MAGIC
#include <magic.h>
#endif

#include "internal.h"
#include "fiu-local.h"

static const size_t GT_MAX_READ = 1 << 16;

zathura_error_t
zathura_realpath(const char* path, char** real_path)
{
  if (path == NULL || strlen(path) == 0 || real_path == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  long path_max;
#ifdef PATH_MAX
  path_max = PATH_MAX;
#else
  path_max = pathconf(path, _PC_PATH_MAX);
  if (path_max <= 0) {
    path_max = 4096;
  }
#endif

  *real_path = calloc(path_max, sizeof(**real_path));
  if (*real_path == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  if (realpath(path, *real_path) == NULL) {
    free(*real_path);
    *real_path = NULL;
    return ZATHURA_ERROR_UNKNOWN;
  }

  return ZATHURA_ERROR_OK;
}

#ifdef WITH_MAGIC
char*
guess_type_magic(const char* path) {
  if (path == NULL || strlen(path) == 0) {
    return NULL;
  }

  char* mime_type = NULL;

  /* creat magic cookie */
  const int flags =
    MAGIC_MIME_TYPE |
    MAGIC_SYMLINK |
    MAGIC_NO_CHECK_APPTYPE |
    MAGIC_NO_CHECK_CDF |
    MAGIC_NO_CHECK_ELF |
    MAGIC_NO_CHECK_ENCODING;
  magic_t magic = magic_open(flags);
  if (magic == NULL) {
    goto cleanup;
  }

  /* ... and load mime database */
  if (magic_load(magic, NULL) < 0) {
    goto cleanup;
  }

  /* get the mime type */
  mime_type = (char*) magic_file(magic, path);
  if (mime_type == NULL) {
    goto cleanup;
  }

  /* dup so we own the memory */
  mime_type = g_strdup(mime_type);

cleanup:

  if (magic != NULL) {
    magic_close(magic);
  }

  return mime_type;
}
#endif

char*
guess_type_file(const char* path)
{
  if (path == NULL || strlen(path) == 0) {
    return NULL;
  }

  GString* command = g_string_new("file -b --mime-type ");
  char* tmp        = g_shell_quote(path);

  g_string_append(command, tmp);
  g_free(tmp);

  GError* error = NULL;
  char* out = NULL;
  int ret = 0;
  g_spawn_command_line_sync(command->str, &out, NULL, &ret, &error);
  g_string_free(command, TRUE);

  if (error != NULL) {
    g_error_free(error);
    g_free(out);
    return NULL;
  }

  if (WEXITSTATUS(ret) != 0) {
    g_free(out);
    return NULL;
  }

  g_strdelimit(out, "\n\r", '\0');
  return out;
}

char*
guess_type_glib(const char* path)
{
  if (path == NULL || strlen(path) == 0) {
    return NULL;
  }

  gboolean uncertain = FALSE;
  char* content_type = g_content_type_guess(path, NULL, 0, &uncertain);
  if (content_type != NULL) {
    if (uncertain == FALSE) {
      return content_type;
    } else {
      g_free(content_type);
      content_type = NULL;
    }
  }

  FILE* f = fopen(path, "rb");
  if (f == NULL) {
    return NULL;
  }

  const int fd = fileno(f);
  guchar* content = NULL;
  size_t length = 0u;
  ssize_t bytes_read = -1;
  while (uncertain == TRUE && length < GT_MAX_READ && bytes_read != 0) {
    g_free(content_type);
    content_type = NULL;

    guchar* temp_content = g_try_realloc(content, length + BUFSIZ);
    if (temp_content == NULL) {
      break;
    }
    content = temp_content;

    bytes_read = read(fd, content + length, BUFSIZ);
    if (bytes_read == -1) {
      break;
    }

    length += bytes_read;
    content_type = g_content_type_guess(NULL, content, length, &uncertain);
  }

  fclose(f);
  g_free(content);
  if (uncertain == FALSE) {
    return content_type;
  }

  g_free(content_type);

  return NULL;
}

zathura_error_t
zathura_guess_type(const char* path, char** type)
{
  if (path == NULL || strlen(path) == 0 || type == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

#ifdef WITH_MAGIC
  /* try content type detection with libmagic */
  *type = guess_type_magic(path);
  if (*type != NULL) {
    return ZATHURA_ERROR_OK;
  }
#endif

  /* try content type detection with glib */
  *type = guess_type_glib(path);
  if (*type != NULL) {
    return ZATHURA_ERROR_OK;
  }

  /* try content type detection with find */
  *type = guess_type_file(path);
  if (*type != NULL) {
    return ZATHURA_ERROR_OK;
  }

  return ZATHURA_ERROR_UNKNOWN;
}

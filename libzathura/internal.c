/* See LICENSE file for license and copyright information */

#define _DEFAULT_SOURCE

#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <stdio.h>
#include <gio/gio.h>

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

  *real_path = calloc(sizeof(char), path_max);
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

zathura_error_t
zathura_guess_type(const char* path, char** type)
{
  if (path == NULL || strlen(path) == 0 || type == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  /* guess by path */
  gboolean uncertain;
  char* content_type = g_content_type_guess(path, NULL, 0, &uncertain);
  fiu_do_on("zathura_guess_type_g_content_type_guess", g_free(content_type); content_type = NULL);
  if (content_type == NULL) {
    return ZATHURA_ERROR_UNKNOWN;
  }

  fiu_do_on("zathura_guess_type_uncertain_1", uncertain = TRUE);
  if (uncertain == FALSE) {
    *type = content_type;
    return ZATHURA_ERROR_OK;
  }

  /* guess from data */
  char* real_path;
  if (zathura_realpath(path, &real_path) != ZATHURA_ERROR_OK) {
    return ZATHURA_ERROR_UNKNOWN;
  }

  FILE* f = fopen(real_path, "rb");
  if (f == NULL) {
    free(real_path);
    g_free((void*) content_type);
    return ZATHURA_ERROR_OK;;
  }

  free(real_path);

  const int fd = fileno(f);
  guchar* content = NULL;
  size_t length = 0u;

  while (uncertain == TRUE && length < GT_MAX_READ) {
    g_free((void*)content_type);
    content_type = NULL;

    content = g_try_realloc(content, length + BUFSIZ);
    if (content == NULL) {
      continue;
    }

    const ssize_t r = read(fd, content + length, BUFSIZ);
    if (r == -1) {
      break;
    }

    length += r;
    content_type = g_content_type_guess(NULL, content, length, &uncertain);
  }

  fclose(f);
  g_free(content);

  if (uncertain == FALSE) {
    *type = content_type;
    return ZATHURA_ERROR_OK;
  }

  g_free((void*) content_type);
  content_type = NULL;

  /* guess by using the file command */
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
    return ZATHURA_ERROR_UNKNOWN;
  }

  if (WEXITSTATUS(ret) != 0) {
    g_free(out);
    return ZATHURA_ERROR_UNKNOWN;
  }

  g_strdelimit(out, "\n\r", '\0');
  *type = out;

  return ZATHURA_ERROR_OK;
}

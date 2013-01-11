/* See LICENSE file for license and copyright information */

#define _BSD_SOURCE
#define _XOPEN_SOURCE 700

#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

#include "internal.h"

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

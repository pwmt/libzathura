/* See LICENSE file for license and copyright information */

#include <stdlib.h>
#include <stdio.h>

#include "plugin.h"
#include "error.h"
#include "internal.h"

zathura_error_t
zathura_plugin_get_name(zathura_plugin_t* plugin, const char** name)
{
  if (plugin == NULL || name == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *name = plugin->name;

  if (*name != NULL) {
    return ZATHURA_ERROR_OK;
  } else {
    return ZATHURA_ERROR_UNKNOWN;
  }
}

zathura_error_t
zathura_plugin_get_path(zathura_plugin_t* plugin, const char** path)
{
  if (plugin == NULL || path == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *path = plugin->path;

  if (*path != NULL) {
    return ZATHURA_ERROR_OK;
  } else {
    return ZATHURA_ERROR_UNKNOWN;
  }
}

zathura_error_t
zathura_plugin_get_version(zathura_plugin_t* plugin, zathura_plugin_version_t*
    version)
{
  if (plugin == NULL || version == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  version->major = plugin->version.major;
  version->minor = plugin->version.minor;
  version->rev   = plugin->version.rev;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_plugin_get_functions(zathura_plugin_t* plugin,
    zathura_plugin_functions_t** functions)
{
  if (plugin == NULL || functions == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  return ZATHURA_ERROR_OK;
}

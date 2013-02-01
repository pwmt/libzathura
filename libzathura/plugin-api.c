/* See LICENSE file for license and copyright information */

#include <stdlib.h>
#include <string.h>

#include "plugin-api.h"
#include "internal.h"

zathura_error_t
zathura_plugin_set_name(zathura_plugin_t* plugin, const char* name)
{
  if (plugin == NULL || name == NULL || strlen(name) == 0) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  plugin->name = (char*) name;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_plugin_set_register_function(zathura_plugin_t* plugin,
    zathura_plugin_register_function_t function)
{
  if (plugin == NULL || function == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  plugin->register_function = function;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_plugin_add_mimetype(zathura_plugin_t* plugin, const char* mime_type)
{
  if (plugin == NULL || mime_type == NULL || strlen(mime_type) == 0) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  return ZATHURA_ERROR_OK;
}

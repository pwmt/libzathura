/* See LICENSE file for license and copyright information */

#include <string.h>
#include <stdlib.h>

#include "plugin-manager.h"

struct zathura_plugin_manager_s {
  zathura_list_t* plugins; /**< List of pluins */
};

zathura_error_t
zathura_plugin_manager_new(zathura_plugin_manager_t** plugin_manager)
{
  if (plugin_manager == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  if ((*plugin_manager = calloc(1, sizeof(zathura_plugin_manager_t))) == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_plugin_manager_free(zathura_plugin_manager_t* plugin_manager)
{
  if (plugin_manager == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  free(plugin_manager);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_plugin_manager_add_dir(zathura_plugin_manager_t* plugin_manager, const
    char* dir)
{
  if (plugin_manager == NULL || dir == NULL || strlen(dir) == 0) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t 
zathura_plugin_manager_load(zathura_plugin_manager_t* plugin_manager)
{
  if (plugin_manager == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_plugin_manager_get_plugins(zathura_plugin_manager_t* plugin_manager,
    zathura_list_t** plugins)
{
  if (plugin_manager == NULL || plugins == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  return ZATHURA_ERROR_OK;
}

/* See LICENSE file for license and copyright information */

#include <string.h>
#include <stdlib.h>
#include <glib.h>
#include <gmodule.h>

#include "plugin-manager.h"
#include "plugin-api.h"
#include "types.h"
#include "version.h"

struct zathura_plugin_manager_s {
  zathura_list_t* plugins; /**< List of pluins */
};

typedef unsigned int (*zathura_plugin_api_version_t)(void);
typedef unsigned int (*zathura_plugin_abi_version_t)(void);

zathura_error_t
zathura_plugin_manager_new(zathura_plugin_manager_t** plugin_manager)
{
  zathura_error_t error;

  if (plugin_manager == NULL) {
    error = ZATHURA_ERROR_INVALID_ARGUMENTS;
    goto error_ret;
  }

  if ((*plugin_manager = calloc(1, sizeof(zathura_plugin_manager_t))) == NULL) {
    error = ZATHURA_ERROR_OUT_OF_MEMORY;
    goto error_free;
  }

  if (((*plugin_manager)->plugins = zathura_list_alloc()) == NULL) {
    error = ZATHURA_ERROR_OUT_OF_MEMORY;
    goto error_free;
  }

  return ZATHURA_ERROR_OK;

error_free:

  if (*plugin_manager != NULL) {
    if ((*plugin_manager)->plugins != NULL) {
      zathura_list_free((*plugin_manager)->plugins);
    }

    free(*plugin_manager);
  }

error_ret:

  return error;
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
zathura_plugin_manager_load(zathura_plugin_manager_t* plugin_manager, const char* path)
{
  zathura_error_t error;

  if (plugin_manager == NULL || path == NULL || strlen(path) == 0) {
    error = ZATHURA_ERROR_INVALID_ARGUMENTS;
    goto error_ret;
  }

  /* load module */
  GModule* handle = g_module_open(path, G_MODULE_BIND_LOCAL);
  if (handle == NULL) {
    error = ZATHURA_ERROR_INVALID_ARGUMENTS;
    goto error_ret;
  }

  /* resolve symbols and check API and ABI version*/
  zathura_plugin_api_version_t api_version = NULL;
  if (g_module_symbol(handle, PLUGIN_API_VERSION_FUNCTION, (gpointer*) &api_version) == FALSE ||
      api_version == NULL) {
    error = ZATHURA_ERROR_PLUGIN_RESOLVE_SYMBOL;
    goto error_free;
  }

  if (api_version() != ZATHURA_API_VERSION) {
    error = ZATHURA_ERROR_PLUGIN_VERSION;
    goto error_free;
  }

  zathura_plugin_abi_version_t abi_version = NULL;
  if (g_module_symbol(handle, PLUGIN_ABI_VERSION_FUNCTION, (gpointer*) &abi_version) == FALSE ||
      abi_version == NULL) {
    error = ZATHURA_ERROR_PLUGIN_RESOLVE_SYMBOL;
    goto error_free;
  }

  if (abi_version() != ZATHURA_ABI_VERSION) {
    error = ZATHURA_ERROR_PLUGIN_VERSION;
    goto error_free;
  }

  return ZATHURA_ERROR_OK;

error_free:

  g_module_close(handle);

error_ret:

  return error;
}

zathura_error_t
zathura_plugin_manager_load_dir(zathura_plugin_manager_t* plugin_manager, const
    char* directory)
{
  if (plugin_manager == NULL || directory == NULL || strlen(directory) == 0) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  /* open directory */
  GDir* dir = g_dir_open(directory, 0, NULL);
  if (dir == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  /* read files */
  char* name;
  while ((name = (char*) g_dir_read_name(dir)) != NULL) {
    char* path = g_build_filename(directory, name, NULL);
    if (g_file_test(path, G_FILE_TEST_IS_REGULAR) == 0) {
      g_free(path);
      continue;
    }

  }

  g_dir_close(dir);

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

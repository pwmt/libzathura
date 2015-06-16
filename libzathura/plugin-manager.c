/* See LICENSE file for license and copyright information */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <glib.h>
#include <gmodule.h>

#include "plugin-manager.h"
#include "plugin-api.h"
#include "types.h"
#include "version.h"
#include "internal.h"

typedef void (*zathura_plugin_register_service_t)(zathura_plugin_t*);
typedef unsigned int (*zathura_plugin_api_version_t)(void);
typedef unsigned int (*zathura_plugin_abi_version_t)(void);
typedef unsigned int (*zathura_plugin_major_version_t)(void);
typedef unsigned int (*zathura_plugin_minor_version_t)(void);
typedef unsigned int (*zathura_plugin_rev_version_t)(void);

static void
zathura_plugin_free(zathura_plugin_t* plugin)
{
  if (plugin == NULL) {
    return;
  }

  if (plugin->mimetypes != NULL) {
    zathura_list_free_full(plugin->mimetypes, g_free);
  }

  if (plugin->handle != NULL) {
    g_module_close(plugin->handle);
  }

  free(plugin->path);
  free(plugin);
}

zathura_error_t
zathura_plugin_manager_new(zathura_plugin_manager_t** plugin_manager)
{
  zathura_error_t error;

  if (plugin_manager == NULL) {
    error = ZATHURA_ERROR_INVALID_ARGUMENTS;
    goto error_ret;
  }

  if ((*plugin_manager = calloc(1, sizeof(**plugin_manager))) == NULL) {
    error = ZATHURA_ERROR_OUT_OF_MEMORY;
    goto error_ret;
  }

  return ZATHURA_ERROR_OK;

error_ret:

  return error;
}

zathura_error_t
zathura_plugin_manager_free(zathura_plugin_manager_t* plugin_manager)
{
  if (plugin_manager == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  /* free plugins */
  if (plugin_manager->plugins != NULL) {
    zathura_list_free_full(plugin_manager->plugins, (GDestroyNotify) zathura_plugin_free);
  }

  /* free plugin manager */
  free(plugin_manager);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_plugin_manager_load(zathura_plugin_manager_t* plugin_manager, const char* path)
{
  zathura_error_t error;
  char* real_path = NULL;
  GModule* handle = NULL;
  zathura_plugin_t* plugin = NULL;

  if (plugin_manager == NULL || path == NULL || strlen(path) == 0) {
    error = ZATHURA_ERROR_INVALID_ARGUMENTS;
    goto error_ret;
  }

  /* generate real path of file path */
  if (zathura_realpath(path, &real_path) != ZATHURA_ERROR_OK) {
    error = ZATHURA_ERROR_UNKNOWN;
    goto error_ret;
  }

  /* load module */
  handle = g_module_open(real_path, G_MODULE_BIND_LOCAL);
  if (handle == NULL) {
    free(real_path);
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

  zathura_plugin_major_version_t major_version = NULL;
  if (g_module_symbol(handle, PLUGIN_VERSION_MAJOR_FUNCTION, (gpointer*) &major_version) == FALSE ||
      major_version == NULL) {
    error = ZATHURA_ERROR_PLUGIN_RESOLVE_SYMBOL;
    goto error_free;
  }

  zathura_plugin_minor_version_t minor_version = NULL;
  if (g_module_symbol(handle, PLUGIN_VERSION_MINOR_FUNCTION, (gpointer*) &minor_version) == FALSE ||
      minor_version == NULL) {
    error = ZATHURA_ERROR_PLUGIN_RESOLVE_SYMBOL;
    goto error_free;
  }

  zathura_plugin_rev_version_t rev_version = NULL;
  if (g_module_symbol(handle, PLUGIN_VERSION_REVISION_FUNCTION, (gpointer*) &rev_version) == FALSE ||
      rev_version == NULL) {
    error = ZATHURA_ERROR_PLUGIN_RESOLVE_SYMBOL;
    goto error_free;
  }

  zathura_plugin_register_service_t register_service = NULL;
  if (g_module_symbol(handle, PLUGIN_REGISTER_FUNCTION, (gpointer*)
        &register_service) == FALSE || register_service == NULL) {
    error = ZATHURA_ERROR_PLUGIN_RESOLVE_SYMBOL;
    goto error_free;
  }

  /* create and register plugin */
  plugin = calloc(1, sizeof(*plugin));
  if (plugin == NULL) {
    error = ZATHURA_ERROR_OUT_OF_MEMORY;
    goto error_free;
  }

  /* setup plugin */
  plugin->handle        = handle;
  plugin->path          = real_path;
  plugin->version.major = major_version();
  plugin->version.minor = minor_version();
  plugin->version.rev   = rev_version();

  register_service(plugin);

  if (plugin->register_function == NULL || plugin->name == NULL) {
    free(plugin->path);
    error = ZATHURA_ERROR_OUT_OF_MEMORY;
    goto error_free;
  }

  /* register functions */
  plugin->register_function(&(plugin->functions));

  /* add plugin to the list */
  plugin_manager->plugins = zathura_list_append(plugin_manager->plugins, plugin);
  if (plugin_manager->plugins == NULL) {
    error = ZATHURA_ERROR_OUT_OF_MEMORY;
    goto error_free;
  }

  return ZATHURA_ERROR_OK;

error_free:

  if (plugin != NULL) {
    free(plugin);
  }

  if (real_path != NULL) {
    free(real_path);
  }

  if (handle != NULL) {
    g_module_close(handle);
  }

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

    zathura_plugin_manager_load(plugin_manager, path);
    g_free(path);
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

  *plugins = plugin_manager->plugins;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_plugin_manager_get_plugin(zathura_plugin_manager_t* plugin_manager,
    zathura_plugin_t** plugin, const char* mime_type)
{
  if (plugin_manager == NULL || mime_type == NULL || strlen(mime_type) == 0 || plugin == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  if (plugin_manager->plugins == NULL) {
    return ZATHURA_ERROR_UNKNOWN;
  }

  for (unsigned int i = 0; i < zathura_list_length(plugin_manager->plugins); i++) {
    zathura_plugin_t* tmp_plugin = (zathura_plugin_t*) zathura_list_nth_data(plugin_manager->plugins, i);
    if (tmp_plugin == NULL || tmp_plugin->mimetypes == NULL) {
      continue;
    }

    for (unsigned int j = 0; j < zathura_list_length(tmp_plugin->mimetypes); j++) {
      char* tmp_mime_type = (char*) zathura_list_nth_data(tmp_plugin->mimetypes, j);
      if (tmp_mime_type == NULL) {
        continue;
      }

      if (strcmp(mime_type, tmp_mime_type) == 0) {
        *plugin = tmp_plugin;
        return ZATHURA_ERROR_OK;
      }
    }
  }

  return ZATHURA_ERROR_UNKNOWN;
}

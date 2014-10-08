/* See LICENSE file for license and copyright information */

#ifndef PLUGIN_MANAGER_H
#define PLUGIN_MANAGER_H

#include "error.h"
#include "list.h"
#include "document.h"
#include "plugin.h"

typedef struct zathura_plugin_manager_s zathura_plugin_manager_t;

/**
 * Creates a new instance of the plugin manager
 *
 * @param[out] plugin_manager The plugin manager
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_plugin_manager_new(zathura_plugin_manager_t** plugin_manager);

/**
 * Frees the instance of the plugin manager
 *
 * @param[in] plugin_manager The plugin manager
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_plugin_manager_free(zathura_plugin_manager_t* plugin_manager);

/**
 * Loads a module specified by its @a path
 *
 * @param[in] plugin_manager The plugin manager
 * @param[in] path The path of the module
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 * @return ZATHURA_ERROR_PLUGIN_RESOLVE_SYMBOL Could not resolve symbol
 * @return ZATHURA_ERROR_PLUGIN_VERSION The versions of the plugin are not
 *  compatible with the instance of the plugin manager
 */
zathura_error_t zathura_plugin_manager_load(zathura_plugin_manager_t* plugin_manager, const char* path);

/**
 * Loads all modules existing in the given @a directory
 *
 * @param[in] plugin_manager The plugin manager
 * @param[in] directory The path of the directory of modules
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_plugin_manager_load_dir(zathura_plugin_manager_t* plugin_manager, const char* directory);

/**
 * Returns the list of plugins that are managed by the plugin manager
 *
 * @param[in] plugin_manager The plugin manager
 * @param[out] plugins List of plugins
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 */
zathura_error_t zathura_plugin_manager_get_plugins(zathura_plugin_manager_t* plugin_manager, zathura_list_t** plugins);

/**
 * Get a plugin that supports the given mime type
 *
 * @param[in] plugin_manager The plugin manager
 * @param[in] mime_type The mime type
 * @param[out] plugin The plugin
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_plugin_manager_get_plugin(zathura_plugin_manager_t* plugin_manager, zathura_plugin_t** plugin, const char* mime_type);

#endif /* PLUGIN_MANAGER_H */

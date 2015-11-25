/* See LICENSE file for license and copyright information */

#ifndef LIBZATHURA_PLUGIN_H
#define LIBZATHURA_PLUGIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "document.h"
#include "error.h"

typedef struct zathura_plugin_s zathura_plugin_t;
typedef struct zathura_plugin_functions_s zathura_plugin_functions_t;

typedef struct zathura_plugin_version_s {
  unsigned int major; /**< Major version of the plugin */
  unsigned int minor; /**< Minor version of the plugin */
  unsigned int rev; /**< Revision of the plugin */
} zathura_plugin_version_t;

/**
 * Returns the name of the plugin
 *
 * @param[in] plugin The plugin
 * @param[out] name The name of the plugin
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_plugin_get_name(zathura_plugin_t* plugin, const char** name);

/**
 * Returns the path of the plugin
 *
 * @param[in] plugin The plugin
 * @param[out] path The path of the plugin
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_plugin_get_path(zathura_plugin_t* plugin, const char** path);

/**
 * Returns the version of the plugin
 *
 * @param[in] plugin The plugin
 * @param[out] version The version of the plugin
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_plugin_get_version(zathura_plugin_t* plugin, zathura_plugin_version_t* version);

/**
 * Returns the functions of the plugin
 *
 * @param[in] plugin The plugin
 * @param[out] functions The functions of the plugin
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_plugin_get_functions(zathura_plugin_t* plugin, zathura_plugin_functions_t** functions);

/**
 * Opens a document with the plugin
 *
 * @param[in] plugin The plugin
 * @param[out] document The document
 * @param[in] path The path to the document file
 * @param[in] password (Optional) password of the file
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_plugin_open_document(zathura_plugin_t* plugin,
    zathura_document_t** document, const char* path, const char* password);

#ifdef __cplusplus
}
#endif

#endif /* PLUGIN_H */

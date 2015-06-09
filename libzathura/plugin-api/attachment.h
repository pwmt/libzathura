/* See LICENSE file for license and copyright information */

#ifndef PLUGIN_API_ATTACHMENT_H
#define PLUGIN_API_ATTACHMENT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../attachment.h"
#include "../error.h"
#include "../types.h"

/**
 * Sets the custom data of an attachment object
 *
 * @param[in] attachment The attachment object
 * @param[in] user_data The custom data
 * @param[in] free_function The custom data free function
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_attachment_set_user_data(zathura_attachment_t*
    attachment, void* user_data, zathura_free_function_t free_function);

/**
 * Returns the custom data of an attachment object
 *
 * @param[in] attachment The attachment object
 * @param[out] data The custom data
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_attachment_get_user_data(zathura_attachment_t* attachment, void** data);

/**
 * A function type that can be used for a plugin to implement a custom save
 * attachment function.
 *
 * @param[in] attachment The attachment
 * @param path[in] The path where the file should be saved
 * @param user_data[in] Custom user data (set by the plugin)
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
typedef zathura_error_t (*zathura_attachment_save_function_t)(zathura_attachment_t* attachment, const char* path, void* user_data);

/**
 * Sets a function that is used by a plugin to implement a custom save
 * attachment function.
 *
 * @param[in] attachment The attachment
 * @param[in] save_function The save function
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_attachment_set_save_function(zathura_attachment_t* attachment, zathura_attachment_save_function_t save_function);

#ifdef __cplusplus
}
#endif

#endif /* PLUGIN_API_ATTACHMENT_H */

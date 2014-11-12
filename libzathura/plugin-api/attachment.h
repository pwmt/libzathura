/* See LICENSE file for license and copyright information */

#ifndef PLUGIN_API_ATTACHMENT_H
#define PLUGIN_API_ATTACHMENT_H

#include "../attachment.h"
#include "../error.h"

/**
 * Sets the custom data of an attachment object
 *
 * @param[in] attachment The attachment object
 * @param[in] data The custom data
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_attachment_set_user_data(zathura_attachment_t* attachment, void* data);

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

#endif /* PLUGIN_API_ATTACHMENT_H */

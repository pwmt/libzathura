/* See LICENSE file for license and copyright information */

#ifndef PLUGIN_API_ATTACHMENT_H
#define PLUGIN_API_ATTACHMENT_H

#include "../error.h"
#include "../attachment.h"

/**
 * Create a new attachment object
 *
 * @param[out] attachment The attachment object
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_attachment_new(zathura_attachment_t** attachment);

/**
 * Frees an attachment object
 *
 * @param[in] attachment The attachment object
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_attachment_free(zathura_attachment_t* attachment);

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
zathura_error_t zathura_attachment_set_data(zathura_attachment_t* attachment, void* data);

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
zathura_error_t zathura_attachment_get_data(zathura_attachment_t* attachment, void** data);

/**
 * Sets the name of the attachment. The name can be NULL but must not be an
 * empty string.
 *
 * @param[in] attachment The attachment object
 * @param[in] name The name
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_attachment_set_name(zathura_attachment_t* attachment, const char* name);

/**
 * Sets the description of the attachment. The description can be NULL but must
 * not be an empty string.
 *
 * @param[in] attachment The attachment object
 * @param[in] description The description
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_attachment_set_description(zathura_attachment_t* attachment, const char* description);

/**
 * Sets the size (in bytes) of the attachment
 *
 * @param[in] attachment The attachment object
 * @param[in] size The size
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_attachment_set_size(zathura_attachment_t* attachment, unsigned int size);

/**
 * Sets the creation time of the attachment
 *
 * @param attachment The attachment object
 * @param creation_time The creation time
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_attachment_set_creation_time(zathura_attachment_t* attachment, time_t creation_time);

/**
 * Sets the modification time of the atachment
 *
 * @param[in] attachment The attachment object
 * @param[in] modification_time The modification time
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_attachment_set_modification_time(zathura_attachment_t* attachment, time_t modification_time);

/**
 * Sets the checksum of the attachment. The checksum can be NULL or can be a 16
 * characters long string.
 *
 * @param[in] attachment The attachment object
 * @param[in] checksum The checksum
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_attachment_set_checksum(zathura_attachment_t* attachment, const char* checksum);

#endif /* PLUGIN_API_ATTACHMENT_H */

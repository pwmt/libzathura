/* See LICENSE file for license and copyright information */

#ifndef ATTACHMENT_H
#define ATTACHMENT_H

#include <time.h>

#include "error.h"

typedef struct zathura_attachment_s zathura_attachment_t;

/**
 * Saves the attachment to the given path
 *
 * @param[in] attachment The attachment object
 * @param[in] path The path where the attachment should be saved to
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_attachment_save(zathura_attachment_t* attachment, const char* path);

/**
 * Returns the name of the attachment
 *
 * @param[in] attachment The attachment object
 * @param[out] name The name of the attachment
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_attachment_get_name(zathura_attachment_t* attachment, const char** name);

/**
 * Returns the description of the document
 *
 * @param[in] attachment The attachment object
 * @param[out] description The description of the attachment
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_attachment_get_description(zathura_attachment_t*
    attachment, const char** description);

/**
 * Returns the size of the attachment in bytes.
 *
 * @param[in] attachment The attachment object
 * @param[out] size The size of the attachment in bytes
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_attachment_get_size(zathura_attachment_t* attachment, unsigned int* size);

/**
 * Returns the creation time of the attachment
 *
 * @param[in] attachment The attachment object
 * @param[in] creation_time The creation time
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_attachment_get_creation_time(zathura_attachment_t* attachment, time_t* creation_time);

/**
 * Returns the modification time where the attachment has been modified last
 *
 * @param[in] attachment The attachment object
 * @param[out] modification_time The time the attachment has been modified last
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_attachment_get_modification_time(zathura_attachment_t*
    attachment, time_t* modification_time);

/**
 * Returns a MD5 checksum of the attachment
 *
 * @param[in] attachment The attachment object
 * @param[out] checksum The checksum of the object
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_attachment_get_checksum(zathura_attachment_t*
    attachment, const char** checksum);

#endif /* ATTACHMENT_H */

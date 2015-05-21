/* See LICENSE file for license and copyright information */

#ifndef IMAGE_BUFFER_H
#define IMAGE_BUFFER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "error.h"

#define ZATHURA_IMAGE_BUFFER_ROWSTRIDE 3

typedef struct zathura_image_buffer_s zathura_image_buffer_t;

/**
 * Creates an image buffer with the given @a width and @a height
 *
 * @param[out] buffer The image buffer
 * @param[in] width The width of the image
 * @param[in] height The height of the image
 *
 * @return @ref ZATHURA_ERROR_OK No error occurred
 * @return @ref ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been
 *  passed
 * @return @ref ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 */
zathura_error_t zathura_image_buffer_new(zathura_image_buffer_t** buffer, unsigned int width, unsigned int height);

/**
 * Frees the image buffer
 *
 * @param[in] buffer The image buffer
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return @ref ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been
 *  passed
 */
zathura_error_t zathura_image_buffer_free(zathura_image_buffer_t* buffer);

/**
 * Retrieves the data of the image buffer
 *
 * @param[in] buffer The image buffer
 * @param[out] data The data of the buffer
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return @ref ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been
 *  passed
 */
zathura_error_t zathura_image_buffer_get_data(zathura_image_buffer_t* buffer, unsigned char** data);

/**
 * Retrieves the height of the image buffer
 *
 * @param[in] buffer The image buffer
 * @param[out] height The height of the buffer
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return @ref ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been
 *  passed
 */
zathura_error_t zathura_image_buffer_get_height(zathura_image_buffer_t* buffer, unsigned int* height);

/**
 * Retrieves the width of the image buffer
 *
 * @param[in] buffer The image buffer
 * @param[out] width The height of the buffer
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return @ref ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been
 *  passed
 */
zathura_error_t zathura_image_buffer_get_width(zathura_image_buffer_t* buffer, unsigned int* width);

/**
 * Retrieves the rowstride of the image buffer
 *
 * @param[in] buffer The image buffer
 * @param[out] rowstride The rowstride of the buffer
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return @ref ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been
 *  passed
 */
zathura_error_t zathura_image_buffer_get_rowstride(zathura_image_buffer_t* buffer, unsigned int* rowstride);

#ifdef __cplusplus
}
#endif

#endif /* IMAGE_BUFFER_H */

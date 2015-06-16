/* See LICENSE file for license and copyright information */

#include <stdlib.h>
#include <stdint.h>

#include "image-buffer.h"
#include "plugin-api/image-buffer.h"

typedef struct zathura_image_buffer_s {
  unsigned char* data; /**< The image buffers data */
  unsigned int height; /**< Height of the buffer */
  unsigned int width; /**< Width of the buffer */
  unsigned int rowstride; /**< Rowstride of the buffer */
} image_buffer_t;

zathura_error_t
zathura_image_buffer_new(zathura_image_buffer_t** buffer, unsigned int width,
    unsigned int height)
{
  if (buffer == NULL || width == 0 || height == 0) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  /* Check for malicious input */
  uint64_t q = (uint64_t) width * (uint64_t) height;
  if (q > (uint32_t) 0xFFFFFFFFUL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  if ((*buffer = calloc(1, sizeof(**buffer))) == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  if (((*buffer)->data = calloc(width * height *
          ZATHURA_IMAGE_BUFFER_ROWSTRIDE, sizeof(unsigned char))) == NULL) {
    free(*buffer);
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  (*buffer)->height    = height;
  (*buffer)->width     = width;
  (*buffer)->rowstride = ZATHURA_IMAGE_BUFFER_ROWSTRIDE;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_image_buffer_free(zathura_image_buffer_t* buffer)
{
  if (buffer == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  free(buffer->data);
  free(buffer);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_image_buffer_get_data(zathura_image_buffer_t* buffer, unsigned char**
    data)
{
  if (buffer == NULL || data == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *data = buffer->data;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_image_buffer_get_height(zathura_image_buffer_t* buffer, unsigned int*
    height)
{
  if (buffer == NULL || height == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *height = buffer->height;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_image_buffer_get_width(zathura_image_buffer_t* buffer, unsigned int*
    width)
{
  if (buffer == NULL || width == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *width = buffer->width;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_image_buffer_set_rowstride(zathura_image_buffer_t* buffer, unsigned int
    rowstride)
{
  if (buffer == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  buffer->rowstride = rowstride;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_image_buffer_get_rowstride(zathura_image_buffer_t* buffer, unsigned int*
    rowstride)
{
  if (buffer == NULL || rowstride == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *rowstride = buffer->rowstride;

  return ZATHURA_ERROR_OK;
}

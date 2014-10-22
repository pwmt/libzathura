/* See LICENSE file for license and copyright information */

#include <stdlib.h>
#include <string.h>

#include "image.h"
#include "types.h"

struct zathura_image_s {
  zathura_rectangle_t position; /**< Position of the image */
  void* data; /**< Image data */
};

zathura_error_t
zathura_image_new(zathura_image_t** image, zathura_rectangle_t position)
{
  if (image == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *image = calloc(1, sizeof(zathura_image_t));
  if (*image == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  if (memcpy(&((*image)->position), &position, sizeof(zathura_rectangle_t))
      != &((*image)->position)) {
    return ZATHURA_ERROR_UNKNOWN;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_image_get_position(zathura_image_t* image, zathura_rectangle_t* position)
{
  if (image == NULL || position == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  if (memcpy(position, &(image->position), sizeof(zathura_rectangle_t)) != position) {
    return ZATHURA_ERROR_UNKNOWN;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_image_get_buffer(zathura_image_t* image, zathura_image_buffer_t** buffer)
{
  if (image == NULL || buffer == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  return ZATHURA_ERROR_OK;
}

#if HAVE_CAIRO
zathura_error_t
zathura_image_get_cairo_surface(zathura_image_t* image, cairo_surface_t* surface)
{
  if (image == NULL || surface == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  return ZATHURA_ERROR_OK;
}
#endif

zathura_error_t
zathura_image_free(zathura_image_t* image)
{
  if (image == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  free(image);

  return ZATHURA_ERROR_OK;
}

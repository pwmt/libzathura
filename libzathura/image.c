/* See LICENSE file for license and copyright information */

#include <stdlib.h>

#include "image.h"
#include "types.h"

struct zathura_image_s {
  zathura_rectangle_t position; /**< Position of the image */
  void* data; /**< Image data */
};

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

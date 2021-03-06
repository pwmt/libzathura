/* See LICENSE file for license and copyright information */

#include <stdlib.h>
#include <string.h>

#include "image.h"
#include "types.h"
#include "plugin-api/image.h"

struct zathura_image_s {
  zathura_rectangle_t position; /**< Position of the image */
  zathura_image_get_buffer_t get_buffer;
  zathura_image_get_cairo_surface_t get_cairo_surface;
  void* user_data; /**< Image data */
  zathura_free_function_t user_data_free_function; /**< User data free function */
};

zathura_error_t
zathura_image_new(zathura_image_t** image, zathura_rectangle_t position)
{
  if (image == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *image = calloc(1, sizeof(**image));
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
zathura_image_free(zathura_image_t* image)
{
  if (image == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  if (image->user_data != NULL && image->user_data_free_function) {
    image->user_data_free_function(image->user_data);
  }

  free(image);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_image_set_user_data(zathura_image_t* image, void* user_data,
    zathura_free_function_t free_function)
{
  if (image == NULL || user_data == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  if (image->user_data != NULL && image->user_data_free_function) {
    image->user_data_free_function(image->user_data);
  }

  image->user_data = user_data;
  image->user_data_free_function = free_function;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_image_get_user_data(zathura_image_t* image, void** user_data)
{
  if (image == NULL || user_data == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *user_data = image->user_data;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_image_set_get_cairo_surface_function(zathura_image_t* image, zathura_image_get_cairo_surface_t function)
{
  if (image == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  image->get_cairo_surface = function;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_image_set_get_buffer_function(zathura_image_t* image, zathura_image_get_buffer_t function)
{
  if (image == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  image->get_buffer = function;

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
  if (image == NULL || buffer == NULL || image->get_buffer == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  return image->get_buffer(image, buffer);
}

#if HAVE_CAIRO
zathura_error_t
zathura_image_get_cairo_surface(zathura_image_t* image, cairo_surface_t** surface)
{
  if (image == NULL || surface == NULL || image->get_cairo_surface == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  return image->get_cairo_surface(image, surface);
}
#endif

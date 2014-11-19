/* See LICENSE file for license and copyright information */

#ifndef PLUGIN_API_IMAGE_H
#define PLUGIN_API_IMAGE_H

#include "../error.h"
#include "../page.h"

typedef zathura_error_t (*zathura_image_get_cairo_surface_t)(zathura_image_t* image, cairo_surface_t** surface);
typedef zathura_error_t (*zathura_image_get_buffer_t)(zathura_image_t* image, zathura_image_buffer_t** buffer);

zathura_error_t zathura_image_new(zathura_image_t** image, zathura_rectangle_t position);
zathura_error_t zathura_image_set_user_data(zathura_image_t* image, void* data);
zathura_error_t zathura_image_get_user_data(zathura_image_t* image, void** data);
zathura_error_t zathura_image_set_get_cairo_surface_function(zathura_image_t* image, zathura_image_get_cairo_surface_t function);
zathura_error_t zathura_image_set_get_buffer_function(zathura_image_t* image, zathura_image_get_buffer_t function);

#endif /* PLUGIN_API_IMAGE_H */

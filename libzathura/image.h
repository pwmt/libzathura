/* See LICENSE file for license and copyright information */

#ifndef IMAGE_H
#define IMAGE_H

#if HAVE_CAIRO
#include <cairo.h>
#endif

#include "error.h"
#include "image-buffer.h"

typedef struct zathura_image_s zathura_image_t;

zathura_error_t zathura_image_get_buffer(zathura_image_t* image, zathura_image_buffer_t** buffer);

#if HAVE_CAIRO
zathura_error_t zathura_image_get_cairo_surface(zathura_image_t* image, cairo_surface_t* surface);
#endif

zathura_error_t zathura_image_free(zathura_image_t* image);

#endif /* IMAGE_H */

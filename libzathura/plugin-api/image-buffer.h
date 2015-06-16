/* See LICENSE file for license and copyright information */

#ifndef PLUGIN_API_IMAGE_BUFFER_H
#define PLUGIN_API_IMAGE_BUFFER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../error.h"
#include "../page.h"
#include "../types.h"

zathura_error_t zathura_image_buffer_set_rowstride(zathura_image_buffer_t*
    buffer, unsigned int rowstride);

#ifdef __cplusplus
}
#endif

#endif /* PLUGIN_API_IMAGE_BUFFER_H */

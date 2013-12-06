/* See LICENSE file for license and copyright information */

#ifndef PAGE_H
#define PAGE_H

#include "error.h"
#include "types.h"
#include "image-buffer.h"
#include "transition.h"

typedef struct zathura_page_s zathura_page_t;

zathura_error_t zathura_page_get_index(zathura_page_t* page, unsigned int* index);
zathura_error_t zathura_page_get_width(zathura_page_t* page, unsigned int* width);
zathura_error_t zathura_page_get_height(zathura_page_t* page, unsigned int* height);
zathura_error_t zathura_page_get_label(zathura_page_t* page, const char** label);
zathura_error_t zathura_paget_get_transition(zathura_page_t* page, zathura_page_transition_t* transition);

zathura_error_t zathura_page_search_text(zathura_page_t* page, const char* text,
    zathura_list_t** results);
zathura_error_t zathura_page_get_text(zathura_page_t* page, char** text,
    zathura_rectangle_t rectangle);
zathura_error_t zathura_page_get_links(zathura_page_t* page, zathura_list_t** links);
zathura_error_t zathura_page_get_form_fields(zathura_page_t* page, zathura_list_t** form_fields);
zathura_error_t zathura_page_get_images(zathura_page_t* page, zathura_list_t** images);

zathura_error_t zathura_page_render(zathura_page_t* page,
    zathura_image_buffer_t** buffer, double scale, int rotation, int flags);
#ifdef HAVE_CAIRO
zathura_error_t zathura_page_render_cairo(zathura_page_t* page, cairo_t* cairo,
    double scale, int rotation, int flags);
#endif

#endif /* PAGE_H */

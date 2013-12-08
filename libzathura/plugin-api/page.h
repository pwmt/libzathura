/* See LICENSE file for license and copyright information */

#ifndef PLUGIN_API_PAGE_H
#define PLUGIN_API_PAGE_H

#include "../error.h"
#include "../page.h"

zathura_error_t zathura_page_new(zathura_page_t** page);
zathura_error_t zathura_page_set_data(zathura_page_t* page, void* data);
zathura_error_t zathura_page_get_data(zathura_page_t* page, void** data);
zathura_error_t zathura_page_set_index(zathura_page_t* page, unsigned int index);
zathura_error_t zathura_page_set_width(zathura_page_t* page, unsigned int width);
zathura_error_t zathura_page_set_height(zathura_page_t* page, unsigned int height);
zathura_error_t zathura_page_set_label(zathura_page_t* page, const char* label);
zathura_error_t zathura_page_set_transition(zathura_page_t* page, zathura_page_transition_t* transition);

#endif /* PLUGIN_API_PAGE_H */

/* See LICENSE file for license and copyright information */

#ifndef PLUGIN_API_OUTLINE_H
#define PLUGIN_API_OUTLINE_H

#include "../error.h"
#include "../outline.h"
#include "../action.h"

zathura_error_t zathura_outline_element_new(zathura_outline_element_t** element,
    const char* title, zathura_action_t* action);

zathura_error_t zathura_outline_element_free(zathura_outline_element_t* element);

#endif /* PLUGIN_API_OUTLINE_H */

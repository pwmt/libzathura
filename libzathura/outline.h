/* See LICENSE file for license and copyright information */

#ifndef OUTLINE_H
#define OUTLINE_H

#include "error.h"
#include "action.h"
#include "node.h"

typedef struct zathura_outline_element_s zathura_outline_element_t;

zathura_error_t zathura_outline_element_get_title(zathura_outline_element_t* element, const char** title);
zathura_error_t zathura_outline_element_get_action(zathura_outline_element_t* element, zathura_action_t** action);

zathura_error_t zathura_outline_free(zathura_node_t* outline);

#endif /* OUTLINE_H */

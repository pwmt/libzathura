/* See LICENSE file for license and copyright information */

#ifndef INTERNAL_ACTION_GOTO_H
#define INTERNAL_ACTION_GOTO_H

#include "../../action.h"

typedef struct zathura_action_goto_s {
  zathura_destination_t destination;
} zathura_action_goto_t;

zathura_error_t zathura_action_goto_get_destination(zathura_action_t* action, zathura_destination_t* destination);

zathura_error_t zathura_action_goto_init(zathura_action_t* action);
zathura_error_t zathura_action_goto_clear(zathura_action_t* action);

#endif /* INTERNAL_ACTION_GOTO_H */

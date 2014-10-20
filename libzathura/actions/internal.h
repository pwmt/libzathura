/* See LICENSE file for license and copyright information */

#ifndef INTERNAL_ACTIONS_H
#define INTERNAL_ACTIONS_H

#include "../action.h"

#include "internal/action-goto-dest.h"

struct zathura_action_s {
  zathura_action_type_t type;

  union {
    struct zathura_action_goto_dest_s goto_dest;  
  } data;
};

#endif /* INTERNAL_ACTIONS_H */

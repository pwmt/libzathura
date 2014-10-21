/* See LICENSE file for license and copyright information */

#ifndef INTERNAL_ACTIONS_H
#define INTERNAL_ACTIONS_H

#include "../action.h"

#include "internal/action-goto-3d-view.h"
#include "internal/action-goto-embedded.h"
#include "internal/action-goto.h"
#include "internal/action-goto-remote.h"
#include "internal/action-hide.h"
#include "internal/action-launch.h"
#include "internal/action-movie.h"
#include "internal/action-named.h"
#include "internal/action-rendition.h"
#include "internal/action-set-ocg-state.h"
#include "internal/action-sound.h"
#include "internal/action-thread.h"
#include "internal/action-transition.h"
#include "internal/action-uri.h"

struct zathura_action_s {
  zathura_action_type_t type;

  union {
    struct zathura_action_goto_s* goto_dest;
  } data;
};

#endif /* INTERNAL_ACTIONS_H */

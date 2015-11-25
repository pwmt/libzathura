/* See LICENSE file for license and copyright information */

#ifndef LIBZATHURA_INTERNAL_ACTIONS_H
#define LIBZATHURA_INTERNAL_ACTIONS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../action.h"

#include "internal/action-goto-3d-view.h"
#include "internal/action-goto-embedded.h"
#include "internal/action-goto.h"
#include "internal/action-goto-remote.h"
#include "internal/action-hide-annotations.h"
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
    struct zathura_action_goto_remote_s* goto_remote_dest;
    struct zathura_action_goto_3d_view_s* goto_3d_view_dest;
    struct zathura_action_uri_s* uri_dest;
    struct zathura_action_rendition_s* rendition_dest;
    struct zathura_action_movie_s* movie_dest;
    struct zathura_action_sound_s* sound_dest;
    struct zathura_action_remote_s* remote_dest;
    struct zathura_action_set_ocg_state_s* set_ocg_state_dest;
    struct zathura_action_named_s* named_dest;
    struct zathura_action_goto_embedded_s* goto_embedded_dest;
    struct zathura_action_launch_s* launch_dest;
    struct zathura_action_hide_annotations_s* hide_annotations_dest;
    struct zathura_action_thread_s* thread_dest;
    struct zathura_action_transition_s* transition_dest;
  } data;
};

#ifdef __cplusplus
}
#endif

#endif /* INTERNAL_ACTIONS_H */

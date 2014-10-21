/* See LICENSE file for license and copyright information */

#ifndef PLUGIN_API_ACTIONS_H
#define PLUGIN_API_ACTIONS_H

#include "../error.h"
#include "../action.h"

/**
 * Creates a new action of the given type.
 *
 * @param[out] action The action
 * @param[in] type The type
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_action_new(zathura_action_t** action,
    zathura_action_type_t type);

/**
 * Frees an action
 *
 * @param[in] action The action
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_action_free(zathura_action_t* action);

#include "actions/action-goto-3d-view.h"
#include "actions/action-goto-embedded.h"
#include "actions/action-goto.h"
#include "actions/action-goto-remote.h"
#include "actions/action-hide-annotations.h"
#include "actions/action-launch.h"
#include "actions/action-movie.h"
#include "actions/action-named.h"
#include "actions/action-rendition.h"
#include "actions/action-set-ocg-state.h"
#include "actions/action-sound.h"
#include "actions/action-thread.h"
#include "actions/action-transition.h"
#include "actions/action-uri.h"

#endif /* PLUGIN_API_ACTIONS_H */

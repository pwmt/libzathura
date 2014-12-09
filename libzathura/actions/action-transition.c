/* See LICENSE file for license and copyright information */

#include <stdlib.h>

#include "../action.h"
#include "../error.h"

#include "action-transition.h"

#define ACTION_TRANSITION_CHECK_TYPE() \
  if (action->type != ZATHURA_ACTION_TRANSITION) { \
    return ZATHURA_ERROR_ACTION_INVALID_TYPE; \
  }

#define ACTION_TRANSITION_CHECK_DATA() \
  if (action->data.transition_dest == NULL) { \
    return ZATHURA_ERROR_UNKNOWN; \
  }

zathura_error_t
zathura_action_transition_init(zathura_action_t* action)
{
  if (action == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ACTION_TRANSITION_CHECK_TYPE()

  if (action->data.transition_dest != NULL) {
    free(action->data.transition_dest);
  }

  action->data.transition_dest = calloc(1, sizeof(zathura_action_transition_t));
  if (action->data.transition_dest == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_action_transition_clear(zathura_action_t* action)
{
  if (action == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ACTION_TRANSITION_CHECK_TYPE()

  free(action->data.transition_dest);
  action->data.transition_dest = NULL;

  return ZATHURA_ERROR_OK;
}

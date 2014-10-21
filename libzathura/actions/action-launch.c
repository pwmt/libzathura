/* See LICENSE file for license and copyright information */

#include <stdlib.h>

#include "../action.h"
#include "../error.h"

#include "action-launch.h"

#define ACTION_LAUNCH_CHECK_TYPE() \
  if (action->type != ZATHURA_ACTION_LAUNCH) { \
    return ZATHURA_ERROR_ACTION_INVALID_TYPE; \
  }

#define ACTION_LAUNCH_CHECK_DATA() \
  if (action->data.launch_dest == NULL) { \
    return ZATHURA_ERROR_UNKNOWN; \
  }

zathura_error_t
zathura_action_launch_init(zathura_action_t* action)
{
  if (action == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ACTION_LAUNCH_CHECK_TYPE()

  if (action->data.launch_dest != NULL) {
    free(action->data.launch_dest);
  }

  action->data.launch_dest = calloc(1, sizeof(zathura_action_launch_t));
  if (action->data.launch_dest == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_action_launch_clear(zathura_action_t* action)
{
  if (action == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ACTION_LAUNCH_CHECK_TYPE()

  free(action->data.launch_dest);
  action->data.launch_dest = NULL;

  return ZATHURA_ERROR_OK;
}
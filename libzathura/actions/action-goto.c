/* See LICENSE file for license and copyright information */

#include <stdlib.h>

#include "../action.h"
#include "../error.h"

#include "action-goto.h"

#define ACTION_GOTO_CHECK_TYPE() \
  if (action->type != ZATHURA_ACTION_GOTO) { \
    return ZATHURA_ERROR_ACTION_INVALID_TYPE; \
  }

#define ACTION_GOTO_CHECK_DATA() \
  if (action->data.goto_dest == NULL) { \
    return ZATHURA_ERROR_UNKNOWN; \
  }

zathura_error_t
zathura_action_goto_init(zathura_action_t* action)
{
  if (action == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ACTION_GOTO_CHECK_TYPE()

  if (action->data.goto_dest != NULL) {
    free(action->data.goto_dest);
  }

  action->data.goto_dest = calloc(1, sizeof(zathura_action_goto_t));
  if (action->data.goto_dest == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_action_goto_clear(zathura_action_t* action)
{
  if (action == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ACTION_GOTO_CHECK_TYPE()

  free(action->data.goto_dest);
  action->data.goto_dest = NULL;

  return ZATHURA_ERROR_OK;
}
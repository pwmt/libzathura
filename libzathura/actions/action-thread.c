/* See LICENSE file for license and copyright information */

#include <stdlib.h>

#include "../action.h"
#include "../error.h"

#include "action-thread.h"

#define ACTION_THREAD_CHECK_TYPE() \
  if (action->type != ZATHURA_ACTION_THREAD) { \
    return ZATHURA_ERROR_ACTION_INVALID_TYPE; \
  }

#define ACTION_THREAD_CHECK_DATA() \
  if (action->data.thread_dest == NULL) { \
    return ZATHURA_ERROR_UNKNOWN; \
  }

zathura_error_t
zathura_action_thread_init(zathura_action_t* action)
{
  if (action == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ACTION_THREAD_CHECK_TYPE()

  if (action->data.thread_dest != NULL) {
    free(action->data.thread_dest);
  }

  action->data.thread_dest = calloc(1, sizeof(zathura_action_thread_t));
  if (action->data.thread_dest == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_action_thread_clear(zathura_action_t* action)
{
  if (action == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ACTION_THREAD_CHECK_TYPE()

  free(action->data.thread_dest);
  action->data.thread_dest = NULL;

  return ZATHURA_ERROR_OK;
}

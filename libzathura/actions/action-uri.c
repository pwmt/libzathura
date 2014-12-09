/* See LICENSE file for license and copyright information */

#include <stdlib.h>

#include "../action.h"
#include "../error.h"

#include "action-uri.h"

#define ACTION_URI_CHECK_TYPE() \
  if (action->type != ZATHURA_ACTION_URI) { \
    return ZATHURA_ERROR_ACTION_INVALID_TYPE; \
  }

#define ACTION_URI_CHECK_DATA() \
  if (action->data.uri_dest == NULL) { \
    return ZATHURA_ERROR_UNKNOWN; \
  }

zathura_error_t
zathura_action_uri_init(zathura_action_t* action)
{
  if (action == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ACTION_URI_CHECK_TYPE()

  if (action->data.uri_dest != NULL) {
    free(action->data.uri_dest);
  }

  action->data.uri_dest = calloc(1, sizeof(zathura_action_uri_t));
  if (action->data.uri_dest == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_action_uri_clear(zathura_action_t* action)
{
  if (action == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ACTION_URI_CHECK_TYPE()

  free(action->data.uri_dest);
  action->data.uri_dest = NULL;

  return ZATHURA_ERROR_OK;
}

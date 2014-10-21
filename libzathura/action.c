/* See LICENSE file for license and copyright information */

#include <stdlib.h>

#include "action.h"
#include "plugin-api/action.h"
#include "actions/internal.h"

zathura_error_t zathura_action_new(zathura_action_t** action, zathura_action_type_t type)
{
  if (action == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  switch (type) {
    case ZATHURA_ACTION_UNKNOWN:
    case ZATHURA_ACTION_NONE:
    case ZATHURA_ACTION_GOTO:
    case ZATHURA_ACTION_GOTO_REMOTE:
    case ZATHURA_ACTION_GOTO_EMBEDDED:
    case ZATHURA_ACTION_LAUNCH:
    case ZATHURA_ACTION_THREAD:
    case ZATHURA_ACTION_URI:
    case ZATHURA_ACTION_SOUND:
    case ZATHURA_ACTION_MOVIE:
    case ZATHURA_ACTION_HIDE_ANNOTATIONS:
    case ZATHURA_ACTION_NAMED:
    case ZATHURA_ACTION_SET_OCG_STATE:
    case ZATHURA_ACTION_RENDITION:
    case ZATHURA_ACTION_TRANSITION:
    case ZATHURA_ACTION_GOTO_3D_VIEW:
      break;
    default:
      return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *action = calloc(1, sizeof(zathura_action_t));
  if (*action == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  (*action)->type = type;

  /* Initialize sub types */
  zathura_error_t error = ZATHURA_ERROR_OK;

  switch (type) {
    case ZATHURA_ACTION_UNKNOWN:
    case ZATHURA_ACTION_NONE:
    case ZATHURA_ACTION_GOTO:
    case ZATHURA_ACTION_GOTO_REMOTE:
    case ZATHURA_ACTION_GOTO_EMBEDDED:
    case ZATHURA_ACTION_LAUNCH:
    case ZATHURA_ACTION_THREAD:
    case ZATHURA_ACTION_URI:
    case ZATHURA_ACTION_SOUND:
    case ZATHURA_ACTION_MOVIE:
    case ZATHURA_ACTION_HIDE_ANNOTATIONS:
    case ZATHURA_ACTION_NAMED:
    case ZATHURA_ACTION_SET_OCG_STATE:
    case ZATHURA_ACTION_RENDITION:
    case ZATHURA_ACTION_TRANSITION:
    case ZATHURA_ACTION_GOTO_3D_VIEW:
      break;
  }

  if (error != ZATHURA_ERROR_OK) {
    free(*action);
    return error;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_action_free(zathura_action_t* action)
{
  if (action == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  /* Free sub types */
  zathura_error_t error = ZATHURA_ERROR_OK;

  switch (action->type) {
    case ZATHURA_ACTION_UNKNOWN:
    case ZATHURA_ACTION_NONE:
    case ZATHURA_ACTION_GOTO:
    case ZATHURA_ACTION_GOTO_REMOTE:
    case ZATHURA_ACTION_GOTO_EMBEDDED:
    case ZATHURA_ACTION_LAUNCH:
    case ZATHURA_ACTION_THREAD:
    case ZATHURA_ACTION_URI:
    case ZATHURA_ACTION_SOUND:
    case ZATHURA_ACTION_MOVIE:
    case ZATHURA_ACTION_HIDE_ANNOTATIONS:
    case ZATHURA_ACTION_NAMED:
    case ZATHURA_ACTION_SET_OCG_STATE:
    case ZATHURA_ACTION_RENDITION:
    case ZATHURA_ACTION_TRANSITION:
    case ZATHURA_ACTION_GOTO_3D_VIEW:
      break;
  }

  free(action);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_action_get_type(zathura_action_t* action, zathura_action_type_t* type)
{
  if (action == NULL || type == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *type = action->type;

  return ZATHURA_ERROR_OK;
}


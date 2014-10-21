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
    case ZATHURA_ACTION_GOTO_3D_VIEW:
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
      break;
    case ZATHURA_ACTION_NONE:
      break;
    case ZATHURA_ACTION_GOTO_3D_VIEW:
      error = zathura_action_goto_3d_view_init(*action);
      break;
    case ZATHURA_ACTION_GOTO:
      error = zathura_action_goto_init(*action);
      break;
    case ZATHURA_ACTION_GOTO_REMOTE:
      error = zathura_action_goto_remote_init(*action);
      break;
    case ZATHURA_ACTION_GOTO_EMBEDDED:
      error = zathura_action_goto_embedded_init(*action);
      break;
    case ZATHURA_ACTION_LAUNCH:
      error = zathura_action_launch_init(*action);
      break;
    case ZATHURA_ACTION_THREAD:
      error = zathura_action_thread_init(*action);
      break;
    case ZATHURA_ACTION_URI:
      error = zathura_action_uri_init(*action);
      break;
    case ZATHURA_ACTION_SOUND:
      error = zathura_action_sound_init(*action);
      break;
    case ZATHURA_ACTION_MOVIE:
      error = zathura_action_movie_init(*action);
      break;
    case ZATHURA_ACTION_HIDE_ANNOTATIONS:
      error = zathura_action_hide_annotations_init(*action);
      break;
    case ZATHURA_ACTION_NAMED:
      error = zathura_action_named_init(*action);
      break;
    case ZATHURA_ACTION_SET_OCG_STATE:
      error = zathura_action_set_ocg_state_init(*action);
      break;
    case ZATHURA_ACTION_RENDITION:
      error = zathura_action_rendition_init(*action);
      break;
    case ZATHURA_ACTION_TRANSITION:
      error = zathura_action_transition_init(*action);
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
      break;
    case ZATHURA_ACTION_NONE:
      break;
    case ZATHURA_ACTION_GOTO_3D_VIEW:
      error = zathura_action_goto_3d_view_clear(action);
      break;
    case ZATHURA_ACTION_GOTO:
      error = zathura_action_goto_clear(action);
      break;
    case ZATHURA_ACTION_GOTO_REMOTE:
      error = zathura_action_goto_remote_clear(action);
      break;
    case ZATHURA_ACTION_GOTO_EMBEDDED:
      error = zathura_action_goto_embedded_clear(action);
      break;
    case ZATHURA_ACTION_LAUNCH:
      error = zathura_action_launch_clear(action);
      break;
    case ZATHURA_ACTION_THREAD:
      error = zathura_action_thread_clear(action);
      break;
    case ZATHURA_ACTION_URI:
      error = zathura_action_uri_clear(action);
      break;
    case ZATHURA_ACTION_SOUND:
      error = zathura_action_sound_clear(action);
      break;
    case ZATHURA_ACTION_MOVIE:
      error = zathura_action_movie_clear(action);
      break;
    case ZATHURA_ACTION_HIDE_ANNOTATIONS:
      error = zathura_action_hide_annotations_clear(action);
      break;
    case ZATHURA_ACTION_NAMED:
      error = zathura_action_named_clear(action);
      break;
    case ZATHURA_ACTION_SET_OCG_STATE:
      error = zathura_action_set_ocg_state_clear(action);
      break;
    case ZATHURA_ACTION_RENDITION:
      error = zathura_action_rendition_clear(action);
      break;
    case ZATHURA_ACTION_TRANSITION:
      error = zathura_action_transition_clear(action);
      break;
  }

  free(action);

  if (error != ZATHURA_ERROR_OK) {
      return error;
  }

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


/* See LICENSE file for license and copyright information */

#include <stdlib.h>

#include "../action.h"
#include "../error.h"

#include "action-hide-annotations.h"

#define ACTION_HIDE_ANNOTATIONS_CHECK_TYPE() \
  if (action->type != ZATHURA_ACTION_HIDE_ANNOTATIONS) { \
    return ZATHURA_ERROR_ACTION_INVALID_TYPE; \
  }

#define ACTION_HIDE_ANNOTATIONS_CHECK_DATA() \
  if (action->data.hide_annotations_dest == NULL) { \
    return ZATHURA_ERROR_UNKNOWN; \
  }

zathura_error_t
zathura_action_hide_annotations_init(zathura_action_t* action)
{
  if (action == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ACTION_HIDE_ANNOTATIONS_CHECK_TYPE()

  if (action->data.hide_annotations_dest != NULL) {
    free(action->data.hide_annotations_dest);
  }

  action->data.hide_annotations_dest = calloc(1, sizeof(zathura_action_hide_annotations_t));
  if (action->data.hide_annotations_dest == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_action_hide_annotations_clear(zathura_action_t* action)
{
  if (action == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ACTION_HIDE_ANNOTATIONS_CHECK_TYPE()

  free(action->data.hide_annotations_dest);
  action->data.hide_annotations_dest = NULL;

  return ZATHURA_ERROR_OK;
}

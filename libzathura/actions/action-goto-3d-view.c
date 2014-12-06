/* See LICENSE file for license and copyright information */

#include <stdlib.h>

#include "../action.h"
#include "../error.h"

#include "action-goto-3d-view.h"
#include "internal/action-goto-3d-view.h"

#define ACTION_GOTO_3D_VIEW_CHECK_TYPE() \
  if (action->type != ZATHURA_ACTION_GOTO_3D_VIEW) { \
    return ZATHURA_ERROR_ACTION_INVALID_TYPE; \
  }

#define ACTION_GOTO_3D_VIEW_CHECK_DATA() \
  if (action->data.goto_3d_view_dest == NULL) { \
    return ZATHURA_ERROR_UNKNOWN; \
  }

zathura_error_t
zathura_action_goto_3d_view_init(zathura_action_t* action)
{
  if (action == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ACTION_GOTO_3D_VIEW_CHECK_TYPE()

  if (action->data.goto_3d_view_dest != NULL) {
    free(action->data.goto_3d_view_dest);
  }

  action->data.goto_3d_view_dest = calloc(1, sizeof(*(action->data.goto_3d_view_dest)));
  if (action->data.goto_3d_view_dest == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_action_goto_3d_view_clear(zathura_action_t* action)
{
  if (action == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ACTION_GOTO_3D_VIEW_CHECK_TYPE()

  free(action->data.goto_3d_view_dest);
  action->data.goto_3d_view_dest = NULL;

  return ZATHURA_ERROR_OK;
}

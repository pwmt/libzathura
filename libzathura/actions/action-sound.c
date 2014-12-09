/* See LICENSE file for license and copyright information */

#include <stdlib.h>

#include "../action.h"
#include "../error.h"

#include "action-sound.h"

#define ACTION_SOUND_CHECK_TYPE() \
  if (action->type != ZATHURA_ACTION_SOUND) { \
    return ZATHURA_ERROR_ACTION_INVALID_TYPE; \
  }

#define ACTION_SOUND_CHECK_DATA() \
  if (action->data.sound_dest == NULL) { \
    return ZATHURA_ERROR_UNKNOWN; \
  }

zathura_error_t
zathura_action_sound_init(zathura_action_t* action)
{
  if (action == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ACTION_SOUND_CHECK_TYPE()

  if (action->data.sound_dest != NULL) {
    free(action->data.sound_dest);
  }

  action->data.sound_dest = calloc(1, sizeof(zathura_action_sound_t));
  if (action->data.sound_dest == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_action_sound_clear(zathura_action_t* action)
{
  if (action == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ACTION_SOUND_CHECK_TYPE()

  free(action->data.sound_dest);
  action->data.sound_dest = NULL;

  return ZATHURA_ERROR_OK;
}

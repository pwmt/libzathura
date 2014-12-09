/* See LICENSE file for license and copyright information */

#include <stdlib.h>

#include "../action.h"
#include "../error.h"

#include "action-movie.h"

#define ACTION_MOVIE_CHECK_TYPE() \
  if (action->type != ZATHURA_ACTION_MOVIE) { \
    return ZATHURA_ERROR_ACTION_INVALID_TYPE; \
  }

#define ACTION_MOVIE_CHECK_DATA() \
  if (action->data.movie_dest == NULL) { \
    return ZATHURA_ERROR_UNKNOWN; \
  }

zathura_error_t
zathura_action_movie_init(zathura_action_t* action)
{
  if (action == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ACTION_MOVIE_CHECK_TYPE()

  if (action->data.movie_dest != NULL) {
    free(action->data.movie_dest);
  }

  action->data.movie_dest = calloc(1, sizeof(zathura_action_movie_t));
  if (action->data.movie_dest == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_action_movie_clear(zathura_action_t* action)
{
  if (action == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ACTION_MOVIE_CHECK_TYPE()

  free(action->data.movie_dest);
  action->data.movie_dest = NULL;

  return ZATHURA_ERROR_OK;
}

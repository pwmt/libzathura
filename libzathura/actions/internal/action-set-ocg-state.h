/* See LICENSE file for license and copyright information */

#ifndef LIBZATHURA_INTERNAL_ACTION_SET_OCG_STATE_H
#define LIBZATHURA_INTERNAL_ACTION_SET_OCG_STATE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../action.h"

/**
 * A set-ocg-state action
 */
typedef struct zathura_action_set_ocg_state_s {
  /**
   * FIXME: Temporary value so that the struct is not empty
   */
  void* tmp;
} zathura_action_set_ocg_state_t;

/**
 * Initializes the action as a set-ocg-state action
 *
 * @param[in] action The action
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_action_set_ocg_state_init(zathura_action_t* action);

/**
 * Clear the set-ocg-state action
 *
 * @param[in] action The action
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_action_set_ocg_state_clear(zathura_action_t* action);

#ifdef __cplusplus
}
#endif

#endif /* INTERNAL_ACTION_SET_OCG_STATE_H */

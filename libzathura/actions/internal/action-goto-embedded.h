/* See LICENSE file for license and copyright information */

#ifndef INTERNAL_ACTION_GOTO_EMBEDDED_H
#define INTERNAL_ACTION_GOTO_EMBEDDED_H

#include "../../action.h"

/**
 * A goto-embedded action
 */
typedef struct zathura_action_goto_embedded_s {
  /**
   * FIXME: Temporary value so that the struct is not empty
   */
  void* tmp;
} zathura_action_goto_embedded_t;

/**
 * Initializes the action as a goto-embedded action
 *
 * @param[in] action The action
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_action_goto_embedded_init(zathura_action_t* action);

/**
 * Clear the goto-embedded action
 *
 * @param[in] action The action
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_action_goto_embedded_clear(zathura_action_t* action);

#endif /* INTERNAL_ACTION_GOTO_EMBEDDED_H */

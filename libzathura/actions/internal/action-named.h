/* See LICENSE file for license and copyright information */

#ifndef LIBZATHURA_INTERNAL_ACTION_NAMED_H
#define LIBZATHURA_INTERNAL_ACTION_NAMED_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../action.h"

/**
 * A named action
 */
typedef struct zathura_action_named_s {
  /**
   * FIXME: Temporary value so that the struct is not empty
   */
  void* tmp;
} zathura_action_named_t;

/**
 * Initializes the action as a named action
 *
 * @param[in] action The action
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_action_named_init(zathura_action_t* action);

/**
 * Clear the named action
 *
 * @param[in] action The action
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_action_named_clear(zathura_action_t* action);

#ifdef __cplusplus
}
#endif

#endif /* INTERNAL_ACTION_NAMED_H */

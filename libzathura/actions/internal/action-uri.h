/* See LICENSE file for license and copyright information */

#ifndef LIBZATHURA_INTERNAL_ACTION_URI_H
#define LIBZATHURA_INTERNAL_ACTION_URI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../action.h"

/**
 * A uri action
 */
typedef struct zathura_action_uri_s {
  /**
   * FIXME: Temporary value so that the struct is not empty
   */
  void* tmp;
} zathura_action_uri_t;

/**
 * Initializes the action as a uri action
 *
 * @param[in] action The action
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_action_uri_init(zathura_action_t* action);

/**
 * Clear the uri action
 *
 * @param[in] action The action
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_action_uri_clear(zathura_action_t* action);

#ifdef __cplusplus
}
#endif

#endif /* INTERNAL_ACTION_URI_H */

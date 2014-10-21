/* See LICENSE file for license and copyright information */

#ifndef INTERNAL_ACTION_HIDE_ANNOTATIONS_H
#define INTERNAL_ACTION_HIDE_ANNOTATIONS_H

#include "../../action.h"

/**
 * A hide-annotations action
 */
typedef struct zathura_action_hide_annotations_s {
  /**
   * FIXME: Temporary value so that the struct is not empty
   */
  void* tmp;
} zathura_action_hide_annotations_t;

/**
 * Initializes the action as a hide-annotations action
 *
 * @param[in] action The action
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_action_hide_annotations_init(zathura_action_t* action);

/**
 * Clear the hide-annotations action
 *
 * @param[in] action The action
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_action_hide_annotations_clear(zathura_action_t* action);

#endif /* INTERNAL_ACTION_HIDE_ANNOTATIONS_H */
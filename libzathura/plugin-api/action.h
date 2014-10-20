/* See LICENSE file for license and copyright information */

#ifndef PLUGIN_API_ACTIONS_H
#define PLUGIN_API_ACTIONS_H

#include "../error.h"
#include "../action.h"

/**
 * Creates a new action of the given type.
 *
 * @param[out] action The action
 * @param[in] type The type
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_action_new(zathura_action_t** action,
    zathura_action_type_t type);

/**
 * Frees an action
 *
 * @param[in] action The action
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_action_free(zathura_action_t* action);

#endif /* PLUGIN_API_ACTIONS_H */

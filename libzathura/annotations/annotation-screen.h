/* See LICENSE file for license and copyright information */

#ifndef ANNOTATION_SCREEN_H
#define ANNOTATION_SCREEN_H

#include "../annotations.h"
#include "types.h"

/**
 * Sets the title of this screen annotation
 *
 * @param[in] annotation The annotation
 * @param[in] title The title
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_screen_set_title(zathura_annotation_t*
    annotation, const char* title);

/**
 * Returns the title of this screen annotation
 *
 * @param[in] annotation The annotation
 * @param[out] title The title
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_screen_get_title(zathura_annotation_t*
    annotation, char** title);

/**
 * Sets an action to be performed when the screen annotation is activated.
 *
 * @param[in] annotation The annotation
 * @param[in] action The action
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t
zathura_annotation_screen_set_action(zathura_annotation_t* annotation,
    zathura_action_t* action);

/**
 * Returns an action to be performed when the screen annotation is activated.
 *
 * @param[in] annotation The annotation
 * @param[out] action The action
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t
zathura_annotation_screen_get_action(zathura_annotation_t* annotation,
    zathura_action_t** action);

#endif // ANNOTATION_SCREEN_H

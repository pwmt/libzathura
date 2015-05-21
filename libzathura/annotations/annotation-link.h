/* See LICENSE file for license and copyright information */

#ifndef ANNOTATION_LINK_H
#define ANNOTATION_LINK_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../annotations.h"
#include "../error.h"

/**
 * Sets an action to be performed when the link annotation is activated.
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
zathura_annotation_link_set_action(zathura_annotation_t* annotation,
    zathura_action_t* action);

/**
 * Returns an action to be performed when the link annotation is activated.
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
zathura_annotation_link_get_action(zathura_annotation_t* annotation,
    zathura_action_t** action);

/**
 * Sets the annotation’s highlighting mode, the visual effect to be used when
 * the mouse button is pressed or held down inside its active area.
 *
 * @param[in] annotation The annotation
 * @param[in] mode The highlighting mode
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t
zathura_annotation_link_set_highlighting_mode(zathura_annotation_t* annotation,
    zathura_annotation_highlighting_mode_t mode);

/**
 * Returns the  annotation’s highlighting mode, the visual effect to be used
 * when the mouse button is pressed or held down inside its active area.
 *
 * @param[in] annotation The annotation
 * @param[out] mode The highlighting mode
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t
zathura_annotation_link_get_highlighting_mode(zathura_annotation_t* annotation,
    zathura_annotation_highlighting_mode_t* mode);

/**
 * Sets a list of 8 × n numbers specifying the coordinates of n quadri-
 * laterals in default user space. Each quadrilateral encompasses a word
 * or group of contiguous words in the text underlying the annotation.
 *
 * The text is oriented with respect to the edge connecting points.
 *
 * @param[in] annotation The annotation
 * @param[in] quad_points The list of points
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_link_set_quad_points(zathura_annotation_t* annotation, zathura_list_t* quad_points);

/**
 * Returns a list of 8 × n numbers specifying the coordinates of n quadri-
 * laterals in default user space. Each quadrilateral encompasses a word
 * or group of contiguous words in the text underlying the annotation.
 *
 * The text is oriented with respect to the edge connecting points.
 *
 * @param[in] annotation The annotation
 * @param[out] quad_points The list of quad points
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_link_get_quad_points(zathura_annotation_t* annotation, zathura_list_t** quad_points);

#ifdef __cplusplus
}
#endif

#endif // ANNOTATION_LINK_H

/* See LICENSE file for license and copyright information */

#ifndef LIBZATHURA_ANNOTATION_UNDERLINE_H
#define LIBZATHURA_ANNOTATION_UNDERLINE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../annotations.h"
#include "../error.h"

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
zathura_error_t zathura_annotation_underline_set_quad_points(zathura_annotation_t* annotation, zathura_list_t* quad_points);

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
zathura_error_t zathura_annotation_underline_get_quad_points(zathura_annotation_t* annotation, zathura_list_t** quad_points);

#ifdef __cplusplus
}
#endif

#endif // ANNOTATION_UNDERLINE_H

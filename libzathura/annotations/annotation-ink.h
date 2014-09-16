/* See LICENSE file for license and copyright information */

#ifndef ANNOTATION_INK_H
#define ANNOTATION_INK_H

#include "../annotations.h"
#include "../list.h"
#include "border.h"

/**
 * Sets a list of n zathura_path_t paths, each representing a stroked path.
 * Each array is a series of alternating horizontal and vertical
 * coordinates in default user space, specifying points along the path.
 * When drawn, the points are connected by straight lines or curves in an
 * implementation-dependent way.
 *
 * @param[in] annotation The annotation
 * @param[in] paths The list of paths
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_ink_set_paths(zathura_annotation_t* annotation, zathura_list_t* paths);

/**
 * Returns a list of n zathura_path_t paths, each representing a stroked path.
 * Each array is a series of alternating horizontal and vertical
 * coordinates in default user space, specifying points along the path.
 * When drawn, the points are connected by straight lines or curves in an
 * implementation-dependent way.
 *
 * @param[in] annotation The annotation
 * @param[out] paths The list of paths
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_ink_get_paths(zathura_annotation_t* annotation, zathura_list_t** paths);

/**
 * Sets the border of this free text annotation
 *
 * @param[in] annotation The annotation
 * @param[in] border The border
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_ink_set_border(zathura_annotation_t*
    annotation, zathura_annotation_border_t border);

/**
 * Returns the border of this free text annotation
 *
 * @param[in] annotation The annotation
 * @param[out] border The border
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_ink_get_border(zathura_annotation_t*
    annotation, zathura_annotation_border_t* border);

#endif // ANNOTATION_INK_H

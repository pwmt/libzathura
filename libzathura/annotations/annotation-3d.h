/* See LICENSE file for license and copyright information */

#ifndef ANNOTATION_3D_H
#define ANNOTATION_3D_H

#include "../annotations.h"
#include "types.h"

typedef struct zathura_3d_s zathura_3d_t;

/**
 * Sets the actual 3d of this 3d annotation
 *
 * @param[in] annotation The annotation
 * @param[in] artwork The 3d object
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_3d_set_artwork(zathura_annotation_t*
    annotation, zathura_3d_t* artwork);

/**
 * Returns the actual 3d of this 3d annotation
 *
 * @param[in] annotation The annotation
 * @param[out] artwork The 3d object
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_3d_get_artwork(zathura_annotation_t*
    annotation, zathura_3d_t** artwork);

/**
 * Sets the view_box of the 3d annotation
 *
 * @param[in] annotation The annotation
 * @param[in] view_box The view box
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_3d_set_view_box(zathura_annotation_t*
    annotation, zathura_rectangle_t view_box);

/**
 * Returns the view_box of the 3d annotation
 *
 * @param[in] annotation The annotation
 * @param[out] view_box The view box
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_3d_get_view_box(zathura_annotation_t*
    annotation, zathura_rectangle_t* view_box);

/**
 * Sets a flag indicating the primary use of the 3D annotation. If true , it is
 * intended to be interactive; if false, it is intended to be manipulated
 * programmatically, as with a JavaScript animation. Viewer applications may
 * present different user interface controls for interactive 3D annotations
 * (for example, to rotate, pan, or zoom the artwork) than for those managed
 * by a script or other mechanism.
 *
 * @param[in] annotation The annotation
 * @param[in] is_interactive If the annotation should be interactive
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t
zathura_annotation_3d_set_interactive(zathura_annotation_t* annotation, bool is_interactive);

/**
 * Sets a flag indicating the primary use of the 3D annotation. If true , it is
 * intended to be interactive; if false, it is intended to be manipulated
 * programmatically, as with a JavaScript animation. Viewer applications may
 * present different user interface controls for interactive 3D annotations
 * (for example, to rotate, pan, or zoom the artwork) than for those managed
 * by a script or other mechanism.
 *
 * @param[in] annotation The annotation
 * @param[out] is_interactive If the annotation should be interactive
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t
zathura_annotation_3d_is_interactive(zathura_annotation_t* annotation, bool* is_interactive);

#endif //ANNOTATION_3D_H

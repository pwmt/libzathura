/* See LICENSE file for license and copyright information */

#ifndef ANNOTATION_POPUP_H
#define ANNOTATION_POPUP_H

#include "../annotations.h"
#include "../error.h"

/**
 * Sets the parent annotation with which this pop-up annotation is associated.
 *
 * @param[in] annotation The annotation
 * @param[in] parent The parent annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_popup_set_parent(zathura_annotation_t* annotation, zathura_annotation_t* parent);

/**
 * Sets the parent annotation with which this pop-up annotation is associated.
 *
 * @param[in] annotation The annotation
 * @param[out] parent The parent annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_popup_get_parent(zathura_annotation_t* annotation, zathura_annotation_t** parent);

/**
 * Sets a flag specifying whether the pop-up annotation should initially be
 * displayed open.
 *
 * @param[in] annotation The annotation
 * @param[in] is_open If the annotation should initially be displayed open
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_popup_set_open(zathura_annotation_t* annotation, bool is_open);

/**
 * Returns a flag specifying whether the pop-up annotation should initially be
 * displayed open.
 *
 * @param[in] annotation The annotation
 * @param[out] is_open If the annotation should initially be displayed open
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_popup_is_open(zathura_annotation_t* annotation, bool* is_open);

#endif //ANNOTATION_POPUP_H

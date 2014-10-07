/* See LICENSE file for license and copyright information */

#ifndef ANNOTATION_MARKUP_H
#define ANNOTATION_MARKUP_H

#include "../annotations.h"

/**
 * Checks if the given annotation is a markup annotation or not.
 *
 * @param[in] annotation The annotation
 * @param[out] is_markup_annotation If the annotation is a markup annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_is_markup_annotation(zathura_annotation_t*
    annotation, bool* is_markup_annotation);

/**
 * Returns the label of this text annotation
 *
 * @param[in] annotation The annotation
 * @param[in] label The attachment
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_markup_set_label(zathura_annotation_t*
    annotation, char* label);

/**
 * Returns the label of this text annotation
 *
 * @param[in] annotation The annotation
 * @param[out] label The attachment
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_markup_get_label(zathura_annotation_t*
    annotation, char** label);

/**
 * Sets the pop-up annotation annotation with which this markup annotation is associated.
 *
 * @param[in] annotation The annotation
 * @param[in] popup_annotation The popup annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_markup_set_popup_annotation(zathura_annotation_t* annotation, zathura_annotation_t* popup_annotation);

/**
 * Sets the pop-up annotation annotation with which this markup annotation is associated.
 *
 * @param[in] annotation The annotation
 * @param[out] popup_annotation The popup annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_markup_get_popup_annotation(zathura_annotation_t* annotation, zathura_annotation_t** popup_annotation);

/**
 * Returns the text of this text annotation
 *
 * @param[in] annotation The annotation
 * @param[in] text The attachment
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_markup_set_text(zathura_annotation_t*
    annotation, char* text);

/**
 * Returns the text of this text annotation
 *
 * @param[in] annotation The annotation
 * @param[out] text The attachment
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_markup_get_text(zathura_annotation_t*
    annotation, char** text);

/**
 * Sets the date and time when the annotation was created.
 *
 * @param[in] annotation The annotation
 * @param[in] creation_date The creation date of the annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_markup_set_creation_date(zathura_annotation_t*
    annotation, time_t creation_date);

/**
 * Returns the date and time when the annotation was created.
 *
 * @param[in] annotation The annotation
 * @param[in] creation_date The creation date of the annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_markup_get_creation_date(zathura_annotation_t*
    annotation, time_t* creation_date);

/**
 * Sets the reply-to annotation annotation with which this markup annotation is
 * associated.
 *
 * @param[in] annotation The annotation
 * @param[in] reply_to_annotation Reply-to annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t
zathura_annotation_markup_set_reply_to_annotation(zathura_annotation_t*
    annotation, zathura_annotation_t* reply_to_annotation);

/**
 * Returns the reply-to annotation annotation with which this markup annotation
 * is associated.
 *
 * @param[in] annotation The annotation
 * @param[out] reply_to_annotation Reply-to annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t
zathura_annotation_markup_get_reply_to_annotation(zathura_annotation_t*
    annotation, zathura_annotation_t** reply_to_annotation);

/**
 * Sets a reply_type used for the following purpose:
 *
 * @param[in] annotation The annotation
 * @param[in] reply_type The reply_type
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_markup_set_reply_type(zathura_annotation_t* annotation,
    zathura_annotation_markup_reply_type_t reply_type);

/**
 * Returns the reply_type used for the following purpose:
 *
 * @param[in] annotation The annotation
 * @param[in] reply_type The reply_type
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_markup_get_reply_type(zathura_annotation_t* annotation,
    zathura_annotation_markup_reply_type_t* reply_type);

#endif // ANOTATION_MARKUP_H

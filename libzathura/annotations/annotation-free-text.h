/* See LICENSE file for license and copyright information */

#ifndef ANNOTATION_FREE_TEXT_H
#define ANNOTATION_FREE_TEXT_H

#include "../types.h"
#include "types.h"

#include "../annotations.h"

/**
 * Sets the text of this free text annotation
 *
 * @param[in] annotation The annotation
 * @param[in] text The text
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_free_text_set_text(zathura_annotation_t*
    annotation, const char* text);

/**
 * Returns the text of this free text annotation
 *
 * @param[in] annotation The annotation
 * @param[out] text The text
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_free_text_get_text(zathura_annotation_t*
    annotation, char** text);

/**
 * Sets the justification of this free text annotation
 *
 * @param[in] annotation The annotation
 * @param[in] justification The justification
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_free_text_set_justification(zathura_annotation_t*
    annotation, zathura_annotation_justification_t justification);

/**
 * Returns the justification of this free text annotation
 *
 * @param[in] annotation The annotation
 * @param[out] justification The justification
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_free_text_get_justification(zathura_annotation_t*
    annotation, zathura_annotation_justification_t* justification);

/**
 * Sets the rich text of this free text annotation
 *
 * @param[in] annotation The annotation
 * @param[in] rich_text The rich text
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_free_text_set_rich_text(zathura_annotation_t*
    annotation, const char* rich_text);

/**
 * Returns the rich text of this free text annotation
 *
 * @param[in] annotation The annotation
 * @param[out] rich_text The rich text
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_free_text_get_rich_text(zathura_annotation_t*
    annotation, char** rich_text);

/**
 * Sets the style string of this free text annotation
 *
 * @param[in] annotation The annotation
 * @param[in] style_string The style string
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_free_text_set_style_string(zathura_annotation_t*
    annotation, const char* style_string);

/**
 * Returns the style string of this free text annotation
 *
 * @param[in] annotation The annotation
 * @param[out] style_string The style string
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_free_text_get_style_string(zathura_annotation_t*
    annotation, char** style_string);

/**
 * Sets the callout line of this free text annotation
 *
 * @param[in] annotation The annotation
 * @param[in] callout_line The callout line
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_free_text_set_callout_line(zathura_annotation_t*
    annotation, zathura_annotation_callout_line_t callout_line);

/**
 * Returns the callout line of this free text annotation
 *
 * @param[in] annotation The annotation
 * @param[out] callout_line The callout line
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_free_text_get_callout_line(zathura_annotation_t*
    annotation, zathura_annotation_callout_line_t* callout_line);

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
zathura_error_t zathura_annotation_free_text_set_border(zathura_annotation_t*
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
zathura_error_t zathura_annotation_free_text_get_border(zathura_annotation_t*
    annotation, zathura_annotation_border_t* border);

/**
 * Sets the intent of this free text annotation
 *
 * @param[in] annotation The annotation
 * @param[in] intent The intent
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_free_text_set_intent(zathura_annotation_t*
    annotation, zathura_annotation_markup_intent_t intent);

/**
 * Returns the intent of this free text annotation
 *
 * @param[in] annotation The annotation
 * @param[out] intent The intent
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_free_text_get_intent(zathura_annotation_t*
    annotation, zathura_annotation_markup_intent_t* intent);

/**
 * Sets the padding of this free text annotation
 *
 * @param[in] annotation The annotation
 * @param[in] padding The padding
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_free_text_set_padding(zathura_annotation_t*
    annotation, zathura_annotation_padding_t padding);

/**
 * Returns the padding of this free text annotation
 *
 * @param[in] annotation The annotation
 * @param[out] padding The padding
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_free_text_get_padding(zathura_annotation_t*
    annotation, zathura_annotation_padding_t* padding);

/**
 * Sets the line ending of this free text annotation
 *
 * @param[in] annotation The annotation
 * @param[in] line_ending The line ending
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_free_text_set_line_ending(zathura_annotation_t*
    annotation, zathura_annotation_line_ending_t line_ending[2]);

/**
 * Returns the line ending of this free text annotation
 *
 * @param[in] annotation The annotation
 * @param[out] line_ending The line ending
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_free_text_get_line_ending(zathura_annotation_t*
    annotation, zathura_annotation_line_ending_t line_ending[2]);

#endif // ANNOTATION_FREE_TEXT_H

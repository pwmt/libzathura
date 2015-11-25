/* See LICENSE file for license and copyright information */

#ifndef LIBZATHURA_ANNOTATION_LINE_H
#define LIBZATHURA_ANNOTATION_LINE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../annotations.h"

/**
 * Sets the coordinates of this line annotation consisting of the start (index
 * 0) and end (index 1) point
 *
 * @param[in] annotation The annotation
 * @param[in] coordinates The coordinates
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_line_set_coordinates(zathura_annotation_t*
    annotation, zathura_point_t coordinates[2]);

/**
 * Returns the coordinates of this line annotation consisting of the start (index
 * 0) and end (index 1) point
 *
 * @param[in] annotation The annotation
 * @param[out] coordinates The coordinates
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_line_get_coordinates(zathura_annotation_t*
    annotation, zathura_point_t coordinates[2]);

/**
 * Sets the border of this line annotation
 *
 * @param[in] annotation The annotation
 * @param[in] border The border
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_line_set_border(zathura_annotation_t*
    annotation, zathura_annotation_border_t border);

/**
 * Returns the border of this line annotation
 *
 * @param[in] annotation The annotation
 * @param[out] border The border
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_line_get_border(zathura_annotation_t*
    annotation, zathura_annotation_border_t* border);

/**
 * Sets the line ending of this line annotation
 *
 * @param[in] annotation The annotation
 * @param[in] line_ending The line ending
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_line_set_line_ending(zathura_annotation_t*
    annotation, zathura_annotation_line_ending_t line_ending[2]);

/**
 * Returns the line ending of this line annotation
 *
 * @param[in] annotation The annotation
 * @param[out] line_ending The line ending
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_line_get_line_ending(zathura_annotation_t*
    annotation, zathura_annotation_line_ending_t line_ending[2]);

/**
 * Sets the color of the line annotation
 *
 * @param[in] annotation The annotation
 * @param[in] color The color
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_line_set_color(zathura_annotation_t*
    annotation, zathura_annotation_color_t color);

/**
 * Returns the color of the line annotation
 *
 * @param[in] annotation The annotation
 * @param[out] color The color
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_line_get_color(zathura_annotation_t*
    annotation, zathura_annotation_color_t* color);

/**
 * Sets the leader lines length of the line annotation
 *
 * @param[in] annotation The annotation
 * @param[in] leader_lines_length Length of the leader lines
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_line_set_leader_lines_length(zathura_annotation_t*
    annotation, int leader_lines_length);

/**
 * Returns the leader lines length of the line annotation
 *
 * @param[in] annotation The annotation
 * @param[out] leader_lines_length Length of the leader lines
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_line_get_leader_lines_length(zathura_annotation_t*
    annotation, int* leader_lines_length);

/**
 * Sets the leader line extensions length of the line annotation
 *
 * @param[in] annotation The annotation
 * @param[in] leader_line_extensions_length Length of the leader lines
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_line_set_leader_line_extensions_length(zathura_annotation_t*
    annotation, unsigned int leader_line_extensions_length);

/**
 * Returns the leader line extensions length of the line annotation
 *
 * @param[in] annotation The annotation
 * @param[out] leader_line_extensions_length Length of the leader lines
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_line_get_leader_line_extensions_length(zathura_annotation_t*
    annotation, unsigned int* leader_line_extensions_length);

/**
 * Sets the leader lines offset of the line annotation
 *
 * @param[in] annotation The annotation
 * @param[in] leader_line_offset Length of the leader lines
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_line_set_leader_line_offset(zathura_annotation_t*
    annotation, unsigned int leader_line_offset);

/**
 * Returns the leader lines offset of the line annotation
 *
 * @param[in] annotation The annotation
 * @param[out] leader_line_offset Length of the leader lines
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_line_get_leader_line_offset(zathura_annotation_t*
    annotation, unsigned int* leader_line_offset);

/**
 * Sets a flag specifying whether the line annotation should initially be
 * displayed open.
 *
 * @param[in] annotation The annotation
 * @param[in] caption If the annotation should initially be displayed open
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_line_set_caption(zathura_annotation_t* annotation, bool caption);

/**
 * Returns a flag specifying whether the line annotation should initially be
 * displayed open.
 *
 * @param[in] annotation The annotation
 * @param[out] caption If the annotation should initially be displayed open
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_line_has_caption(zathura_annotation_t* annotation, bool* caption);

/**
 * Sets the caption_position of this line annotation
 *
 * @param[in] annotation The annotation
 * @param[in] caption_position The caption_position
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_line_set_caption_position(zathura_annotation_t*
    annotation, zathura_annotation_line_caption_position_t caption_position);

/**
 * Returns the caption_position of this line annotation
 *
 * @param[in] annotation The annotation
 * @param[out] caption_position The caption_position
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_line_get_caption_position(zathura_annotation_t*
    annotation, zathura_annotation_line_caption_position_t* caption_position);

/**
 * Sets the intent of this line annotation
 *
 * @param[in] annotation The annotation
 * @param[in] intent The intent
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_line_set_intent(zathura_annotation_t*
    annotation, zathura_annotation_markup_intent_t intent);

/**
 * Returns the intent of this line annotation
 *
 * @param[in] annotation The annotation
 * @param[out] intent The intent
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_line_get_intent(zathura_annotation_t*
    annotation, zathura_annotation_markup_intent_t* intent);

#ifdef __cplusplus
}
#endif

#endif // ANNOTATION_LINE_H

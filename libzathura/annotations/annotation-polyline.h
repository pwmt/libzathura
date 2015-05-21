/* See LICENSE file for license and copyright information */

#ifndef ANNOTATION_POLY_LINE_H
#define ANNOTATION_POLY_LINE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../annotations.h"
#include "types.h"
#include "color.h"

/**
 * Sets a list of zathura_point_t representing the alternating horizontal and
 * vertical coordinates, respectively, of each vertex, in default user space.
 *
 * @param[in] annotation The annotation
 * @param[in] vertices The list of vertices
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_poly_line_set_vertices(zathura_annotation_t* annotation, zathura_list_t* vertices);

/**
 * Returns a list of zathura_point_t representing the alternating horizontal and
 * vertical coordinates, respectively, of each vertex, in default user space.
 *
 * @param[in] annotation The annotation
 * @param[out] vertices The list of vertices
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_poly_line_get_vertices(zathura_annotation_t* annotation, zathura_list_t** vertices);

/**
 * Sets the line ending of this poly-line annotation
 *
 * @param[in] annotation The annotation
 * @param[in] line_ending The line ending
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_poly_line_set_line_ending(zathura_annotation_t*
    annotation, zathura_annotation_line_ending_t line_ending[2]);

/**
 * Returns the line ending of this poly-line annotation
 *
 * @param[in] annotation The annotation
 * @param[out] line_ending The line ending
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_poly_line_get_line_ending(zathura_annotation_t*
    annotation, zathura_annotation_line_ending_t line_ending[2]);

/**
 * Sets a list of zathura_border_t borders specifying the width and dash pattern
 * to be used in drawing the line.
 *
 * @param[in] annotation The annotation
 * @param[in] borders The list of borders
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_poly_line_set_borders(zathura_annotation_t* annotation, zathura_list_t* borders);

/**
 * Returns a list of zathura_border_t borders specifying the width and dash pattern
 * to be used in drawing the line.
 *
 * @param[in] annotation The annotation
 * @param[out] borders The list of borders
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_poly_line_get_borders(zathura_annotation_t* annotation, zathura_list_t** borders);

/**
 * Sets the interior color of the poly-line annotation with which to fill the
 * annotation’s line endings.
 *
 * @param[in] annotation The annotation
 * @param[in] interior_color The interior_color
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_poly_line_set_interior_color(zathura_annotation_t*
    annotation, zathura_annotation_color_t interior_color);

/**
 * Returns the interior color of the poly-line annotation with which to fill the
 * annotation’s line endings.
 *
 * @param[in] annotation The annotation
 * @param[out] interior_color The interior_color
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_poly_line_get_interior_color(zathura_annotation_t*
    annotation, zathura_annotation_color_t* interior_color);

/**
 * Sets the intent of this poly-line annotation
 *
 * @param[in] annotation The annotation
 * @param[in] intent The intent
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_poly_line_set_intent(zathura_annotation_t*
    annotation, zathura_annotation_markup_intent_t intent);

/**
 * Returns the intent of this poly-line annotation
 *
 * @param[in] annotation The annotation
 * @param[out] intent The intent
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_poly_line_get_intent(zathura_annotation_t*
    annotation, zathura_annotation_markup_intent_t* intent);

/**
 * Sets the measure dictionary of this poly-line annotation
 *
 * @param[in] annotation The annotation
 * @param[in] measure The measure
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_poly_line_set_measure(zathura_annotation_t*
    annotation, zathura_annotation_measure_t* measure);

/**
 * Returns the measure dictionary of this poly-line annotation
 *
 * @param[in] annotation The annotation
 * @param[out] measure The measure
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_poly_line_get_measure(zathura_annotation_t*
    annotation, zathura_annotation_measure_t** measure);

#ifdef __cplusplus
}
#endif

#endif // ANNOTATION_POLY_LINE_H

/* See LICENSE file for license and copyright information */

#ifndef INTERNAL_ANNOTATION_POLY_LINE_H
#define INTERNAL_ANNOTATION_POLY_LINE_H

#include "../color.h"
#include "../../list.h"

/**
 * poly_line annotations display closed poly_lines on the page. Such poly_lines may
 * have any number of vertices connected by straight lines.
 */
typedef struct zathura_annotation_poly_line_s {
  /**
   * An array of numbers representing the alternating horizontal and vertical
   * coordinates, respectively, of each vertex, in default user space.
   */
  zathura_list_t* vertices;

  /**
   * An array of two names specifying the line ending styles to be used in
   * drawing the annotation’s border. The first and second elements of the
   * array specify the line ending styles for the endpoints defined,
   * respectively, by the first and second pairs of coordinates, (x1, y1)
   * and (x2, y2), in the L array.
   */
  zathura_annotation_line_ending_t line_endings[2];

  /**
   * A border style dictionary specifying the width and dash pattern to be used
   * in drawing the line.
   */
  zathura_list_t* borders;

  /**
   * An array of numbers in the range 0.0 to 1.0 specifying the interior color
   * with which to fill the annotation’s line ending.
   */
  zathura_annotation_color_t interior_color;

  /**
   * A name describing the intent of the poly_line or polyline annotation
   */
  zathura_annotation_markup_intent_t intent;

  /**
   * A measure dictionary that specifies the scale and units that apply to the
   * annotation.
   */
  zathura_annotation_measure_t* measure;
} zathura_annotation_poly_line_t;

/**
 * Initializes the annotation as a poly_line annotation
 *
 * @param annotation The annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_poly_line_init(zathura_annotation_t* annotation);

/**
 * Clear the annotation as a poly_line annotation
 *
 * @param annotation The annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_poly_line_clear(zathura_annotation_t* annotation);

#endif // INTERNAL_ANNOTATION_POLY_LINE_H

/* See LICENSE file for license and copyright information */

#ifndef INTERNAL_ANNOTATION_POLYGON_H
#define INTERNAL_ANNOTATION_POLYGON_H

/**
 * Polygon annotations display closed polygons on the page. Such polygons may
 * have any number of vertices connected by straight lines.
 */
typedef struct zathura_annotation_polygon_s {
  /**
   * An array of numbers representing the alternating horizontal and vertical
   * coordinates, respectively, of each vertex, in default user space.
   */
  zathura_list_t* vertices;

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
   * A name describing the intent of the polygon or polyline annotation
   */
  zathura_annotation_markup_intent_t intent;

  /**
   * A measure dictionary that specifies the scale and units that apply to the
   * annotation.
   */
  zathura_annotation_measure_t* measure;
} zathura_annotation_polygon_t;

/**
 * Initializes the annotation as a polygon annotation
 *
 * @param annotation The annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_polygon_init(zathura_annotation_t* annotation);

/**
 * Clear the annotation as a polygon annotation
 *
 * @param annotation The annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_polygon_clear(zathura_annotation_t* annotation);

#endif // INTERNAL_ANNOTATION_POLYGON_H

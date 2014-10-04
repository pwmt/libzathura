/* See LICENSE file for license and copyright information */

#ifndef INTERNAL_ANNOTATION_POLYGON_H
#define INTERNAL_ANNOTATION_POLYGON_H

typedef struct zathura_annotation_polygon_s {
  zathura_list_t* vertices;
  zathura_list_t* borders;
  zathura_annotation_color_t interior_color;
  zathura_annotation_markup_intent_t intent;
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

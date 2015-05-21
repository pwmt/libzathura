/* See LICENSE file for license and copyright information */

#ifndef ANNOTATION_TEXT_MARKUP_H
#define ANNOTATION_TEXT_MARKUP_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../list.h"

/**
 * Text markup annotations appear as highlights, underlines, strikeouts or
 * jagged ("squiggly") underlines in the text of a document. When opened,
 * they display a pop-up window containing the text of the associated note.
 *
 * The type of annotation that this dictionary describes; must be Highlight,
 * Underline, Squiggly, or StrikeOut for a highlight, underline,
 * squiggly-underline, or strikeout annotation, respectively.
 */
typedef struct zathura_annotation_text_markup_s {
  /**
   * An array of 8 × n numbers specifying the coordinates of n quadri-
   * laterals in default user space. Each quadrilateral encompasses a word
   * or group of contiguous words in the text underlying the annotation.
   *
   * The text is oriented with respect to the edge connecting points.
   */
  zathura_list_t* quad_points;
} zathura_annotation_text_markup_t;

/**
 * Sets a list of 8 × n numbers specifying the coordinates of n quadri-
 * laterals in default user space. Each quadrilateral encompasses a word
 * or group of contiguous words in the text underlying the annotation.
 *
 * The text is oriented with respect to the edge connecting points.
 *
 * @param[in] annotation The annotation
 * @param[in] quad_points The list of points
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t
zathura_annotation_text_markup_set_quad_points(zathura_annotation_t* annotation,
    zathura_list_t* quad_points);

/**
 * Returns a list of 8 × n numbers specifying the coordinates of n quadri-
 * laterals in default user space. Each quadrilateral encompasses a word
 * or group of contiguous words in the text underlying the annotation.
 *
 * The text is oriented with respect to the edge connecting points.
 *
 * @param[in] annotation The annotation
 * @param[out] quad_points The list of quad points
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t
zathura_annotation_text_markup_get_quad_points(zathura_annotation_t* annotation,
    zathura_list_t** quad_points);

zathura_error_t zathura_annotation_text_markup_init(zathura_annotation_t* annotation);

zathura_error_t zathura_annotation_text_markup_clear(zathura_annotation_t* annotation);

#ifdef __cplusplus
}
#endif

#endif // ANNOTATION_TEXT_MARKUP_H

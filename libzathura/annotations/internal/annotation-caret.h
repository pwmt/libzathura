/* See LICENSE file for license and copyright information */

#ifndef INTERNAL_ANNOTATION_CARET_H
#define INTERNAL_ANNOTATION_CARET_H

/**
 * A caret annotation is a visual symbol that indicates the presence of text
 * edits.
 */
typedef struct zathura_annotation_caret_s {
  /**
   * A set of four numbers describing the numerical differences between two
   * rectangles: the Rect entry of the annotation and the actual boundaries
   * of the underlying caret. Such a difference can occur, for example, when
   * a paragraph symbol specified by @a symbol is displayed along with the caret.
   *
   * The four numbers correspond to the differences in default user space
   * between the left, top, right, and bottom coordinates of Rect and those
   * of the caret, respectively. Each value must be greater than or equal
   * to 0. The sum of the top and bottom differences must be less than the
   * height of Rect, and the sum of the left and right differences must be
   * less than the width of Rect.
   */
  zathura_annotation_padding_t padding;

  /**
   * A name specifying a symbol to be associated with the caret
   */
  zathura_annotation_caret_symbol_t symbol;
} zathura_annotation_caret_t;

/**
 * Initializes the annotation as a caret annotation
 *
 * @param annotation The annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_caret_init(zathura_annotation_t* annotation);

/**
 * Clear the annotation as a caret annotation
 *
 * @param annotation The annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_caret_clear(zathura_annotation_t* annotation);

#endif // INTERNAL_ANNOTATION_CARET_H

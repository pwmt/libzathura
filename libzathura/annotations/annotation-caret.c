/* See LICENSE file for license and copyright information */

#include "annotation-caret.h"

/**
 * A caret annotation is a visual symbol that indicates the presence of text
 * edits.
 */
struct zathura_annotation_caret_s {
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
  struct {
    unsigned int left;
    unsigned int top;
    unsigned int right;
    unsigned int bottom;
  } padding;

  /**
   * A name specifying a symbol to be associated with the caret
   */
  zathura_annotation_caret_symbol_t symbol;
};

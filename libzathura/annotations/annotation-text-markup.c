/* See LICENSE file for license and copyright information */

#include "../list.h"

/**
 * Text markup annotations appear as highlights, underlines, strikeouts or
 * jagged ("squiggly") underlines in the text of a document. When opened,
 * they display a pop-up window containing the text of the associated note.
 *
 * The type of annotation that this dictionary describes; must be Highlight,
 * Underline, Squiggly, or StrikeOut for a highlight, underline,
 * squiggly-underline, or strikeout annotation, respectively.
 */
struct zathura_text_markup_s {
  /**
   * An array of 8 × n numbers specifying the coordinates of n quadri-
   * laterals in default user space. Each quadrilateral encompasses a word
   * or group of contiguous words in the text underlying the annotation.
   *
   * The text is oriented with respect to the edge connecting points.
   */
  zathura_list_t* quad_points;
};

/* See LICENSE file for license and copyright information */

#include "annotation-free-text.h"
#include "annotation-markup.h"
#include "annotation-line.h"
#include "border.h"

/**
 * A free text annotation displays text directly on the page. Unlike an
 * ordinary text annotation , a free text annotation has no open or closed
 * state; instead of being displayed in a pop-up window, the text is always
 * visible.
 */
struct zathura_annotation_free_text_s {
  /**
   * The default appearance string to be used in formatting the text.
   */
  char* text;

  /**
   * Specifying the form of quadding (justification) to be
   * used in displaying the annotation’s text:
   */
  zathura_annotation_justification_t justification;

  /**
   * A rich text string.
   */
  char* rich_text;

  /**
   * A default style string,
   */
  char* style_string;

  /**
   * Specifying a call-out line attached to the free
   * text annotation.
   */
  zathura_callout_line_t callout_line;

  /**
   * Border of the annotation.
   */
  zathura_annotation_border_t border;

  /**
   * A name describing the intent of the markup annotation. Intents allow
   * viewer applications to distinguish between different uses and behaviors
   * of a single markup annotation type. If this entry is not present or its
   * value is the same as the annotation type, the annotation has no
   * explicit intent and should behave in a generic manner in a viewer
   * application.
   */
  zathura_annotation_markup_intent_t intent;

  /**
   * A set of four numbers describing the numerical differences between two
   * rectangles: the position entry of the annotation and a rectangle
   * contained within that rectangle. The inner rectangle is where the
   * annotation’s text should be displayed. Any border styles and/or border
   * effects specified by the border entry, respectively, are applied to the
   * border of the inner rectangle. The four numbers correspond to the
   * differences in default user space between the left, top, right, and
   * bottom coordinates of the position and those of the inner rectangle,
   * respectively. Each value must be greater than or equal to 0. The sum of
   * the top and bottom differences must be less than the height of
   * position, and the sum of the left and right differences must be less
   * than the width of position.
   */
  struct {
    unsigned int left;
    unsigned int top;
    unsigned int right;
    unsigned int bottom;
  } padding;

  /**
   * An array of two names specifying the line ending styles to be used in
   * drawing the annotation’s border. The first and second elements of the
   * array specify the line ending styles for the endpoints defined,
   * respectively, by the first and second pairs of coordinates, (x1, y1)
   * and (x2, y2), in the L array.
   */
  zathura_annotation_line_ending_t line_endings[2];
};

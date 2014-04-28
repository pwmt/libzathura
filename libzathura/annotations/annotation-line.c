/* See LICENSE file for license and copyright information */

#include <stdbool.h>

#include "../types.h"

#include "color.h"
#include "border.h"
#include "annotation-line.h"
#include "annotation-markup.h"

/**
 * A line annotation displays a single straight line on the page. When
 * opened, it displays a pop-up window containing the text of the associated
 * note.
 */
struct zathura_annotation_line_s {
  /**
   * Specifying the starting and ending coordinates of the line in default
   * user space.
   */
  struct {
    zathura_point_t start; /**< Start point */
    zathura_point_t end; /*<< End point */
  } coordinates;

  /**
   * Border style
   */
  zathura_annotation_border_t border;

  /**
   * An array of two names specifying the line ending styles to be used in
   * drawing the annotation’s border. The first and second elements of the
   * array specify the line ending styles for the endpoints defined,
   * respectively, by the first and second pairs of coordinates, (x1, y1)
   * and (x2, y2), in the L array.
   */
  zathura_annotation_line_ending_t line_endings[2];

  /**
   * The color
   */
  zathura_annotation_color_t color;

  /**
   * The length of leader lines in default user space that extend from each
   * endpoint of the line perpendicular to the line itself. A positive value
   * means that the leader lines appear in the direction that is clockwise
   * when traversing the line from its starting point to its ending point
   * (as specified by @a coordinates); a negative value indicates the
   * opposite direction.
   */
  int leader_lines;

  /**
   * A non-negative number representing the length of leader line extensions
   * that extend from the line proper 180 degrees from the leader lines.
   */
  unsigned int leader_line_extensions_length;

  /**
   * If true, the text specified by the annotations contents or rich content
   * entries should be replicated as a caption in the appearance of the
   * line. The text should be rendered in a manner appropriate to the
   * content, taking into account factors such as writing direction.
   */
  bool caption;

  /**
   * A name describing the intent of the line annotation. Valid values are
   * @a ZATHURA_ANNOTATION_MARKUP_INTENT_LINE_ARROW, which means that the
   * annotation is intended to function as an arrow, and
   * ZATHURA_ANNOTATION_MARKUP_INTENT_LINE_DIMENSION, which means that the
   * annotation is intended to function as a dimension line.
   */
  zathura_annotation_markup_intent_t intent;

  /**
   * A non-negative number representing the length of the leader line
   * offset, which is the amount of empty space between the endpoints of the
   * annotation and the beginning of the leader lines.
   */
  unsigned int leader_line_offset;

  /**
   * A name describing the annotation’s caption positioning. Valid values
   * are @a ZATHURA_ANNOTATION_CAPTION_POSITION_INLINE, meaning the caption
   * will be centered inside the line, and @a
   * ZATHURA_ANNOTATION_CAPTION_POSITION_TOP , meaning the caption will be
   * on top of the line.
   */
  zathura_annotation_line_caption_position_t caption_position;
};

/* See LICENSE file for license and copyright information */

#ifndef ANNOTATION_LINE_H
#define ANNOTATION_LINE_H

/**
 * Line ending styles.
 */
typedef enum zathura_annotation_line_ending_e {
  /**
   * No line ending.
   */
  ZATHURA_ANOOTATION_LINE_ENDING_NONE,

  /**
   * A square filled with the annotation’s interior color, if any.
   */
  ZATHURA_ANOOTATION_LINE_ENDING_SQUARE,

  /**
   * A circle filled with the annotation’s interior color, if any.
   */
  ZATHURA_ANOOTATION_LINE_ENDING_CIRCLE,

  /**
   * A diamond shape filled with the annotation’s interior color, if any.
   */
  ZATHURA_ANOOTATION_LINE_ENDING_DIAMOND,

  /**
   * Two short lines meeting in an acute angle to form an open arrowhead.
   */
  ZATHURA_ANOOTATION_LINE_ENDING_OPEN_ARROW,

  /**
   * Two short lines meeting in an acute angle as in the OpenArrow style (see
   * above) and connected by a third line to form a triangular closed arrowhead
   * filled with the annotation’s interior color, if any.
   */
  ZATHURA_ANOOTATION_LINE_ENDING_CLOSED_ARROW,

  /**
   * A short line at the endpoint perpendicular to the line itself.
   */
  ZATHURA_ANOOTATION_LINE_ENDING_BUTT,

  /**
   * Two short lines in the reverse direction from OpenArrow.
   */
  ZATHURA_ANOOTATION_LINE_ENDING_R_OPEN_ARROW,

  /**
   * A triangular closed arrowhead in the reverse direction from
   * ClosedArrow.
   */
  ZATHURA_ANOOTATION_LINE_ENDING_R_CLOSED_ARROW,

  /**
   * A short line at the endpoint approximately 30 degrees clockwise
   * from perpendicular to the line itself.
   */
  ZATHURA_ANOOTATION_LINE_ENDING_SLASH,
} zathura_annotation_line_ending_t;

typedef enum zathura_annotation_line_caption_position_e {
  ZATHURA_ANNOTATION_CAPTION_POSITION_INLINE,
  ZATHURA_ANNOTATION_CAPTION_POSITION_TOP,
} zathura_annotation_line_caption_position_t;

#endif // ANNOTATION_LINE_H

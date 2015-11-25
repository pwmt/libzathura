/* See LICENSE file for license and copyright information */

#ifndef LIBZATHURA_ANNOTATION_TYPES_H
#define LIBZATHURA_ANNOTATION_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct zathura_annotation_padding_s {
  unsigned int left;
  unsigned int top;
  unsigned int right;
  unsigned int bottom;
} zathura_annotation_padding_t;

/**
 * Describes a callout line.
 */
typedef struct zathura_annotation_callout_line_s {
  zathura_point_t start; /**< Starting point. */
  zathura_point_t knee; /**< Knee point. */
  zathura_point_t end; /**< End point. */
} zathura_annotation_callout_line_t;

/**
 * Specifying the form of justification to be used in displaying the
 * annotations' text.
 */
typedef enum zathura_annotation_justification_e {
  /**
   * Left justified.
   */
  ZATHURA_ANNOTATION_JUSTIFICATION_LEFT_JUSTIFIED = 0,

  /**
   * Centered.
   */
  ZATHURA_ANNOTATION_JUSTIFICATION_CENTERED = 1,

  /**
   * Right justified.
   */
  ZATHURA_ANNOTATION_JUSTIFICATION_RIGHT_JUSTIFIED = 3,
} zathura_annotation_justification_t;

/**
 * Line ending styles.
 */
typedef enum zathura_annotation_line_ending_e {
  /**
   * No line ending.
   */
  ZATHURA_ANNOTATION_LINE_ENDING_NONE,

  /**
   * A square filled with the annotation’s interior color, if any.
   */
  ZATHURA_ANNOTATION_LINE_ENDING_SQUARE,

  /**
   * A circle filled with the annotation’s interior color, if any.
   */
  ZATHURA_ANNOTATION_LINE_ENDING_CIRCLE,

  /**
   * A diamond shape filled with the annotation’s interior color, if any.
   */
  ZATHURA_ANNOTATION_LINE_ENDING_DIAMOND,

  /**
   * Two short lines meeting in an acute angle to form an open arrowhead.
   */
  ZATHURA_ANNOTATION_LINE_ENDING_OPEN_ARROW,

  /**
   * Two short lines meeting in an acute angle as in the OpenArrow style (see
   * above) and connected by a third line to form a triangular closed arrowhead
   * filled with the annotation’s interior color, if any.
   */
  ZATHURA_ANNOTATION_LINE_ENDING_CLOSED_ARROW,

  /**
   * A short line at the endpoint perpendicular to the line itself.
   */
  ZATHURA_ANNOTATION_LINE_ENDING_BUTT,

  /**
   * Two short lines in the reverse direction from OpenArrow.
   */
  ZATHURA_ANNOTATION_LINE_ENDING_R_OPEN_ARROW,

  /**
   * A triangular closed arrowhead in the reverse direction from
   * ClosedArrow.
   */
  ZATHURA_ANNOTATION_LINE_ENDING_R_CLOSED_ARROW,

  /**
   * A short line at the endpoint approximately 30 degrees clockwise
   * from perpendicular to the line itself.
   */
  ZATHURA_ANNOTATION_LINE_ENDING_SLASH,
} zathura_annotation_line_ending_t;

typedef enum zathura_annotation_line_caption_position_e {
  ZATHURA_ANNOTATION_CAPTION_POSITION_INLINE,
  ZATHURA_ANNOTATION_CAPTION_POSITION_TOP,
} zathura_annotation_line_caption_position_t;

/**
 * Describing the intent of the markup annotation. Intents allow viewer
 * applications to distinguish between different uses and behaviors of a single
 * markup annotation type. If this entry is not present or its value is the same
 * as the annotation type, the annotation has no explicit intent and should
 * behave in a generic manner in a viewer application.
 */
typedef enum zathura_annotation_markup_intent_e {
  /**
   * No intent defined.
   */
  ZATHURA_ANNOTATION_MARKUP_INTENT_NONE,

  /**
   * The annotation is intended to function as a callout.
   */
  ZATHURA_ANNOTATION_MARKUP_INTENT_FREE_TEXT_CALL_OUT,

  /**
   * The annotation is intended to function as a click-to-type or typewriter
   * object.
   */
  ZATHURA_ANNOTATION_MARKUP_INTENT_FREE_TEXT_TYPE_WRITER,

  /**
   * The annotation is intended to function as an arrow.
   */
  ZATHURA_ANNOTATION_MARKUP_INTENT_LINE_ARROW,

  /**
   * The annotation is intended to function as a dimension line.
   */
  ZATHURA_ANNOTATION_MARKUP_INTENT_LINE_DIMENSION,

  /**
   * The annotation is intended to function as a cloud object.
   */
  ZATHURA_ANNOTATION_MARKUP_INTENT_POLYGON_CLOUD,

  /**
   * The polygon annotation is intended to function as a dimension.
   */
  ZATHURA_ANNOTATION_MARKUP_INTENT_POLYGON_DIMENSION,

  /**
   * The polyline annotation is intended to function as a dimension
   */
  ZATHURA_ANNOTATION_MARKUP_INTENT_POLY_LINE_DIMENSION,
} zathura_annotation_markup_intent_t;

/**
 * A type specifying the relationship (the “reply type”) between this annotation
 * and one specified by @a ::zathura_annotation_markup_reply_type_t.
 */
typedef enum zathura_annotation_markup_reply_type_e {
  /**
   * The annotation is considered a reply to the annotation specified by
   * @a ::zathura_annotation_markup_reply_type_t.
   */
  ZATHURA_ANNOTATION_MARKUP_REPLY_TYPE_REPLY,

  /**
   * The annotation is grouped with the annotation specified by
   * @a ::zathura_annotation_markup_reply_type_t.
   */
  ZATHURA_ANNOTATION_MARKUP_REPLY_TYPE_GROUP
} zathura_annotation_markup_reply_type_t;

/**
 * The annotation’s highlighting mode, the visual effect to be used when the
 * mouse button is pressed or held down inside its active area.
 */
typedef enum zathura_annotation_highlighting_mode_e {
  /**
   * No highlighting.
   */
  ZATHURA_ANNOTATION_HIGHLIGHTING_NONE = 'N',

  /**
   * Invert the contents of the annotation rectangle.
   */
  ZATHURA_ANNOTATION_HIGHLIGHTING_INVERT = 'I',

  /**
   * Invert the annotation’s border.
   */
  ZATHURA_ANNOTATION_HIGHLIGHTING_OUTLINE = 'O',

  /**
   * Display the annotation as if it were being pushed below the surface of the
   * page.
   */
  ZATHURA_ANNOTATION_HIGHLIGHTING_PUSH = 'P'
} zathura_annotation_highlighting_mode_t;

/**
 * A measure dictionary specifies an alternate coordinate system for a region of
 * a page. Along with the viewport dictionary, it provides the information
 * needed to convert coordinates in the page’s coordinate system to coordinates
 * in the measuring coordinate system. The measure dictionary provides
 * information for formatting the resulting values into textual form for
 * presentation in a graphical user interface.
 *
 * TODO: Implement the measure dictionary.
 */
typedef struct zathura_annotation_measure_s {
  char* scale_ratio;
} zathura_annotation_measure_t;

#ifdef __cplusplus
}
#endif

#endif // ANNOTATION_TYPES_H

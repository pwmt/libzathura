/* See LICENSE file for license and copyright information */

#ifndef ANNOTATION_H
#define ANNOTATION_H

#include <time.h>
#include <stdbool.h>

#include "page.h"
#include "types.h"

// TODO: Should we map this to the name field of a text annotation?
typedef enum zathura_annotation_text_icon_s {
  ZATHURA_ANNOTATION_TEXT_ICON_UNKNOWN,
  ZATHURA_ANNOTATION_TEXT_ICON_NOTE,
  ZATHURA_ANNOTATION_TEXT_ICON_COMMENT,
  ZATHURA_ANNOTATION_TEXT_ICON_KEY,
  ZATHURA_ANNOTATION_TEXT_ICON_HELP,
  ZATHURA_ANNOTATION_TEXT_ICON_NEW_PARAGRAPH,
  ZATHURA_ANNOTATION_TEXT_ICON_PARAGRAPH,
  ZATHURA_ANNOTATION_TEXT_ICON_INSERT,
  ZATHURA_ANNOTATION_TEXT_ICON_CROSS,
  ZATHURA_ANNOTATION_TEXT_ICON_CIRCLE
} zathura_annotation_text_icon_t;

/**
 * An annotation associates an object such as a note, sound, or movie with a
 * location on a page of a document, or provides a way to interact with the user
 * by means of the mouse and keyboard.
 *
 * Many of the standard annotation types may be displayed in either the open or
 * the closed state. When closed, they appear on the page in some distinctive
 * form, such as an icon, a box, or a rubber stamp, depending on the specific
 * annotation type. When the user activates the annotation by clicking it, it
 * exhibits its associated object, such as by opening a pop-up window displaying
 * a text note or by playing a sound or a movie.
 */
typedef struct zathura_annotation_s zathura_annotation_t;

/**
 * Standard annotation types
 */
typedef enum zathura_annotation_type_s {
  ZATHURA_ANNOTATION_UNKNOWN,
  ZATHURA_ANNOTATION_TEXT,
  ZATHURA_ANNOTATION_LINK,
  ZATHURA_ANNOTATION_FREE_TEXT,
  ZATHURA_ANNOTATION_LINE,
  ZATHURA_ANNOTATION_SQUARE,
  ZATHURA_ANNOTATION_CIRCLE,
  ZATHURA_ANNOTATION_POLYGON,
  ZATHURA_ANNOTATION_POLY_LINE,
  ZATHURA_ANNOTATION_HIGHLIGHT,
  ZATHURA_ANNOTATION_UNDERLINE,
  ZATHURA_ANNOTATION_SQUIGGLY,
  ZATHURA_ANNOTATION_STRIKE_OUT,
  ZATHURA_ANNOTATION_STAMP,
  ZATHURA_ANNOTATION_CARET,
  ZATHURA_ANNOTATION_INK,
  ZATHURA_ANNOTATION_POPUP,
  ZATHURA_ANNOTATION_FILE_ATTACHMENT,
  ZATHURA_ANNOTATION_SOUND,
  ZATHURA_ANNOTATION_MOVIE,
  ZATHURA_ANNOTATION_WIDGET,
  ZATHURA_ANNOTATION_SCREEN,
  ZATHURA_ANNOTATION_PRINTER_MARK,
  ZATHURA_ANNOTATION_TRAP_NET,
  ZATHURA_ANNOTATION_WATERMARK,
  ZATHURA_ANNOTATION_3D,
} zathura_annotation_type_t;

/**
 * The value of the annotation flags entry is an unsigned 32-bit integer
 * containing flags specifying various characteristics of the annotation. Bit
 * positions within the flag word are numbered from 1 (low-order) to 32
 * (high-order). All undefined flag bits are reserved and must be set to 0.
 */
typedef enum zathura_annotation_flag_s {
  /**
   * Undefined flags
   */
  ZATHURA_ANNOTATION_FLAG_UNDEFINED = 0,

  /**
   * f set, do not display the annotation if it does not belong to one of the
   * standard annotation types and no annotation handler is available. If clear,
   * display such an unknown annotation using an appearance stream specified by
   * its appearance dictionary, if any.
   */
  ZATHURA_ANNOTATION_FLAG_INVISIBLE = 1 << 0,

  /**
   * If set, do not display or print the annotation or allow it to interact with
   * the user, regardless of its annotation type or whether an annotation
   * handler is available. In cases where screen space is limited, the ability
   * to hide and show annotations selectively can be used in combination with
   * appearance streams to display auxiliary pop-up information similar in
   * function to online help systems.
   */
  ZATHURA_ANNOTATION_FLAG_HIDDEN = 1 << 1,

  /**
   * If set, print the annotation when the page is printed. If clear, never
   * print the annotation, regardless of whether it is displayed on the screen.
   * This can be useful, for example, for annotations representing interactive
   * pushbuttons, which would serve no meaningful purpose on the printed page.
   */
  ZATHURA_ANNOTATION_FLAG_PRINT = 1 << 2,

  /**
   * If set, do not scale the annotation’s appearance to match the magnification
   * of the page. The location of the annotation on the page (defined by the
   * upper-left corner of its annotation rectangle) remains fixed, regardless of
   * the page magnification.
   */
  ZATHURA_ANNOTATION_FLAG_NO_ZOOM = 1 << 3,

  /**
   * If set, do not rotate the annotation’s appearance to match the rotation of
   * the page. The upper-left corner of the annotation rectangle remains in a
   * fixed location on the page, regardless of the page rotation.
   */
  ZATHURA_ANNOTATION_FLAG_NO_ROTATE = 1 << 4,

  /**
   * If set, do not display the annotation on the screen or allow it to interact
   * with the user. The annotation may be printed (depending on the setting of
   * the Print flag) but should be considered hidden for purposes of on-screen
   * display and user interaction.
   */
  ZATHURA_ANNOTATION_FLAG_NO_VIEW = 1 << 5,

  /**
   * If set, do not allow the annotation to interact with the user. The
   * annotation may be displayed or printed (depending on the settings of the
   * NoView and Print flags) but should not respond to mouse clicks or change
   * its appearance in response to mouse motions.
   */
  ZATHURA_ANNOTATION_FLAG_READ_ONLY = 1 << 6,

  /**
   * If set, do not allow the annotation to be deleted or its properties
   * (including position and size) to be modified by the user. However, this
   * flag does not restrict changes to the annotation’s contents, such as the
   * value of a form field.
   */
  ZATHURA_ANNOTATION_FLAG_LOCKED = 1 << 7,

  /**
   * If set, invert the interpretation of the NoView flag for certain events. A
   * typical use is to have an annotation that appears only when a mouse cursor
   * is held over it.
   */
  ZATHURA_ANNOTATION_FLAG_TOGGLE_NO_VIEW = 1 << 8,

  /**
   * If set, do not allow the contents of the annotation to be modified by the
   * user. This flag does not restrict deletion of the annotation or changes to
   * other annotation properties, such as position and size.
   */
  ZATHURA_ANNOTATION_FLAG_LOCKED_CONTENTS = 1 << 9,
} zathura_annotation_flag_t;

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
  ZATHURA_ANNOTATION_MARKUP_INTENT_LINE_POLYGON_CLOUD,

  /**
   * The polygon annotation is intended to function as a dimension.
   */
  ZATHURA_ANNOTATION_MARKUP_INTENT_LINE_POLYGON_DIMENSION,

  /**.
   * The polyline annotation is intended to function as a dimension
   */
  ZATHURA_ANNOTATION_MARKUP_INTENT_LINE_POLYLINE_DIMENSION,
} zathura_annotation_markup_intent_t;

/**
 * Defines the different supported color spaces.
 */
typedef enum zathura_annotation_color_space_e {
  /**
   * No color, transparent.
   */
  ZATHURA_ANNOTATION_COLOR_SPACE_NONE = 0,

  /**
   * Grayscale
   */
  ZATHURA_ANNOTATION_COLOR_SPACE_GRAY = 1,

  /**
   * RGB
   */
  ZATHURA_ANNOTATION_COLOR_SPACE_RGB = 2,

  /**
   * CMYK
   */
  ZATHURA_ANNOTATION_COLOR_SPACE_CMYK = 3
} zathura_annotation_color_space_t;

/**
 * Defines a color object
 */
typedef struct zathura_annotation_color_s {
  /**
   * The used color space
   */
  zathura_annotation_color_space_t color_space;

  /**
   * Values that depend on the used colorspace
   */
  double values[4];
} zathura_annotation_color_t;

/**
 * The border style.
 */
typedef enum zathura_annotation_border_style_e {
  /**
   * A solid rectangle surrounding the annotation.
   */
  ZATHURA_ANNOTATION_BORDER_STYLE_SOLID,

  /**
   * A dashed rectangle surrounding the annotation. The dash pattern is
   * specified by the D entry (see below).
   */
  ZATHURA_ANNOTATION_BORDER_STYLE_DASHED,

  /**
   * A simulated embossed rectangle that appears to be raised above the surface
   * of the page.
   */
  ZATHURA_ANNOTATION_BORDER_STYLE_BEVELED,

  /**
   * A simulated engraved rectangle that appears to be recessed below the
   * surface of the page.
   */
  ZATHURA_ANNOTATION_BORDER_STYLE_INSET,

  /**
   * A single line along the bottom of the annotation rectangle.
   */
  ZATHURA_ANNOTATION_BORDER_STYLE_UNDERLINE
} zathura_annotation_border_style_t;

typedef enum zathura_annotation_border_effect_e {
  /**
   * No effect.
   * */
  ZATHURA_ANNOTATION_BORDER_EFFECT_NONE,

  /**
   * The border should appear “cloudy”. The width and dash array specified by
   * border style are honored.
   */
  ZATHURA_ANNOTATION_BORDER_EFFECT_CLOUDY
} zathura_annotation_border_effect_t;

/**
 * An annotation may optionally be surrounded by a border when displayed or
 * printed. If present, the border is drawn completely inside the annotation
 * rectangle.
 */
typedef struct zathura_annotation_border_s {
  unsigned int width;
  zathura_annotation_border_style_t style;
  zathura_annotation_border_effect_t effect;
  float intensity;
} zathura_annotation_border_t;

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

/**
 * Describes a callout line.
 */
typedef struct zathura_callout_line_s {
  zathura_point_t start; /**< Starting point. */
  zathura_point_t knee; /**< Knee point. */
  zathura_point_t end; /**< End point. */
} zathura_callout_line_t;

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
 * A type specifying the relationship (the “reply type”) between this annotation
 * and one specified by @a ::reply_type.
 */
typedef enum zathura_annotation_reply_type_e {
  /**
   * The annotation is considered a reply to the annotation specified by
   * @a ::reply_type.
   */
  ZATHURA_ANNOTATION_REPLY_TYPE_REPLY,

  /**
   * The annotation is grouped with the annotation specified by
   * @a ::reply_type.
   */
  ZATHURA_ANNOTATION_REPLY_TYPE_GROUP
} zathura_annotation_reply_type_t;

/**
 * Annotations may have an author-specific state associated with them. The state
 * is not specified in the annotation itself but in a separate text annotation
 * that refers to the original annotation by means of its reply_to (“in reply to”)
 * entry.
 */
typedef enum zathura_annotation_text_state_s {
  /**
   * Unknown state
   */
  ZATHURA_ANNOTATION_TEXT_STATE_UNKNOWN,

  /**
   * The user has indicated nothing about the change (the default).
   */
  ZATHURA_ANNOTATION_TEXT_STATE_NONE,

  /**
   * The annotation has been marked by the user.
   */
  ZATHURA_ANNOTATION_TEXT_STATE_MARKED,

  /**
   * The annotation has not been marked by the user (the default).
   */
  ZATHURA_ANNOTATION_TEXT_STATE_UNMARKED,

  /**
   * The user agrees with the change.
   */
  ZATHURA_ANNOTATION_TEXT_STATE_ACCEPTED,

  /**
   * The user disagrees with the change.
   */
  ZATHURA_ANNOTATION_TEXT_STATE_REJECTED,

  /**
   * The change has been cancelled.
   */
  ZATHURA_ANNOTATION_TEXT_STATE_CANCELLED,

  /**
   * The change has been completed.
   */
  ZATHURA_ANNOTATION_TEXT_STATE_COMPLETED
} zathura_annotation_text_state_t;

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

zathura_error_t zathura_annotation_new(zathura_annotation_t** annotation, zathura_annotation_type_t type);
zathura_error_t zathura_annotation_free(zathura_annotation_t* annotation);
zathura_error_t zathura_annotation_is_markup_annotation(zathura_annotation_t* annotation, bool* is_markup_annotation);

#endif /* ANNOTATION_H */

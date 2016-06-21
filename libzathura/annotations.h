/* See LICENSE file for license and copyright information */

#ifndef LIBZATHURA_ANNOTATIONS_H
#define LIBZATHURA_ANNOTATIONS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <time.h>
#include <stdbool.h>

#include "action.h"
#include "attachment.h"
#include "movie.h"
#include "page.h"
#include "sound.h"
#include "types.h"

#include "annotations/border.h"
#include "annotations/color.h"
#include "annotations/flags.h"

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
 * Annotation mapping
 */
typedef struct zathura_annotation_mapping_s {
  zathura_rectangle_t position;
  zathura_annotation_t* annotation;
} zathura_annotation_mapping_t;

/**
 * Standard annotation types
 */
typedef enum zathura_annotation_type_s {
  /**
   * Unknown annotation type.
   */
  ZATHURA_ANNOTATION_UNKNOWN,

  /**
   * A text annotation.
   */
  ZATHURA_ANNOTATION_TEXT,

  /**
   * A link annotation.
   */
  ZATHURA_ANNOTATION_LINK,

  /**
   * A free-text annotation.
   */
  ZATHURA_ANNOTATION_FREE_TEXT,

  /**
   * A line annotation.
   */
  ZATHURA_ANNOTATION_LINE,

  /**
   * A square annotation.
   */
  ZATHURA_ANNOTATION_SQUARE,

  /**
   * A circle annotation.
   */
  ZATHURA_ANNOTATION_CIRCLE,

  /**
   * A polygon annotation.
   */
  ZATHURA_ANNOTATION_POLYGON,

  /**
   * A polyline annotation.
   */
  ZATHURA_ANNOTATION_POLY_LINE,

  /**
   * A highlight annotation.
   */
  ZATHURA_ANNOTATION_HIGHLIGHT,

  /**
   * A underline annotation.
   */
  ZATHURA_ANNOTATION_UNDERLINE,

  /**
   * A squiggly annotation.
   */
  ZATHURA_ANNOTATION_SQUIGGLY,

  /**
   * A strike-out annotation.
   */
  ZATHURA_ANNOTATION_STRIKE_OUT,

  /**
   * A stamp annotation.
   */
  ZATHURA_ANNOTATION_STAMP,

  /**
   * A caret annotation.
   */
  ZATHURA_ANNOTATION_CARET,

  /**
   * An ink annotation.
   */
  ZATHURA_ANNOTATION_INK,

  /**
   * A pop-up annotation.
   */
  ZATHURA_ANNOTATION_POPUP,

  /**
   * A file-attachment annotation.
   */
  ZATHURA_ANNOTATION_FILE_ATTACHMENT,

  /**
   * A sound annotation.
   */
  ZATHURA_ANNOTATION_SOUND,

  /**
   * A movie annotation.
   */
  ZATHURA_ANNOTATION_MOVIE,

  /**
   * A widget annotation.
   */
  ZATHURA_ANNOTATION_WIDGET,

  /**
   * A screen annotation.
   */
  ZATHURA_ANNOTATION_SCREEN,

  /**
   * A printer's mark annotation..
   */
  ZATHURA_ANNOTATION_PRINTER_MARK,

  /**
   * A trap-net annotation.
   */
  ZATHURA_ANNOTATION_TRAP_NET,

  /**
   * A watermark annotation.
   */
  ZATHURA_ANNOTATION_WATERMARK,

  /**
   * A 3D annotation.
   */
  ZATHURA_ANNOTATION_3D,
} zathura_annotation_type_t;

/**
 * Creates a new annotation of the specified type
 *
 * @param[in] page The page that is associated with this annotation
 * @param[out] annotation The annotation
 * @param[in] type The type of the annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_new(zathura_page_t* page, zathura_annotation_t** annotation,
    zathura_annotation_type_t type);

/**
 * Frees the passed annotation
 *
 * @param[in] annotation The annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_free(zathura_annotation_t* annotation);

/**
 * Returns the type of the passed annotation
 *
 * @param[in] annotation The annotation
 * @param[out] type The type of the annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_get_type(zathura_annotation_t* annotation,
    zathura_annotation_type_t* type);

/**
 * Sets the position of the annotation defining the location of the annotation
 * on the page in default user space units.
 *
 * @param[in] annotation The annotation
 * @param[in] position The position defining the location of the annotation on
 *  the page in default user space units
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_set_position(zathura_annotation_t* annotation,
    zathura_rectangle_t position);

/**
 * Returns the position of the annotation defining the location of the annotation
 * on the page in default user space units.
 *
 * @param[in] annotation The annotation
 * @param[out] position The position defining the location of the annotation on
 *  the page in default user space units
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_get_position(zathura_annotation_t* annotation,
    zathura_rectangle_t* position);

/**
 * Sets the text to be displayed for the annotation or, if this type of
 * annotation does not display text, an alternate description of the
 * annotation’s contents in human-readable form. In either case, this text is
 * useful when extracting the document’s contents in support of accessibility to
 * users with disabilities or for other purposes.
 *
 * @param[in] annotation The annotation
 * @param[in] content The content of the annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_set_content(zathura_annotation_t* annotation,
    const char* content);

/**
 * Sets the text to be displayed for the annotation or, if this type of
 * annotation does not display text, an alternate description of the
 * annotation’s contents in human-readable form. In either case, this text is
 * useful when extracting the document’s contents in support of accessibility to
 * users with disabilities or for other purposes.
 *
 * @param[in] annotation The annotation
 * @param[out] content The content of the annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_get_content(zathura_annotation_t* annotation,
    char** content);

/**
 * Sets the annotation name, a text string uniquely identifying it among all the
 * annotations on its page.
 *
 * @param[in] annotation The annotation
 * @param[in] name The name of the annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_set_name(zathura_annotation_t* annotation,
    const char* name);

/**
 * Returns the annotation name, a text string uniquely identifying it among all the
 * annotations on its page.
 *
 * @param[in] annotation The annotation
 * @param[out] name The name of the annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_get_name(zathura_annotation_t* annotation,
    char** name);

/**
 * Sets the date and time when the annotation was most recently modified.
 *
 * @param[in] annotation The annotation
 * @param[in] modification_date The date of the annotation modification
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_set_modification_date(zathura_annotation_t*
    annotation, time_t modification_date);

/**
 * Returns the date and time when the annotation was most recently modified.
 *
 * @param[in] annotation The annotation
 * @param[in] modification_date The date of the annotation modification
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_get_modification_date(zathura_annotation_t*
    annotation, time_t* modification_date);

/**
 * Sets a set of flags specifying various characteristics of the annotation.
 *
 * @param[in] annotation The annotation
 * @param[in] flags The flags of the annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_set_flags(zathura_annotation_t* annotation,
    zathura_annotation_flag_t flags);

/**
 * Returns a set of flags specifying various characteristics of the annotation.
 *
 * @param[in] annotation The annotation
 * @param[out] flags The flags of the annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_get_flags(zathura_annotation_t* annotation,
    zathura_annotation_flag_t* flags);

/**
 * Sets a color used for the following purpose:
 *
 *  - The background of the annotation’s icon when closed
 *  - The title bar of the annotation’s pop-up window
 *  - The border of a link annotation
 *
 * @param[in] annotation The annotation
 * @param[in] color The color
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_set_color(zathura_annotation_t* annotation,
    zathura_annotation_color_t color);

/**
 * Returns the color used for the following purpose:
 *
 *  - The background of the annotation’s icon when closed
 *  - The title bar of the annotation’s pop-up window
 *  - The border of a link annotation
 *
 * @param[in] annotation The annotation
 * @param[out] color The color
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_get_color(zathura_annotation_t* annotation,
    zathura_annotation_color_t* color);

/**
 * Sets the blend mode of the annotation
 *
 * @param[in] annotation The annotation
 * @param[in] blend_mode The blend mode
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_set_blend_mode(zathura_annotation_t* annotation,
    zathura_blend_mode_t blend_mode);

/**
 * Returns the blend mode of the annotation
 *
 * @param[in] annotation The annotation
 * @param[out] blend_mode The blend mode
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_get_blend_mode(zathura_annotation_t* annotation,
    zathura_blend_mode_t* blend_mode);

/**
 * Sets the opacity of the annotation
 *
 * @param[in] annotation The annotation
 * @param[in] opacity The opacity
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_set_opacity(zathura_annotation_t* annotation,
    float opacity);

/**
 * Returns the opacity of the annotation
 *
 * @param[in] annotation The annotation
 * @param[out] opacity The opacity
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_get_opacity(zathura_annotation_t* annotation,
    float* opacity);

/**
 * Returns the page associated with this annotation
 *
 * @param[in] annotation The annotation
 * @param[out] page The associated page
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_get_page(zathura_annotation_t* annotation,
    zathura_page_t** page);

/**
 * Checks if the annotation has an appearance stream
 *
 * @param[in] annotation The used annotation object
 * @param[out] has_appearance_stream If the object has an appearance stream
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_has_appearance_stream(zathura_annotation_t* annotation,
    bool* has_appearance_stream);

/**
 * Renders the annotation to a @a ::zathura_image_buffer_t image buffer
 *
 * @param[in] annotation The used annotation object
 * @param[out] buffer The image buffer
 * @param[in] scale Scale level
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_render(zathura_annotation_t* annotation,
    zathura_image_buffer_t** buffer, double scale);

#ifdef HAVE_CAIRO
/**
 * Renders the annotation to a cairo object
 *
 * @param[in] annotation The used annotation object
 * @param[out] cairo The cairo object
 * @param[in] scale Scale level
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_render_cairo(zathura_annotation_t* annotation, cairo_t* cairo,
    double scale);
#endif

#include "annotations/annotation-3d.h"
#include "annotations/annotation-caret.h"
#include "annotations/annotation-circle.h"
#include "annotations/annotation-file-attachment.h"
#include "annotations/annotation-free-text.h"
#include "annotations/annotation-highlight.h"
#include "annotations/annotation-ink.h"
#include "annotations/annotation-line.h"
#include "annotations/annotation-link.h"
#include "annotations/annotation-markup.h"
#include "annotations/annotation-movie.h"
#include "annotations/annotation-polyline.h"
#include "annotations/annotation-polygon.h"
#include "annotations/annotation-popup.h"
#include "annotations/annotation-printer-mark.h"
#include "annotations/annotation-screen.h"
#include "annotations/annotation-sound.h"
#include "annotations/annotation-square.h"
#include "annotations/annotation-squiggly.h"
#include "annotations/annotation-stamp.h"
#include "annotations/annotation-strike-out.h"
#include "annotations/annotation-text.h"
#include "annotations/annotation-trap-net.h"
#include "annotations/annotation-underline.h"
#include "annotations/annotation-watermark.h"

#ifdef __cplusplus
}
#endif

#endif /* ANNOTATIONS_H */

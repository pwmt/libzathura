/* See LICENSE file for license and copyright information */

#ifndef ANNOTATIONS_H
#define ANNOTATIONS_H

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
 * Creates a new annotation of the specified type
 *
 * @param[out] annotation The annotation
 * @param[in] type The type of the annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_new(zathura_annotation_t** annotation,
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
 * @param[in] date The date of the annotation
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
 * @param[in] date The date of the annotation
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
 * @param[in] color The color
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_get_color(zathura_annotation_t* annotation,
    zathura_annotation_color_t* color);

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
#include "annotations/annotation-poly-line.h"
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

#endif /* ANNOTATIONS_H */

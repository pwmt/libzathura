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

zathura_error_t zathura_annotation_new(zathura_annotation_t** annotation, zathura_annotation_type_t type);
zathura_error_t zathura_annotation_free(zathura_annotation_t* annotation);
zathura_error_t zathura_annotation_get_type(zathura_annotation_t* annotation, zathura_annotation_type_t* type);

#include "annotations/border.h"
#include "annotations/color.h"
#include "annotations/flags.h"

#include "annotations/annotation-caret.h"
#include "annotations/annotation-circle.h"
#include "annotations/annotation-file.h"
#include "annotations/annotation-free-text.h"
#include "annotations/annotation-ink.h"
#include "annotations/annotation-line.h"
#include "annotations/annotation-link.h"
#include "annotations/annotation-markup.h"
#include "annotations/annotation-movie.h"
#include "annotations/annotation-popup.h"
#include "annotations/annotation-screen.h"
#include "annotations/annotation-sound.h"
#include "annotations/annotation-square.h"
#include "annotations/annotation-stamp.h"
#include "annotations/annotation-text.h"
#include "annotations/annotation-text-markup.h"

#endif /* ANNOTATIONS_H */

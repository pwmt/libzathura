/* See LICENSE file for license and copyright information */

#ifndef ZATHURA_ANNOTATION_INTERNAL_H
#define ZATHURA_ANNOTATION_INTERNAL_H

#include <time.h>

#include "../annotations.h"

struct zathura_annotation_s {
  /**
   * The type of annotation that this dictionary describes
   */
  zathura_annotation_type_t type;

  /**
   * The annotation rectangle, defining the location of the annotation on
   * the page in default user space units.
   */
  zathura_rectangle_t position;

  /**
   * Text to be displayed for the annotation or, if this type of annotation does
   * not display text, an alternate description of the annotation’s contents in
   * human-readable form. In either case, this text is useful when extracting
   * the document’s contents in support of accessibility to users with
   * disabilities or for other purposes.
   */
  char* content;

  /**
   * The annotation name, a text string uniquely identifying it
   * among all the annotations on its page.
   */
  char* name;

  /**
   * The date and time when the annotation was most recently
   * modified.
   */
  time_t modification_date; /**< Modification date */

  /**
   * Set of flags specifying various characteristics of the annotation.
   */
  zathura_annotation_flag_t flags; /**< Flags of the annotation */

  /**
   * An color object representing a color used for the following purposes:
   *
   * * The background of the annotation’s icon when closed
   * * The title bar of the annotation’s pop-up window
   * * The border of a link annotation
   */
   zathura_annotation_color_t color;

  /**
   * Describes if the annotation is a markup annotation
   */
  bool is_markup;

  union {
    /**
     * A markup annotation
     */
    struct zathura_annotation_markup_s* markup;

    /**
     * A text annotation
     */
    struct zathura_annotation_text_s* text;

    /**
     * A link annotation
     */
    struct zathura_annotation_link_s* link;

    /**
     * A free text annotation
     */
    struct zathura_annotation_free_text_s* free_text;

    /**
     * A line annotation
     */
    struct zathura_annotation_line_s* line;

    /**
     * A square or circle annotation
     */
    struct zathura_annotation_square_and_circle_s* square_and_circle;

    /**
     * A text markup annotations
     */
    struct zathura_annotation_text_markup_s* text_markup;

    /**
     * A caret annotation
     */
    struct zathura_annotation_caret_s* caret;

    /**
     * A rubber stamp
     */
    struct zathura_annotation_stamp_s* stamp;

    /**
     * An ink annotation
     */
    struct zathura_annotation_ink_s* ink;

    /**
     * A pop-up annotation
     */
    struct zathura_annotation_popup_s* popup;

    /**
     * A file attachment annotation
     */
    struct zathura_annotation_file_s* file;

    /**
     * A sound annotation
     */
    struct zathura_annotation_sound_s* sound;

    /**
     * A movie annotation
     */
    struct zathura_annotation_movie_s* movie;

    /**
     * A screen annotation
     */
    struct zathura_annotation_screen_s* screen;
  } data;
};

#include "internal/annotation-caret.h"
#include "internal/annotation-file.h"
#include "internal/annotation-free-text.h"
#include "internal/annotation-ink.h"
#include "internal/annotation-line.h"
#include "internal/annotation-link.h"
#include "internal/annotation-movie.h"
#include "internal/annotation-popup.h"
#include "internal/annotation-screen.h"
#include "internal/annotation-sound.h"
#include "internal/annotation-stamp.h"
#include "internal/annotation-square-and-circle.h"
#include "internal/annotation-text.h"
#include "internal/annotation-text-markup.h"

#endif // ZATHURA_ANNOTATION_INTERNAL_H

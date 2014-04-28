/* See LICENSE file for license and copyright information */

#include <stdlib.h>
#include <string.h>

#include "annotations.h"

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

zathura_error_t
zathura_annotation_new(zathura_annotation_t** annotation, zathura_annotation_type_t type)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  switch (type) {
      case ZATHURA_ANNOTATION_UNKNOWN:
      case ZATHURA_ANNOTATION_TEXT:
      case ZATHURA_ANNOTATION_LINK:
      case ZATHURA_ANNOTATION_FREE_TEXT:
      case ZATHURA_ANNOTATION_TEXT_MARKUP:
      case ZATHURA_ANNOTATION_LINE:
      case ZATHURA_ANNOTATION_SQUARE:
      case ZATHURA_ANNOTATION_CIRCLE:
      case ZATHURA_ANNOTATION_POLYGON:
      case ZATHURA_ANNOTATION_POLY_LINE:
      case ZATHURA_ANNOTATION_HIGHLIGHT:
      case ZATHURA_ANNOTATION_UNDERLINE:
      case ZATHURA_ANNOTATION_SQUIGGLY:
      case ZATHURA_ANNOTATION_STRIKE_OUT:
      case ZATHURA_ANNOTATION_STAMP:
      case ZATHURA_ANNOTATION_CARET:
      case ZATHURA_ANNOTATION_INK:
      case ZATHURA_ANNOTATION_POPUP:
      case ZATHURA_ANNOTATION_FILE_ATTACHMENT:
      case ZATHURA_ANNOTATION_SOUND:
      case ZATHURA_ANNOTATION_MOVIE:
      case ZATHURA_ANNOTATION_WIDGET:
      case ZATHURA_ANNOTATION_SCREEN:
      case ZATHURA_ANNOTATION_PRINTER_MARK:
      case ZATHURA_ANNOTATION_TRAP_NET:
      case ZATHURA_ANNOTATION_WATERMARK:
      case ZATHURA_ANNOTATION_3D:
      break;
    default:
      return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *annotation = calloc(1, sizeof(zathura_annotation_t));
  if (*annotation == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  (*annotation)->type = type;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_free(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  free(annotation);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_get_type(zathura_annotation_t* annotation, zathura_annotation_type_t* type)
{
  if (annotation == NULL || type == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *type = annotation->type;

  return ZATHURA_ERROR_OK;
}

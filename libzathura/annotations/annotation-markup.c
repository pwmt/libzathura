/* See LICENSE file for license and copyright information */

#include "../annotations.h"
#include "internal.h"

/**
 * Many annotation types are defined as markup annotations because they are
 * used primarily to mark up PDF documents. These annotations have text that
 * appears as part of the annotation and may be displayed in other ways by a
 * viewer application, such as in a Comments pane.
 */
struct zathura_annotation_markup_s {
  /**
   * The text label to be displayed in the title bar of the annotation’s
   * pop-up window when open and active. By convention, this entry
   * identifies the user who added the annotation.
   */
  char* label;

  /**
   * An indirect reference to a pop-up annotation for entering or editing
   * the text associated with this annotation.
   */
  zathura_annotation_t* popup_annotation;

  /**
   * A rich text string to be displayed in the pop-up window when the
   * annotation is opened.
   */
  char* text;

  /**
   * The date and time when the annotation was created.
   */
  time_t creation_date;

  /**
   * A reference to the annotation that this annotation is “in reply to”.
   * Both annotations must be on the same page of the document. The
   * relationship between the two annotations is specified by the RT entry.
   */
  zathura_annotation_t* reply_to_annotation;

  /**
   * A type specifying the relationship (the “reply type”) between this
   * annotation and one specified by @a ::reply_type.
   */
  zathura_annotation_markup_reply_type_t reply_type;
};

zathura_error_t
zathura_annotation_is_markup_annotation(zathura_annotation_t* annotation, bool*
    is_markup_annotation)
{
  if (annotation == NULL || is_markup_annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }
  
  switch (annotation->type) {
    case ZATHURA_ANNOTATION_UNKNOWN:
    case ZATHURA_ANNOTATION_LINK:
    case ZATHURA_ANNOTATION_POPUP:
    case ZATHURA_ANNOTATION_MOVIE:
    case ZATHURA_ANNOTATION_WIDGET:
    case ZATHURA_ANNOTATION_SCREEN:
    case ZATHURA_ANNOTATION_PRINTER_MARK:
    case ZATHURA_ANNOTATION_TRAP_NET:
    case ZATHURA_ANNOTATION_WATERMARK:
    case ZATHURA_ANNOTATION_3D:
      *is_markup_annotation = false;
      break;
    case ZATHURA_ANNOTATION_TEXT:
    case ZATHURA_ANNOTATION_FREE_TEXT:
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
    case ZATHURA_ANNOTATION_FILE_ATTACHMENT:
    case ZATHURA_ANNOTATION_SOUND:
      *is_markup_annotation = true;
      break;
    default:
      return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  return ZATHURA_ERROR_OK;
}

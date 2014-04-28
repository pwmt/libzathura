/* See LICENSE file for license and copyright information */

#include "../annotations.h"

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

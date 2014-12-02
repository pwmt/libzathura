/* See LICENSE file for license and copyright information */

#ifndef INTERNAL_ANNOTATION_MARKUP_H
#define INTERNAL_ANNOTATION_MARKUP_H

/**
 * Many annotation types are defined as markup annotations because they are
 * used primarily to mark up PDF documents. These annotations have text that
 * appears as part of the annotation and may be displayed in other ways by a
 * viewer application, such as in a Comments pane.
 */
typedef struct zathura_annotation_markup_s {
  /**
   * The text label to be displayed in the title bar of the annotation’s
   * pop-up window when open and active. By convention, this entry
   * identifies the user who added the annotation.
   */
  char* label;

  /** The constant opacity value to be used in painting the annotation. This
   * value applies to all visible elements of the annotation in its closed state
   * (including its background and border) but not to the popup window that
   * appears when the annotation is opened. The specified value is not used if
   * the annotation has a double opacity;
   *
   * Default: 1.0
   */
  double opacity;

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
   * annotation and one specified by @a
   * ::zathura_annotation_markup_reply_type_t.
   */
  zathura_annotation_markup_reply_type_t reply_type;
} zathura_annotation_markup_t;

/**
 * Initializes the annotation as a markup annotation
 *
 * @param annotation The annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_markup_init(zathura_annotation_t* annotation);

/**
 * Clear the annotation as a markup annotation
 *
 * @param annotation The annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_markup_clear(zathura_annotation_t* annotation);

#endif // INTERNAL_ANNOTATION_MARKUP_H

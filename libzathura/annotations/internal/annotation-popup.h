/* See LICENSE file for license and copyright information */

#ifndef INTERNAL_ANNOTATION_POPUP_H
#define INTERNAL_ANNOTATION_POPUP_H

typedef struct zathura_annotation_popup_s {
  /**
   * The parent annotation with which this pop-up annotation is associated.
   * Note: If this entry is present, the parent annotation’s contents ,
   * modification date, color, and text entries (see Table 8.15 on page 606)
   * override those of the pop-up annotation itself.
   */
  zathura_annotation_t* parent;

  /**
   * A flag specifying whether the pop-up annotation should initially
   * be displayed open.
   */
  bool is_open;
} zathura_annotation_popup_t;

/**
 * Initializes the annotation as a popup annotation
 *
 * @param annotation The annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_popup_init(zathura_annotation_t* annotation);

/**
 * Clear the annotation as a popup annotation
 *
 * @param annotation The annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_popup_clear(zathura_annotation_t* annotation);

#endif // INTERNAL_ANNOTATION_POPUP_H

/* See LICENSE file for license and copyright information */

#ifndef INTERNAL_ANNOTATION_STAMP_H
#define INTERNAL_ANNOTATION_STAMP_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * A rubber stamp annotation displays text or graphics intended to look as
 * if they were stamped on the page with a rubber stamp. When opened, it
 * displays a pop-up window containing the text of the associated note.
 */
typedef struct zathura_annotation_stamp_s {
  /**
   * The name of an icon to be used in displaying the annotation. Viewer
   * applications should provide predefined icon appearances for at least
   * the following standard names:
   *
   * * Approved
   * * AsIs
   * * Confidential
   * * Departmental
   * * Draft
   * * Experimental
   * * Expired
   * * Final
   * * ForComment
   * * ForPublicRelease
   * * NotApproved
   * * NotForPublicRelease
   * * Sold
   * * TopSecret
   *
   * Additional names may be supported as well.
   */
  char* icon_name;
} zathura_annotation_stamp_t;

/**
 * Initializes the annotation as a stamp annotation
 *
 * @param annotation The annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_stamp_init(zathura_annotation_t* annotation);

/**
 * Clear the annotation as a stamp annotation
 *
 * @param annotation The annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_stamp_clear(zathura_annotation_t* annotation);

#ifdef __cplusplus
}
#endif

#endif // INTERNAL_ANNOTATION_STAMP_H

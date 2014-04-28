/* See LICENSE file for license and copyright information */

/**
 * A rubber stamp annotation displays text or graphics intended to look as
 * if they were stamped on the page with a rubber stamp. When opened, it
 * displays a pop-up window containing the text of the associated note.
 */
struct zathura_annotation_stamp_s {
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
};

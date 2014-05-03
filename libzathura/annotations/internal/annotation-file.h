/* See LICENSE file for license and copyright information */

#ifndef INTERNAL_ANNOTATION_FILE_H
#define INTERNAL_ANNOTATION_FILE_H

/**
 * A file attachment annotation contains a reference to a file, which
 * typically is embedded in the document For example, a table of data might
 * use a file attachment annotation to link to a spreadsheet file based on
 * that data; activating the annotation extracts the embedded file and gives
 * the user an opportunity to view it or store it in the file system.
 *
 * The contents entry of the annotation dictionary may specify descriptive
 * text relating to the attached file. Viewer applications should use this
 * entry rather than the optional description entry.
 */
typedef struct zathura_annotation_file_s {
  /**
   * The file associated with this annotation     .
   */
  zathura_attachment_t* file;

  /**
   * The name of an icon to be used in displaying the annotation.  Viewer
   * applications should provide predefined icon appearances for at least the
   * following standard names:
   *
   * * Graph
   * * PushPin
   * * Paperclip
   * * Tag
   *
   * Additional names may be supported as well.
   */
  char* icon_name;
} zathura_annotation_file_t;

/**
 * Initializes the annotation as a file annotation
 *
 * @param annotation The annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_file_init(zathura_annotation_t* annotation);

/**
 * Clear the annotation as a file annotation
 *
 * @param annotation The annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_file_clear(zathura_annotation_t* annotation);

#endif // INTERNAL_ANNOTATION_FILE_H

/* See LICENSE file for license and copyright information */

#ifndef LIBZATHURA_INTERNAL_ANNOTATION_PRINTER_MARK_H
#define LIBZATHURA_INTERNAL_ANNOTATION_PRINTER_MARK_H

#ifdef __cplusplus
extern "C" {
#endif

/** 
 * Printer’s marks are graphic symbols or text added to a page to assist
 * production personnel in identifying components of a multiple-plate job and
 * maintaining consistent output during production. Examples commonly used in
 * the printing industry include these:
 *
 *  - Registration targets for aligning plates
 *  - Gray ramps and color bars for measuring colors and ink densities
 *  - Cut marks showing where the output medium is to be trimmed
 *
 * Although PDF producer applications traditionally include such marks in the
 * content stream of a document, they are logically separate from the content of
 * the page itself and typically appear outside the boundaries (the crop box,
 * trim box, and art box) defining the extent of that content. Printer’s mark
 * annotations provide a mechanism for incorporating printer’s marks into the
 * PDF representation of a page, while keeping them separate from the actual
 * page content. Each page in a PDF document may contain any number of such
 * annotations, each of which represents a single printer’s mark.
 */
typedef struct zathura_annotation_printer_mark_s {
  /**
   * An arbitrary name identifying the type of printer’s mark, such as ColorBar
   * or RegistrationTarget.
   */
  char* name;

  /**
   * A text string representing the printer’s mark in human-readable form and
   * suitable for presentation to the user on the screen.
   */
  char* mark_style;

  /**
   * A list identifying the individual colorants associated with a
   * printer’s mark, such as a color bar. For each entry in this dictionary, the
   * key is a colorant name and the value is an array defining a Separation
   * color space for that colorant.
   */
  zathura_list_t* colorants;
} zathura_annotation_printer_mark_t;

/**
 * Initializes the annotation as a printer-mark annotation
 *
 * @param annotation The annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_printer_mark_init(zathura_annotation_t* annotation);

/**
 * Clear the annotation as a printer-mark annotation
 *
 * @param annotation The annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_printer_mark_clear(zathura_annotation_t* annotation);

#ifdef __cplusplus
}
#endif

#endif // INTERNAL_ANNOTATION_PRINTER_MARK_H

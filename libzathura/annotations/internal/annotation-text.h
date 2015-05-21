/* See LICENSE file for license and copyright information */

#ifndef INTERNAL_ANNOTATION_TEXT_H
#define INTERNAL_ANNOTATION_TEXT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../types.h"

/**
 * A text annotation represents a “sticky note” attached to a point in the PDF
 * document. When closed, the annotation appears as an icon; when open, it
 * displays a pop-up window containing the text of the note in a font and
 * size chosen by the viewer application. Text annotations do not scale and
 * rotate with the page; they behave as if the NoZoom and NoRotate
 * annotation flags were always set.
 */
typedef struct zathura_annotation_text_s {
  /**
   * A flag specifying whether the annotation should initially be displayed
   * open.
   */
  bool is_open;

  /**
   * The name of an icon to be used in displaying the annotation. Viewer
   * applications should provide predefined icon appearances for at least
   * the following standard names:
   *
   * * Comment
   * * Help
   * * Insert
   * * Key
   * * NewParagraph
   * * Note
   * * Paragraph
   *
   * Additional names may be supported as well.
   */
  char* icon_name;

  /**
   * The state to which the original annotation should be set
   */
  zathura_annotation_text_state_t state;
} zathura_annotation_text_t;

/**
 * Initializes the annotation as a text annotation
 *
 * @param annotation The annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_text_init(zathura_annotation_t* annotation);

/**
 * Clear the annotation as a text annotation
 *
 * @param annotation The annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_text_clear(zathura_annotation_t* annotation);

#ifdef __cplusplus
}
#endif

#endif // INTERNAL_ANNOTATION_TEXT_H

/* See LICENSE file for license and copyright information */

#include "../annotations.h"

/**
 * A text annotation represents a “sticky note” attached to a point in the PDF
 * document. When closed, the annotation appears as an icon; when open, it
 * displays a pop-up window containing the text of the note in a font and
 * size chosen by the viewer application. Text annotations do not scale and
 * rotate with the page; they behave as if the NoZoom and NoRotate
 * annotation flags were always set.
 */
struct zathura_annotation_text_s {
  /**
   * A flag specifying whether the annotation should initially be displayed
   * open.
   */
  bool open;

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
};

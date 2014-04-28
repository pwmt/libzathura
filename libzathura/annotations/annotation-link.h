/* See LICENSE file for license and copyright information */

#ifndef ANNOTATION_LINK_H
#define ANNOTATION_LINK_H

/**
 * The annotation’s highlighting mode, the visual effect to be used when the
 * mouse button is pressed or held down inside its active area.
 */
typedef enum zathura_annotation_link_highlighting_mode_e {
  /**
   * No highlighting.
   */
  ZATHURA_ANNOTATION_HIGHLIGHTING_NONE = 'N',

  /**
   * Invert the contents of the annotation rectangle.
   */
  ZATHURA_ANNOTATION_HIGHLIGHTING_INVERT = 'I',

  /**
   * Invert the annotation’s border.
   */
  ZATHURA_ANNOTATION_HIGHLIGHTING_OUTLINE = 'O',

  /**
   * Display the annotation as if it were being pushed below the surface of the
   * page.
   */
  ZATHURA_ANNOTATION_HIGHLIGHTING_PUSH = 'P'
} zathura_annotation_link_highlighting_mode_t;

#endif // ANNOTATION_LINK_H

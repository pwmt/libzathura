/* See LICENSE file for license and copyright information */

#ifndef INTERNAL_ANNOTATION_SCREEN_H
#define INTERNAL_ANNOTATION_SCREEN_H

/**
 * A screen annotation specifies a region of a page upon which
 * media clips may be played. It also serves as an object from which actions
 * can be triggered.
 *
 * TODO: Apperance characteristics dictionary, Additional actions dictionary
 */
typedef struct zathura_annotation_screen_s {
  /**
   * The title of the screen annotation.
   */
  char* title;

  /**
   * An action to be performed when the annotation is activated.
   */
  zathura_action_t* action;
} zathura_annotation_screen_t;

/**
 * Initializes the annotation as a screen annotation
 *
 * @param annotation The annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_screen_init(zathura_annotation_t* annotation);

/**
 * Clear the annotation as a screen annotation
 *
 * @param annotation The annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_screen_clear(zathura_annotation_t* annotation);

#endif // INTERNAL_ANNOTATION_SCREEN_H

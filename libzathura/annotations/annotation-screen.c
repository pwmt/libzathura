/* See LICENSE file for license and copyright information */

#include "../action.h"

/**
 * A screen annotation specifies a region of a page upon which
 * media clips may be played. It also serves as an object from which actions
 * can be triggered.
 *
 * TODO: Apperance characteristics dictionary, Additional actions dictionary
 */
struct zathura_annotation_screen_s {
  /**
   * The title of the screen annotation.
   */
  char* title;

  /**
   * An action to be performed when the annotation is activated.
   */
  zathura_action_t* action;
};

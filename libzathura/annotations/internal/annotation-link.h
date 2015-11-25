/* See LICENSE file for license and copyright information */

#ifndef LIBZATHURA_INTERNAL_ANNOTATION_LINK_H
#define LIBZATHURA_INTERNAL_ANNOTATION_LINK_H

#ifdef __cplusplus
extern "C" {
#endif

#include "annotation-link.h"

/**
 * A link annotation represents either a hypertext link to a destination
 * elsewhere in the document or an action to be performed.
 */
typedef struct zathura_annotation_link_s {
  /**
   * An action to be performed when the link annotation is activated.
   */
  zathura_action_t* action;

  /**
   * The annotation’s highlighting mode, the visual effect to be used when
   * the mouse button is pressed or held down inside its active area.
   */
  zathura_annotation_highlighting_mode_t highlighting_mode;

  /**
   * An list of n @a zathura_quad_point_t objects specifying the coordinates
   * of n quadrilaterals in default user space that comprise the region in
   * which the link should be activated.
   */
  zathura_list_t* quad_points;
} zathura_annotation_link_t;

/**
 * Initializes the annotation as a link annotation
 *
 * @param annotation The annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_link_init(zathura_annotation_t* annotation);

/**
 * Clear the annotation as a link annotation
 *
 * @param annotation The annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_link_clear(zathura_annotation_t* annotation);

#ifdef __cplusplus
}
#endif

#endif // INTERNAL_ANNOTATION_LINK_H

/* See LICENSE file for license and copyright information */

#include "annotation-link.h"
#include "../list.h"

/**
 * A link annotation represents either a hypertext link to a destination
 * elsewhere in the document or an action to be performed.
 */
struct zathura_annotation_link_s {
  /**
   * An action to be performed when the link annotation is ac-
   * tivated
   */
  /* zathura_link_t action; */

  /**
   * The annotation’s highlighting mode, the visual effect to be used when
   * the mouse button is pressed or held down inside its active area.
   */
  zathura_annotation_link_highlighting_mode_t highlighting_mode;

  /**
   * An list of n @a zathura_quad_point_t objects specifying the coordinates
   * of n quadrilaterals in default user space that comprise the region in
   * which the link should be activated.
   *
   * If this entry is not present or the viewer application does not
   * recognize it, the region specified by the @a ::position entry should be
   * used.  @a region should be ignored if any coordinate in the array lies
   * outside the region specified by @a ::position.
   */
  zathura_list_t* quad_points;
};

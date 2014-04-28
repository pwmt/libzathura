/* See LICENSE file for license and copyright information */

#include "../list.h"

#include "border.h"

/**
 * An ink annotation represents a freehand "scribble" composed of one or
 * more disjoint paths. When opened, it displays a pop-up window containing
 * the text of the associated note. Table 8.33 shows the annotation
 * dictionary entries specific to this type of annotation.
 */
struct zathura_annotation_ink_s {
  /**
   * An list of n zathura_path_t paths, each representing a stroked path.
   * Each array is a series of alternating horizontal and vertical
   * coordinates in default user space, specifying points along the path.
   * When drawn, the points are connected by straight lines or curves in an
   * implementation-dependent way.
   */
  zathura_list_t* paths;

  /**
   * A border style dictionary specifying the line width and dash pattern to
   * be used in drawing the paths.
   */
  zathura_annotation_border_t border;
};

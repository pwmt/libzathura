/* See LICENSE file for license and copyright information */

#ifndef INTERNAL_ANNOTATION_INK_H
#define INTERNAL_ANNOTATION_INK_H

#include "../types.h"

/**
 * An ink annotation represents a freehand "scribble" composed of one or
 * more disjoint paths. When opened, it displays a pop-up window containing
 * the text of the associated note. Table 8.33 shows the annotation
 * dictionary entries specific to this type of annotation.
 */
typedef struct zathura_annotation_ink_s {
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
} zathura_annotation_ink_t;

/**
 * Initializes the annotation as a ink annotation
 *
 * @param annotation The annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_ink_init(zathura_annotation_t* annotation);

/**
 * Clear the annotation as a ink annotation
 *
 * @param annotation The annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_ink_clear(zathura_annotation_t* annotation);

#endif // INTERNAL_ANNOTATION_INK_H

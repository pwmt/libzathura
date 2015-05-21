/* See LICENSE file for license and copyright information */

#ifndef INTERNAL_ANNOTATION_3D_H
#define INTERNAL_ANNOTATION_3D_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../types.h"

/**
 * 3D annotations are the means by which 3D artwork is represented in a
 * document. 
 */
typedef struct zathura_annotation_3d_s {
  /**
   * A 3D stream or 3D reference dictionary that specifies the 3D artwork to be
   * shown.
   */
  zathura_3d_t* artwork;

  /**
   * A flag indicating the primary use of the 3D annotation. If true , it is
   * intended to be interactive; if false, it is intended to be manipulated
   * programmatically, as with a JavaScript animation. Viewer applications may
   * present different user interface controls for interactive 3D annotations
   * (for example, to rotate, pan, or zoom the artwork) than for those managed
   * by a script or other mechanism.
   */
  bool is_interactive;

  /** 
   * The 3D view box, which is the rectangular area in which the 3D artwork is
   * to be drawn. It must be within the rectangle specified by the annotation’s
   * Rect entry and is expressed in the annotation’s target coordinate system.
   */
  zathura_rectangle_t view_box;
} zathura_annotation_3d_t;

/**
 * Initializes the annotation as a 3D annotation
 *
 * @param annotation The annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_3d_init(zathura_annotation_t* annotation);

/**
 * Clear the annotation as a 3D annotation
 *
 * @param annotation The annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_3d_clear(zathura_annotation_t* annotation);

#ifdef __cplusplus
}
#endif

#endif // INTERNAL_ANNOTATION_3D_H

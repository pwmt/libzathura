/* See LICENSE file for license and copyright information */

#ifndef LIBZATHURA_ANNOTATION_COLOR_SPACE_H
#define LIBZATHURA_ANNOTATION_COLOR_SPACE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Defines the different supported color spaces.
 */
typedef enum zathura_annotation_color_space_e {
  /**
   * No color, transparent.
   */
  ZATHURA_ANNOTATION_COLOR_SPACE_NONE = 0,

  /**
   * Grayscale
   */
  ZATHURA_ANNOTATION_COLOR_SPACE_GRAY = 1,

  /**
   * RGB
   */
  ZATHURA_ANNOTATION_COLOR_SPACE_RGB = 2,

  /**
   * CMYK
   */
  ZATHURA_ANNOTATION_COLOR_SPACE_CMYK = 3
} zathura_annotation_color_space_t;


/**
 * Defines a color object
 */
typedef struct zathura_annotation_color_s {
  /**
   * The used color space
   */
  zathura_annotation_color_space_t color_space;

  /**
   * Values that depend on the used colorspace
   */
  uint16_t values[4];
} zathura_annotation_color_t;

#ifdef __cplusplus
}
#endif

#endif // ANNOTATION_COLOR_SPACE_H

/* See LICENSE file for license and copyright information */

#ifndef ANNOTATION_FREE_TEXT_H
#define ANNOTATION_FREE_TEXT_H

#include "../types.h"

/**
 * Describes a callout line.
 */
typedef struct zathura_callout_line_s {
  zathura_point_t start; /**< Starting point. */
  zathura_point_t knee; /**< Knee point. */
  zathura_point_t end; /**< End point. */
} zathura_callout_line_t;

/**
 * Specifying the form of justification to be used in displaying the
 * annotations' text.
 */
typedef enum zathura_annotation_justification_e {
  /**
   * Left justified.
   */
  ZATHURA_ANNOTATION_JUSTIFICATION_LEFT_JUSTIFIED = 0,

  /**
   * Centered.
   */
  ZATHURA_ANNOTATION_JUSTIFICATION_CENTERED = 1,

  /**
   * Right justified.
   */
  ZATHURA_ANNOTATION_JUSTIFICATION_RIGHT_JUSTIFIED = 3,
} zathura_annotation_justification_t;

#endif // ANNOTATION_FREE_TEXT_H

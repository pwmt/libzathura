/* See LICENSE file for license and copyright information */

#include "border.h"
#include "color.h"

/**
 * Square and circle annotations display, respectively, a rectangle or an
 * ellipse on the page. When opened, they display a pop-up window containing
 * the text of the associated note. The rectangle or ellipse is inscribed
 * within the annotation rectangle defined by the annotation position entry.
 * Despite the names square and circle, the width and height of the
 * annotation rectangle need not be equal.
 */
struct zathura_annotation_square_and_circle_s {
  /**
   * The border
   */
  zathura_annotation_border_t border;

  /**
   * The color
   */
  zathura_annotation_color_t color;

  /**
   * A set of four numbers describing the numerical differences between two
   * rectangles: the position entry of the annotation and the actual
   * boundaries of the underlying square or circle. Such a difference can
   * occur in situations where a border effect causes the size of the
   * position to increase beyond that of the square or circle.
   *
   * The four numbers correspond to the differences in default user space
   * between the left, top, right, and bottom coordinates of the position
   * and those of the square or circle, respectively. Each value must be
   * greater than or equal to 0. The sum of the top and bottom differences
   * must be less than the height of the position, and the sum of the left
   * and right differences must be less than the width of the position.
   */
  struct {
    unsigned int left;
    unsigned int top;
    unsigned int right;
    unsigned int bottom;
  } padding;
};

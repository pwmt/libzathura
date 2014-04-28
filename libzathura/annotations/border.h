/* See LICENSE file for license and copyright information */

#ifndef ANNOTATION_BORDER_H
#define ANNOTATION_BORDER_H

#include "../list.h"

/**
 * The border style.
 */
typedef enum zathura_annotation_border_style_e {
  /**
   * A solid rectangle surrounding the annotation.
   */
  ZATHURA_ANNOTATION_BORDER_STYLE_SOLID,

  /**
   * A dashed rectangle surrounding the annotation. The dash pattern is
   * specified by the D entry (see below).
   */
  ZATHURA_ANNOTATION_BORDER_STYLE_DASHED,

  /**
   * A simulated embossed rectangle that appears to be raised above the surface
   * of the page.
   */
  ZATHURA_ANNOTATION_BORDER_STYLE_BEVELED,

  /**
   * A simulated engraved rectangle that appears to be recessed below the
   * surface of the page.
   */
  ZATHURA_ANNOTATION_BORDER_STYLE_INSET,

  /**
   * A single line along the bottom of the annotation rectangle.
   */
  ZATHURA_ANNOTATION_BORDER_STYLE_UNDERLINE
} zathura_annotation_border_style_t;

typedef enum zathura_annotation_border_effect_e {
  /**
   * No effect.
   * */
  ZATHURA_ANNOTATION_BORDER_EFFECT_NONE,

  /**
   * The border should appear “cloudy”. The width and dash array specified by
   * border style are honored.
   */
  ZATHURA_ANNOTATION_BORDER_EFFECT_CLOUDY
} zathura_annotation_border_effect_t;

/**
 * The line dash pattern controls the pattern of dashes and gaps used to stroke
 * paths. It is specified by a dash array and a dash phase. The dash array’s
 * elements are numbers that specify the lengths of alternating dashes and gaps;
 * the numbers must be nonnegative and not all zero. The dash phase specifies
 * the distance intohe dash pattern at which to start the dash. The elements of
 * both the dash array and the dash phase are expressed in user space units.
 *
 * Before beginning to stroke a path, the dash array is cycled through, adding
 * up the lengths of dashes and gaps. When the accumulated length equals the
 * value specified by the dash phase, stroking of the path begins, and the dash
 * array is used cyclically from that point onward. An empty dash array and zero
 * phase can be used to restore the dash pattern to a solid line.
 *
 * Dashed lines wrap around curves and corners just as solid stroked lines do.
 * The ends of each dash are treated with the current line cap style, and
 * corners within dashes are treated with the current line join style. A
 * stroking operation takes no measures to coordinate the dash pattern with
 * features of the path; it simply dispenses dashes and gaps along the path in
 * the pattern defined by the dash array. When a path consisting of several
 * subpaths is stroked, each subpath is treated independently - that is, the
 * dash pattern is restarted and the dash phase is reapplied to it at the
 * beginning of each subpath.
 */
typedef struct zathura_annotation_line_dash_pattern_s {
  /**
   * The dash array’s elements are numbers that specify the lengths of
   * alternating dashes and gaps; the numbers must be nonnegative and not all
   * zero.
   */
  zathura_list_t* dash_array;

  /**
   * The dash phase specifies the distance into the dash pattern at which to
   * start the dash.
   */
  unsigned int dash_phase;
} zathura_annotation_line_dash_pattern_t;

/**
 * An annotation may optionally be surrounded by a border when displayed or
 * printed. If present, the border is drawn completely inside the annotation
 * rectangle.
 */
typedef struct zathura_annotation_border_s {
  unsigned int width;
  zathura_annotation_border_style_t style;
  zathura_annotation_line_dash_pattern_t dash_pattern;
  zathura_annotation_border_effect_t effect;
  float intensity;
} zathura_annotation_border_t;

#endif // ANNOTATION_BORDER_H

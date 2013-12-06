/* See LICENSE file for license and copyright information */

#ifndef TRANSITION_H
#define TRANSITION_H

#include <stdbool.h>

typedef enum zathura_page_transition_style_e {
  /**
   * Two lines sweep across the screen, revealing the new page. The lines may be
   * either horizontal or vertical and may move inward from the edges of the
   * page or outward from the center, as specified by the @a
   * ::zathura_page_transition_t.dimension and @a
   * ::zathura_page_transition_t.motion entries, respectively.
   */
  ZATHURA_PAGE_TRANSITION_SPLIT,

  /**
   * Multiple lines, that are evenly spaced accross the screen, synchronously
   * sweep in the same.motion to reveal the new page. The lines may either be
   * horizontal or vertical, as specified by the @a
   * ::zathura_page_transition_t.dimension entry. Horizontal lines move
   * downward, vertical lines move to the right.
   */
  ZATHURA_PAGE_TRANSITION_BLINDS,

  /**
   * A rectangular box sweeps inward from the edges of the page or outward from
   * the center, as specified by the @a ::zathura_page_transition_t.motion
   * entry, revealing the new page .
   */
  ZATHURA_PAGE_TRANSITION_BOX,

  /**
   * A single line sweeps across the screen from one edge to the other in the
   *.motion specified by the ::zathura_page_transition_t.motion entry,
   * revealing the new page.
   */
  ZATHURA_PAGE_TRANSITION_WIPE,

  /**
   * The old pages dissolves gradually to reveal the new one.
   */
  ZATHURA_PAGE_TRANSITION_DISSOLVE,

  /**
   * Similar to Dissolve, except that the effect sweeps across the page in a
   * wide band moving from one side of the screen to the other in the direction
   * specified by the @a ::zathura_page_transition_t.motion entry.
   */
  ZATHURA_PAGE_TRANSITION_GLITTER,

  /**
   * The new page simply replaces the old one with no special transition effect;
   * the @a ::zathura_page_transition_t.duration entry is ignored.
   * */
  ZATHURA_PAGE_TRANSITION_REPLACE,

  /**
   * Changes are flown out or in (as specified by @a
   * ::zathura_page_transition_t.motion), in the direction specified by @a
   * ::zathura_page_transition_t.angle, to
   * or from a location that is offscreen except when @a
   * ::zathura_page_transition_t.angle is 0.
   *
   */
  ZATHURA_PAGE_TRANSITION_FLY,

  /**
   * The old page slides off the screen while the new page slides in,
   * pushing the old page out in the direction specified by @a
   * ::zathura_page_transition_t.angle
   *
   */
  ZATHURA_PAGE_TRANSITION_PUSH,

  /**
   * The new page slides on to the screen in the direction specified
   * by @a ::zathura_page_transition_t.angle, covering the old page.
   *
   */
  ZATHURA_PAGE_TRANSITION_COVER,

  /**
   * The old page slides off the screen in the direction specified by @a
   * ::zathura_page_transition_t.angle, uncovering the new page in the direction
   * specified by @a ::zathura_page_transition_t.angle.
   */
  ZATHURA_PAGE_TRANSITION_UNCOVER,

  /**
   * The new page gradually comes visible through the old one
   */
  ZATHURA_PAGE_TRANSITION_FADE
} zathura_page_transition_style_t;

typedef enum zathura_page_transition_dimension_e {
  ZATHURA_PAGE_TRANSITION_HORIZONTAL, /**< Horizontal */
  ZATHURA_PAGE_TRANSITION_VERTICAL /**< Vertical */
} zathura_page_transition_dimension_t;

typedef enum zathura_page_transition_motion_e {
  ZATHURA_PAGE_TRANSITION_INWARD, /**< From the edges of the page */
  ZATHURA_PAGE_TRANSITION_OUTWARD /**< From the center of the page */
} zathura_page_transition_motion_t;

/**
 * For presentations
 */
typedef struct zathura_page_transition_s {
  /**
   * The transition style to use when moving to this page from another during a
   * presentation.
   */
  zathura_page_transition_style_t style;

  /**
   * The duration of the transition effect, in seconds.
   */
  unsigned int duration;

  /**
   * Split and Blinds transition styles only) The dimension in which the
   * specified transition effect occurs:
   *
   * * @a ::ZATHURA_PAGE_TRANSITION_HORIZONTAL: Horizontal
   * * @a ::ZATHURA_PAGE_TRANSITION_VERTICAL: Vertical
   *
   * Only for @a ::ZATHURA_PAGE_TRANSITION_SPLIT and @a
   * ::ZATHURA_PAGE_TRANSITION_BLINDS transition types.
   */
  zathura_page_transition_dimension_t dimension;

  /**
   * The direction of motion for the specified transition effect:
   *
   * * @a ::ZATHURA_PAGE_TRANSITION_INWARD: From the edges of the page
   * * @a ::ZATHURA_PAGE_TRANSITION_OUTWARD: From the center of the page
   *
   * Only for @a ::ZATHURA_PAGE_TRANSITION_SPLIT, @a
   * ::ZATHURA_PAGE_TRANSITION_BOX and @a ::ZATHURA_PAGE_TRANSITION_FLY
   * transition types.
   */
  zathura_page_transition_motion_t motion;

  /**
   * The direction in which the specified transition effect moves, expressed in
   * degrees counterclockwise starting from a left-to-right direction. (This
   * differs from the page object’s Rotate entry, which is measured clockwise
   * from the top.)
   *
   * The following numeric values are valid:
   *
   *  * 0: Left to right
   *  * 90: Bottom to top (@a ::ZATHURA_PAGE_TRANSITION_WIPE only)
   *  * 180: Right to left (@a ::ZATHURA_PAGE_TRANSITION_WIPE only)
   *  * 270: Top to bottom
   *  * 315: Top-left to bottom-right (@a ::ZATHURA_PAGE_TRANSITION_GLITTER only)
   *
   * Only for @a ::ZATHURA_PAGE_TRANSITION_WIPE, @a
   * ::ZATHURA_PAGE_TRANSITION_GLITTER, @a ::ZATHURA_PAGE_TRANSITION_FLY, @a
   * ::ZATHURA_PAGE_TRANSITION_COVER, @a ::ZATHURA_PAGE_TRANSITION_UNCOVER and
   * @a ::ZATHURA_PAGE_TRANSITION_PUSH transition styles.
   */
  int angle;

  /**
   * scale
   */
  double scale;

  /**
   * If true, the area to be flown in is rectangular and opaque. This field is
   * only important if @a style is set to @a
   * ::ZATHURA_PAGE_TRANSITION_UNCOVER.
   */
  bool rectangular;
} zathura_page_transition_t;

#endif /* TRANSITION_H */

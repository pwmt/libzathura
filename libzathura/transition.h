/* See LICENSE file for license and copyright information */

#ifndef TRANSITION_H
#define TRANSITION_H

#include <stdbool.h>

#include "error.h"

typedef enum zathura_page_transition_style_e {
  /**
   * Two lines sweep across the screen, revealing the new page. The lines may be
   * either horizontal or vertical and may move inward from the edges of the
   * page or outward from the center, as specified by the 
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

typedef enum zathura_page_transition_angle_e {
  ZATHURA_PAGE_TRANSITION_ANGLE_LEFT_TO_RIGHT = 0,
  ZATHURA_PAGE_TRANSITION_ANGLE_NONE = 1,
  ZATHURA_PAGE_TRANSITION_ANGLE_BOTTOM_TO_TOP = 90,
  ZATHURA_PAGE_TRANSITION_ANGLE_RIGHT_TO_LEFT = 180,
  ZATHURA_PAGE_TRANSITION_ANGLE_TOP_TO_BOTTOM = 270,
  ZATHURA_PAGE_TRANSITION_ANGLE_TOP_LEFT_TO_BOTTOM_RIGHT = 315
} zathura_page_transition_angle_t;

/* forward declaration */
typedef struct zathura_page_transition_s zathura_page_transition_t;

/**
 * Returns the style of the transition.
 *
 * @param[in] transition The transition object
 * @param[out] style The style of the transition
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_page_transition_get_style(zathura_page_transition_t*
    transition, zathura_page_transition_style_t* style);

/**
 * Returns the duration of the transition in seconds.
 *
 * @param[in] transition The transition object
 * @param[out] duration The duration of the transition in seconds
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_page_transition_get_duration(zathura_page_transition_t*
    transition, unsigned int* duration);

/**
 * Returns the dimension of the transition.
 *
 * @param[in] transition The transition object
 * @param[out] dimension The dimension of the transition
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_page_transition_get_dimension(zathura_page_transition_t*
    transition, zathura_page_transition_dimension_t* dimension);

/**
 * Returns the motion of the transition object.
 *
 * @param[in] transition The transition object
 * @param[out] motion The motion of the transition
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_page_transition_get_motion(zathura_page_transition_t*
    transition, zathura_page_transition_motion_t* motion);

/**
 * Returns the angle of the transition object.
 *
 * @param[in] transition The transition object
 * @param[out] angle The angle of the transition
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_page_transition_get_angle(zathura_page_transition_t*
    transition, zathura_page_transition_angle_t* angle);

/**
 * Returns the scale of the transition
 *
 * @param[in] transition The transition object
 * @param[out] scale The scale of the transition
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_page_transition_get_scale(zathura_page_transition_t*
    transition, double* scale);

/**
 * Returns if the transition is rectangular
 *
 * @param[in] transition The transtion object
 * @param[out] is_rectangular If the transition is rectangular
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t
zathura_page_transition_is_rectangular(zathura_page_transition_t* transition,
    bool* is_rectangular);

#endif /* TRANSITION_H */

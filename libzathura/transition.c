/* See LICENSE file for license and copyright information */

#include <stdbool.h>
#include <stdlib.h>

#include "transition.h"

/**
 * Describes the transition object of the page which is used
 * for presentations
 */
struct zathura_page_transition_s {
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
  zathura_page_transition_angle_t angle;

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
};

zathura_error_t
zathura_page_transition_new(zathura_page_transition_t** transition,
    zathura_page_transition_style_t style)
{
  if (transition == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *transition = calloc(1, sizeof(zathura_page_transition_t));
  if (*transition == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  switch (style) {
    case ZATHURA_PAGE_TRANSITION_SPLIT:
    case ZATHURA_PAGE_TRANSITION_BLINDS:
    case ZATHURA_PAGE_TRANSITION_BOX:
    case ZATHURA_PAGE_TRANSITION_WIPE:
    case ZATHURA_PAGE_TRANSITION_DISSOLVE:
    case ZATHURA_PAGE_TRANSITION_GLITTER:
    case ZATHURA_PAGE_TRANSITION_REPLACE:
    case ZATHURA_PAGE_TRANSITION_FLY:
    case ZATHURA_PAGE_TRANSITION_PUSH:
    case ZATHURA_PAGE_TRANSITION_COVER:
    case ZATHURA_PAGE_TRANSITION_UNCOVER:
    case ZATHURA_PAGE_TRANSITION_FADE:
      break;
    default:
      return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  (*transition)->style = style;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_page_transition_free(zathura_page_transition_t* transition)
{
  if (transition == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  free(transition);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_page_transition_get_style(zathura_page_transition_t*
    transition, zathura_page_transition_style_t* style)
{
  if (transition == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *style = transition->style;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_page_transition_set_duration(zathura_page_transition_t*
    transition, unsigned int duration)
{
  if (transition == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  transition->duration = duration;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_page_transition_get_duration(zathura_page_transition_t*
    transition, unsigned int* duration)
{
  if (transition == NULL || duration == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *duration = transition->duration;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_page_transition_set_dimension(zathura_page_transition_t*
    transition, zathura_page_transition_dimension_t dimension)
{
  if (transition == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  switch (transition->style) {
    case ZATHURA_PAGE_TRANSITION_SPLIT:
    case ZATHURA_PAGE_TRANSITION_BLINDS:
      break;
    default:
      return ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION;
  }

  transition->dimension = dimension;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_page_transition_get_dimension(zathura_page_transition_t*
    transition, zathura_page_transition_dimension_t* dimension)
{
  if (transition == NULL || dimension == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  switch (transition->style) {
    case ZATHURA_PAGE_TRANSITION_SPLIT:
    case ZATHURA_PAGE_TRANSITION_BLINDS:
      break;
    default:
      return ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION;
  }

  *dimension = transition->dimension;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_page_transition_set_motion(zathura_page_transition_t*
    transition, zathura_page_transition_motion_t motion)
{
  if (transition == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  switch (transition->style) {
    case ZATHURA_PAGE_TRANSITION_SPLIT:
    case ZATHURA_PAGE_TRANSITION_BOX:
    case ZATHURA_PAGE_TRANSITION_FLY:
      break;
    default:
      return ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION;
  }

  transition->motion = motion;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_page_transition_get_motion(zathura_page_transition_t*
    transition, zathura_page_transition_motion_t* motion)
{
  if (transition == NULL || motion == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  switch (transition->style) {
    case ZATHURA_PAGE_TRANSITION_SPLIT:
    case ZATHURA_PAGE_TRANSITION_BOX:
    case ZATHURA_PAGE_TRANSITION_FLY:
      break;
    default:
      return ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION;
  }

  *motion = transition->motion;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_page_transition_set_angle(zathura_page_transition_t*
    transition, zathura_page_transition_angle_t angle)
{
  if (transition == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  switch (transition->style) {
    case ZATHURA_PAGE_TRANSITION_WIPE:
    case ZATHURA_PAGE_TRANSITION_GLITTER:
    case ZATHURA_PAGE_TRANSITION_FLY:
    case ZATHURA_PAGE_TRANSITION_COVER:
    case ZATHURA_PAGE_TRANSITION_UNCOVER:
    case ZATHURA_PAGE_TRANSITION_PUSH:
      break;
    default:
      return ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION;
  }

  switch (angle) {
    case ZATHURA_PAGE_TRANSITION_ANGLE_LEFT_TO_RIGHT:
      break;
    case ZATHURA_PAGE_TRANSITION_ANGLE_NONE:
      if (transition->style != ZATHURA_PAGE_TRANSITION_FLY || transition->scale == 1.0)
        goto error_out;
      break;
    case ZATHURA_PAGE_TRANSITION_ANGLE_BOTTOM_TO_TOP:
      if (transition->style != ZATHURA_PAGE_TRANSITION_WIPE)
        goto error_out;
      break;
    case ZATHURA_PAGE_TRANSITION_ANGLE_RIGHT_TO_LEFT:
      if (transition->style != ZATHURA_PAGE_TRANSITION_WIPE)
        goto error_out;
      break;
    case ZATHURA_PAGE_TRANSITION_ANGLE_TOP_TO_BOTTOM:
      break;
    case ZATHURA_PAGE_TRANSITION_ANGLE_TOP_LEFT_TO_BOTTOM_RIGHT:
      if (transition->style != ZATHURA_PAGE_TRANSITION_GLITTER)
        goto error_out;
      break;
    default:
      return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  transition->angle = angle;

  return ZATHURA_ERROR_OK;

error_out:

  return ZATHURA_ERROR_INVALID_ARGUMENTS;
}

zathura_error_t
zathura_page_transition_get_angle(zathura_page_transition_t*
    transition, zathura_page_transition_angle_t* angle)
{
  if (transition == NULL || angle == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  switch (transition->style) {
    case ZATHURA_PAGE_TRANSITION_WIPE:
    case ZATHURA_PAGE_TRANSITION_GLITTER:
    case ZATHURA_PAGE_TRANSITION_FLY:
    case ZATHURA_PAGE_TRANSITION_COVER:
    case ZATHURA_PAGE_TRANSITION_UNCOVER:
    case ZATHURA_PAGE_TRANSITION_PUSH:
      break;
    default:
      return ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION;
  }

  *angle = transition->angle;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_page_transition_set_scale(zathura_page_transition_t*
    transition, double scale)
{
  if (transition == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  switch (transition->style) {
    case ZATHURA_PAGE_TRANSITION_FLY:
      if (scale == 1.0)
        transition->angle = ZATHURA_PAGE_TRANSITION_ANGLE_LEFT_TO_RIGHT;
      break;
    default:
      return ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION;
  }

  transition->scale = scale;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_page_transition_get_scale(zathura_page_transition_t*
    transition, double* scale)
{
  if (transition == NULL || scale == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  switch (transition->style) {
    case ZATHURA_PAGE_TRANSITION_FLY:
      break;
    default:
      return ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION;
  }

  *scale = transition->scale;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_page_transition_set_rectangular(zathura_page_transition_t* transition,
    bool is_rectangular)
{
  if (transition == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  switch (transition->style) {
    case ZATHURA_PAGE_TRANSITION_FLY:
      break;
    default:
      return ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION;
  }

  transition->rectangular = is_rectangular;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_page_transition_is_rectangular(zathura_page_transition_t* transition,
    bool* is_rectangular)
{
  if (transition == NULL || is_rectangular == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  switch (transition->style) {
    case ZATHURA_PAGE_TRANSITION_FLY:
      break;
    default:
      return ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION;
  }

  *is_rectangular = transition->rectangular;

  return ZATHURA_ERROR_OK;
}

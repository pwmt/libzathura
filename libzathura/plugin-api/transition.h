/* See LICENSE file for license and copyright information */

#ifndef PLUGIN_API_TRANSITION_H
#define PLUGIN_API_TRANSITION_H

#include "../transition.h"
#include "../error.h"

/**
 * Creates a new page transition object
 *
 * @param[out] transition The transition object
 * @param[in] style The transition style
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_page_transition_new(zathura_page_transition_t** transition, zathura_page_transition_style_t style);

/**
 * Frees the transition object
 * 
 * @param[in] transition The transition style
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_page_transition_free(zathura_page_transition_t* transition);

/**
 * Sets the duration of the transition object
 *
 * @param transition The transition object
 * @param duration
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_page_transition_set_duration(zathura_page_transition_t* transition, unsigned int duration);

/**
 * Sets the dimension of the transition
 *
 * @param transition The transition object
 * @param dimension
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_page_transition_set_dimension(zathura_page_transition_t* transition, zathura_page_transition_dimension_t dimension);

/**
 * Sets the motion of the transition
 *
 * @param transition The transition object
 * @param motion
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_page_transition_set_motion(zathura_page_transition_t* transition, zathura_page_transition_motion_t motion);

/**
 * Sets the angle of the transition
 *
 * @param transition The transition object
 * @param angle
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_page_transition_set_angle(zathura_page_transition_t* transition, zathura_page_transition_angle_t angle);

/**
 * Sets the scale of the transition
 *
 * @param transition The transition object
 * @param scale
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_page_transition_set_scale(zathura_page_transition_t* transition, double scale);

/**
 * Sets if the transition is rectangular or not
 *
 * @param transition The transition object
 * @param is_rectangular
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_page_transition_set_rectangular(zathura_page_transition_t* transition, bool is_rectangular);

#endif /* PLUGIN_API_TRANSITION_H */

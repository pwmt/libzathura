/* See LICENSE file for license and copyright information */

#include <check.h>
#include <fiu.h>
#include <stdio.h>
#include <limits.h>

#include "transition.h"
#include "plugin-api.h"

zathura_page_transition_t* transition;

static void teardown(void) {
  fail_unless(zathura_page_transition_free(transition) == ZATHURA_ERROR_OK);
  transition = NULL;
}

START_TEST(test_transition_free) {
  /* basic invalid arguments */
  fail_unless(zathura_page_transition_free(NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_transition_new) {
  zathura_page_transition_t* transition;

  /* basic invalid arguments */
  fail_unless(zathura_page_transition_new(NULL, 0) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_transition_new(&transition, INT_MAX) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_SPLIT) == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_free(transition) == ZATHURA_ERROR_OK);

  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_BLINDS) == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_free(transition) == ZATHURA_ERROR_OK);

  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_BOX) == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_free(transition) == ZATHURA_ERROR_OK);

  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_WIPE) == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_free(transition) == ZATHURA_ERROR_OK);

  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_DISSOLVE) == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_free(transition) == ZATHURA_ERROR_OK);

  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_GLITTER) == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_free(transition) == ZATHURA_ERROR_OK);

  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_REPLACE) == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_free(transition) == ZATHURA_ERROR_OK);

  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_FLY) == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_free(transition) == ZATHURA_ERROR_OK);

  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_PUSH) == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_free(transition) == ZATHURA_ERROR_OK);

  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_COVER) == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_free(transition) == ZATHURA_ERROR_OK);

  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_UNCOVER) == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_free(transition) == ZATHURA_ERROR_OK);

  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_FADE) == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_free(transition) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_transition_get_style) {
  /* invalid arguments */
  fail_unless(zathura_page_transition_get_style(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  zathura_page_transition_t* transition;
  zathura_page_transition_style_t style;

  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_SPLIT) == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_get_style(transition, &style) == ZATHURA_ERROR_OK);
  fail_unless(style == ZATHURA_PAGE_TRANSITION_SPLIT);
  fail_unless(zathura_page_transition_free(transition) == ZATHURA_ERROR_OK);

  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_BLINDS) == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_get_style(transition, &style) == ZATHURA_ERROR_OK);
  fail_unless(style == ZATHURA_PAGE_TRANSITION_BLINDS);
  fail_unless(zathura_page_transition_free(transition) == ZATHURA_ERROR_OK);

  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_BOX) == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_get_style(transition, &style) == ZATHURA_ERROR_OK);
  fail_unless(style == ZATHURA_PAGE_TRANSITION_BOX);
  fail_unless(zathura_page_transition_free(transition) == ZATHURA_ERROR_OK);

  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_WIPE) == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_get_style(transition, &style) == ZATHURA_ERROR_OK);
  fail_unless(style == ZATHURA_PAGE_TRANSITION_WIPE);
  fail_unless(zathura_page_transition_free(transition) == ZATHURA_ERROR_OK);

  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_DISSOLVE) == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_get_style(transition, &style) == ZATHURA_ERROR_OK);
  fail_unless(style == ZATHURA_PAGE_TRANSITION_DISSOLVE);
  fail_unless(zathura_page_transition_free(transition) == ZATHURA_ERROR_OK);

  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_GLITTER) == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_get_style(transition, &style) == ZATHURA_ERROR_OK);
  fail_unless(style == ZATHURA_PAGE_TRANSITION_GLITTER);
  fail_unless(zathura_page_transition_free(transition) == ZATHURA_ERROR_OK);

  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_REPLACE) == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_get_style(transition, &style) == ZATHURA_ERROR_OK);
  fail_unless(style == ZATHURA_PAGE_TRANSITION_REPLACE);
  fail_unless(zathura_page_transition_free(transition) == ZATHURA_ERROR_OK);

  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_FLY) == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_get_style(transition, &style) == ZATHURA_ERROR_OK);
  fail_unless(style == ZATHURA_PAGE_TRANSITION_FLY);
  fail_unless(zathura_page_transition_free(transition) == ZATHURA_ERROR_OK);

  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_PUSH) == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_get_style(transition, &style) == ZATHURA_ERROR_OK);
  fail_unless(style == ZATHURA_PAGE_TRANSITION_PUSH);
  fail_unless(zathura_page_transition_free(transition) == ZATHURA_ERROR_OK);

  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_COVER) == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_get_style(transition, &style) == ZATHURA_ERROR_OK);
  fail_unless(style == ZATHURA_PAGE_TRANSITION_COVER);
  fail_unless(zathura_page_transition_free(transition) == ZATHURA_ERROR_OK);

  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_SPLIT) == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_get_style(transition, &style) == ZATHURA_ERROR_OK);
  fail_unless(style == ZATHURA_PAGE_TRANSITION_SPLIT);
  fail_unless(zathura_page_transition_free(transition) == ZATHURA_ERROR_OK);

  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_FADE) == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_get_style(transition, &style) == ZATHURA_ERROR_OK);
  fail_unless(style == ZATHURA_PAGE_TRANSITION_FADE);
  fail_unless(zathura_page_transition_free(transition) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_transition_set_duration) {
  /* invalid paramters */
  fail_unless(zathura_page_transition_set_duration(NULL, 0) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid parameters */
  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_SPLIT) == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_set_duration(transition, 5) == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_free(transition) == ZATHURA_ERROR_OK);
  transition = NULL;
} END_TEST

START_TEST(test_transition_get_duration) {
  zathura_page_transition_t* transition;
  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_SPLIT) == ZATHURA_ERROR_OK);

  /* invalid paramters */
  fail_unless(zathura_page_transition_get_duration(NULL, NULL)       == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_transition_get_duration(transition, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid parameters */
  unsigned int duration = 0;
  fail_unless(zathura_page_transition_set_duration(transition, 5) == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_get_duration(transition, &duration) == ZATHURA_ERROR_OK);
  fail_unless(duration == 5);

  /* clean up */
  fail_unless(zathura_page_transition_free(transition) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_transition_set_dimension) {
  /* invalid paramters */
  fail_unless(zathura_page_transition_set_dimension(NULL, 0) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_transition_get_dimension) {
  zathura_page_transition_t* transition;
  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_SPLIT) == ZATHURA_ERROR_OK);

  /* invalid paramters */
  fail_unless(zathura_page_transition_get_dimension(NULL, NULL)       == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_transition_get_dimension(transition, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* clean up */
  fail_unless(zathura_page_transition_free(transition) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_transition_set_motion) {
  /* invalid paramters */
  fail_unless(zathura_page_transition_set_motion(NULL, 0) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_transition_get_motion) {
  zathura_page_transition_t* transition;
  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_SPLIT) == ZATHURA_ERROR_OK);

  /* invalid paramters */
  fail_unless(zathura_page_transition_get_motion(NULL, NULL)       == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_transition_get_motion(transition, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* clean up */
  fail_unless(zathura_page_transition_free(transition) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_transition_set_angle) {
  zathura_page_transition_t* transition;
  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_WIPE) == ZATHURA_ERROR_OK);

  /* invalid paramters */
  fail_unless(zathura_page_transition_set_angle(NULL, 0) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_transition_set_angle(transition, 2) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid parameter */
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_RIGHT_TO_LEFT) == ZATHURA_ERROR_OK);

  fail_unless(zathura_page_transition_free(transition) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_transition_get_angle) {
  zathura_page_transition_t* transition;
  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_SPLIT) == ZATHURA_ERROR_OK);

  /* invalid paramters */
  fail_unless(zathura_page_transition_get_angle(NULL, NULL)       == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_transition_get_angle(transition, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* clean up */
  fail_unless(zathura_page_transition_free(transition) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_transition_set_scale) {
  /* invalid paramters */
  fail_unless(zathura_page_transition_set_scale(NULL, 0) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_transition_get_scale) {
  zathura_page_transition_t* transition;
  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_SPLIT) == ZATHURA_ERROR_OK);

  /* invalid paramters */
  fail_unless(zathura_page_transition_get_scale(NULL, NULL)       == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_transition_get_scale(transition, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* clean up */
  fail_unless(zathura_page_transition_free(transition) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_transition_set_rectangular) {
  /* invalid paramters */
  fail_unless(zathura_page_transition_set_rectangular(NULL, 0) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_transition_is_rectangular) {
  zathura_page_transition_t* transition;
  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_SPLIT) == ZATHURA_ERROR_OK);

  /* invalid paramters */
  fail_unless(zathura_page_transition_is_rectangular(NULL, NULL)       == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_transition_is_rectangular(transition, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* clean up */
  fail_unless(zathura_page_transition_free(transition) == ZATHURA_ERROR_OK);
} END_TEST

static void setup_split(void) {
  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_SPLIT) == ZATHURA_ERROR_OK);
}

START_TEST(test_split_transition_set_dimension) {
  fail_unless(zathura_page_transition_set_dimension(transition, ZATHURA_PAGE_TRANSITION_HORIZONTAL) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_split_transition_get_dimension) {
  zathura_page_transition_dimension_t dimension;
  fail_unless(zathura_page_transition_get_dimension(transition, &dimension) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_split_transition_set_motion) {
  fail_unless(zathura_page_transition_set_motion(transition, ZATHURA_PAGE_TRANSITION_INWARD) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_split_transition_get_motion) {
  zathura_page_transition_motion_t motion;
  fail_unless(zathura_page_transition_get_motion(transition, &motion) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_split_transition_set_angle) {
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_NONE) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_split_transition_get_angle) {
  zathura_page_transition_angle_t angle;
  fail_unless(zathura_page_transition_get_angle(transition, &angle) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_split_transition_set_scale) {
  fail_unless(zathura_page_transition_set_scale(transition, 0) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_split_transition_get_scale) {
  double scale;
  fail_unless(zathura_page_transition_get_scale(transition, &scale) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_split_transition_set_rectangular) {
  fail_unless(zathura_page_transition_set_rectangular(transition, true) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_split_transition_is_rectangular) {
  bool rectangular;
  fail_unless(zathura_page_transition_is_rectangular(transition, &rectangular) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

static void setup_blinds(void) {
  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_BLINDS) == ZATHURA_ERROR_OK);
}

START_TEST(test_blinds_transition_set_dimension) {
  fail_unless(zathura_page_transition_set_dimension(transition, ZATHURA_PAGE_TRANSITION_HORIZONTAL) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_blinds_transition_get_dimension) {
  zathura_page_transition_dimension_t dimension;
  fail_unless(zathura_page_transition_get_dimension(transition, &dimension) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_blinds_transition_set_motion) {
  fail_unless(zathura_page_transition_set_motion(transition, ZATHURA_PAGE_TRANSITION_INWARD) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_blinds_transition_get_motion) {
  zathura_page_transition_motion_t motion;
  fail_unless(zathura_page_transition_get_motion(transition, &motion) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_blinds_transition_set_angle) {
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_NONE) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_blinds_transition_get_angle) {
  zathura_page_transition_angle_t angle;
  fail_unless(zathura_page_transition_get_angle(transition, &angle) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_blinds_transition_set_scale) {
  fail_unless(zathura_page_transition_set_scale(transition, 0) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_blinds_transition_get_scale) {
  double scale;
  fail_unless(zathura_page_transition_get_scale(transition, &scale) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_blinds_transition_set_rectangular) {
  fail_unless(zathura_page_transition_set_rectangular(transition, true) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_blinds_transition_is_rectangular) {
  bool rectangular;
  fail_unless(zathura_page_transition_is_rectangular(transition, &rectangular) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

static void setup_box(void) {
  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_BOX) == ZATHURA_ERROR_OK);
}

START_TEST(test_box_transition_set_dimension) {
  fail_unless(zathura_page_transition_set_dimension(transition, ZATHURA_PAGE_TRANSITION_HORIZONTAL) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_box_transition_get_dimension) {
  zathura_page_transition_dimension_t dimension;
  fail_unless(zathura_page_transition_get_dimension(transition, &dimension) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_box_transition_set_motion) {
  fail_unless(zathura_page_transition_set_motion(transition, ZATHURA_PAGE_TRANSITION_INWARD) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_box_transition_get_motion) {
  zathura_page_transition_motion_t motion;
  fail_unless(zathura_page_transition_get_motion(transition, &motion) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_box_transition_set_angle) {
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_NONE) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_box_transition_get_angle) {
  zathura_page_transition_angle_t angle;
  fail_unless(zathura_page_transition_get_angle(transition, &angle) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_box_transition_set_scale) {
  fail_unless(zathura_page_transition_set_scale(transition, 0) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_box_transition_get_scale) {
  double scale;
  fail_unless(zathura_page_transition_get_scale(transition, &scale) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_box_transition_set_rectangular) {
  fail_unless(zathura_page_transition_set_rectangular(transition, true) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_box_transition_is_rectangular) {
  bool rectangular;
  fail_unless(zathura_page_transition_is_rectangular(transition, &rectangular) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

static void setup_wipe(void) {
  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_WIPE) == ZATHURA_ERROR_OK);
}

START_TEST(test_wipe_transition_set_dimension) {
  fail_unless(zathura_page_transition_set_dimension(transition, ZATHURA_PAGE_TRANSITION_HORIZONTAL) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_wipe_transition_get_dimension) {
  zathura_page_transition_dimension_t dimension;
  fail_unless(zathura_page_transition_get_dimension(transition, &dimension) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_wipe_transition_set_motion) {
  fail_unless(zathura_page_transition_set_motion(transition, ZATHURA_PAGE_TRANSITION_INWARD) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_wipe_transition_get_motion) {
  zathura_page_transition_motion_t motion;
  fail_unless(zathura_page_transition_get_motion(transition, &motion) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_wipe_transition_set_angle) {
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_NONE)                     == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_LEFT_TO_RIGHT)            == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_BOTTOM_TO_TOP)            == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_RIGHT_TO_LEFT)            == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_TOP_TO_BOTTOM)            == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_TOP_LEFT_TO_BOTTOM_RIGHT) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_wipe_transition_get_angle) {
  zathura_page_transition_angle_t angle;
  fail_unless(zathura_page_transition_get_angle(transition, &angle) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_wipe_transition_set_scale) {
  fail_unless(zathura_page_transition_set_scale(transition, 0) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_wipe_transition_get_scale) {
  double scale;
  fail_unless(zathura_page_transition_get_scale(transition, &scale) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_wipe_transition_set_rectangular) {
  fail_unless(zathura_page_transition_set_rectangular(transition, true) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_wipe_transition_is_rectangular) {
  bool rectangular;
  fail_unless(zathura_page_transition_is_rectangular(transition, &rectangular) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

static void setup_dissolve(void) {
  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_DISSOLVE) == ZATHURA_ERROR_OK);
}

START_TEST(test_dissolve_transition_set_dimension) {
  fail_unless(zathura_page_transition_set_dimension(transition, ZATHURA_PAGE_TRANSITION_HORIZONTAL) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_dissolve_transition_get_dimension) {
  zathura_page_transition_dimension_t dimension;
  fail_unless(zathura_page_transition_get_dimension(transition, &dimension) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_dissolve_transition_set_motion) {
  fail_unless(zathura_page_transition_set_motion(transition, ZATHURA_PAGE_TRANSITION_INWARD) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_dissolve_transition_get_motion) {
  zathura_page_transition_motion_t motion;
  fail_unless(zathura_page_transition_get_motion(transition, &motion) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_dissolve_transition_set_angle) {
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_NONE) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_dissolve_transition_get_angle) {
  zathura_page_transition_angle_t angle;
  fail_unless(zathura_page_transition_get_angle(transition, &angle) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_dissolve_transition_set_scale) {
  fail_unless(zathura_page_transition_set_scale(transition, 0) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_dissolve_transition_get_scale) {
  double scale;
  fail_unless(zathura_page_transition_get_scale(transition, &scale) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_dissolve_transition_set_rectangular) {
  fail_unless(zathura_page_transition_set_rectangular(transition, true) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_dissolve_transition_is_rectangular) {
  bool rectangular;
  fail_unless(zathura_page_transition_is_rectangular(transition, &rectangular) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

static void setup_glitter(void) {
  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_GLITTER) == ZATHURA_ERROR_OK);
}

START_TEST(test_glitter_transition_set_dimension) {
  fail_unless(zathura_page_transition_set_dimension(transition, ZATHURA_PAGE_TRANSITION_HORIZONTAL) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_glitter_transition_get_dimension) {
  zathura_page_transition_dimension_t dimension;
  fail_unless(zathura_page_transition_get_dimension(transition, &dimension) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_glitter_transition_set_motion) {
  fail_unless(zathura_page_transition_set_motion(transition, ZATHURA_PAGE_TRANSITION_INWARD) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_glitter_transition_get_motion) {
  zathura_page_transition_motion_t motion;
  fail_unless(zathura_page_transition_get_motion(transition, &motion) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_glitter_transition_set_angle) {
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_NONE)                     == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_LEFT_TO_RIGHT)            == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_BOTTOM_TO_TOP)            == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_RIGHT_TO_LEFT)            == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_TOP_TO_BOTTOM)            == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_TOP_LEFT_TO_BOTTOM_RIGHT) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_glitter_transition_get_angle) {
  zathura_page_transition_angle_t angle;
  fail_unless(zathura_page_transition_get_angle(transition, &angle) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_glitter_transition_set_scale) {
  fail_unless(zathura_page_transition_set_scale(transition, 0) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_glitter_transition_get_scale) {
  double scale;
  fail_unless(zathura_page_transition_get_scale(transition, &scale) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_glitter_transition_set_rectangular) {
  fail_unless(zathura_page_transition_set_rectangular(transition, true) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_glitter_transition_is_rectangular) {
  bool rectangular;
  fail_unless(zathura_page_transition_is_rectangular(transition, &rectangular) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

static void setup_replace(void) {
  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_REPLACE) == ZATHURA_ERROR_OK);
}

START_TEST(test_replace_transition_set_dimension) {
  fail_unless(zathura_page_transition_set_dimension(transition, ZATHURA_PAGE_TRANSITION_HORIZONTAL) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_replace_transition_get_dimension) {
  zathura_page_transition_dimension_t dimension;
  fail_unless(zathura_page_transition_get_dimension(transition, &dimension) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_replace_transition_set_motion) {
  fail_unless(zathura_page_transition_set_motion(transition, ZATHURA_PAGE_TRANSITION_INWARD) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_replace_transition_get_motion) {
  zathura_page_transition_motion_t motion;
  fail_unless(zathura_page_transition_get_motion(transition, &motion) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_replace_transition_set_angle) {
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_NONE) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_replace_transition_get_angle) {
  zathura_page_transition_angle_t angle;
  fail_unless(zathura_page_transition_get_angle(transition, &angle) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_replace_transition_set_scale) {
  fail_unless(zathura_page_transition_set_scale(transition, 0) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_replace_transition_get_scale) {
  double scale;
  fail_unless(zathura_page_transition_get_scale(transition, &scale) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_replace_transition_set_rectangular) {
  fail_unless(zathura_page_transition_set_rectangular(transition, true) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_replace_transition_is_rectangular) {
  bool rectangular;
  fail_unless(zathura_page_transition_is_rectangular(transition, &rectangular) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

static void setup_fly(void) {
  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_FLY) == ZATHURA_ERROR_OK);
}

START_TEST(test_fly_transition_set_dimension) {
  fail_unless(zathura_page_transition_set_dimension(transition, ZATHURA_PAGE_TRANSITION_HORIZONTAL) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_fly_transition_get_dimension) {
  zathura_page_transition_dimension_t dimension;
  fail_unless(zathura_page_transition_get_dimension(transition, &dimension) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_fly_transition_set_motion) {
  fail_unless(zathura_page_transition_set_motion(transition, ZATHURA_PAGE_TRANSITION_INWARD) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_fly_transition_get_motion) {
  zathura_page_transition_motion_t motion;
  fail_unless(zathura_page_transition_get_motion(transition, &motion) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_fly_transition_set_angle) {
  fail_unless(zathura_page_transition_set_scale(transition, 2.0)                                == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_NONE) == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_set_scale(transition, 1.0)                                == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_NONE) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_LEFT_TO_RIGHT)            == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_BOTTOM_TO_TOP)            == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_RIGHT_TO_LEFT)            == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_TOP_TO_BOTTOM)            == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_TOP_LEFT_TO_BOTTOM_RIGHT) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_fly_transition_get_angle) {
  zathura_page_transition_angle_t angle;
  fail_unless(zathura_page_transition_get_angle(transition, &angle) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_fly_transition_set_scale) {
  fail_unless(zathura_page_transition_set_scale(transition, 2.0) == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_NONE) == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_set_scale(transition, 1.0) == ZATHURA_ERROR_OK);
  zathura_page_transition_angle_t angle;
  fail_unless(zathura_page_transition_get_angle(transition, &angle) == ZATHURA_ERROR_OK);
  fail_unless(angle == ZATHURA_PAGE_TRANSITION_ANGLE_LEFT_TO_RIGHT);
} END_TEST

START_TEST(test_fly_transition_get_scale) {
  double scale;
  fail_unless(zathura_page_transition_get_scale(transition, &scale) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_fly_transition_set_rectangular) {
  fail_unless(zathura_page_transition_set_rectangular(transition, true) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_fly_transition_is_rectangular) {
  bool rectangular;
  fail_unless(zathura_page_transition_is_rectangular(transition, &rectangular) == ZATHURA_ERROR_OK);
} END_TEST

static void setup_push(void) {
  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_PUSH) == ZATHURA_ERROR_OK);
}

START_TEST(test_push_transition_set_dimension) {
  fail_unless(zathura_page_transition_set_dimension(transition, ZATHURA_PAGE_TRANSITION_HORIZONTAL) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_push_transition_get_dimension) {
  zathura_page_transition_dimension_t dimension;
  fail_unless(zathura_page_transition_get_dimension(transition, &dimension) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_push_transition_set_motion) {
  fail_unless(zathura_page_transition_set_motion(transition, ZATHURA_PAGE_TRANSITION_INWARD) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_push_transition_get_motion) {
  zathura_page_transition_motion_t motion;
  fail_unless(zathura_page_transition_get_motion(transition, &motion) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_push_transition_set_angle) {
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_NONE)                     == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_LEFT_TO_RIGHT)            == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_BOTTOM_TO_TOP)            == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_RIGHT_TO_LEFT)            == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_TOP_TO_BOTTOM)            == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_TOP_LEFT_TO_BOTTOM_RIGHT) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_push_transition_get_angle) {
  zathura_page_transition_angle_t angle;
  fail_unless(zathura_page_transition_get_angle(transition, &angle) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_push_transition_set_scale) {
  fail_unless(zathura_page_transition_set_scale(transition, 0) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_push_transition_get_scale) {
  double scale;
  fail_unless(zathura_page_transition_get_scale(transition, &scale) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_push_transition_set_rectangular) {
  fail_unless(zathura_page_transition_set_rectangular(transition, true) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_push_transition_is_rectangular) {
  bool rectangular;
  fail_unless(zathura_page_transition_is_rectangular(transition, &rectangular) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

static void setup_cover(void) {
  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_COVER) == ZATHURA_ERROR_OK);
}

START_TEST(test_cover_transition_set_dimension) {
  fail_unless(zathura_page_transition_set_dimension(transition, ZATHURA_PAGE_TRANSITION_HORIZONTAL) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_cover_transition_get_dimension) {
  zathura_page_transition_dimension_t dimension;
  fail_unless(zathura_page_transition_get_dimension(transition, &dimension) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_cover_transition_set_motion) {
  fail_unless(zathura_page_transition_set_motion(transition, ZATHURA_PAGE_TRANSITION_INWARD) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_cover_transition_get_motion) {
  zathura_page_transition_motion_t motion;
  fail_unless(zathura_page_transition_get_motion(transition, &motion) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_cover_transition_set_angle) {
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_NONE)                     == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_LEFT_TO_RIGHT)            == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_BOTTOM_TO_TOP)            == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_RIGHT_TO_LEFT)            == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_TOP_TO_BOTTOM)            == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_TOP_LEFT_TO_BOTTOM_RIGHT) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_cover_transition_get_angle) {
  zathura_page_transition_angle_t angle;
  fail_unless(zathura_page_transition_get_angle(transition, &angle) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_cover_transition_set_scale) {
  fail_unless(zathura_page_transition_set_scale(transition, 0) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_cover_transition_get_scale) {
  double scale;
  fail_unless(zathura_page_transition_get_scale(transition, &scale) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_cover_transition_set_rectangular) {
  fail_unless(zathura_page_transition_set_rectangular(transition, true) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_cover_transition_is_rectangular) {
  bool rectangular;
  fail_unless(zathura_page_transition_is_rectangular(transition, &rectangular) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

static void setup_uncover(void) {
  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_UNCOVER) == ZATHURA_ERROR_OK);
}

START_TEST(test_uncover_transition_set_dimension) {
  fail_unless(zathura_page_transition_set_dimension(transition, ZATHURA_PAGE_TRANSITION_HORIZONTAL) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_uncover_transition_get_dimension) {
  zathura_page_transition_dimension_t dimension;
  fail_unless(zathura_page_transition_get_dimension(transition, &dimension) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_uncover_transition_set_motion) {
  fail_unless(zathura_page_transition_set_motion(transition, ZATHURA_PAGE_TRANSITION_INWARD) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_uncover_transition_get_motion) {
  zathura_page_transition_motion_t motion;
  fail_unless(zathura_page_transition_get_motion(transition, &motion) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_uncover_transition_set_angle) {
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_NONE)                     == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_LEFT_TO_RIGHT)            == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_BOTTOM_TO_TOP)            == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_RIGHT_TO_LEFT)            == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_TOP_TO_BOTTOM)            == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_TOP_LEFT_TO_BOTTOM_RIGHT) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_uncover_transition_get_angle) {
  zathura_page_transition_angle_t angle;
  fail_unless(zathura_page_transition_get_angle(transition, &angle) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_uncover_transition_set_scale) {
  fail_unless(zathura_page_transition_set_scale(transition, 0) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_uncover_transition_get_scale) {
  double scale;
  fail_unless(zathura_page_transition_get_scale(transition, &scale) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_uncover_transition_set_rectangular) {
  fail_unless(zathura_page_transition_set_rectangular(transition, true) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_uncover_transition_is_rectangular) {
  bool rectangular;
  fail_unless(zathura_page_transition_is_rectangular(transition, &rectangular) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

static void setup_fade(void) {
  fail_unless(zathura_page_transition_new(&transition, ZATHURA_PAGE_TRANSITION_FADE) == ZATHURA_ERROR_OK);
}

START_TEST(test_fade_transition_set_dimension) {
  fail_unless(zathura_page_transition_set_dimension(transition, ZATHURA_PAGE_TRANSITION_HORIZONTAL) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_fade_transition_get_dimension) {
  zathura_page_transition_dimension_t dimension;
  fail_unless(zathura_page_transition_get_dimension(transition, &dimension) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_fade_transition_set_motion) {
  fail_unless(zathura_page_transition_set_motion(transition, ZATHURA_PAGE_TRANSITION_INWARD) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_fade_transition_get_motion) {
  zathura_page_transition_motion_t motion;
  fail_unless(zathura_page_transition_get_motion(transition, &motion) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_fade_transition_set_angle) {
  fail_unless(zathura_page_transition_set_angle(transition, ZATHURA_PAGE_TRANSITION_ANGLE_NONE) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_fade_transition_get_angle) {
  zathura_page_transition_angle_t angle;
  fail_unless(zathura_page_transition_get_angle(transition, &angle) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_fade_transition_set_scale) {
  fail_unless(zathura_page_transition_set_scale(transition, 0) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_fade_transition_get_scale) {
  double scale;
  fail_unless(zathura_page_transition_get_scale(transition, &scale) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_fade_transition_set_rectangular) {
  fail_unless(zathura_page_transition_set_rectangular(transition, true) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

START_TEST(test_fade_transition_is_rectangular) {
  bool rectangular;
  fail_unless(zathura_page_transition_is_rectangular(transition, &rectangular) == ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION);
} END_TEST

Suite*
suite_transition(void)
{
  TCase* tcase = NULL;
  Suite* suite = suite_create("transition");

  tcase = tcase_create("basic");
  tcase_add_test(tcase, test_transition_free);
  tcase_add_test(tcase, test_transition_new);
  tcase_add_test(tcase, test_transition_get_style);
  tcase_add_test(tcase, test_transition_set_duration);
  tcase_add_test(tcase, test_transition_get_duration);
  tcase_add_test(tcase, test_transition_set_dimension);
  tcase_add_test(tcase, test_transition_get_dimension);
  tcase_add_test(tcase, test_transition_set_motion);
  tcase_add_test(tcase, test_transition_get_motion);
  tcase_add_test(tcase, test_transition_set_angle);
  tcase_add_test(tcase, test_transition_get_angle);
  tcase_add_test(tcase, test_transition_set_scale);
  tcase_add_test(tcase, test_transition_get_scale);
  tcase_add_test(tcase, test_transition_set_rectangular);
  tcase_add_test(tcase, test_transition_is_rectangular);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("split");
  tcase_add_checked_fixture(tcase, setup_split, teardown);
  tcase_add_test(tcase, test_split_transition_set_dimension);
  tcase_add_test(tcase, test_split_transition_get_dimension);
  tcase_add_test(tcase, test_split_transition_set_motion);
  tcase_add_test(tcase, test_split_transition_get_motion);
  tcase_add_test(tcase, test_split_transition_set_angle);
  tcase_add_test(tcase, test_split_transition_get_angle);
  tcase_add_test(tcase, test_split_transition_set_scale);
  tcase_add_test(tcase, test_split_transition_get_scale);
  tcase_add_test(tcase, test_split_transition_set_rectangular);
  tcase_add_test(tcase, test_split_transition_is_rectangular);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("blinds");
  tcase_add_checked_fixture(tcase, setup_blinds, teardown);
  tcase_add_test(tcase, test_blinds_transition_set_dimension);
  tcase_add_test(tcase, test_blinds_transition_get_dimension);
  tcase_add_test(tcase, test_blinds_transition_set_motion);
  tcase_add_test(tcase, test_blinds_transition_get_motion);
  tcase_add_test(tcase, test_blinds_transition_set_angle);
  tcase_add_test(tcase, test_blinds_transition_get_angle);
  tcase_add_test(tcase, test_blinds_transition_set_scale);
  tcase_add_test(tcase, test_blinds_transition_get_scale);
  tcase_add_test(tcase, test_blinds_transition_set_rectangular);
  tcase_add_test(tcase, test_blinds_transition_is_rectangular);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("box");
  tcase_add_checked_fixture(tcase, setup_box, teardown);
  tcase_add_test(tcase, test_box_transition_set_dimension);
  tcase_add_test(tcase, test_box_transition_get_dimension);
  tcase_add_test(tcase, test_box_transition_set_motion);
  tcase_add_test(tcase, test_box_transition_get_motion);
  tcase_add_test(tcase, test_box_transition_set_angle);
  tcase_add_test(tcase, test_box_transition_get_angle);
  tcase_add_test(tcase, test_box_transition_set_scale);
  tcase_add_test(tcase, test_box_transition_get_scale);
  tcase_add_test(tcase, test_box_transition_set_rectangular);
  tcase_add_test(tcase, test_box_transition_is_rectangular);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("wipe");
  tcase_add_checked_fixture(tcase, setup_wipe, teardown);
  tcase_add_test(tcase, test_wipe_transition_set_dimension);
  tcase_add_test(tcase, test_wipe_transition_get_dimension);
  tcase_add_test(tcase, test_wipe_transition_set_motion);
  tcase_add_test(tcase, test_wipe_transition_get_motion);
  tcase_add_test(tcase, test_wipe_transition_set_angle);
  tcase_add_test(tcase, test_wipe_transition_get_angle);
  tcase_add_test(tcase, test_wipe_transition_set_scale);
  tcase_add_test(tcase, test_wipe_transition_get_scale);
  tcase_add_test(tcase, test_wipe_transition_set_rectangular);
  tcase_add_test(tcase, test_wipe_transition_is_rectangular);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("dissolve");
  tcase_add_checked_fixture(tcase, setup_dissolve, teardown);
  tcase_add_test(tcase, test_dissolve_transition_set_dimension);
  tcase_add_test(tcase, test_dissolve_transition_get_dimension);
  tcase_add_test(tcase, test_dissolve_transition_set_motion);
  tcase_add_test(tcase, test_dissolve_transition_get_motion);
  tcase_add_test(tcase, test_dissolve_transition_set_angle);
  tcase_add_test(tcase, test_dissolve_transition_get_angle);
  tcase_add_test(tcase, test_dissolve_transition_set_scale);
  tcase_add_test(tcase, test_dissolve_transition_get_scale);
  tcase_add_test(tcase, test_dissolve_transition_set_rectangular);
  tcase_add_test(tcase, test_dissolve_transition_is_rectangular);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("glitter");
  tcase_add_checked_fixture(tcase, setup_glitter, teardown);
  tcase_add_test(tcase, test_glitter_transition_set_dimension);
  tcase_add_test(tcase, test_glitter_transition_get_dimension);
  tcase_add_test(tcase, test_glitter_transition_set_motion);
  tcase_add_test(tcase, test_glitter_transition_get_motion);
  tcase_add_test(tcase, test_glitter_transition_set_angle);
  tcase_add_test(tcase, test_glitter_transition_get_angle);
  tcase_add_test(tcase, test_glitter_transition_set_scale);
  tcase_add_test(tcase, test_glitter_transition_get_scale);
  tcase_add_test(tcase, test_glitter_transition_set_rectangular);
  tcase_add_test(tcase, test_glitter_transition_is_rectangular);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("replace");
  tcase_add_checked_fixture(tcase, setup_replace, teardown);
  tcase_add_test(tcase, test_replace_transition_set_dimension);
  tcase_add_test(tcase, test_replace_transition_get_dimension);
  tcase_add_test(tcase, test_replace_transition_set_motion);
  tcase_add_test(tcase, test_replace_transition_get_motion);
  tcase_add_test(tcase, test_replace_transition_set_angle);
  tcase_add_test(tcase, test_replace_transition_get_angle);
  tcase_add_test(tcase, test_replace_transition_set_scale);
  tcase_add_test(tcase, test_replace_transition_get_scale);
  tcase_add_test(tcase, test_replace_transition_set_rectangular);
  tcase_add_test(tcase, test_replace_transition_is_rectangular);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("fly");
  tcase_add_checked_fixture(tcase, setup_fly, teardown);
  tcase_add_test(tcase, test_fly_transition_set_dimension);
  tcase_add_test(tcase, test_fly_transition_get_dimension);
  tcase_add_test(tcase, test_fly_transition_set_motion);
  tcase_add_test(tcase, test_fly_transition_get_motion);
  tcase_add_test(tcase, test_fly_transition_set_angle);
  tcase_add_test(tcase, test_fly_transition_get_angle);
  tcase_add_test(tcase, test_fly_transition_set_scale);
  tcase_add_test(tcase, test_fly_transition_get_scale);
  tcase_add_test(tcase, test_fly_transition_set_rectangular);
  tcase_add_test(tcase, test_fly_transition_is_rectangular);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("push");
  tcase_add_checked_fixture(tcase, setup_push, teardown);
  tcase_add_test(tcase, test_push_transition_set_dimension);
  tcase_add_test(tcase, test_push_transition_get_dimension);
  tcase_add_test(tcase, test_push_transition_set_motion);
  tcase_add_test(tcase, test_push_transition_get_motion);
  tcase_add_test(tcase, test_push_transition_set_angle);
  tcase_add_test(tcase, test_push_transition_get_angle);
  tcase_add_test(tcase, test_push_transition_set_scale);
  tcase_add_test(tcase, test_push_transition_get_scale);
  tcase_add_test(tcase, test_push_transition_set_rectangular);
  tcase_add_test(tcase, test_push_transition_is_rectangular);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("cover");
  tcase_add_checked_fixture(tcase, setup_cover, teardown);
  tcase_add_test(tcase, test_cover_transition_set_dimension);
  tcase_add_test(tcase, test_cover_transition_get_dimension);
  tcase_add_test(tcase, test_cover_transition_set_motion);
  tcase_add_test(tcase, test_cover_transition_get_motion);
  tcase_add_test(tcase, test_cover_transition_set_angle);
  tcase_add_test(tcase, test_cover_transition_get_angle);
  tcase_add_test(tcase, test_cover_transition_set_scale);
  tcase_add_test(tcase, test_cover_transition_get_scale);
  tcase_add_test(tcase, test_cover_transition_set_rectangular);
  tcase_add_test(tcase, test_cover_transition_is_rectangular);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("uncover");
  tcase_add_checked_fixture(tcase, setup_uncover, teardown);
  tcase_add_test(tcase, test_uncover_transition_set_dimension);
  tcase_add_test(tcase, test_uncover_transition_get_dimension);
  tcase_add_test(tcase, test_uncover_transition_set_motion);
  tcase_add_test(tcase, test_uncover_transition_get_motion);
  tcase_add_test(tcase, test_uncover_transition_set_angle);
  tcase_add_test(tcase, test_uncover_transition_get_angle);
  tcase_add_test(tcase, test_uncover_transition_set_scale);
  tcase_add_test(tcase, test_uncover_transition_get_scale);
  tcase_add_test(tcase, test_uncover_transition_set_rectangular);
  tcase_add_test(tcase, test_uncover_transition_is_rectangular);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("fade");
  tcase_add_checked_fixture(tcase, setup_fade, teardown);
  tcase_add_test(tcase, test_fade_transition_set_dimension);
  tcase_add_test(tcase, test_fade_transition_get_dimension);
  tcase_add_test(tcase, test_fade_transition_set_motion);
  tcase_add_test(tcase, test_fade_transition_get_motion);
  tcase_add_test(tcase, test_fade_transition_set_angle);
  tcase_add_test(tcase, test_fade_transition_get_angle);
  tcase_add_test(tcase, test_fade_transition_set_scale);
  tcase_add_test(tcase, test_fade_transition_get_scale);
  tcase_add_test(tcase, test_fade_transition_set_rectangular);
  tcase_add_test(tcase, test_fade_transition_is_rectangular);
  suite_add_tcase(suite, tcase);

  return suite;
}

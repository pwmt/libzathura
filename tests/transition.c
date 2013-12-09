/* See LICENSE file for license and copyright information */

#include <check.h>
#include <fiu.h>
#include <stdio.h>
#include <limits.h>

#include "transition.h"
#include "plugin-api.h"

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
} END_TEST

START_TEST(test_transition_get_duration) {
} END_TEST

START_TEST(test_transition_set_dimension) {
} END_TEST

START_TEST(test_transition_get_dimension) {
} END_TEST

START_TEST(test_transition_set_motion) {
} END_TEST

START_TEST(test_transition_get_motion) {
} END_TEST

START_TEST(test_transition_set_angle) {
} END_TEST

START_TEST(test_transition_get_angle) {
} END_TEST

START_TEST(test_transition_set_scale) {
} END_TEST

START_TEST(test_transition_get_scale) {
} END_TEST

START_TEST(test_transition_set_rectangular) {
} END_TEST

START_TEST(test_transition_is_rectangular) {
} END_TEST

Suite*
suite_transition(void)
{
  TCase* tcase = NULL;
  Suite* suite = suite_create("transition");

  tcase = tcase_create("basic");
  tcase_add_test(tcase, test_transition_free);
  tcase_add_test(tcase, test_transition_new);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("properties");
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

  return suite;
}

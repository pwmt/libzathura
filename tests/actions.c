/* See LICENSE file for license and copyright information */

#include <check.h>
#include <limits.h>
#include <fiu.h>
#include <fiu-control.h>

#include "action.h"
#include "plugin-api.h"
#include "plugin-api/action.h"

zathura_action_t* action;

static void setup(void) {
  fail_unless(zathura_action_new(&action, ZATHURA_ACTION_UNKNOWN) == ZATHURA_ERROR_OK);
  fail_unless(action != NULL);
}

static void teardown(void) {
  fail_unless(zathura_action_free(action) == ZATHURA_ERROR_OK);
  action = NULL;
}

START_TEST(test_action_free) {
  /* basic invalid arguments */
  fail_unless(zathura_action_free(NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_action_new) {
  zathura_action_t* action;

  /* basic invalid arguments */
  fail_unless(zathura_action_new(NULL, 0) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_action_new(&action, INT_MAX) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_action_new(&action, ZATHURA_ACTION_UNKNOWN) == ZATHURA_ERROR_OK);
  fail_unless(zathura_action_free(action) == ZATHURA_ERROR_OK);

  /* fault injection */
  fiu_enable("libc/mm/calloc", 1, NULL, 0);
  fail_unless(zathura_action_new(&action, ZATHURA_ACTION_UNKNOWN) == ZATHURA_ERROR_OUT_OF_MEMORY);
  fiu_disable("libc/mm/calloc");
} END_TEST

START_TEST(test_action_get_type) {
  zathura_action_type_t type;

  /* invalid arguments */
  fail_unless(zathura_action_get_type(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_action_get_type(action, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_action_get_type(NULL, &type) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_action_get_type(action, &type) == ZATHURA_ERROR_OK);
  fail_unless(type == ZATHURA_ACTION_UNKNOWN);
} END_TEST

#include "actions/action-goto.c"

Suite*
suite_actions(void)
{
  TCase* tcase = NULL;
  Suite* suite = suite_create("actions");

  tcase = tcase_create("basic");
  tcase_add_checked_fixture(tcase, setup, teardown);
  tcase_add_test(tcase, test_action_free);
  tcase_add_test(tcase, test_action_new);
  tcase_add_test(tcase, test_action_get_type);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("goto");
  tcase_add_checked_fixture(tcase, setup_action_goto, teardown);
  tcase_add_test(tcase, test_action_goto_new);
  tcase_add_test(tcase, test_action_goto_get_type);
  tcase_add_test(tcase, test_action_goto_init);
  tcase_add_test(tcase, test_action_goto_clear);
  suite_add_tcase(suite, tcase);

  return suite;
}

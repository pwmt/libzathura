/* See LICENSE file for license and copyright information */

#include <check.h>

#include "action.h"

static void setup_action_launch(void) {
  fail_unless(zathura_action_new(&action, ZATHURA_ACTION_LAUNCH) == ZATHURA_ERROR_OK);
  fail_unless(action != NULL);
}

START_TEST(test_action_launch_new) {
} END_TEST

START_TEST(test_action_launch_get_type) {
  zathura_action_type_t type;
  fail_unless(zathura_action_get_type(action, &type) == ZATHURA_ERROR_OK);
  fail_unless(type == ZATHURA_ACTION_LAUNCH);
} END_TEST

START_TEST(test_action_launch_init) {
  /* invalid arguments */
  fail_unless(zathura_action_launch_init(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_action_launch_init(action)
      == ZATHURA_ERROR_OK); // double initialization

  /* fault injection */
  fiu_enable("libc/mm/calloc", 1, NULL, 0);
  fail_unless(zathura_action_launch_init(action)
      == ZATHURA_ERROR_OUT_OF_MEMORY); // double initialization
  fiu_disable("libc/mm/calloc");
} END_TEST

START_TEST(test_action_launch_clear) {
  /* invalid arguments */
  fail_unless(zathura_action_launch_clear(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_action_launch_clear(action)
      == ZATHURA_ERROR_OK);
} END_TEST
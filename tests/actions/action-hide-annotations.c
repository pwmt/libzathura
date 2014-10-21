/* See LICENSE file for license and copyright information */

#include <check.h>

#include "action.h"

static void setup_action_hide_annotations(void) {
  fail_unless(zathura_action_new(&action, ZATHURA_ACTION_HIDE_ANNOTATIONS) == ZATHURA_ERROR_OK);
  fail_unless(action != NULL);
}

START_TEST(test_action_hide_annotations_new) {
} END_TEST

START_TEST(test_action_hide_annotations_get_type) {
  zathura_action_type_t type;
  fail_unless(zathura_action_get_type(action, &type) == ZATHURA_ERROR_OK);
  fail_unless(type == ZATHURA_ACTION_HIDE_ANNOTATIONS);
} END_TEST

START_TEST(test_action_hide_annotations_init) {
  /* invalid arguments */
  fail_unless(zathura_action_hide_annotations_init(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_action_hide_annotations_init(action)
      == ZATHURA_ERROR_OK); // double initialization

  /* fault injection */
  fiu_enable("libc/mm/calloc", 1, NULL, 0);
  fail_unless(zathura_action_hide_annotations_init(action)
      == ZATHURA_ERROR_OUT_OF_MEMORY); // double initialization
  fiu_disable("libc/mm/calloc");
} END_TEST

START_TEST(test_action_hide_annotations_clear) {
  /* invalid arguments */
  fail_unless(zathura_action_hide_annotations_clear(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_action_hide_annotations_clear(action)
      == ZATHURA_ERROR_OK);
} END_TEST
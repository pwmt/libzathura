/* See LICENSE file for license and copyright information */

#include <check.h>

#include <libzathura/action.h>

static void setup_action_goto_3d_view(void) {
  fail_unless(zathura_action_new(&action, ZATHURA_ACTION_GOTO_3D_VIEW) == ZATHURA_ERROR_OK);
  fail_unless(action != NULL);
}

START_TEST(test_action_goto_3d_view_new) {
} END_TEST

START_TEST(test_action_goto_3d_view_get_type) {
  zathura_action_type_t type;
  fail_unless(zathura_action_get_type(action, &type) == ZATHURA_ERROR_OK);
  fail_unless(type == ZATHURA_ACTION_GOTO_3D_VIEW);
} END_TEST

START_TEST(test_action_goto_3d_view_init) {
  /* invalid arguments */
  fail_unless(zathura_action_goto_3d_view_init(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  zathura_action_t* action_unknown;
  fail_unless(zathura_action_new(&action_unknown, ZATHURA_ACTION_UNKNOWN) == ZATHURA_ERROR_OK);
  fail_unless(action_unknown != NULL);
  fail_unless(zathura_action_goto_3d_view_init(action_unknown) == ZATHURA_ERROR_ACTION_INVALID_TYPE);
  fail_unless(zathura_action_free(action_unknown) == ZATHURA_ERROR_OK);

  /* valid arguments */
  fail_unless(zathura_action_goto_3d_view_init(action)
      == ZATHURA_ERROR_OK); // double initialization

  /* fault injection */
#ifdef WITH_LIBFIU
  fiu_enable("libc/mm/calloc", 1, NULL, 0);
  fail_unless(zathura_action_goto_3d_view_init(action)
      == ZATHURA_ERROR_OUT_OF_MEMORY); // double initialization
  fiu_disable("libc/mm/calloc");
#endif
} END_TEST

START_TEST(test_action_goto_3d_view_clear) {
  /* invalid arguments */
  fail_unless(zathura_action_goto_3d_view_clear(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  zathura_action_t* action_unknown;
  fail_unless(zathura_action_new(&action_unknown, ZATHURA_ACTION_UNKNOWN) == ZATHURA_ERROR_OK);
  fail_unless(action_unknown != NULL);
  fail_unless(zathura_action_goto_3d_view_clear(action_unknown) == ZATHURA_ERROR_ACTION_INVALID_TYPE);
  fail_unless(zathura_action_free(action_unknown) == ZATHURA_ERROR_OK);

  /* valid arguments */
  fail_unless(zathura_action_goto_3d_view_clear(action)
      == ZATHURA_ERROR_OK);
} END_TEST

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

#include "actions/action-goto-3d-view.c"
#include "actions/action-goto.c"
#include "actions/action-goto-embedded.c"
#include "actions/action-goto-remote.c"
#include "actions/action-hide-annotations.c"
#include "actions/action-launch.c"
#include "actions/action-movie.c"
#include "actions/action-named.c"
#include "actions/action-rendition.c"
#include "actions/action-set-ocg-state.c"
#include "actions/action-sound.c"
#include "actions/action-thread.c"
#include "actions/action-transition.c"
#include "actions/action-uri.c"

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

  tcase = tcase_create("goto_3d_view");
  tcase_add_checked_fixture(tcase, setup_action_goto_3d_view, teardown);
  tcase_add_test(tcase, test_action_goto_3d_view_new);
  tcase_add_test(tcase, test_action_goto_3d_view_get_type);
  tcase_add_test(tcase, test_action_goto_3d_view_init);
  tcase_add_test(tcase, test_action_goto_3d_view_clear);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("goto");
  tcase_add_checked_fixture(tcase, setup_action_goto, teardown);
  tcase_add_test(tcase, test_action_goto_new);
  tcase_add_test(tcase, test_action_goto_get_type);
  tcase_add_test(tcase, test_action_goto_init);
  tcase_add_test(tcase, test_action_goto_clear);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("goto_embedded");
  tcase_add_checked_fixture(tcase, setup_action_goto_embedded, teardown);
  tcase_add_test(tcase, test_action_goto_embedded_new);
  tcase_add_test(tcase, test_action_goto_embedded_get_type);
  tcase_add_test(tcase, test_action_goto_embedded_init);
  tcase_add_test(tcase, test_action_goto_embedded_clear);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("goto_remote");
  tcase_add_checked_fixture(tcase, setup_action_goto_remote, teardown);
  tcase_add_test(tcase, test_action_goto_remote_new);
  tcase_add_test(tcase, test_action_goto_remote_get_type);
  tcase_add_test(tcase, test_action_goto_remote_init);
  tcase_add_test(tcase, test_action_goto_remote_clear);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("hide_annotations");
  tcase_add_checked_fixture(tcase, setup_action_hide_annotations, teardown);
  tcase_add_test(tcase, test_action_hide_annotations_new);
  tcase_add_test(tcase, test_action_hide_annotations_get_type);
  tcase_add_test(tcase, test_action_hide_annotations_init);
  tcase_add_test(tcase, test_action_hide_annotations_clear);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("launch");
  tcase_add_checked_fixture(tcase, setup_action_launch, teardown);
  tcase_add_test(tcase, test_action_launch_new);
  tcase_add_test(tcase, test_action_launch_get_type);
  tcase_add_test(tcase, test_action_launch_init);
  tcase_add_test(tcase, test_action_launch_clear);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("movie");
  tcase_add_checked_fixture(tcase, setup_action_movie, teardown);
  tcase_add_test(tcase, test_action_movie_new);
  tcase_add_test(tcase, test_action_movie_get_type);
  tcase_add_test(tcase, test_action_movie_init);
  tcase_add_test(tcase, test_action_movie_clear);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("movie");
  tcase_add_checked_fixture(tcase, setup_action_movie, teardown);
  tcase_add_test(tcase, test_action_movie_new);
  tcase_add_test(tcase, test_action_movie_get_type);
  tcase_add_test(tcase, test_action_movie_init);
  tcase_add_test(tcase, test_action_movie_clear);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("named");
  tcase_add_checked_fixture(tcase, setup_action_named, teardown);
  tcase_add_test(tcase, test_action_named_new);
  tcase_add_test(tcase, test_action_named_get_type);
  tcase_add_test(tcase, test_action_named_init);
  tcase_add_test(tcase, test_action_named_clear);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("rendition");
  tcase_add_checked_fixture(tcase, setup_action_rendition, teardown);
  tcase_add_test(tcase, test_action_rendition_new);
  tcase_add_test(tcase, test_action_rendition_get_type);
  tcase_add_test(tcase, test_action_rendition_init);
  tcase_add_test(tcase, test_action_rendition_clear);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("set_ocg_state");
  tcase_add_checked_fixture(tcase, setup_action_set_ocg_state, teardown);
  tcase_add_test(tcase, test_action_set_ocg_state_new);
  tcase_add_test(tcase, test_action_set_ocg_state_get_type);
  tcase_add_test(tcase, test_action_set_ocg_state_init);
  tcase_add_test(tcase, test_action_set_ocg_state_clear);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("sound");
  tcase_add_checked_fixture(tcase, setup_action_sound, teardown);
  tcase_add_test(tcase, test_action_sound_new);
  tcase_add_test(tcase, test_action_sound_get_type);
  tcase_add_test(tcase, test_action_sound_init);
  tcase_add_test(tcase, test_action_sound_clear);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("thread");
  tcase_add_checked_fixture(tcase, setup_action_thread, teardown);
  tcase_add_test(tcase, test_action_thread_new);
  tcase_add_test(tcase, test_action_thread_get_type);
  tcase_add_test(tcase, test_action_thread_init);
  tcase_add_test(tcase, test_action_thread_clear);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("transition");
  tcase_add_checked_fixture(tcase, setup_action_transition, teardown);
  tcase_add_test(tcase, test_action_transition_new);
  tcase_add_test(tcase, test_action_transition_get_type);
  tcase_add_test(tcase, test_action_transition_init);
  tcase_add_test(tcase, test_action_transition_clear);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("uri");
  tcase_add_checked_fixture(tcase, setup_action_uri, teardown);
  tcase_add_test(tcase, test_action_uri_new);
  tcase_add_test(tcase, test_action_uri_get_type);
  tcase_add_test(tcase, test_action_uri_init);
  tcase_add_test(tcase, test_action_uri_clear);
  suite_add_tcase(suite, tcase);

  return suite;
}

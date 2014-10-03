/* See LICENSE file for license and copyright information */

#include <check.h>

#include "annotations.h"

static void setup_annotation_screen(void) {
  fail_unless(zathura_annotation_new(&annotation, ZATHURA_ANNOTATION_SCREEN) == ZATHURA_ERROR_OK);
  fail_unless(annotation != NULL);
}

START_TEST(test_annotation_screen_new) {
} END_TEST

START_TEST(test_annotation_screen_get_type) {
  zathura_annotation_type_t type;
  fail_unless(zathura_annotation_get_type(annotation, &type) == ZATHURA_ERROR_OK);
  fail_unless(type == ZATHURA_ANNOTATION_SCREEN);
} END_TEST

START_TEST(test_annotation_screen_init) {
  /* invalid arguments */
  fail_unless(zathura_annotation_screen_init(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_screen_init(annotation)
      == ZATHURA_ERROR_OK); // double initialization

  /* fault injection */
  fiu_enable("libc/mm/calloc", 1, NULL, 0);
  fail_unless(zathura_annotation_screen_init(annotation)
      == ZATHURA_ERROR_OUT_OF_MEMORY); // double initialization
  fiu_disable("libc/mm/calloc");
} END_TEST

START_TEST(test_annotation_screen_clear) {
  /* invalid arguments */
  fail_unless(zathura_annotation_screen_clear(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_annotation_screen_set_title) {
  /* invalid arguments */
  fail_unless(zathura_annotation_screen_set_title(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_screen_set_title(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_screen_set_title(NULL, "title") == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_screen_set_title(annotation, "title") == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_screen_set_title(annotation, "") == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_screen_get_title) {
  char* title = NULL;

  /* invalid arguments */
  fail_unless(zathura_annotation_screen_get_title(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_screen_get_title(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_screen_get_title(NULL, &title) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_screen_get_title(annotation, &title) == ZATHURA_ERROR_OK);
  fail_unless(title == NULL);
  fail_unless(zathura_annotation_screen_set_title(annotation, "title") == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_screen_get_title(annotation, &title) == ZATHURA_ERROR_OK);
  fail_unless(title != NULL);
  fail_unless(strcmp(title, "title") == 0);
} END_TEST

START_TEST(test_annotation_screen_set_action) {
  zathura_action_t* action;

  /* invalid arguments */
  fail_unless(zathura_annotation_screen_set_action(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_screen_set_action(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_screen_set_action(NULL, action) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_screen_set_action(annotation, action) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_screen_get_action) {
  zathura_action_t* action;

  /* invalid arguments */
  fail_unless(zathura_annotation_screen_get_action(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_screen_get_action(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_screen_get_action(NULL, &action) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_screen_get_action(annotation, &action) == ZATHURA_ERROR_OK);
} END_TEST

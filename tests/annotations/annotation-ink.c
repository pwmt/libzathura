/* See LICENSE file for license and copyright information */

#include <check.h>

#include "annotations.h"

static void setup_annotation_ink(void) {
  fail_unless(zathura_annotation_new(&annotation, ZATHURA_ANNOTATION_INK) == ZATHURA_ERROR_OK);
  fail_unless(annotation != NULL);
}

START_TEST(test_annotation_ink_new) {
} END_TEST

START_TEST(test_annotation_ink_init) {
  /* invalid arguments */
  fail_unless(zathura_annotation_ink_init(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_ink_init(annotation)
      == ZATHURA_ERROR_OK); // double initialization

  /* fault injection */
  fiu_enable("libc/mm/calloc", 1, NULL, 0);
  fail_unless(zathura_annotation_ink_init(annotation)
      == ZATHURA_ERROR_OUT_OF_MEMORY); // double initialization
  fiu_disable("libc/mm/calloc");
} END_TEST

START_TEST(test_annotation_ink_clear) {
  /* invalid arguments */
  fail_unless(zathura_annotation_ink_clear(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_annotation_ink_get_type) {
  zathura_annotation_type_t type;
  fail_unless(zathura_annotation_get_type(annotation, &type) == ZATHURA_ERROR_OK);
  fail_unless(type == ZATHURA_ANNOTATION_INK);
} END_TEST

START_TEST(test_annotation_ink_set_paths) {
  zathura_list_t* paths = zathura_list_alloc();
  fail_unless(paths != NULL);

  /* invalid arguments */
  fail_unless(zathura_annotation_ink_set_paths(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_ink_set_paths(NULL, paths) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_ink_set_paths(annotation, paths) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_ink_set_paths(annotation, NULL) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_ink_get_paths) {
  zathura_list_t* paths;

  /* invalid arguments */
  fail_unless(zathura_annotation_ink_get_paths(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_ink_get_paths(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_ink_get_paths(NULL, &paths) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_ink_get_paths(annotation, &paths) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_ink_set_border) {
  zathura_annotation_border_t border = { 0 };

  /* invalid arguments */
  fail_unless(zathura_annotation_ink_set_border(NULL, border) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_ink_set_border(annotation, border) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_ink_get_border) {
  zathura_annotation_border_t border = { 0,
    ZATHURA_ANNOTATION_BORDER_STYLE_SOLID, { NULL, 0 },
    ZATHURA_ANNOTATION_BORDER_EFFECT_NONE, 0.0 };
  zathura_annotation_border_t border_input = { 0,
    ZATHURA_ANNOTATION_BORDER_STYLE_SOLID, { NULL, 0 },
    ZATHURA_ANNOTATION_BORDER_EFFECT_NONE, 0.0 };

  /* invalid arguments */
  fail_unless(zathura_annotation_ink_get_border(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_ink_get_border(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_ink_get_border(NULL, &border) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_ink_get_border(annotation, &border) == ZATHURA_ERROR_OK);

  fail_unless(zathura_annotation_ink_set_border(annotation, border_input) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_ink_get_border(annotation, &border) == ZATHURA_ERROR_OK);
} END_TEST

/* See LICENSE stamp for license and copyright information */

#include <check.h>

#include "annotations.h"

static void setup_annotation_stamp(void) {
  fail_unless(zathura_annotation_new(&annotation, ZATHURA_ANNOTATION_STAMP) == ZATHURA_ERROR_OK);
  fail_unless(annotation != NULL);
}

START_TEST(test_annotation_stamp_new) {
} END_TEST

START_TEST(test_annotation_stamp_get_type) {
  zathura_annotation_type_t type;
  fail_unless(zathura_annotation_get_type(annotation, &type) == ZATHURA_ERROR_OK);
  fail_unless(type == ZATHURA_ANNOTATION_STAMP);
} END_TEST

START_TEST(test_annotation_stamp_init) {
  /* invalid arguments */
  fail_unless(zathura_annotation_stamp_init(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_stamp_init(annotation)
      == ZATHURA_ERROR_OK); // double initialization

  /* fault injection */
  fiu_enable("libc/mm/calloc", 1, NULL, 0);
  fail_unless(zathura_annotation_stamp_init(annotation)
      == ZATHURA_ERROR_OUT_OF_MEMORY); // double initialization
  fiu_disable("libc/mm/calloc");
} END_TEST

START_TEST(test_annotation_stamp_clear) {
  /* invalid arguments */
  fail_unless(zathura_annotation_stamp_clear(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_annotation_stamp_set_icon_name) {
  /* invalid arguments */
  fail_unless(zathura_annotation_stamp_set_icon_name(NULL, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_stamp_set_icon_name(annotation, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_stamp_set_icon_name(NULL, "test")
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_stamp_set_icon_name(annotation, "test")
      == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_stamp_set_icon_name(annotation, "test")
      == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_stamp_get_icon_name) {
  char* icon_name = NULL;

  /* invalid arguments */
  fail_unless(zathura_annotation_stamp_get_icon_name(NULL, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_stamp_get_icon_name(annotation, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_stamp_get_icon_name(NULL, &icon_name)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_stamp_get_icon_name(annotation, &icon_name)
      == ZATHURA_ERROR_OK);
  fail_unless(icon_name == NULL);
  fail_unless(zathura_annotation_stamp_set_icon_name(annotation, "test")
      == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_stamp_get_icon_name(annotation, &icon_name)
      == ZATHURA_ERROR_OK);
  fail_unless(g_strcmp0(icon_name, "test") == 0);
} END_TEST

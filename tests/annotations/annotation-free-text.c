/* See LICENSE file for license and copyright information */

#include <check.h>

#include "annotations.h"

static void setup_annotation_free_text(void) {
  fail_unless(zathura_annotation_new(&annotation, ZATHURA_ANNOTATION_FREE_TEXT) == ZATHURA_ERROR_OK);
  fail_unless(annotation != NULL);
}

START_TEST(test_annotation_free_text_new) {
} END_TEST

START_TEST(test_annotation_free_text_get_type) {
  zathura_annotation_type_t type;
  fail_unless(zathura_annotation_get_type(annotation, &type) == ZATHURA_ERROR_OK);
  fail_unless(type == ZATHURA_ANNOTATION_FREE_TEXT);
} END_TEST

START_TEST(test_annotation_free_text_init) {
  /* invalid arguments */
  fail_unless(zathura_annotation_free_text_init(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_free_text_init(annotation)
      == ZATHURA_ERROR_OK); // double initialization

  /* fault injection */
  fiu_enable("libc/mm/calloc", 1, NULL, 0);
  fail_unless(zathura_annotation_free_text_init(annotation)
      == ZATHURA_ERROR_OUT_OF_MEMORY); // double initialization
  fiu_disable("libc/mm/calloc");
} END_TEST

START_TEST(test_annotation_free_text_clear) {
  /* invalid arguments */
  fail_unless(zathura_annotation_free_text_clear(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_annotation_free_text_set_text) {
  /* invalid arguments */
  fail_unless(zathura_annotation_free_text_set_text(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_free_text_set_text(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_free_text_set_text(NULL, "text") == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_free_text_set_text(annotation, "text") == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_free_text_set_text(annotation, "") == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_free_text_get_text) {
} END_TEST

START_TEST(test_annotation_free_text_set_justification) {
} END_TEST

START_TEST(test_annotation_free_text_get_justification) {
} END_TEST

START_TEST(test_annotation_free_text_set_rich_text) {
  /* invalid arguments */
  fail_unless(zathura_annotation_free_text_set_rich_text(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_free_text_set_rich_text(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_free_text_set_rich_text(NULL, "text") == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_free_text_set_rich_text(annotation, "text") == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_free_text_set_rich_text(annotation, "") == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_free_text_get_rich_text) {
} END_TEST

START_TEST(test_annotation_free_text_set_style_string) {
} END_TEST

START_TEST(test_annotation_free_text_get_style_string) {
} END_TEST

START_TEST(test_annotation_free_text_set_callout_line) {
} END_TEST

START_TEST(test_annotation_free_text_get_callout_line) {
} END_TEST

START_TEST(test_annotation_free_text_set_border) {
} END_TEST

START_TEST(test_annotation_free_text_get_border) {
} END_TEST

START_TEST(test_annotation_free_text_set_intent) {
} END_TEST

START_TEST(test_annotation_free_text_get_intent) {
} END_TEST

START_TEST(test_annotation_free_text_set_padding) {
} END_TEST

START_TEST(test_annotation_free_text_get_padding) {
} END_TEST

START_TEST(test_annotation_free_text_set_line_ending) {
} END_TEST

START_TEST(test_annotation_free_text_get_line_ending) {
} END_TEST

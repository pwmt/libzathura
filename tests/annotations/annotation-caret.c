/* See LICENSE file for license and copyright information */

#include <check.h>
#include <limits.h>

#include "annotations.h"

static void setup_annotation_caret(void) {
  fail_unless(zathura_annotation_new(&annotation, ZATHURA_ANNOTATION_CARET) == ZATHURA_ERROR_OK);
  fail_unless(annotation != NULL);
}

START_TEST(test_annotation_caret_new) {
} END_TEST

START_TEST(test_annotation_caret_init) {
  /* invalid arguments */
  fail_unless(zathura_annotation_caret_init(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_caret_init(annotation)
      == ZATHURA_ERROR_OK); // double initialization

  /* fault injection */
  fiu_enable("libc/mm/calloc", 1, NULL, 0);
  fail_unless(zathura_annotation_caret_init(annotation)
      == ZATHURA_ERROR_OUT_OF_MEMORY); // double initialization
  fiu_disable("libc/mm/calloc");
} END_TEST

START_TEST(test_annotation_caret_clear) {
  /* invalid arguments */
  fail_unless(zathura_annotation_caret_clear(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_annotation_caret_get_type) {
  zathura_annotation_type_t type;
  fail_unless(zathura_annotation_get_type(annotation, &type) == ZATHURA_ERROR_OK);
  fail_unless(type == ZATHURA_ANNOTATION_CARET);
} END_TEST

START_TEST(test_annotation_caret_set_symbol) {
  /* invalid arguments */
  fail_unless(zathura_annotation_caret_set_symbol(NULL, ZATHURA_ANNOTATION_CARET_SYMBOL_NONE)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_caret_set_symbol(annotation, INT_MAX)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_caret_set_symbol(annotation, ZATHURA_ANNOTATION_CARET_SYMBOL_NONE)
      == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_caret_set_symbol(annotation, ZATHURA_ANNOTATION_CARET_SYMBOL_PARAGRAPH)
      == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_caret_get_symbol) {
  zathura_annotation_caret_symbol_t symbol;

  /* invalid arguments */
  fail_unless(zathura_annotation_caret_get_symbol(NULL, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_caret_get_symbol(NULL, &symbol)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_caret_get_symbol(annotation, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_caret_get_symbol(annotation, &symbol)
      == ZATHURA_ERROR_OK);
  fail_unless(symbol == ZATHURA_ANNOTATION_CARET_SYMBOL_NONE);

  fail_unless(zathura_annotation_caret_set_symbol(annotation, ZATHURA_ANNOTATION_CARET_SYMBOL_PARAGRAPH)
      == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_caret_get_symbol(annotation, &symbol)
      == ZATHURA_ERROR_OK);
  fail_unless(symbol == ZATHURA_ANNOTATION_CARET_SYMBOL_PARAGRAPH);
} END_TEST

START_TEST(test_annotation_caret_set_padding) {
  zathura_annotation_caret_padding_t padding = { 0, 0, 0, 0 };

  /* invalid arguments */
  fail_unless(zathura_annotation_caret_set_padding(NULL, padding)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_caret_set_padding(annotation, padding)
      == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_caret_get_padding) {
  zathura_annotation_caret_padding_t padding = { 1, 1, 1, 1 };

  /* invalid arguments */
  fail_unless(zathura_annotation_caret_get_padding(NULL, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_caret_get_padding(annotation, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_caret_get_padding(NULL, &padding)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_caret_get_padding(annotation, &padding)
      == ZATHURA_ERROR_OK);
  fail_unless(padding.left == 0);
  fail_unless(padding.top == 0);
  fail_unless(padding.right == 0);
  fail_unless(padding.bottom == 0);

  zathura_annotation_caret_padding_t padding_in = { 1, 2, 3, 4 };

  fail_unless(zathura_annotation_caret_set_padding(annotation, padding_in)
      == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_caret_get_padding(annotation, &padding)
      == ZATHURA_ERROR_OK);
  fail_unless(padding.left == 1);
  fail_unless(padding.top == 2);
  fail_unless(padding.right == 3);
  fail_unless(padding.bottom == 4);
} END_TEST


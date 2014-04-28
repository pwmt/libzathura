/* See LICENSE file for license and copyright information */

#include <check.h>

#include "annotations.h"

static void setup_annotation_markup(void) {
  fail_unless(zathura_annotation_new(&annotation, ZATHURA_ANNOTATION_TEXT) == ZATHURA_ERROR_OK);
  fail_unless(annotation != NULL);
}

START_TEST(test_annotation_markup_new) {
} END_TEST

START_TEST(test_annotation_is_markup_annotation) {
  zathura_annotation_t* markup_annotation;
  bool is_markup_annotation;

  /* invalid arguments */
  fail_unless(zathura_annotation_is_markup_annotation(NULL, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_is_markup_annotation(markup_annotation, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_is_markup_annotation(NULL, &is_markup_annotation)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
#define TEST_IS_MARKUP_ANNOTATION(type, result) \
  fail_unless(zathura_annotation_new(&markup_annotation, (type)) \
      == ZATHURA_ERROR_OK); \
  fail_unless(markup_annotation != NULL); \
  fail_unless(zathura_annotation_is_markup_annotation(markup_annotation, &is_markup_annotation) \
      == ZATHURA_ERROR_OK); \
  fail_unless(is_markup_annotation == (result)); \
  fail_unless(zathura_annotation_free(markup_annotation) == ZATHURA_ERROR_OK); \
  markup_annotation = NULL;

  TEST_IS_MARKUP_ANNOTATION(ZATHURA_ANNOTATION_UNKNOWN,         false)
  TEST_IS_MARKUP_ANNOTATION(ZATHURA_ANNOTATION_TEXT,            true)
  TEST_IS_MARKUP_ANNOTATION(ZATHURA_ANNOTATION_LINK,            false)
  TEST_IS_MARKUP_ANNOTATION(ZATHURA_ANNOTATION_FREE_TEXT,       true)
  TEST_IS_MARKUP_ANNOTATION(ZATHURA_ANNOTATION_LINE,            true)
  TEST_IS_MARKUP_ANNOTATION(ZATHURA_ANNOTATION_SQUARE,          true)
  TEST_IS_MARKUP_ANNOTATION(ZATHURA_ANNOTATION_CIRCLE,          true)
  TEST_IS_MARKUP_ANNOTATION(ZATHURA_ANNOTATION_POLYGON,         true)
  TEST_IS_MARKUP_ANNOTATION(ZATHURA_ANNOTATION_POLY_LINE,       true)
  TEST_IS_MARKUP_ANNOTATION(ZATHURA_ANNOTATION_HIGHLIGHT,       true)
  TEST_IS_MARKUP_ANNOTATION(ZATHURA_ANNOTATION_UNDERLINE,       true)
  TEST_IS_MARKUP_ANNOTATION(ZATHURA_ANNOTATION_SQUIGGLY,        true)
  TEST_IS_MARKUP_ANNOTATION(ZATHURA_ANNOTATION_STRIKE_OUT,      true)
  TEST_IS_MARKUP_ANNOTATION(ZATHURA_ANNOTATION_STAMP,           true)
  TEST_IS_MARKUP_ANNOTATION(ZATHURA_ANNOTATION_CARET,           true)
  TEST_IS_MARKUP_ANNOTATION(ZATHURA_ANNOTATION_INK,             true)
  TEST_IS_MARKUP_ANNOTATION(ZATHURA_ANNOTATION_POPUP,           false)
  TEST_IS_MARKUP_ANNOTATION(ZATHURA_ANNOTATION_FILE_ATTACHMENT, true)
  TEST_IS_MARKUP_ANNOTATION(ZATHURA_ANNOTATION_SOUND,           true)
  TEST_IS_MARKUP_ANNOTATION(ZATHURA_ANNOTATION_MOVIE,           false)
  TEST_IS_MARKUP_ANNOTATION(ZATHURA_ANNOTATION_WIDGET,          false)
  TEST_IS_MARKUP_ANNOTATION(ZATHURA_ANNOTATION_SCREEN,          false)
  TEST_IS_MARKUP_ANNOTATION(ZATHURA_ANNOTATION_PRINTER_MARK,    false)
  TEST_IS_MARKUP_ANNOTATION(ZATHURA_ANNOTATION_TRAP_NET,        false)
  TEST_IS_MARKUP_ANNOTATION(ZATHURA_ANNOTATION_WATERMARK,       false)
  TEST_IS_MARKUP_ANNOTATION(ZATHURA_ANNOTATION_3D,              false)
} END_TEST

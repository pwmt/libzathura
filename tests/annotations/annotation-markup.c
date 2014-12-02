/* See LICENSE file for license and copyright information */

#include <check.h>
#include <limits.h>

#include "annotations.h"
#include "annotations/internal.h"

static void setup_annotation_markup(void) {
  fail_unless(zathura_annotation_new(&annotation, ZATHURA_ANNOTATION_TEXT) == ZATHURA_ERROR_OK);
  fail_unless(annotation != NULL);
}

START_TEST(test_annotation_markup_init) {
  /* invalid arguments */
  fail_unless(zathura_annotation_markup_init(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_markup_init(annotation)
      == ZATHURA_ERROR_OK); // double initialization

  /* fault injection */
  fiu_enable("libc/mm/calloc", 1, NULL, 0);
  fail_unless(zathura_annotation_markup_init(annotation)
      == ZATHURA_ERROR_OUT_OF_MEMORY); // double initialization
  fiu_disable("libc/mm/calloc");
} END_TEST

START_TEST(test_annotation_markup_clear) {
  /* invalid arguments */
  fail_unless(zathura_annotation_markup_clear(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

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

  /* corrupted data */
  fail_unless(zathura_annotation_new(&markup_annotation, ZATHURA_ANNOTATION_TEXT)
      == ZATHURA_ERROR_OK);
  markup_annotation->type = INT_MAX;
  fail_unless(zathura_annotation_is_markup_annotation(markup_annotation, &is_markup_annotation)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  markup_annotation->type = ZATHURA_ANNOTATION_TEXT;
  fail_unless(zathura_annotation_free(markup_annotation) == ZATHURA_ERROR_OK);
  markup_annotation = NULL;

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

START_TEST(test_annotation_markup_set_label) {
  /* invalid arguments */
  fail_unless(zathura_annotation_markup_set_label(NULL, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_markup_set_label(annotation, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_markup_set_label(NULL, "test")
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_markup_set_label(annotation, "test")
      == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_markup_set_label(annotation, "test")
      == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_markup_get_label) {
  char* label = NULL;

  /* invalid arguments */
  fail_unless(zathura_annotation_markup_get_label(NULL, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_markup_get_label(annotation, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_markup_get_label(NULL, &label)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_markup_get_label(annotation, &label)
      == ZATHURA_ERROR_OK);
  fail_unless(label == NULL);
  fail_unless(zathura_annotation_markup_set_label(annotation, "test")
      == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_markup_get_label(annotation, &label)
      == ZATHURA_ERROR_OK);
  fail_unless(g_strcmp0(label, "test") == 0);
} END_TEST

START_TEST(test_annotation_markup_set_opacity) {
  /* invalid arguments */
  fail_unless(zathura_annotation_markup_set_opacity(NULL, 0.0)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_markup_set_opacity(annotation, -1.0)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_markup_set_opacity(annotation, 1.5)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_markup_set_opacity(annotation, 1.0)
      == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_markup_set_opacity(annotation, 0.5)
      == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_markup_set_opacity(annotation, 0.0)
      == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_markup_get_opacity) {
  double opacity = 0.0;

  /* invalid arguments */
  fail_unless(zathura_annotation_markup_get_opacity(NULL, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_markup_get_opacity(annotation, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_markup_get_opacity(NULL, &opacity)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_markup_get_opacity(annotation, &opacity)
      == ZATHURA_ERROR_OK);
  fail_unless(opacity == 1.0);

  fail_unless(zathura_annotation_markup_set_opacity(annotation, 0.5)
      == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_markup_get_opacity(annotation, &opacity)
      == ZATHURA_ERROR_OK);
  fail_unless(opacity == 0.5);
} END_TEST

START_TEST(test_annotation_markup_set_popup_annotation) {
  zathura_annotation_t* popup = (zathura_annotation_t*) 0xCAFEBABE;

  /* invalid arguments */
  fail_unless(zathura_annotation_markup_set_popup_annotation(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_markup_set_popup_annotation(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_markup_set_popup_annotation(NULL, popup) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_markup_set_popup_annotation(annotation, popup) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_markup_get_popup_annotation) {
  zathura_annotation_t* popup;

  /* invalid arguments */
  fail_unless(zathura_annotation_markup_get_popup_annotation(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_markup_get_popup_annotation(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_markup_get_popup_annotation(NULL, &popup) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_markup_get_popup_annotation(annotation, &popup) == ZATHURA_ERROR_OK);
  fail_unless(popup == NULL);

  fail_unless(zathura_annotation_markup_set_popup_annotation(annotation, (zathura_annotation_t*) 0xCAFEBABE) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_markup_get_popup_annotation(annotation, &popup) == ZATHURA_ERROR_OK);
  fail_unless(popup == (zathura_annotation_t*) 0xCAFEBABE);
} END_TEST

START_TEST(test_annotation_markup_set_text) {
  /* invalid arguments */
  fail_unless(zathura_annotation_markup_set_text(NULL, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_markup_set_text(annotation, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_markup_set_text(NULL, "test")
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_markup_set_text(annotation, "test")
      == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_markup_set_text(annotation, "test")
      == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_markup_get_text) {
  char* text = NULL;

  /* invalid arguments */
  fail_unless(zathura_annotation_markup_get_text(NULL, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_markup_get_text(annotation, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_markup_get_text(NULL, &text)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_markup_get_text(annotation, &text)
      == ZATHURA_ERROR_OK);
  fail_unless(text == NULL);
  fail_unless(zathura_annotation_markup_set_text(annotation, "test")
      == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_markup_get_text(annotation, &text)
      == ZATHURA_ERROR_OK);
  fail_unless(g_strcmp0(text, "test") == 0);
} END_TEST

START_TEST(test_annotation_markup_set_creation_date) {
  time_t creation_date = time(NULL);

  /* invalid arguments */
  fail_unless(zathura_annotation_markup_set_creation_date(NULL, creation_date) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_markup_set_creation_date(annotation, creation_date) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_markup_get_creation_date) {
  time_t creation_date = time(NULL);

  /* invalid arguments */
  fail_unless(zathura_annotation_markup_get_creation_date(NULL, NULL)               == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_markup_get_creation_date(annotation, NULL)         == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_markup_get_creation_date(NULL, &creation_date) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  time_t creation_date2;
  fail_unless(zathura_annotation_markup_set_creation_date(annotation, creation_date) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_markup_get_creation_date(annotation, &creation_date2) == ZATHURA_ERROR_OK);
  fail_unless(difftime(creation_date, creation_date2) == 0);
} END_TEST

START_TEST(test_annotation_markup_set_reply_to_annotation) {
  zathura_annotation_t* reply_to = (zathura_annotation_t*) 0xCAFEBABE;

  /* invalid arguments */
  fail_unless(zathura_annotation_markup_set_reply_to_annotation(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_markup_set_reply_to_annotation(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_markup_set_reply_to_annotation(NULL, reply_to) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_markup_set_reply_to_annotation(annotation, reply_to) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_markup_get_reply_to_annotation) {
  zathura_annotation_t* reply_to;

  /* invalid arguments */
  fail_unless(zathura_annotation_markup_get_reply_to_annotation(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_markup_get_reply_to_annotation(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_markup_get_reply_to_annotation(NULL, &reply_to) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_markup_get_reply_to_annotation(annotation, &reply_to) == ZATHURA_ERROR_OK);
  fail_unless(reply_to == NULL);

  fail_unless(zathura_annotation_markup_set_reply_to_annotation(annotation, (zathura_annotation_t*) 0xCAFEBABE) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_markup_get_reply_to_annotation(annotation, &reply_to) == ZATHURA_ERROR_OK);
  fail_unless(reply_to == (zathura_annotation_t*) 0xCAFEBABE);
} END_TEST

START_TEST(test_annotation_markup_set_reply_type) {
  zathura_annotation_markup_reply_type_t reply_type = ZATHURA_ANNOTATION_MARKUP_REPLY_TYPE_REPLY;

  /* invalid arguments */
  fail_unless(zathura_annotation_markup_set_reply_type(NULL, reply_type) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  fail_unless(zathura_annotation_markup_set_reply_type(annotation, reply_type) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_markup_get_reply_type) {
  zathura_annotation_markup_reply_type_t reply_type = ZATHURA_ANNOTATION_MARKUP_REPLY_TYPE_REPLY;

  /* invalid arguments */
  fail_unless(zathura_annotation_markup_get_reply_type(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_markup_get_reply_type(NULL, &reply_type) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_markup_get_reply_type(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  fail_unless(zathura_annotation_markup_get_reply_type(annotation, &reply_type) == ZATHURA_ERROR_OK);
  fail_unless(reply_type == ZATHURA_ANNOTATION_MARKUP_REPLY_TYPE_REPLY);

  fail_unless(zathura_annotation_markup_set_reply_type(annotation, ZATHURA_ANNOTATION_MARKUP_REPLY_TYPE_GROUP) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_markup_get_reply_type(annotation, &reply_type) == ZATHURA_ERROR_OK);
  fail_unless(reply_type == ZATHURA_ANNOTATION_MARKUP_REPLY_TYPE_GROUP);
} END_TEST

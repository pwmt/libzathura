/* See LICENSE file for license and copyright information */

#include <check.h>
#include <string.h>

#include "annotations.h"

static void setup_annotation_free_text(void) {
  setup_document_plugin(&plugin_manager, &document);

  fail_unless(zathura_document_get_page(document, 0, &page) == ZATHURA_ERROR_OK);
  fail_unless(page != NULL);

  fail_unless(zathura_annotation_new(page, &annotation, ZATHURA_ANNOTATION_FREE_TEXT) == ZATHURA_ERROR_OK);
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
  char* text = NULL;

  /* invalid arguments */
  fail_unless(zathura_annotation_free_text_get_text(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_free_text_get_text(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_free_text_get_text(NULL, &text) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_free_text_get_text(annotation, &text) == ZATHURA_ERROR_OK);
  fail_unless(text != NULL);
  fail_unless(strcmp(text, "") == 0);
  fail_unless(zathura_annotation_free_text_set_text(annotation, "text") == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_free_text_get_text(annotation, &text) == ZATHURA_ERROR_OK);
  fail_unless(text != NULL);
  fail_unless(strcmp(text, "text") == 0);
} END_TEST

START_TEST(test_annotation_free_text_set_justification) {
  zathura_annotation_justification_t justification = ZATHURA_ANNOTATION_JUSTIFICATION_CENTERED;

  /* invalid arguments */
  fail_unless(zathura_annotation_free_text_set_justification(NULL, justification) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_free_text_set_justification(annotation, justification) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_free_text_get_justification) {
  zathura_annotation_justification_t justification = ZATHURA_ANNOTATION_JUSTIFICATION_CENTERED;

  /* invalid arguments */
  fail_unless(zathura_annotation_free_text_get_justification(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_free_text_get_justification(NULL, &justification) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_free_text_get_justification(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_free_text_set_justification(annotation, justification) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_free_text_get_justification(annotation, &justification) == ZATHURA_ERROR_OK);
  fail_unless(justification == ZATHURA_ANNOTATION_JUSTIFICATION_CENTERED);
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
  char* text = NULL;

  /* invalid arguments */
  fail_unless(zathura_annotation_free_text_get_rich_text(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_free_text_get_rich_text(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_free_text_get_rich_text(NULL, &text) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_free_text_get_rich_text(annotation, &text) == ZATHURA_ERROR_OK);
  fail_unless(text != NULL);
  fail_unless(strcmp(text, "") == 0);
  fail_unless(zathura_annotation_free_text_set_rich_text(annotation, "text") == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_free_text_get_rich_text(annotation, &text) == ZATHURA_ERROR_OK);
  fail_unless(text != NULL);
  fail_unless(strcmp(text, "text") == 0);
} END_TEST

START_TEST(test_annotation_free_text_set_style_string) {
  /* invalid arguments */
  fail_unless(zathura_annotation_free_text_set_style_string(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_free_text_set_style_string(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_free_text_set_style_string(NULL, "text") == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_free_text_set_style_string(annotation, "text") == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_free_text_set_style_string(annotation, "") == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_free_text_get_style_string) {
  char* text = NULL;

  /* invalid arguments */
  fail_unless(zathura_annotation_free_text_get_style_string(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_free_text_get_style_string(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_free_text_get_style_string(NULL, &text) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_free_text_get_style_string(annotation, &text) == ZATHURA_ERROR_OK);
  fail_unless(text != NULL);
  fail_unless(strcmp(text, "") == 0);
  fail_unless(zathura_annotation_free_text_set_style_string(annotation, "text") == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_free_text_get_style_string(annotation, &text) == ZATHURA_ERROR_OK);
  fail_unless(text != NULL);
  fail_unless(strcmp(text, "text") == 0);
} END_TEST

START_TEST(test_annotation_free_text_set_callout_line) {
  zathura_point_t start = {0, 0};
  zathura_point_t knee = {0, 0};
  zathura_point_t end = {0, 0};
  zathura_annotation_callout_line_t callout_line = { start, knee, end };

  /* invalid arguments */
  fail_unless(zathura_annotation_free_text_set_callout_line(NULL, callout_line) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_free_text_set_callout_line(annotation, callout_line) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_free_text_get_callout_line) {
  zathura_annotation_callout_line_t callout_line;

  /* invalid arguments */
  fail_unless(zathura_annotation_free_text_get_callout_line(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_free_text_get_callout_line(NULL, &callout_line) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_free_text_get_callout_line(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_free_text_get_callout_line(annotation, &callout_line) == ZATHURA_ERROR_OK);
  fail_unless(callout_line.start.x == 0);
  fail_unless(callout_line.start.y == 0);
  fail_unless(callout_line.knee.x  == 0);
  fail_unless(callout_line.knee.y  == 0);
  fail_unless(callout_line.end.x   == 0);
  fail_unless(callout_line.end.y   == 0);

  zathura_point_t start = {1, 2};
  zathura_point_t knee = {3, 4};
  zathura_point_t end = {5, 6};
  zathura_annotation_callout_line_t callout_line2 = { start, knee, end };

  fail_unless(zathura_annotation_free_text_set_callout_line(annotation, callout_line2) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_free_text_get_callout_line(annotation, &callout_line) == ZATHURA_ERROR_OK);
  fail_unless(callout_line.start.x == 1);
  fail_unless(callout_line.start.y == 2);
  fail_unless(callout_line.knee.x  == 3);
  fail_unless(callout_line.knee.y  == 4);
  fail_unless(callout_line.end.x   == 5);
  fail_unless(callout_line.end.y   == 6);
} END_TEST

START_TEST(test_annotation_free_text_set_border) {
  zathura_annotation_border_t border = { 0 };

  /* invalid arguments */
  fail_unless(zathura_annotation_free_text_set_border(NULL, border) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_free_text_set_border(annotation, border) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_free_text_get_border) {
  zathura_annotation_border_t border = { 0,
    ZATHURA_ANNOTATION_BORDER_STYLE_SOLID, { NULL, 0 },
    ZATHURA_ANNOTATION_BORDER_EFFECT_NONE, 0.0 };
  zathura_annotation_border_t border_input = { 0,
    ZATHURA_ANNOTATION_BORDER_STYLE_SOLID, { NULL, 0 },
    ZATHURA_ANNOTATION_BORDER_EFFECT_NONE, 0.0 };

  /* invalid arguments */
  fail_unless(zathura_annotation_free_text_get_border(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_free_text_get_border(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_free_text_get_border(NULL, &border) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_free_text_get_border(annotation, &border) == ZATHURA_ERROR_OK);

  fail_unless(zathura_annotation_free_text_set_border(annotation, border_input) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_free_text_get_border(annotation, &border) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_free_text_set_intent) {
  zathura_annotation_markup_intent_t intent = ZATHURA_ANNOTATION_MARKUP_INTENT_NONE;

  /* invalid arguments */
  fail_unless(zathura_annotation_free_text_set_intent(NULL, intent) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  fail_unless(zathura_annotation_free_text_set_intent(annotation, intent) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_free_text_get_intent) {
  zathura_annotation_markup_intent_t intent = ZATHURA_ANNOTATION_MARKUP_INTENT_NONE;

  /* invalid arguments */
  fail_unless(zathura_annotation_free_text_get_intent(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_free_text_get_intent(NULL, &intent) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_free_text_get_intent(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  fail_unless(zathura_annotation_free_text_get_intent(annotation, &intent) == ZATHURA_ERROR_OK);
  fail_unless(intent == ZATHURA_ANNOTATION_MARKUP_INTENT_NONE);

  fail_unless(zathura_annotation_free_text_set_intent(annotation, ZATHURA_ANNOTATION_MARKUP_INTENT_FREE_TEXT_CALL_OUT) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_free_text_get_intent(annotation, &intent) == ZATHURA_ERROR_OK);
  fail_unless(intent == ZATHURA_ANNOTATION_MARKUP_INTENT_FREE_TEXT_CALL_OUT);
} END_TEST

START_TEST(test_annotation_free_text_set_padding) {
  zathura_annotation_padding_t padding = { 0, 0, 0, 0 };

  /* invalid arguments */
  fail_unless(zathura_annotation_free_text_set_padding(NULL, padding) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_free_text_set_padding(annotation, padding) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_free_text_get_padding) {
  zathura_annotation_padding_t padding = { 0, 0, 0, 0 };

  /* invalid arguments */
  fail_unless(zathura_annotation_free_text_get_padding(NULL, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_free_text_get_padding(annotation, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_free_text_get_padding(NULL, &padding)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_free_text_get_padding(annotation, &padding)
      == ZATHURA_ERROR_OK);
  fail_unless(padding.left == 0);
  fail_unless(padding.top == 0);
  fail_unless(padding.right == 0);
  fail_unless(padding.bottom == 0);

  zathura_annotation_padding_t padding_in = { 1, 2, 3, 4 };

  fail_unless(zathura_annotation_free_text_set_padding(annotation, padding_in)
      == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_free_text_get_padding(annotation, &padding)
      == ZATHURA_ERROR_OK);
  fail_unless(padding.left == 1);
  fail_unless(padding.top == 2);
  fail_unless(padding.right == 3);
  fail_unless(padding.bottom == 4);
} END_TEST

START_TEST(test_annotation_free_text_set_line_ending) {
  zathura_annotation_line_ending_t line_ending[2] = { ZATHURA_ANNOTATION_LINE_ENDING_NONE, ZATHURA_ANNOTATION_LINE_ENDING_NONE };
  fail_unless(zathura_annotation_free_text_set_line_ending(NULL, line_ending) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_free_text_set_line_ending(annotation, line_ending) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_free_text_get_line_ending) {
  zathura_annotation_line_ending_t line_ending[2] = { ZATHURA_ANNOTATION_LINE_ENDING_NONE, ZATHURA_ANNOTATION_LINE_ENDING_NONE };

  /* invalid arguments */
  fail_unless(zathura_annotation_free_text_get_line_ending(NULL, line_ending) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_free_text_get_line_ending(annotation, line_ending) == ZATHURA_ERROR_OK);

  zathura_annotation_line_ending_t line_ending2[2] = { ZATHURA_ANNOTATION_LINE_ENDING_CIRCLE, ZATHURA_ANNOTATION_LINE_ENDING_CIRCLE };
  fail_unless(zathura_annotation_free_text_set_line_ending(annotation, line_ending2) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_free_text_get_line_ending(annotation, line_ending) == ZATHURA_ERROR_OK);
  fail_unless(line_ending[0] == ZATHURA_ANNOTATION_LINE_ENDING_CIRCLE);
  fail_unless(line_ending[1] == ZATHURA_ANNOTATION_LINE_ENDING_CIRCLE);
} END_TEST

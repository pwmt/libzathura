/* See LICENSE file for license and copyright information */

#include <check.h>

#include <libzathura/annotations.h>

static void setup_annotation_line(void) {
  setup_document_plugin(&plugin_manager, &document);

  fail_unless(zathura_document_get_page(document, 0, &page) == ZATHURA_ERROR_OK);
  fail_unless(page != NULL);

  fail_unless(zathura_annotation_new(page, &annotation, ZATHURA_ANNOTATION_LINE) == ZATHURA_ERROR_OK);
  fail_unless(annotation != NULL);
}

START_TEST(test_annotation_line_new) {
} END_TEST

START_TEST(test_annotation_line_get_type) {
  zathura_annotation_type_t type;
  fail_unless(zathura_annotation_get_type(annotation, &type) == ZATHURA_ERROR_OK);
  fail_unless(type == ZATHURA_ANNOTATION_LINE);
} END_TEST

START_TEST(test_annotation_line_init) {
  /* invalid arguments */
  fail_unless(zathura_annotation_line_init(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_line_init(annotation)
      == ZATHURA_ERROR_OK); // double initialization

  /* fault injection */
#ifdef WITH_LIBFIU
  fiu_enable("libc/mm/calloc", 1, NULL, 0);
  fail_unless(zathura_annotation_line_init(annotation)
      == ZATHURA_ERROR_OUT_OF_MEMORY); // double initialization
  fiu_disable("libc/mm/calloc");
#endif
} END_TEST

START_TEST(test_annotation_line_clear) {
  /* invalid arguments */
  fail_unless(zathura_annotation_line_clear(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_annotation_line_set_coordinates) {
  zathura_point_t coordinates[2] = { {1,1}, {2,2} };
  fail_unless(zathura_annotation_line_set_coordinates(NULL, coordinates) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_line_set_coordinates(annotation, coordinates) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_line_get_coordinates) {
  zathura_point_t coordinates[2] = { {1,1}, {2,2} };

  /* invalid arguments */
  fail_unless(zathura_annotation_line_get_coordinates(NULL, coordinates) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_line_get_coordinates(annotation, coordinates) == ZATHURA_ERROR_OK);

  zathura_point_t coordinates2[2] = { {1,1}, {2,2} };
  fail_unless(zathura_annotation_line_set_coordinates(annotation, coordinates2) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_line_get_coordinates(annotation, coordinates) == ZATHURA_ERROR_OK);
  fail_unless(coordinates[0].x == 1);
  fail_unless(coordinates[0].y == 1);
  fail_unless(coordinates[1].x == 2);
  fail_unless(coordinates[1].y == 2);
} END_TEST

START_TEST(test_annotation_line_set_border) {
  zathura_annotation_border_t border = { 0,
    ZATHURA_ANNOTATION_BORDER_STYLE_SOLID, {NULL, 0},
    ZATHURA_ANNOTATION_BORDER_EFFECT_NONE, 0.0 };

  /* invalid arguments */
  fail_unless(zathura_annotation_line_set_border(NULL, border) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_line_set_border(annotation, border) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_line_get_border) {
  zathura_annotation_border_t border = { 0,
    ZATHURA_ANNOTATION_BORDER_STYLE_SOLID, {NULL, 0},
    ZATHURA_ANNOTATION_BORDER_EFFECT_NONE, 0.0 };
  zathura_annotation_border_t border_input = { 0,
    ZATHURA_ANNOTATION_BORDER_STYLE_SOLID, {NULL, 0},
    ZATHURA_ANNOTATION_BORDER_EFFECT_NONE, 0.0 };

  /* invalid arguments */
  fail_unless(zathura_annotation_line_get_border(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_line_get_border(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_line_get_border(NULL, &border) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_line_get_border(annotation, &border) == ZATHURA_ERROR_OK);

  fail_unless(zathura_annotation_line_set_border(annotation, border_input) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_line_get_border(annotation, &border) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_line_set_line_ending) {
  zathura_annotation_line_ending_t line_ending[2] = { ZATHURA_ANNOTATION_LINE_ENDING_NONE, ZATHURA_ANNOTATION_LINE_ENDING_NONE };
  fail_unless(zathura_annotation_line_set_line_ending(NULL, line_ending) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_line_set_line_ending(annotation, line_ending) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_line_get_line_ending) {
  zathura_annotation_line_ending_t line_ending[2] = { ZATHURA_ANNOTATION_LINE_ENDING_NONE, ZATHURA_ANNOTATION_LINE_ENDING_NONE };

  /* invalid arguments */
  fail_unless(zathura_annotation_line_get_line_ending(NULL, line_ending) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_line_get_line_ending(annotation, line_ending) == ZATHURA_ERROR_OK);

  zathura_annotation_line_ending_t line_ending2[2] = { ZATHURA_ANNOTATION_LINE_ENDING_CIRCLE, ZATHURA_ANNOTATION_LINE_ENDING_CIRCLE };
  fail_unless(zathura_annotation_line_set_line_ending(annotation, line_ending2) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_line_get_line_ending(annotation, line_ending) == ZATHURA_ERROR_OK);
  fail_unless(line_ending[0] == ZATHURA_ANNOTATION_LINE_ENDING_CIRCLE);
  fail_unless(line_ending[1] == ZATHURA_ANNOTATION_LINE_ENDING_CIRCLE);
} END_TEST

START_TEST(test_annotation_line_set_color) {
  zathura_annotation_color_t color = { 0 };

  /* invalid arguments */
  fail_unless(zathura_annotation_line_set_color(NULL, color) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_line_set_color(annotation, color) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_line_get_color) {
  zathura_annotation_color_t color = { ZATHURA_ANNOTATION_COLOR_SPACE_NONE, {0, 0, 0, 0} };
  zathura_annotation_color_t color_input = { ZATHURA_ANNOTATION_COLOR_SPACE_NONE, {1, 2, 3, 4} };

  /* invalid arguments */
  fail_unless(zathura_annotation_line_get_color(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_line_get_color(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_line_get_color(NULL, &color) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_line_get_color(annotation, &color) == ZATHURA_ERROR_OK);

  fail_unless(zathura_annotation_line_set_color(annotation, color_input) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_line_get_color(annotation, &color) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_line_set_leader_lines_length) {
  /* basic invalid arguments */
  fail_unless(zathura_annotation_line_set_leader_lines_length(NULL, 0) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_line_set_leader_lines_length(annotation, 0) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_line_set_leader_lines_length(annotation, 5) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_line_set_leader_lines_length(annotation, -5) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_line_get_leader_lines_length) {
  int leader_lines_length;

  /* basic invalid arguments */
  fail_unless(zathura_annotation_line_get_leader_lines_length(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_line_get_leader_lines_length(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_line_get_leader_lines_length(NULL, &leader_lines_length) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_line_get_leader_lines_length(annotation, &leader_lines_length) == ZATHURA_ERROR_OK);

  fail_unless(zathura_annotation_line_set_leader_lines_length(annotation, 5) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_line_get_leader_lines_length(annotation, &leader_lines_length) == ZATHURA_ERROR_OK);
  fail_unless(leader_lines_length == 5);

  fail_unless(zathura_annotation_line_set_leader_lines_length(annotation, -5) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_line_get_leader_lines_length(annotation, &leader_lines_length) == ZATHURA_ERROR_OK);
  fail_unless(leader_lines_length == -5);
} END_TEST

START_TEST(test_annotation_line_set_leader_line_extensions_length) {
  /* basic invalid arguments */
  fail_unless(zathura_annotation_line_set_leader_line_extensions_length(NULL, 0) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_line_set_leader_line_extensions_length(annotation, 0) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_line_set_leader_line_extensions_length(annotation, 5) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_line_set_leader_line_extensions_length(annotation, -5) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_line_get_leader_line_extensions_length) {
  unsigned int leader_line_extensions_length;

  /* basic invalid arguments */
  fail_unless(zathura_annotation_line_get_leader_line_extensions_length(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_line_get_leader_line_extensions_length(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_line_get_leader_line_extensions_length(NULL, &leader_line_extensions_length) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_line_get_leader_line_extensions_length(annotation, &leader_line_extensions_length) == ZATHURA_ERROR_OK);

  fail_unless(zathura_annotation_line_set_leader_line_extensions_length(annotation, 5) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_line_get_leader_line_extensions_length(annotation, &leader_line_extensions_length) == ZATHURA_ERROR_OK);
  fail_unless(leader_line_extensions_length == 5);
} END_TEST

START_TEST(test_annotation_line_set_leader_line_offset) {
  /* basic invalid arguments */
  fail_unless(zathura_annotation_line_set_leader_line_offset(NULL, 0) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_line_set_leader_line_offset(annotation, 0) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_line_set_leader_line_offset(annotation, 5) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_line_set_leader_line_offset(annotation, -5) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_line_get_leader_line_offset) {
  unsigned int leader_line_offset;

  /* basic invalid arguments */
  fail_unless(zathura_annotation_line_get_leader_line_offset(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_line_get_leader_line_offset(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_line_get_leader_line_offset(NULL, &leader_line_offset) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_line_get_leader_line_offset(annotation, &leader_line_offset) == ZATHURA_ERROR_OK);

  fail_unless(zathura_annotation_line_set_leader_line_offset(annotation, 5) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_line_get_leader_line_offset(annotation, &leader_line_offset) == ZATHURA_ERROR_OK);
  fail_unless(leader_line_offset == 5);
} END_TEST

START_TEST(test_annotation_line_set_caption) {
  /* invalid arguments */
  fail_unless(zathura_annotation_line_set_caption(NULL, true) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_line_set_caption(annotation, true) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_line_set_caption(annotation, false) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_line_has_caption) {
  bool has_caption = false;

  /* invalid arguments */
  fail_unless(zathura_annotation_line_has_caption(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_line_has_caption(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_line_has_caption(NULL, &has_caption) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_line_has_caption(annotation, &has_caption) == ZATHURA_ERROR_OK);
  fail_unless(has_caption == false);

  fail_unless(zathura_annotation_line_set_caption(annotation, true) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_line_has_caption(annotation, &has_caption) == ZATHURA_ERROR_OK);
  fail_unless(has_caption == true);
} END_TEST

START_TEST(test_annotation_line_set_caption_position) {
  zathura_annotation_line_caption_position_t caption_position = ZATHURA_ANNOTATION_CAPTION_POSITION_INLINE;

  /* invalid arguments */
  fail_unless(zathura_annotation_line_set_caption_position(NULL, caption_position) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  fail_unless(zathura_annotation_line_set_caption_position(annotation, caption_position) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_line_get_caption_position) {
  zathura_annotation_line_caption_position_t caption_position = ZATHURA_ANNOTATION_CAPTION_POSITION_INLINE;

  /* invalid arguments */
  fail_unless(zathura_annotation_line_get_caption_position(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_line_get_caption_position(NULL, &caption_position) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_line_get_caption_position(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  fail_unless(zathura_annotation_line_get_caption_position(annotation, &caption_position) == ZATHURA_ERROR_OK);
  fail_unless(caption_position == ZATHURA_ANNOTATION_CAPTION_POSITION_INLINE);

  fail_unless(zathura_annotation_line_set_caption_position(annotation, ZATHURA_ANNOTATION_CAPTION_POSITION_TOP) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_line_get_caption_position(annotation, &caption_position) == ZATHURA_ERROR_OK);
  fail_unless(caption_position == ZATHURA_ANNOTATION_CAPTION_POSITION_TOP);
} END_TEST

START_TEST(test_annotation_line_set_intent) {
  zathura_annotation_markup_intent_t intent = ZATHURA_ANNOTATION_MARKUP_INTENT_NONE;

  /* invalid arguments */
  fail_unless(zathura_annotation_line_set_intent(NULL, intent) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  fail_unless(zathura_annotation_line_set_intent(annotation, intent) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_line_get_intent) {
  zathura_annotation_markup_intent_t intent = ZATHURA_ANNOTATION_MARKUP_INTENT_NONE;

  /* invalid arguments */
  fail_unless(zathura_annotation_line_get_intent(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_line_get_intent(NULL, &intent) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_line_get_intent(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  fail_unless(zathura_annotation_line_get_intent(annotation, &intent) == ZATHURA_ERROR_OK);
  fail_unless(intent == ZATHURA_ANNOTATION_MARKUP_INTENT_NONE);

  fail_unless(zathura_annotation_line_set_intent(annotation, ZATHURA_ANNOTATION_MARKUP_INTENT_LINE_ARROW) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_line_get_intent(annotation, &intent) == ZATHURA_ERROR_OK);
  fail_unless(intent == ZATHURA_ANNOTATION_MARKUP_INTENT_LINE_ARROW);
} END_TEST

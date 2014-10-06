/* See LICENSE file for license and copyright information */

#include <check.h>
#include <limits.h>
#include <fiu.h>
#include <fiu-control.h>

#include "annotations.h"
#include "annotations/internal.h"

zathura_annotation_t* annotation;

static void setup(void) {
  fail_unless(zathura_annotation_new(&annotation, ZATHURA_ANNOTATION_CARET) == ZATHURA_ERROR_OK);
  fail_unless(annotation != NULL);
}

static void teardown(void) {
  if (annotation != NULL) {
    fail_unless(zathura_annotation_free(annotation) == ZATHURA_ERROR_OK);
  }
}

START_TEST(test_annotation_free) {
  /* invalid arguments */
  fail_unless(zathura_annotation_free(NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* invalid data */
  annotation->type = -1;
  fail_unless(zathura_annotation_free(annotation) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  annotation = NULL;
} END_TEST

START_TEST(test_annotation_new) {
  zathura_annotation_t* test_annotation;

  /* invalid arguments */
  fail_unless(zathura_annotation_new(NULL, 0) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_new(&test_annotation, INT_MAX) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_new(&test_annotation,
        ZATHURA_ANNOTATION_UNKNOWN) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_free(test_annotation) == ZATHURA_ERROR_OK);

  /* fault injection */
  fiu_enable("libc/mm/calloc", 1, NULL, 0);
  fail_unless(zathura_annotation_new(&test_annotation, ZATHURA_PAGE_TRANSITION_SPLIT) == ZATHURA_ERROR_OUT_OF_MEMORY);
  fiu_disable("libc/mm/calloc");
} END_TEST

START_TEST(test_annotation_get_type) {
  zathura_annotation_type_t type;
  fail_unless(zathura_annotation_get_type(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_get_type(NULL, &type) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_get_type(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_annotation_set_position) {
  zathura_rectangle_t rectangle = { {0, 0}, {0, 0} };

  /* invalid arguments */
  fail_unless(zathura_annotation_set_position(NULL, rectangle) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_set_position(annotation, rectangle) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_get_position) {
  zathura_rectangle_t rectangle = { {0, 0}, {0, 0} };
  zathura_rectangle_t rectangle_input = { {1, 2}, {3, 4} };

  /* invalid arguments */
  fail_unless(zathura_annotation_get_position(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_get_position(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_get_position(NULL, &rectangle) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_get_position(annotation, &rectangle) == ZATHURA_ERROR_OK);
  fail_unless(rectangle.p1.x == 0);
  fail_unless(rectangle.p1.y == 0);
  fail_unless(rectangle.p2.x == 0);
  fail_unless(rectangle.p2.y == 0);

  fail_unless(zathura_annotation_set_position(annotation, rectangle_input) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_get_position(annotation, &rectangle) == ZATHURA_ERROR_OK);
  fail_unless(rectangle.p1.x == 1);
  fail_unless(rectangle.p1.y == 2);
  fail_unless(rectangle.p2.x == 3);
  fail_unless(rectangle.p2.y == 4);
} END_TEST

START_TEST(test_annotation_set_content) {
  /* invalid arguments */
  fail_unless(zathura_annotation_set_content(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_set_content(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_set_content(NULL, "content") == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_set_content(annotation, "content") == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_set_content(annotation, "") == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_get_content) {
  char* content = NULL;

  /* invalid arguments */
  fail_unless(zathura_annotation_get_content(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_get_content(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_get_content(NULL, &content) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_get_content(annotation, &content) == ZATHURA_ERROR_OK);
  fail_unless(content == NULL);
  fail_unless(zathura_annotation_set_content(annotation, "content") == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_get_content(annotation, &content) == ZATHURA_ERROR_OK);
  fail_unless(content != NULL);
  fail_unless(strcmp(content, "content") == 0);
} END_TEST

START_TEST(test_annotation_set_name) {
  /* invalid arguments */
  fail_unless(zathura_annotation_set_name(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_set_name(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_set_name(NULL, "name") == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_set_name(annotation, "name") == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_set_name(annotation, "") == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_get_name) {
  char* name = NULL;

  /* invalid arguments */
  fail_unless(zathura_annotation_get_name(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_get_name(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_get_name(NULL, &name) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_get_name(annotation, &name) == ZATHURA_ERROR_OK);
  fail_unless(name == NULL);
  fail_unless(zathura_annotation_set_name(annotation, "name") == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_get_name(annotation, &name) == ZATHURA_ERROR_OK);
  fail_unless(name != NULL);
  fail_unless(strcmp(name, "name") == 0);
} END_TEST

START_TEST(test_annotation_set_modification_date) {
  time_t modification_date = time(NULL);

  /* invalid arguments */
  fail_unless(zathura_annotation_set_modification_date(NULL, modification_date) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_set_modification_date(annotation, modification_date) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_get_modification_date) {
  time_t modification_date = time(NULL);

  /* invalid arguments */
  fail_unless(zathura_annotation_get_modification_date(NULL, NULL)               == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_get_modification_date(annotation, NULL)         == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_get_modification_date(NULL, &modification_date) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  time_t modification_date2;
  fail_unless(zathura_annotation_set_modification_date(annotation, modification_date) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_get_modification_date(annotation, &modification_date2) == ZATHURA_ERROR_OK);
  fail_unless(difftime(modification_date, modification_date2) == 0);
} END_TEST

START_TEST(test_annotation_set_flags) {
  zathura_annotation_flag_t flags = ZATHURA_ANNOTATION_FLAG_UNDEFINED;

  /* invalid arguments */
  fail_unless(zathura_annotation_set_flags(NULL, flags) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  fail_unless(zathura_annotation_set_flags(annotation, flags) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_get_flags) {
  zathura_annotation_flag_t flags = ZATHURA_ANNOTATION_FLAG_UNDEFINED;

  /* invalid arguments */
  fail_unless(zathura_annotation_get_flags(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_get_flags(NULL, &flags) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_get_flags(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  fail_unless(zathura_annotation_get_flags(annotation, &flags) == ZATHURA_ERROR_OK);
  fail_unless(flags == ZATHURA_ANNOTATION_FLAG_UNDEFINED);

  fail_unless(zathura_annotation_set_flags(annotation, ZATHURA_ANNOTATION_FLAG_PRINT) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_get_flags(annotation, &flags) == ZATHURA_ERROR_OK);
  fail_unless(flags & ZATHURA_ANNOTATION_FLAG_PRINT);
} END_TEST

START_TEST(test_annotation_set_color) {
  zathura_annotation_color_t color = { 0 };

  /* invalid arguments */
  fail_unless(zathura_annotation_set_color(NULL, color) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_set_color(annotation, color) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_get_color) {
  zathura_annotation_color_t color = { ZATHURA_ANNOTATION_COLOR_SPACE_NONE, {0, 0, 0, 0} };
  zathura_annotation_color_t color_input = { ZATHURA_ANNOTATION_COLOR_SPACE_NONE, {1, 2, 3, 4} };

  /* invalid arguments */
  fail_unless(zathura_annotation_get_color(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_get_color(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_get_color(NULL, &color) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_get_color(annotation, &color) == ZATHURA_ERROR_OK);

  fail_unless(zathura_annotation_set_color(annotation, color_input) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_get_color(annotation, &color) == ZATHURA_ERROR_OK);
} END_TEST

#include "annotations/annotation-3d.c"
#include "annotations/annotation-caret.c"
#include "annotations/annotation-circle.c"
#include "annotations/annotation-file-attachment.c"
#include "annotations/annotation-free-text.c"
#include "annotations/annotation-highlight.c"
#include "annotations/annotation-ink.c"
#include "annotations/annotation-line.c"
#include "annotations/annotation-link.c"
#include "annotations/annotation-markup.c"
#include "annotations/annotation-movie.c"
#include "annotations/annotation-poly-line.c"
#include "annotations/annotation-polygon.c"
#include "annotations/annotation-popup.c"
#include "annotations/annotation-printer-mark.c"
#include "annotations/annotation-screen.c"
#include "annotations/annotation-sound.c"
#include "annotations/annotation-square.c"
#include "annotations/annotation-squiggly.c"
#include "annotations/annotation-stamp.c"
#include "annotations/annotation-strike-out.c"
#include "annotations/annotation-text.c"
#include "annotations/annotation-text-markup.c"
#include "annotations/annotation-trap-net.c"
#include "annotations/annotation-underline.c"
#include "annotations/annotation-watermark.c"

Suite*
suite_annotations(void)
{
  TCase* tcase = NULL;
  Suite* suite = suite_create("annotations");

  tcase = tcase_create("basic");
  tcase_add_checked_fixture(tcase, setup, teardown);
  tcase_add_test(tcase, test_annotation_free);
  tcase_add_test(tcase, test_annotation_new);
  tcase_add_test(tcase, test_annotation_get_type);
  tcase_add_test(tcase, test_annotation_set_position);
  tcase_add_test(tcase, test_annotation_get_position);
  tcase_add_test(tcase, test_annotation_set_content);
  tcase_add_test(tcase, test_annotation_get_content);
  tcase_add_test(tcase, test_annotation_set_name);
  tcase_add_test(tcase, test_annotation_get_name);
  tcase_add_test(tcase, test_annotation_set_modification_date);
  tcase_add_test(tcase, test_annotation_get_modification_date);
  tcase_add_test(tcase, test_annotation_set_flags);
  tcase_add_test(tcase, test_annotation_get_flags);
  tcase_add_test(tcase, test_annotation_set_color);
  tcase_add_test(tcase, test_annotation_get_color);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("text");
  tcase_add_checked_fixture(tcase, setup_annotation_text, teardown);
  tcase_add_test(tcase, test_annotation_text_new);
  tcase_add_test(tcase, test_annotation_text_init);
  tcase_add_test(tcase, test_annotation_text_clear);
  tcase_add_test(tcase, test_annotation_text_get_type);
  tcase_add_test(tcase, test_annotation_text_set_icon_name);
  tcase_add_test(tcase, test_annotation_text_get_icon_name);
  tcase_add_test(tcase, test_annotation_text_set_open);
  tcase_add_test(tcase, test_annotation_text_is_open);
  tcase_add_test(tcase, test_annotation_text_set_state);
  tcase_add_test(tcase, test_annotation_text_get_state);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("text-markup");
  tcase_add_checked_fixture(tcase, setup_annotation_text_markup, teardown);
  tcase_add_test(tcase, test_annotation_text_markup_new);
  tcase_add_test(tcase, test_annotation_text_markup_init);
  tcase_add_test(tcase, test_annotation_text_markup_clear);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("line");
  tcase_add_checked_fixture(tcase, setup_annotation_line, teardown);
  tcase_add_test(tcase, test_annotation_line_new);
  tcase_add_test(tcase, test_annotation_line_init);
  tcase_add_test(tcase, test_annotation_line_clear);
  tcase_add_test(tcase, test_annotation_line_get_type);
  tcase_add_test(tcase, test_annotation_line_set_coordinates);
  tcase_add_test(tcase, test_annotation_line_get_coordinates);
  tcase_add_test(tcase, test_annotation_line_set_border);
  tcase_add_test(tcase, test_annotation_line_get_border);
  tcase_add_test(tcase, test_annotation_line_set_line_ending);
  tcase_add_test(tcase, test_annotation_line_get_line_ending);
  tcase_add_test(tcase, test_annotation_line_set_color);
  tcase_add_test(tcase, test_annotation_line_get_color);
  tcase_add_test(tcase, test_annotation_line_set_leader_lines_length);
  tcase_add_test(tcase, test_annotation_line_get_leader_lines_length);
  tcase_add_test(tcase, test_annotation_line_set_leader_line_extensions_length);
  tcase_add_test(tcase, test_annotation_line_get_leader_line_extensions_length);
  tcase_add_test(tcase, test_annotation_line_set_leader_line_offset);
  tcase_add_test(tcase, test_annotation_line_get_leader_line_offset);
  tcase_add_test(tcase, test_annotation_line_set_caption);
  tcase_add_test(tcase, test_annotation_line_has_caption);
  tcase_add_test(tcase, test_annotation_line_set_caption_position);
  tcase_add_test(tcase, test_annotation_line_get_caption_position);
  tcase_add_test(tcase, test_annotation_line_set_intent);
  tcase_add_test(tcase, test_annotation_line_get_intent);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("link");
  tcase_add_checked_fixture(tcase, setup_annotation_link, teardown);
  tcase_add_test(tcase, test_annotation_link_new);
  tcase_add_test(tcase, test_annotation_link_init);
  tcase_add_test(tcase, test_annotation_link_clear);
  tcase_add_test(tcase, test_annotation_link_get_type);
  tcase_add_test(tcase, test_annotation_link_set_action);
  tcase_add_test(tcase, test_annotation_link_get_action);
  tcase_add_test(tcase, test_annotation_link_set_highlighting_mode);
  tcase_add_test(tcase, test_annotation_link_get_highlighting_mode);
  tcase_add_test(tcase, test_annotation_link_set_quad_points);
  tcase_add_test(tcase, test_annotation_link_get_quad_points);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("markup");
  tcase_add_checked_fixture(tcase, setup_annotation_markup, teardown);
  tcase_add_test(tcase, test_annotation_markup_new);
  tcase_add_test(tcase, test_annotation_markup_init);
  tcase_add_test(tcase, test_annotation_markup_clear);
  tcase_add_test(tcase, test_annotation_is_markup_annotation);
  tcase_add_test(tcase, test_annotation_markup_set_label);
  tcase_add_test(tcase, test_annotation_markup_get_label);
  tcase_add_test(tcase, test_annotation_markup_set_popup_annotation);
  tcase_add_test(tcase, test_annotation_markup_get_popup_annotation);
  tcase_add_test(tcase, test_annotation_markup_set_text);
  tcase_add_test(tcase, test_annotation_markup_get_text);
  tcase_add_test(tcase, test_annotation_markup_set_creation_date);
  tcase_add_test(tcase, test_annotation_markup_get_creation_date);
  tcase_add_test(tcase, test_annotation_markup_set_reply_to_annotation);
  tcase_add_test(tcase, test_annotation_markup_get_reply_to_annotation);
  tcase_add_test(tcase, test_annotation_markup_set_reply_type);
  tcase_add_test(tcase, test_annotation_markup_get_reply_type);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("free-text");
  tcase_add_checked_fixture(tcase, setup_annotation_free_text, teardown);
  tcase_add_test(tcase, test_annotation_free_text_new);
  tcase_add_test(tcase, test_annotation_free_text_get_type);
  tcase_add_test(tcase, test_annotation_free_text_init);
  tcase_add_test(tcase, test_annotation_free_text_clear);
  tcase_add_test(tcase, test_annotation_free_text_set_text);
  tcase_add_test(tcase, test_annotation_free_text_get_text);
  tcase_add_test(tcase, test_annotation_free_text_set_justification);
  tcase_add_test(tcase, test_annotation_free_text_get_justification);
  tcase_add_test(tcase, test_annotation_free_text_set_rich_text);
  tcase_add_test(tcase, test_annotation_free_text_get_rich_text);
  tcase_add_test(tcase, test_annotation_free_text_set_style_string);
  tcase_add_test(tcase, test_annotation_free_text_get_style_string);
  tcase_add_test(tcase, test_annotation_free_text_set_callout_line);
  tcase_add_test(tcase, test_annotation_free_text_get_callout_line);
  tcase_add_test(tcase, test_annotation_free_text_set_border);
  tcase_add_test(tcase, test_annotation_free_text_get_border);
  tcase_add_test(tcase, test_annotation_free_text_set_intent);
  tcase_add_test(tcase, test_annotation_free_text_get_intent);
  tcase_add_test(tcase, test_annotation_free_text_set_padding);
  tcase_add_test(tcase, test_annotation_free_text_get_padding);
  tcase_add_test(tcase, test_annotation_free_text_set_line_ending);
  tcase_add_test(tcase, test_annotation_free_text_get_line_ending);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("square");
  tcase_add_checked_fixture(tcase, setup_annotation_square, teardown);
  tcase_add_test(tcase, test_annotation_square_new);
  tcase_add_test(tcase, test_annotation_square_and_circle_init);
  tcase_add_test(tcase, test_annotation_square_and_circle_clear);
  tcase_add_test(tcase, test_annotation_square_get_type);
  tcase_add_test(tcase, test_annotation_square_set_rectangle);
  tcase_add_test(tcase, test_annotation_square_get_rectangle);
  tcase_add_test(tcase, test_annotation_square_set_color);
  tcase_add_test(tcase, test_annotation_square_get_color);
  tcase_add_test(tcase, test_annotation_square_set_border);
  tcase_add_test(tcase, test_annotation_square_get_border);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("circle");
  tcase_add_checked_fixture(tcase, setup_annotation_circle, teardown);
  tcase_add_test(tcase, test_annotation_circle_new);
  tcase_add_test(tcase, test_annotation_circle_get_type);
  tcase_add_test(tcase, test_annotation_circle_set_rectangle);
  tcase_add_test(tcase, test_annotation_circle_get_rectangle);
  tcase_add_test(tcase, test_annotation_circle_set_color);
  tcase_add_test(tcase, test_annotation_circle_get_color);
  tcase_add_test(tcase, test_annotation_circle_set_border);
  tcase_add_test(tcase, test_annotation_circle_get_border);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("polygon");
  tcase_add_checked_fixture(tcase, setup_annotation_polygon, teardown);
  tcase_add_test(tcase, test_annotation_polygon_new);
  tcase_add_test(tcase, test_annotation_polygon_get_type);
  tcase_add_test(tcase, test_annotation_polygon_init);
  tcase_add_test(tcase, test_annotation_polygon_clear);
  tcase_add_test(tcase, test_annotation_polygon_set_vertices);
  tcase_add_test(tcase, test_annotation_polygon_get_vertices);
  tcase_add_test(tcase, test_annotation_polygon_set_borders);
  tcase_add_test(tcase, test_annotation_polygon_get_borders);
  tcase_add_test(tcase, test_annotation_polygon_set_interior_color);
  tcase_add_test(tcase, test_annotation_polygon_get_interior_color);
  tcase_add_test(tcase, test_annotation_polygon_set_intent);
  tcase_add_test(tcase, test_annotation_polygon_get_intent);
  tcase_add_test(tcase, test_annotation_polygon_set_measure);
  tcase_add_test(tcase, test_annotation_polygon_get_measure);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("poly-line");
  tcase_add_checked_fixture(tcase, setup_annotation_poly_line, teardown);
  tcase_add_test(tcase, test_annotation_poly_line_new);
  tcase_add_test(tcase, test_annotation_poly_line_get_type);
  tcase_add_test(tcase, test_annotation_poly_line_init);
  tcase_add_test(tcase, test_annotation_poly_line_clear);
  tcase_add_test(tcase, test_annotation_poly_line_set_vertices);
  tcase_add_test(tcase, test_annotation_poly_line_get_vertices);
  tcase_add_test(tcase, test_annotation_poly_line_set_line_ending);
  tcase_add_test(tcase, test_annotation_poly_line_get_line_ending);
  tcase_add_test(tcase, test_annotation_poly_line_set_borders);
  tcase_add_test(tcase, test_annotation_poly_line_get_borders);
  tcase_add_test(tcase, test_annotation_poly_line_set_interior_color);
  tcase_add_test(tcase, test_annotation_poly_line_get_interior_color);
  tcase_add_test(tcase, test_annotation_poly_line_set_intent);
  tcase_add_test(tcase, test_annotation_poly_line_get_intent);
  tcase_add_test(tcase, test_annotation_poly_line_set_measure);
  tcase_add_test(tcase, test_annotation_poly_line_get_measure);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("highlight");
  tcase_add_checked_fixture(tcase, setup_annotation_highlight, teardown);
  tcase_add_test(tcase, test_annotation_highlight_new);
  tcase_add_test(tcase, test_annotation_highlight_get_type);
  tcase_add_test(tcase, test_annotation_highlight_set_quad_points);
  tcase_add_test(tcase, test_annotation_highlight_get_quad_points);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("underline");
  tcase_add_checked_fixture(tcase, setup_annotation_underline, teardown);
  tcase_add_test(tcase, test_annotation_underline_new);
  tcase_add_test(tcase, test_annotation_underline_get_type);
  tcase_add_test(tcase, test_annotation_underline_set_quad_points);
  tcase_add_test(tcase, test_annotation_underline_get_quad_points);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("squiggly");
  tcase_add_checked_fixture(tcase, setup_annotation_squiggly, teardown);
  tcase_add_test(tcase, test_annotation_squiggly_new);
  tcase_add_test(tcase, test_annotation_squiggly_get_type);
  tcase_add_test(tcase, test_annotation_squiggly_set_quad_points);
  tcase_add_test(tcase, test_annotation_squiggly_get_quad_points);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("strike-out");
  tcase_add_checked_fixture(tcase, setup_annotation_strike_out, teardown);
  tcase_add_test(tcase, test_annotation_strike_out_new);
  tcase_add_test(tcase, test_annotation_strike_out_get_type);
  tcase_add_test(tcase, test_annotation_strike_out_set_quad_points);
  tcase_add_test(tcase, test_annotation_strike_out_get_quad_points);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("stamp");
  tcase_add_checked_fixture(tcase, setup_annotation_stamp, teardown);
  tcase_add_test(tcase, test_annotation_stamp_new);
  tcase_add_test(tcase, test_annotation_stamp_init);
  tcase_add_test(tcase, test_annotation_stamp_clear);
  tcase_add_test(tcase, test_annotation_stamp_get_type);
  tcase_add_test(tcase, test_annotation_stamp_set_icon_name);
  tcase_add_test(tcase, test_annotation_stamp_get_icon_name);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("caret");
  tcase_add_checked_fixture(tcase, setup_annotation_caret, teardown);
  tcase_add_test(tcase, test_annotation_caret_new);
  tcase_add_test(tcase, test_annotation_caret_get_type);
  tcase_add_test(tcase, test_annotation_caret_init);
  tcase_add_test(tcase, test_annotation_caret_clear);
  tcase_add_test(tcase, test_annotation_caret_set_symbol);
  tcase_add_test(tcase, test_annotation_caret_get_symbol);
  tcase_add_test(tcase, test_annotation_caret_set_padding);
  tcase_add_test(tcase, test_annotation_caret_get_padding);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("ink");
  tcase_add_checked_fixture(tcase, setup_annotation_ink, teardown);
  tcase_add_test(tcase, test_annotation_ink_new);
  tcase_add_test(tcase, test_annotation_ink_init);
  tcase_add_test(tcase, test_annotation_ink_clear);
  tcase_add_test(tcase, test_annotation_ink_get_type);
  tcase_add_test(tcase, test_annotation_ink_set_paths);
  tcase_add_test(tcase, test_annotation_ink_get_paths);
  tcase_add_test(tcase, test_annotation_ink_set_border);
  tcase_add_test(tcase, test_annotation_ink_get_border);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("popup");
  tcase_add_checked_fixture(tcase, setup_annotation_popup, teardown);
  tcase_add_test(tcase, test_annotation_popup_new);
  tcase_add_test(tcase, test_annotation_popup_init);
  tcase_add_test(tcase, test_annotation_popup_clear);
  tcase_add_test(tcase, test_annotation_popup_get_type);
  tcase_add_test(tcase, test_annotation_popup_set_parent);
  tcase_add_test(tcase, test_annotation_popup_get_parent);
  tcase_add_test(tcase, test_annotation_popup_set_open);
  tcase_add_test(tcase, test_annotation_popup_is_open);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("file-attachment");
  tcase_add_checked_fixture(tcase, setup_annotation_file, teardown);
  tcase_add_test(tcase, test_annotation_file_new);
  tcase_add_test(tcase, test_annotation_file_get_type);
  tcase_add_test(tcase, test_annotation_file_init);
  tcase_add_test(tcase, test_annotation_file_clear);
  tcase_add_test(tcase, test_annotation_file_set_attachment);
  tcase_add_test(tcase, test_annotation_file_get_attachment);
  tcase_add_test(tcase, test_annotation_file_set_icon_name);
  tcase_add_test(tcase, test_annotation_file_get_icon_name);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("sound");
  tcase_add_checked_fixture(tcase, setup_annotation_sound, teardown);
  tcase_add_test(tcase, test_annotation_sound_new);
  tcase_add_test(tcase, test_annotation_sound_get_type);
  tcase_add_test(tcase, test_annotation_sound_init);
  tcase_add_test(tcase, test_annotation_sound_clear);
  tcase_add_test(tcase, test_annotation_sound_set_sound);
  tcase_add_test(tcase, test_annotation_sound_get_sound);
  tcase_add_test(tcase, test_annotation_sound_set_icon_name);
  tcase_add_test(tcase, test_annotation_sound_get_icon_name);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("movie");
  tcase_add_checked_fixture(tcase, setup_annotation_movie, teardown);
  tcase_add_test(tcase, test_annotation_movie_new);
  tcase_add_test(tcase, test_annotation_movie_get_type);
  tcase_add_test(tcase, test_annotation_movie_init);
  tcase_add_test(tcase, test_annotation_movie_clear);
  tcase_add_test(tcase, test_annotation_movie_set_title);
  tcase_add_test(tcase, test_annotation_movie_get_title);
  tcase_add_test(tcase, test_annotation_movie_set_movie);
  tcase_add_test(tcase, test_annotation_movie_get_movie);
  tcase_add_test(tcase, test_annotation_movie_set_movie_activation);
  tcase_add_test(tcase, test_annotation_movie_get_movie_activation);
  tcase_add_test(tcase, test_annotation_movie_set_play_if_activated);
  tcase_add_test(tcase, test_annotation_movie_get_play_if_activated);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("screen");
  tcase_add_checked_fixture(tcase, setup_annotation_screen, teardown);
  tcase_add_test(tcase, test_annotation_screen_new);
  tcase_add_test(tcase, test_annotation_screen_get_type);
  tcase_add_test(tcase, test_annotation_screen_init);
  tcase_add_test(tcase, test_annotation_screen_clear);
  tcase_add_test(tcase, test_annotation_screen_set_title);
  tcase_add_test(tcase, test_annotation_screen_get_title);
  tcase_add_test(tcase, test_annotation_screen_set_action);
  tcase_add_test(tcase, test_annotation_screen_get_action);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("printer-mark");
  tcase_add_checked_fixture(tcase, setup_annotation_printer_mark, teardown);
  tcase_add_test(tcase, test_annotation_printer_mark_new);
  tcase_add_test(tcase, test_annotation_printer_mark_get_type);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("trap-net");
  tcase_add_checked_fixture(tcase, setup_annotation_trap_net, teardown);
  tcase_add_test(tcase, test_annotation_trap_net_new);
  tcase_add_test(tcase, test_annotation_trap_net_get_type);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("watermark");
  tcase_add_checked_fixture(tcase, setup_annotation_watermark, teardown);
  tcase_add_test(tcase, test_annotation_watermark_new);
  tcase_add_test(tcase, test_annotation_watermark_get_type);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("3D");
  tcase_add_checked_fixture(tcase, setup_annotation_3d, teardown);
  tcase_add_test(tcase, test_annotation_3d_new);
  tcase_add_test(tcase, test_annotation_3d_get_type);
  tcase_add_test(tcase, test_annotation_3d_init);
  tcase_add_test(tcase, test_annotation_3d_clear);
  tcase_add_test(tcase, test_annotation_3d_set_artwork);
  tcase_add_test(tcase, test_annotation_3d_get_artwork);
  tcase_add_test(tcase, test_annotation_3d_set_view_box);
  tcase_add_test(tcase, test_annotation_3d_get_view_box);
  tcase_add_test(tcase, test_annotation_3d_set_interactive);
  tcase_add_test(tcase, test_annotation_3d_is_interactive);
  suite_add_tcase(suite, tcase);

  return suite;
}

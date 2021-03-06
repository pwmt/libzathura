/* See LICENSE file for license and copyright information */

#include <check.h>

#include <libzathura/annotations.h>

static void setup_annotation_poly_line(void) {
  setup_document_plugin(&plugin_manager, &document);

  fail_unless(zathura_document_get_page(document, 0, &page) == ZATHURA_ERROR_OK);
  fail_unless(page != NULL);

  fail_unless(zathura_annotation_new(page, &annotation, ZATHURA_ANNOTATION_POLY_LINE) == ZATHURA_ERROR_OK);
  fail_unless(annotation != NULL);
}

START_TEST(test_annotation_poly_line_new) {
} END_TEST

START_TEST(test_annotation_poly_line_init) {
  /* invalid arguments */
  fail_unless(zathura_annotation_poly_line_init(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_poly_line_init(annotation)
      == ZATHURA_ERROR_OK); // double initialization

  /* fault injection */
#ifdef WITH_LIBFIU
  fiu_enable("libc/mm/calloc", 1, NULL, 0);
  fail_unless(zathura_annotation_poly_line_init(annotation)
      == ZATHURA_ERROR_OUT_OF_MEMORY); // double initialization
  fiu_disable("libc/mm/calloc");
#endif
} END_TEST

START_TEST(test_annotation_poly_line_clear) {
  /* invalid arguments */
  fail_unless(zathura_annotation_poly_line_clear(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_annotation_poly_line_get_type) {
  zathura_annotation_type_t type;
  fail_unless(zathura_annotation_get_type(annotation, &type) == ZATHURA_ERROR_OK);
  fail_unless(type == ZATHURA_ANNOTATION_POLY_LINE);
} END_TEST

START_TEST(test_annotation_poly_line_set_vertices) {
  zathura_list_t* vertices = zathura_list_alloc();
  fail_unless(vertices != NULL);

  /* invalid arguments */
  fail_unless(zathura_annotation_poly_line_set_vertices(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_poly_line_set_vertices(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_poly_line_set_vertices(NULL, vertices) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_poly_line_set_vertices(annotation, vertices) == ZATHURA_ERROR_OK);
  zathura_list_free(vertices);
} END_TEST

START_TEST(test_annotation_poly_line_get_vertices) {
  zathura_list_t* vertices;

  /* invalid arguments */
  fail_unless(zathura_annotation_poly_line_get_vertices(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_poly_line_get_vertices(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_poly_line_get_vertices(NULL, &vertices) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_poly_line_get_vertices(annotation, &vertices) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_poly_line_set_line_ending) {
  zathura_annotation_line_ending_t line_ending[2] = { ZATHURA_ANNOTATION_LINE_ENDING_NONE, ZATHURA_ANNOTATION_LINE_ENDING_NONE };
  fail_unless(zathura_annotation_poly_line_set_line_ending(NULL, line_ending) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_poly_line_set_line_ending(annotation, line_ending) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_poly_line_get_line_ending) {
  zathura_annotation_line_ending_t line_ending[2] = { ZATHURA_ANNOTATION_LINE_ENDING_NONE, ZATHURA_ANNOTATION_LINE_ENDING_NONE };

  /* invalid arguments */
  fail_unless(zathura_annotation_poly_line_get_line_ending(NULL, line_ending) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_poly_line_get_line_ending(annotation, line_ending) == ZATHURA_ERROR_OK);

  zathura_annotation_line_ending_t line_ending2[2] = { ZATHURA_ANNOTATION_LINE_ENDING_CIRCLE, ZATHURA_ANNOTATION_LINE_ENDING_CIRCLE };
  fail_unless(zathura_annotation_poly_line_set_line_ending(annotation, line_ending2) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_poly_line_get_line_ending(annotation, line_ending) == ZATHURA_ERROR_OK);
  fail_unless(line_ending[0] == ZATHURA_ANNOTATION_LINE_ENDING_CIRCLE);
  fail_unless(line_ending[1] == ZATHURA_ANNOTATION_LINE_ENDING_CIRCLE);
} END_TEST

START_TEST(test_annotation_poly_line_set_border) {
  zathura_annotation_border_t border = { 0 };

  /* invalid arguments */
  fail_unless(zathura_annotation_poly_line_set_border(NULL, border) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_poly_line_set_border(annotation, border) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_poly_line_get_border) {
  zathura_annotation_border_t border = { 0 };

  /* invalid arguments */
  fail_unless(zathura_annotation_poly_line_get_border(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_poly_line_get_border(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_poly_line_get_border(NULL, &border) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_poly_line_get_border(annotation, &border) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_poly_line_set_interior_color) {
  zathura_annotation_color_t color = { 0 };

  /* invalid arguments */
  fail_unless(zathura_annotation_poly_line_set_interior_color(NULL, color) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_poly_line_set_interior_color(annotation, color) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_poly_line_get_interior_color) {
  zathura_annotation_color_t color = { ZATHURA_ANNOTATION_COLOR_SPACE_NONE, {0, 0, 0, 0} };
  zathura_annotation_color_t color_input = { ZATHURA_ANNOTATION_COLOR_SPACE_NONE, {1, 2, 3, 4} };

  /* invalid arguments */
  fail_unless(zathura_annotation_poly_line_get_interior_color(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_poly_line_get_interior_color(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_poly_line_get_interior_color(NULL, &color) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_poly_line_get_interior_color(annotation, &color) == ZATHURA_ERROR_OK);

  fail_unless(zathura_annotation_poly_line_set_interior_color(annotation, color_input) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_poly_line_get_interior_color(annotation, &color) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_poly_line_set_intent) {
  zathura_annotation_markup_intent_t intent = ZATHURA_ANNOTATION_MARKUP_INTENT_NONE;

  /* invalid arguments */
  fail_unless(zathura_annotation_poly_line_set_intent(NULL, intent) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  fail_unless(zathura_annotation_poly_line_set_intent(annotation, intent) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_poly_line_get_intent) {
  zathura_annotation_markup_intent_t intent = ZATHURA_ANNOTATION_MARKUP_INTENT_NONE;

  /* invalid arguments */
  fail_unless(zathura_annotation_poly_line_get_intent(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_poly_line_get_intent(NULL, &intent) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_poly_line_get_intent(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  fail_unless(zathura_annotation_poly_line_get_intent(annotation, &intent) == ZATHURA_ERROR_OK);
  fail_unless(intent == ZATHURA_ANNOTATION_MARKUP_INTENT_NONE);

  fail_unless(zathura_annotation_poly_line_set_intent(annotation, ZATHURA_ANNOTATION_MARKUP_INTENT_POLY_LINE_DIMENSION) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_poly_line_get_intent(annotation, &intent) == ZATHURA_ERROR_OK);
  fail_unless(intent == ZATHURA_ANNOTATION_MARKUP_INTENT_POLY_LINE_DIMENSION);
} END_TEST

START_TEST(test_annotation_poly_line_set_measure) {
  zathura_annotation_measure_t* measure = (zathura_annotation_measure_t*) 0xCAFEBABE;

  /* invalid arguments */
  fail_unless(zathura_annotation_poly_line_set_measure(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_poly_line_set_measure(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_poly_line_set_measure(NULL, measure) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_poly_line_set_measure(annotation, measure) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_poly_line_get_measure) {
  zathura_annotation_measure_t* measure;

  /* invalid arguments */
  fail_unless(zathura_annotation_poly_line_get_measure(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_poly_line_get_measure(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_poly_line_get_measure(NULL, &measure) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_poly_line_get_measure(annotation, &measure) == ZATHURA_ERROR_OK);
  fail_unless(measure == NULL);

  fail_unless(zathura_annotation_poly_line_set_measure(annotation, (zathura_annotation_measure_t*) 0xCAFEBABE) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_poly_line_get_measure(annotation, &measure) == ZATHURA_ERROR_OK);
  fail_unless(measure == (zathura_annotation_measure_t*) 0xCAFEBABE);
} END_TEST

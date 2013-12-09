/* See LICENSE file for license and copyright information */

#include <check.h>

#include "page.h"
#include "plugin-api.h"
#include "internal.h"

START_TEST(test_page_new) {
  zathura_page_t* page = NULL;

  /* basic invalid arguments */
  fail_unless(zathura_page_new(NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_page_new(&page) == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_free(page) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_page_free) {
  fail_unless(zathura_page_free(NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_page_get_index) {
  zathura_page_t* page = NULL;
  unsigned int index;

  /* basic invalid arguments */
  fail_unless(zathura_page_get_index(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_index(page, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_index(NULL, &index) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_page_set_width) {
  zathura_page_t* page = NULL;

  /* basic invalid arguments */
  fail_unless(zathura_page_set_width(NULL, 0) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_page_get_width) {
  zathura_page_t* page = NULL;
  unsigned int width;

  /* basic invalid arguments */
  fail_unless(zathura_page_get_width(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_width(page, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_width(NULL, &width) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_page_set_height) {
  zathura_page_t* page = NULL;

  /* basic invalid arguments */
  fail_unless(zathura_page_set_height(NULL, 0) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_page_get_height) {
  zathura_page_t* page = NULL;
  unsigned int height;

  /* basic invalid arguments */
  fail_unless(zathura_page_get_height(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_height(page, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_height(NULL, &height) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_page_get_transition) {
  zathura_page_t* page = NULL;
  zathura_page_transition_t* transition;

  /* basic invalid arguments */
  fail_unless(zathura_page_get_transition(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_transition(page, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_transition(NULL, &transition) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_page_get_duration) {
  zathura_page_t* page = NULL;
  unsigned int duration;

  /* basic invalid arguments */
  fail_unless(zathura_page_get_duration(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_duration(page, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_duration(NULL, &duration) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_page_get_crop_box) {
  zathura_page_t* page = NULL;
  zathura_rectangle_t crop_box;

  /* basic invalid arguments */
  fail_unless(zathura_page_get_crop_box(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_crop_box(page, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_crop_box(NULL, &crop_box) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_page_set_label) {
  zathura_page_t* page = NULL;

  /* basic invalid arguments */
  fail_unless(zathura_page_set_label(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_set_label(page, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_set_label(page, "")   == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_set_label(NULL, "a")  == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_page_get_label) {
  zathura_page_t* page = NULL;
  const char* label;

  /* basic invalid arguments */
  fail_unless(zathura_page_get_label(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_label(page, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_label(NULL, &label) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_page_get_text) {
  zathura_page_t* page = NULL;
  char* text;
  zathura_rectangle_t rectangle = { 0, 0, 0, 0};

  /* basic invalid arguments */
  fail_unless(zathura_page_get_text(NULL, NULL, rectangle) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_text(page, NULL, rectangle) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_text(NULL, &text, rectangle) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_page_get_links) {
  zathura_page_t* page = NULL;
  zathura_list_t* links;;

  /* basic invalid arguments */
  fail_unless(zathura_page_get_links(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_links(page, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_links(NULL, &links) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_page_get_form_fields) {
  zathura_page_t* page = NULL;
  zathura_list_t* form_fields;

  /* basic invalid arguments */
  fail_unless(zathura_page_get_form_fields(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_form_fields(page, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_form_fields(NULL, &form_fields) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_page_get_images) {
  zathura_page_t* page = NULL;
  zathura_list_t* images;

  /* basic invalid arguments */
  fail_unless(zathura_page_get_images(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_images(page, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_images(NULL, &images) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_page_search_text) {
  zathura_page_t* page = NULL;
  zathura_list_t* results;
  const char* text;

  /* basic invalid arguments */
  fail_unless(zathura_page_search_text(NULL, NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_search_text(page, NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_search_text(page, "",   NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_search_text(page, "a",  NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_search_text(page, "",   &results) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_page_get_annotations) {
  zathura_page_t* page = NULL;
  zathura_list_t* annotations;

  /* basic invalid arguments */
  fail_unless(zathura_page_get_annotations(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_annotations(page, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_annotations(NULL, &annotations) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_page_render) {
  zathura_page_t* page = NULL;
  zathura_image_buffer_t* buffer;

  /* basic invalid arguments */
  fail_unless(zathura_page_render(NULL, NULL, 0, 0, 0)     == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_render(page, NULL, 0, 0, 0)     == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_render(page, &buffer, -1, 0, 0) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

#ifdef HAVE_CAIRO
START_TEST(test_page_render_cairo) {
  zathura_page_t* page = NULL;
  cairo_t* cairo;

  /* basic invalid arguments */
  fail_unless(zathura_page_render(NULL, NULL, 0, 0, 0)   == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_render(page, NULL, 0, 0, 0)   == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_render(page, cairo, -1, 0, 0) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST
#endif

Suite*
suite_page(void)
{
  TCase* tcase = NULL;
  Suite* suite = suite_create("page");

  tcase = tcase_create("basic");
  tcase_add_test(tcase, test_page_new);
  tcase_add_test(tcase, test_page_free);
  tcase_add_test(tcase, test_page_get_index);
  tcase_add_test(tcase, test_page_set_width);
  tcase_add_test(tcase, test_page_get_width);
  tcase_add_test(tcase, test_page_set_height);
  tcase_add_test(tcase, test_page_get_height);
  tcase_add_test(tcase, test_page_get_transition);
  tcase_add_test(tcase, test_page_get_duration);
  tcase_add_test(tcase, test_page_get_crop_box);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("label");
  tcase_add_test(tcase, test_page_set_label);
  tcase_add_test(tcase, test_page_get_label);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("text");
  tcase_add_test(tcase, test_page_get_text);
  tcase_add_test(tcase, test_page_search_text);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("annotations");
  tcase_add_test(tcase, test_page_get_annotations);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("links");
  tcase_add_test(tcase, test_page_get_links);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("forms");
  tcase_add_test(tcase, test_page_get_form_fields);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("images");
  tcase_add_test(tcase, test_page_get_images);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("render");
  tcase_add_test(tcase, test_page_render);
#ifdef HAVE_CAIRO
  tcase_add_test(tcase, test_page_render_cairo);
#endif
  suite_add_tcase(suite, tcase);

  return suite;
}

/* See LICENSE file for license and copyright information */

#include <check.h>
#include <fiu.h>
#include <fiu-control.h>

#include "page.h"
#include "form-fields.h"
#include "plugin-manager.h"
#include "plugin-api.h"
#include "internal.h"

zathura_page_t* page = NULL;
zathura_document_t* document;
zathura_plugin_manager_t* plugin_manager;

static void setup_page(void) {
  fail_unless(zathura_plugin_manager_new(&plugin_manager) == ZATHURA_ERROR_OK);
  fail_unless(plugin_manager != NULL);
  fail_unless(zathura_plugin_manager_load(plugin_manager, "./plugin/plugin.so") == ZATHURA_ERROR_OK);

  zathura_plugin_t* plugin = NULL;
  fail_unless(zathura_plugin_manager_get_plugin(plugin_manager, &plugin, "libzathura/test-plugin") == ZATHURA_ERROR_OK);
  fail_unless(plugin != NULL);

  fail_unless(zathura_plugin_open_document(plugin, &document, "Makefile", NULL) == ZATHURA_ERROR_OK);
  fail_unless(document != NULL);

  fail_unless(zathura_document_get_page(document, 0, &page) == ZATHURA_ERROR_OK);
  fail_unless(page != NULL);
}

static void teardown_page(void) {
  fail_unless(zathura_document_free(document) == ZATHURA_ERROR_OK);
  document = NULL;

  fail_unless(zathura_plugin_manager_free(plugin_manager) == ZATHURA_ERROR_OK);
  plugin_manager = NULL;
}

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

START_TEST(test_page_set_data) {
  void* data = (void*) 0xCAFEBABE;

  /* basic invalid arguments */
  fail_unless(zathura_page_set_data(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_set_data(page, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_set_data(NULL, data) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_page_set_data(page, data) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_page_get_data) {
  void* data;

  /* basic invalid arguments */
  fail_unless(zathura_page_get_data(NULL, NULL)  == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_data(page, NULL)  == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_data(NULL, &data) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_page_get_data(page, &data) == ZATHURA_ERROR_OK);

  fail_unless(zathura_page_set_data(page, (void*) 0xCAFEBABE) == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_get_data(page, &data) == ZATHURA_ERROR_OK);
  fail_unless(data == (void*) 0xCAFEBABE);
} END_TEST

START_TEST(test_page_set_document) {
  zathura_page_t* page = NULL;
  fail_unless(zathura_page_new(&page) == ZATHURA_ERROR_OK);
  fail_unless(page != NULL);

  zathura_document_t* document;
  fail_unless(zathura_document_new(&document) == ZATHURA_ERROR_OK);
  fail_unless(document != NULL);

  /* basic invalid arguments */
  fail_unless(zathura_page_set_document(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_set_document(page, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_set_document(NULL, document) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_page_set_document(page, document) == ZATHURA_ERROR_OK);

  /* clean-up */
  fail_unless(zathura_page_free(page) == ZATHURA_ERROR_OK);
  fail_unless(zathura_document_free(document) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_page_get_document) {
  zathura_page_t* page = NULL;
  fail_unless(zathura_page_new(&page) == ZATHURA_ERROR_OK);
  fail_unless(page != NULL);

  zathura_document_t* document = (zathura_document_t*) 0xCAFEBABE;

  /* basic invalid arguments */
  fail_unless(zathura_page_get_document(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_document(page, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_document(NULL, &document) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_page_get_document(page, &document) == ZATHURA_ERROR_OK);

  /* clean-up */
  fail_unless(zathura_page_free(page) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_page_set_index) {
  zathura_page_t* page = NULL;
  fail_unless(zathura_page_new(&page) == ZATHURA_ERROR_OK);
  fail_unless(page != NULL);

  /* basic invalid arguments */
  fail_unless(zathura_page_set_index(NULL, 0) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_page_set_index(page, 0) == ZATHURA_ERROR_OK);

  /* clean-up */
  fail_unless(zathura_page_free(page) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_page_get_index) {
  zathura_page_t* page = NULL;
  fail_unless(zathura_page_new(&page) == ZATHURA_ERROR_OK);
  fail_unless(page != NULL);

  unsigned int index;

  /* basic invalid arguments */
  fail_unless(zathura_page_get_index(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_index(page, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_index(NULL, &index) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_page_set_index(page, 0) == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_get_index(page, &index) == ZATHURA_ERROR_OK);
  fail_unless(index == 0);

  /* clean-up */
  fail_unless(zathura_page_free(page) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_page_set_width) {
  zathura_page_t* page = NULL;
  fail_unless(zathura_page_new(&page) == ZATHURA_ERROR_OK);
  fail_unless(page != NULL);

  /* basic invalid arguments */
  fail_unless(zathura_page_set_width(NULL, 0) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_page_set_width(page, 100) == ZATHURA_ERROR_OK);

  /* clean-up */
  fail_unless(zathura_page_free(page) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_page_get_width) {
  zathura_page_t* page = NULL;
  fail_unless(zathura_page_new(&page) == ZATHURA_ERROR_OK);
  fail_unless(page != NULL);

  unsigned int width;

  /* basic invalid arguments */
  fail_unless(zathura_page_get_width(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_width(page, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_width(NULL, &width) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_page_set_width(page, 100) == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_get_width(page, &width) == ZATHURA_ERROR_OK);
  fail_unless(width == 100);

  /* clean-up */
  fail_unless(zathura_page_free(page) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_page_set_height) {
  zathura_page_t* page = NULL;
  fail_unless(zathura_page_new(&page) == ZATHURA_ERROR_OK);
  fail_unless(page != NULL);

  /* basic invalid arguments */
  fail_unless(zathura_page_set_height(NULL, 0) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_page_set_height(page, 100) == ZATHURA_ERROR_OK);

  /* clean-up */
  fail_unless(zathura_page_free(page) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_page_get_height) {
  zathura_page_t* page = NULL;
  fail_unless(zathura_page_new(&page) == ZATHURA_ERROR_OK);
  fail_unless(page != NULL);

  unsigned int height;

  /* basic invalid arguments */
  fail_unless(zathura_page_get_height(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_height(page, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_height(NULL, &height) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_page_set_height(page, 100) == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_get_height(page, &height) == ZATHURA_ERROR_OK);
  fail_unless(height == 100);

  /* clean-up */
  fail_unless(zathura_page_free(page) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_page_set_transition) {
  zathura_page_t* page = NULL;
  fail_unless(zathura_page_new(&page) == ZATHURA_ERROR_OK);
  fail_unless(page != NULL);

  zathura_page_transition_t* transition = (zathura_page_transition_t*) 0xCAFEBABE;

  /* basic invalid arguments */
  fail_unless(zathura_page_set_transition(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_set_transition(page, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_set_transition(NULL, transition) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_page_set_transition(page, transition) == ZATHURA_ERROR_OK);

  /* clean-up */
  fail_unless(zathura_page_free(page) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_page_get_transition) {
  zathura_page_t* page = NULL;
  fail_unless(zathura_page_new(&page) == ZATHURA_ERROR_OK);
  fail_unless(page != NULL);

  zathura_page_transition_t* transition;

  /* basic invalid arguments */
  fail_unless(zathura_page_get_transition(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_transition(page, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_transition(NULL, &transition) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_page_get_transition(page, &transition) == ZATHURA_ERROR_OK);

  /* clean-up */
  fail_unless(zathura_page_free(page) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_page_set_duration) {
  zathura_page_t* page = NULL;
  fail_unless(zathura_page_new(&page) == ZATHURA_ERROR_OK);
  fail_unless(page != NULL);

  /* basic invalid arguments */
  fail_unless(zathura_page_set_duration(NULL, 0) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_page_set_duration(page, 0) == ZATHURA_ERROR_OK);

  /* clean-up */
  fail_unless(zathura_page_free(page) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_page_get_duration) {
  zathura_page_t* page = NULL;
  fail_unless(zathura_page_new(&page) == ZATHURA_ERROR_OK);
  fail_unless(page != NULL);

  unsigned int duration;

  /* basic invalid arguments */
  fail_unless(zathura_page_get_duration(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_duration(page, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_duration(NULL, &duration) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_page_get_duration(page, &duration) == ZATHURA_ERROR_OK);

  /* clean-up */
  fail_unless(zathura_page_free(page) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_page_set_crop_box) {
  zathura_page_t* page = NULL;
  fail_unless(zathura_page_new(&page) == ZATHURA_ERROR_OK);
  fail_unless(page != NULL);

  zathura_rectangle_t crop_box;

  /* basic invalid arguments */
  fail_unless(zathura_page_set_crop_box(NULL, crop_box) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_page_set_crop_box(page, crop_box) == ZATHURA_ERROR_OK);

  /* clean-up */
  fail_unless(zathura_page_free(page) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_page_get_crop_box) {
  zathura_page_t* page = NULL;
  fail_unless(zathura_page_new(&page) == ZATHURA_ERROR_OK);
  fail_unless(page != NULL);

  zathura_rectangle_t crop_box;

  /* basic invalid arguments */
  fail_unless(zathura_page_get_crop_box(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_crop_box(page, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_crop_box(NULL, &crop_box) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_page_get_crop_box(page, &crop_box) == ZATHURA_ERROR_OK);

  /* clean-up */
  fail_unless(zathura_page_free(page) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_page_set_label) {
  zathura_page_t* page = NULL;
  fail_unless(zathura_page_new(&page) == ZATHURA_ERROR_OK);
  fail_unless(page != NULL);

  /* basic invalid arguments */
  fail_unless(zathura_page_set_label(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_set_label(page, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_set_label(page, "")   == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_set_label(NULL, "a")  == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_page_set_label(page, "a")  == ZATHURA_ERROR_OK);

  fiu_enable("libc/mm/calloc", 1, NULL, 0);
  fail_unless(zathura_page_set_label(page, "a")  == ZATHURA_ERROR_OUT_OF_MEMORY);
  fiu_disable("libc/mm/calloc");

  /* clean-up */
  fail_unless(zathura_page_free(page) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_page_get_label) {
  zathura_page_t* page = NULL;
  fail_unless(zathura_page_new(&page) == ZATHURA_ERROR_OK);
  fail_unless(page != NULL);

  const char* label;

  /* basic invalid arguments */
  fail_unless(zathura_page_get_label(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_label(page, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_label(NULL, &label) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_page_get_label(page, &label) == ZATHURA_ERROR_OK);

  /* clean-up */
  fail_unless(zathura_page_free(page) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_page_get_text) {
  char* text;

  /* basic invalid arguments */
  fail_unless(zathura_page_get_text(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_text(page, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_page_get_text(page, &text) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_page_get_selected_text) {
  char* text;
  zathura_rectangle_t rectangle = { {0, 0}, {0, 0}};

  /* basic invalid arguments */
  fail_unless(zathura_page_get_selected_text(NULL, NULL, rectangle) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_selected_text(page, NULL, rectangle) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_selected_text(NULL, &text, rectangle) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_page_get_selected_text(page, &text, rectangle) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_page_get_links) {
  zathura_list_t* links;;

  /* basic invalid arguments */
  fail_unless(zathura_page_get_links(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_links(page, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_links(NULL, &links) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_page_get_links(page, &links) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_page_get_form_fields) {
  zathura_list_t* form_fields;

  /* basic invalid arguments */
  fail_unless(zathura_page_get_form_fields(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_form_fields(page, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_form_fields(NULL, &form_fields) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_page_get_form_fields(page, &form_fields) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_page_save_form_field) {
  zathura_form_field_t* form_field;
  fail_unless(zathura_form_field_new(&form_field, ZATHURA_FORM_FIELD_TEXT) == ZATHURA_ERROR_OK);
  fail_unless(form_field != NULL);

  /* basic invalid arguments */
  fail_unless(zathura_page_save_form_field(NULL, NULL)       == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_save_form_field(page, NULL)       == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_save_form_field(NULL, form_field) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_page_save_form_field(page, form_field) == ZATHURA_ERROR_OK);
  fail_unless(zathura_form_field_free(form_field) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_page_get_images) {
  zathura_list_t* images;

  /* basic invalid arguments */
  fail_unless(zathura_page_get_images(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_images(page, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_images(NULL, &images) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_page_get_images(page, &images) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_page_search_text) {
  zathura_list_t* results;

  /* basic invalid arguments */
  fail_unless(zathura_page_search_text(NULL, NULL, ZATHURA_SEARCH_DEFAULT, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_search_text(page, NULL, ZATHURA_SEARCH_DEFAULT, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_search_text(page, "",   ZATHURA_SEARCH_DEFAULT, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_search_text(page, "a",  ZATHURA_SEARCH_DEFAULT, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_search_text(page, "",   ZATHURA_SEARCH_DEFAULT, &results) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_page_search_text(page, "abc", ZATHURA_SEARCH_DEFAULT, &results) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_page_get_annotations) {
  zathura_list_t* annotations;

  /* basic invalid arguments */
  fail_unless(zathura_page_get_annotations(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_annotations(page, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_get_annotations(NULL, &annotations) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_page_get_annotations(page, &annotations) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_page_render) {
  zathura_image_buffer_t* buffer;

  /* basic invalid arguments */
  fail_unless(zathura_page_render(NULL, NULL, 0, 0, 0)     == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_render(page, NULL, 0, 0, 0)     == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_render(page, &buffer, -1, 0, 0) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_page_render(page, &buffer, 1.0, 0, 0) == ZATHURA_ERROR_OK);
} END_TEST

#ifdef HAVE_CAIRO
START_TEST(test_page_render_cairo) {
  cairo_t* cairo = (cairo_t*) 0xCAFEBABE;

  /* basic invalid arguments */
  fail_unless(zathura_page_render_cairo(NULL, NULL, 0, 0, 0)   == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_render_cairo(page, NULL, 0, 0, 0)   == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_page_render_cairo(page, cairo, -1, 0, 0) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_page_render_cairo(page, cairo, 1.0, 0, 0) == ZATHURA_ERROR_OK);
} END_TEST
#endif

Suite*
suite_page(void)
{
  TCase* tcase = NULL;
  Suite* suite = suite_create("page");

  tcase = tcase_create("basic");
  tcase_add_checked_fixture(tcase, setup_page, teardown_page);
  tcase_add_test(tcase, test_page_new);
  tcase_add_test(tcase, test_page_free);
  tcase_add_test(tcase, test_page_set_data);
  tcase_add_test(tcase, test_page_get_data);
  tcase_add_test(tcase, test_page_set_document);
  tcase_add_test(tcase, test_page_get_document);
  tcase_add_test(tcase, test_page_set_index);
  tcase_add_test(tcase, test_page_get_index);
  tcase_add_test(tcase, test_page_set_width);
  tcase_add_test(tcase, test_page_get_width);
  tcase_add_test(tcase, test_page_set_height);
  tcase_add_test(tcase, test_page_get_height);
  tcase_add_test(tcase, test_page_set_transition);
  tcase_add_test(tcase, test_page_get_transition);
  tcase_add_test(tcase, test_page_set_duration);
  tcase_add_test(tcase, test_page_get_duration);
  tcase_add_test(tcase, test_page_set_crop_box);
  tcase_add_test(tcase, test_page_get_crop_box);
  tcase_add_test(tcase, test_page_set_label);
  tcase_add_test(tcase, test_page_get_label);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("text");
  tcase_add_checked_fixture(tcase, setup_page, teardown_page);
  tcase_add_test(tcase, test_page_get_text);
  tcase_add_test(tcase, test_page_get_selected_text);
  tcase_add_test(tcase, test_page_search_text);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("annotations");
  tcase_add_checked_fixture(tcase, setup_page, teardown_page);
  tcase_add_test(tcase, test_page_get_annotations);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("links");
  tcase_add_checked_fixture(tcase, setup_page, teardown_page);
  tcase_add_test(tcase, test_page_get_links);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("forms");
  tcase_add_checked_fixture(tcase, setup_page, teardown_page);
  tcase_add_test(tcase, test_page_get_form_fields);
  tcase_add_test(tcase, test_page_save_form_field);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("images");
  tcase_add_checked_fixture(tcase, setup_page, teardown_page);
  tcase_add_test(tcase, test_page_get_images);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("render");
  tcase_add_checked_fixture(tcase, setup_page, teardown_page);
  tcase_add_test(tcase, test_page_render);
#ifdef HAVE_CAIRO
  tcase_add_test(tcase, test_page_render_cairo);
#endif
  suite_add_tcase(suite, tcase);

  return suite;
}

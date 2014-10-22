/* See LICENSE file for license and copyright information */

#include <check.h>

#include "document.h"
#include "plugin-manager.h"
#include "plugin-api.h"

zathura_document_t* document;
zathura_plugin_manager_t* plugin_manager;

static void setup_document(void) {
  fail_unless(zathura_plugin_manager_new(&plugin_manager) == ZATHURA_ERROR_OK);
  fail_unless(plugin_manager != NULL);
  fail_unless(zathura_plugin_manager_load(plugin_manager, "./plugin/plugin.so") == ZATHURA_ERROR_OK);

  zathura_plugin_t* plugin = NULL;
  fail_unless(zathura_plugin_manager_get_plugin(plugin_manager, &plugin, "libzathura/test-plugin") == ZATHURA_ERROR_OK);
  fail_unless(plugin != NULL);

  fail_unless(zathura_plugin_open_document(plugin, &document, "Makefile", NULL) == ZATHURA_ERROR_OK);
  fail_unless(document != NULL);
}

static void teardown_document(void) {
  fail_unless(zathura_document_free(document) == ZATHURA_ERROR_OK);
  document = NULL;

  fail_unless(zathura_plugin_manager_free(plugin_manager) == ZATHURA_ERROR_OK);
  plugin_manager = NULL;
}

START_TEST(test_document_free) {
  /* basic invalid arguments */
  fail_unless(zathura_document_free(NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_document_save_as) {
  const char* path = "abc";

  /* basic invalid arguments */
  fail_unless(zathura_document_save_as(NULL,     NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_save_as(document, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_save_as(document, "")   == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_save_as(NULL,     path) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_document_save_as(document, path) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_document_get_path) {
  char* path;

  /* basic invalid arguments */
  fail_unless(zathura_document_get_path(NULL,     NULL)  == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_path(document, NULL)  == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_path(NULL,     &path) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_document_get_path(document, &path) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_document_set_number_of_pages) {
  /* basic invalid arguments */
  fail_unless(zathura_document_set_number_of_pages(NULL, 1) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_document_set_number_of_pages(document, 1) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_document_get_number_of_pages) {
  unsigned int number_of_pages;

  /* basic invalid arguments */
  fail_unless(zathura_document_get_number_of_pages(NULL,     NULL)  == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_number_of_pages(document, NULL)  == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_number_of_pages(NULL,     &number_of_pages) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_document_get_number_of_pages(document, &number_of_pages) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_document_get_page) {
  zathura_page_t* page;

  /* basic invalid arguments */
  fail_unless(zathura_document_get_page(NULL,     0, NULL)  == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_page(document, 0, NULL)  == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_page(NULL,     0, &page) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_document_get_page(document, 0, &page) == ZATHURA_ERROR_OK);
  fail_unless(zathura_document_get_page(document, 100, &page) == ZATHURA_ERROR_DOCUMENT_INVALID_INDEX);
} END_TEST

START_TEST(test_document_get_page_by_label) {
  zathura_page_t* page;

  /* basic invalid arguments */
  fail_unless(zathura_document_get_page_by_label(NULL,     NULL,  NULL)  == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_page_by_label(document, NULL,  NULL)  == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_page_by_label(document, "",    NULL)  == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_page_by_label(document, "abc", NULL)  == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_page_by_label(document, "",    &page) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_document_get_page_by_label(document, "abc", &page) == ZATHURA_ERROR_OK);
  fail_unless(zathura_document_get_page_by_label(document, "xyz", &page) == ZATHURA_ERROR_DOCUMENT_INVALID_LABEL);
} END_TEST

START_TEST(test_document_set_page_mode) {
  /* basic invalid arguments */
  fail_unless(zathura_document_set_page_mode(NULL, ZATHURA_PAGE_MODE_USE_NONE) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_document_set_page_mode(document, ZATHURA_PAGE_MODE_USE_NONE) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_document_get_page_mode) {
  zathura_page_mode_t page_mode;

  /* basic invalid arguments */
  fail_unless(zathura_document_get_page_mode(NULL,     NULL)   == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_page_mode(document, NULL)   == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_page_mode(NULL, &page_mode) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_document_get_page_mode(document, &page_mode) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_document_set_page_layout) {
  /* basic invalid arguments */
  fail_unless(zathura_document_set_page_layout(NULL, ZATHURA_PAGE_LAYOUT_SINGLE_PAGE) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_document_set_page_layout(document, ZATHURA_PAGE_LAYOUT_SINGLE_PAGE) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_document_get_page_layout) {
  zathura_page_layout_t page_layout;

  /* basic invalid arguments */
  fail_unless(zathura_document_get_page_layout(NULL,     NULL)     == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_page_layout(document, NULL)     == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_page_layout(NULL, &page_layout) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_document_get_page_layout(document, &page_layout) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_document_get_outline) {
  zathura_node_t* outline;

  /* basic invalid arguments */
  fail_unless(zathura_document_get_outline(NULL,     NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_outline(document, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_outline(NULL, &outline) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_document_get_outline(document, &outline) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_document_get_attachments) {
  zathura_list_t* attachments;

  /* basic invalid arguments */
  fail_unless(zathura_document_get_attachments(NULL,     NULL)     == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_attachments(document, NULL)     == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_attachments(NULL, &attachments) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_document_get_attachments(document, &attachments) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_document_get_metadata) {
  zathura_list_t* metadata;

  /* basic invalid arguments */
  fail_unless(zathura_document_get_metadata(NULL,     NULL)   == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_metadata(document, NULL)   == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_metadata(NULL, &metadata) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_document_get_metadata(document, &metadata) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_document_set_permissions) {
  /* basic invalid arguments */
  fail_unless(zathura_document_set_permissions(NULL, ZATHURA_PERMISSION_PRINT)   == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_document_set_permissions(document, ZATHURA_PERMISSION_PRINT) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_document_get_permissions) {
  zathura_document_permission_t permissions;

  /* basic invalid arguments */
  fail_unless(zathura_document_get_permissions(NULL,     NULL)   == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_permissions(document, NULL)   == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_permissions(NULL, &permissions) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_document_get_permissions(document, &permissions) == ZATHURA_ERROR_OK);
} END_TEST

Suite*
suite_document(void)
{
  TCase* tcase = NULL;
  Suite* suite = suite_create("document");

  tcase = tcase_create("basic");
  tcase_add_checked_fixture(tcase, setup_document, teardown_document);
  tcase_add_test(tcase, test_document_free);
  tcase_add_test(tcase, test_document_get_path);
  tcase_add_test(tcase, test_document_set_number_of_pages);
  tcase_add_test(tcase, test_document_get_number_of_pages);
  tcase_add_test(tcase, test_document_set_page_mode);
  tcase_add_test(tcase, test_document_get_page_mode);
  tcase_add_test(tcase, test_document_set_page_layout);
  tcase_add_test(tcase, test_document_get_page_layout);
  tcase_add_test(tcase, test_document_set_permissions);
  tcase_add_test(tcase, test_document_get_permissions);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("save-as");
  tcase_add_checked_fixture(tcase, setup_document, teardown_document);
  tcase_add_test(tcase, test_document_save_as);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("pages");
  tcase_add_checked_fixture(tcase, setup_document, teardown_document);
  tcase_add_test(tcase, test_document_get_page);
  tcase_add_test(tcase, test_document_get_page_by_label);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("outline");
  tcase_add_checked_fixture(tcase, setup_document, teardown_document);
  tcase_add_test(tcase, test_document_get_outline);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("attachments");
  tcase_add_checked_fixture(tcase, setup_document, teardown_document);
  tcase_add_test(tcase, test_document_get_attachments);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("metadata");
  tcase_add_checked_fixture(tcase, setup_document, teardown_document);
  tcase_add_test(tcase, test_document_get_metadata);
  suite_add_tcase(suite, tcase);

  return suite;
}

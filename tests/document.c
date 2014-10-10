/* See LICENSE file for license and copyright information */

#include <check.h>

#include "document.h"
#include "plugin-api.h"

START_TEST(test_document_free) {
  /* basic invalid arguments */
  fail_unless(zathura_document_free(NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_document_save_as) {
  zathura_document_t* document = (zathura_document_t*) 0xCAFE;
  const char* path = "abc";

  /* basic invalid arguments */
  fail_unless(zathura_document_save_as(NULL,     NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_save_as(document, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_save_as(document, "")   == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_save_as(NULL,     path) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_document_get_path) {
  zathura_document_t* document = (zathura_document_t*) 0xCAFEBABE;
  char* path;

  /* basic invalid arguments */
  fail_unless(zathura_document_get_path(NULL,     NULL)  == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_path(document, NULL)  == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_path(NULL,     &path) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_document_get_number_of_pages) {
  zathura_document_t* document = (zathura_document_t*) 0xCAFEBABE;
  unsigned int number_of_pages;

  /* basic invalid arguments */
  fail_unless(zathura_document_get_number_of_pages(NULL,     NULL)  == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_number_of_pages(document, NULL)  == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_number_of_pages(NULL,     &number_of_pages) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_document_get_page) {
  zathura_document_t* document = (zathura_document_t*) 0xCAFEBABE;
  zathura_page_t* page;

  /* basic invalid arguments */
  fail_unless(zathura_document_get_page(NULL,     0, NULL)  == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_page(document, 0, NULL)  == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_page(NULL,     0, &page) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_document_get_page_by_label) {
  zathura_document_t* document = (zathura_document_t*) 0xCAFEBABE;
  zathura_page_t* page;

  /* basic invalid arguments */
  fail_unless(zathura_document_get_page_by_label(NULL,     NULL,  NULL)  == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_page_by_label(document, NULL,  NULL)  == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_page_by_label(document, "",    NULL)  == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_page_by_label(document, "abc", NULL)  == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_page_by_label(document, "",    &page) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_document_get_page_mode) {
  zathura_document_t* document = (zathura_document_t*) 0xCAFEBABE;
  zathura_page_mode_t page_mode;

  /* basic invalid arguments */
  fail_unless(zathura_document_get_page_mode(NULL,     NULL)   == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_page_mode(document, NULL)   == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_page_mode(NULL, &page_mode) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_document_get_page_layout) {
  zathura_document_t* document = (zathura_document_t*) 0xCAFEBABE;
  zathura_page_layout_t page_layout;

  /* basic invalid arguments */
  fail_unless(zathura_document_get_page_layout(NULL,     NULL)     == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_page_layout(document, NULL)     == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_page_layout(NULL, &page_layout) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_document_get_outline) {
  zathura_document_t* document = (zathura_document_t*) 0xCAFEBABE;
  zathura_node_t* outline;

  /* basic invalid arguments */
  fail_unless(zathura_document_get_outline(NULL,     NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_outline(document, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_outline(NULL, &outline) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_document_get_attachments) {
  zathura_document_t* document = (zathura_document_t*) 0xCAFEBABE;
  zathura_list_t* attachments;

  /* basic invalid arguments */
  fail_unless(zathura_document_get_attachments(NULL,     NULL)     == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_attachments(document, NULL)     == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_attachments(NULL, &attachments) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_document_get_metadata) {
  zathura_document_t* document = (zathura_document_t*) 0xCAFEBABE;
  zathura_list_t* metadata;

  /* basic invalid arguments */
  fail_unless(zathura_document_get_metadata(NULL,     NULL)   == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_metadata(document, NULL)   == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_metadata(NULL, &metadata) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_document_get_permissions) {
  zathura_document_t* document = (zathura_document_t*) 0xCAFEBABE;
  zathura_document_permission_t permissions;

  /* basic invalid arguments */
  fail_unless(zathura_document_get_permissions(NULL,     NULL)   == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_permissions(document, NULL)   == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_get_permissions(NULL, &permissions) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

Suite*
suite_document(void)
{
  TCase* tcase = NULL;
  Suite* suite = suite_create("document");

  tcase = tcase_create("basic");
  tcase_add_test(tcase, test_document_free);
  tcase_add_test(tcase, test_document_get_path);
  tcase_add_test(tcase, test_document_get_number_of_pages);
  tcase_add_test(tcase, test_document_get_page_mode);
  tcase_add_test(tcase, test_document_get_page_layout);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("save-as");
  tcase_add_test(tcase, test_document_save_as);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("pages");
  tcase_add_test(tcase, test_document_get_page);
  tcase_add_test(tcase, test_document_get_page_by_label);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("outline");
  tcase_add_test(tcase, test_document_get_outline);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("attachments");
  tcase_add_test(tcase, test_document_get_attachments);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("metadata");
  tcase_add_test(tcase, test_document_get_metadata);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("permissions");
  tcase_add_test(tcase, test_document_get_permissions);
  suite_add_tcase(suite, tcase);

  return suite;
}

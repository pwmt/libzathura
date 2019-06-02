/* See LICENSE file for license and copyright information */

#include <check.h>
#include <fiu.h>
#include <fiu-control.h>

#include <libzathura/metadata.h>
#include <libzathura/plugin-api.h>

#include "tests.h"

zathura_document_meta_entry_t* document_meta_entry;

static void setup_document_meta_entry(void) {
  fail_unless(zathura_document_meta_entry_new(&document_meta_entry,
        ZATHURA_DOCUMENT_META_OTHER, "test") == ZATHURA_ERROR_OK);
}

static void teardown_document_meta_entry(void) {
  fail_unless(zathura_document_meta_entry_free(document_meta_entry) ==
      ZATHURA_ERROR_OK);
  document_meta_entry = NULL;
}

START_TEST(test_document_meta_entry_new) {
  zathura_document_meta_entry_t* document_meta_entry;
  zathura_document_meta_type_t type = ZATHURA_DOCUMENT_META_OTHER;
  const char* value = "test";

  /* basic invalid arguments */
  fail_unless(zathura_document_meta_entry_new(NULL, type, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_meta_entry_new(NULL, type, value) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_meta_entry_new(&document_meta_entry, type, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  fail_unless(zathura_document_meta_entry_new(&document_meta_entry, type, value) == ZATHURA_ERROR_OK);
  fail_unless(zathura_document_meta_entry_free(document_meta_entry) == ZATHURA_ERROR_OK);

  /* fault injection */
#ifdef WITH_LIBFIU
  fiu_enable("libc/mm/calloc", 1, NULL, 0);
  fail_unless(zathura_document_meta_entry_new(&document_meta_entry, type, value) == ZATHURA_ERROR_OUT_OF_MEMORY);
  fiu_disable("libc/mm/calloc");
#endif
} END_TEST

START_TEST(test_document_meta_entry_free) {
  /* basic invalid arguments */
  fail_unless(zathura_document_meta_entry_free(NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_document_meta_entry_get_type) {
  zathura_document_meta_type_t type = ZATHURA_DOCUMENT_META_OTHER;

  /* basic invalid arguments */
  fail_unless(zathura_document_meta_entry_get_type(NULL,  NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_meta_entry_get_type(document_meta_entry, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_meta_entry_get_type(NULL, &type) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_document_meta_entry_get_type(document_meta_entry, &type) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_document_meta_entry_get_value) {
  const char* value;

  /* basic invalid arguments */
  fail_unless(zathura_document_meta_entry_get_value(NULL,  NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_meta_entry_get_value(document_meta_entry, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_document_meta_entry_get_value(NULL, &value) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_document_meta_entry_get_value(document_meta_entry, &value) == ZATHURA_ERROR_OK);
} END_TEST

Suite*
create_suite(void)
{
  TCase* tcase = NULL;
  Suite* suite = suite_create("document-meta-entry");

  tcase = tcase_create("basic");
  tcase_add_test(tcase, test_document_meta_entry_free);
  tcase_add_test(tcase, test_document_meta_entry_new);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("properties");
  tcase_add_checked_fixture(tcase, setup_document_meta_entry, teardown_document_meta_entry);
  tcase_add_test(tcase, test_document_meta_entry_get_type);
  tcase_add_test(tcase, test_document_meta_entry_get_value);
  suite_add_tcase(suite, tcase);

  return suite;
}

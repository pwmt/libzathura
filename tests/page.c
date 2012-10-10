/* See LICENSE file for license and copyright information */

#include <check.h>

#include "page.h"
#include "plugin-api.h"

START_TEST(test_page_new) {
  zathura_page_t* page;

  /* basic invalid arguments */
  fail_unless(zathura_page_new(NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_page_new(&page) == ZATHURA_ERROR_OK);
  fail_unless(zathura_page_free(page) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_page_free) {
  fail_unless(zathura_page_free(NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

Suite*
suite_page(void)
{
  TCase* tcase = NULL;
  Suite* suite = suite_create("page");

  tcase = tcase_create("basic");
  tcase_add_test(tcase, test_page_free);
  tcase_add_test(tcase, test_page_new);
  suite_add_tcase(suite, tcase);

  return suite;
}

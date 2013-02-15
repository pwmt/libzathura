/* See LICENSE file for license and copyright information */

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fiu.h>

#include "internal.h"

START_TEST(test_zathura_realpath) {
  char* real_path;

  /* basic invalid arguments */
  fail_unless(zathura_realpath(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_realpath(NULL, &real_path) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_realpath("",   NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_realpath("a",  NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_realpath("",   &real_path) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_realpath("./plugin", &real_path) == ZATHURA_ERROR_OK);
  free(real_path);

  /* fault injection */
  fiu_enable("libc/mm/calloc", 1, NULL, 0);
  fail_unless(zathura_realpath("./plugin", &real_path) == ZATHURA_ERROR_OUT_OF_MEMORY);
  fiu_disable("libc/mm/calloc");
} END_TEST

START_TEST(test_zathura_guess_type) {
  char* type;

  /* basic invalid arguments */
  fail_unless(zathura_guess_type(NULL, NULL)  == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_guess_type(NULL, &type) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_guess_type("",   NULL)  == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_guess_type("a",  NULL)  == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_guess_type("file.pdf", &type) == ZATHURA_ERROR_OK);
  fail_unless(strcmp(type, "application/pdf") == 0);
  free(type);

  fail_unless(zathura_guess_type("file.djvu", &type) == ZATHURA_ERROR_OK);
  fail_unless(strcmp(type, "image/vnd.djvu") == 0);
  free(type);
} END_TEST

Suite*
suite_internal(void)
{
  TCase* tcase = NULL;
  Suite* suite = suite_create("internal");

  tcase = tcase_create("zathura_realpath");
  tcase_add_test(tcase, test_zathura_realpath);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("zathura_guess_type");
  tcase_add_test(tcase, test_zathura_guess_type);
  suite_add_tcase(suite, tcase);

  return suite;
}

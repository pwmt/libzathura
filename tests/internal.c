/* See LICENSE file for license and copyright information */

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
} END_TEST

Suite*
suite_internal(void)
{
  TCase* tcase = NULL;
  Suite* suite = suite_create("internal");

  tcase = tcase_create("zathura_realpath");
  tcase_add_test(tcase, test_zathura_realpath);
  suite_add_tcase(suite, tcase);

  return suite;
}

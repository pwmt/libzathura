/* See LICENSE file for license and copyright information */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <check.h>
#include <fiu.h>
#include <fiu-control.h>

#include <libzathura/internal.h>

#include "tests.h"

/* forward declarations */
char* guess_type_magic(const char* path);
char* guess_type_file(const char* path);
char* guess_type_glib(const char* path);

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
#ifdef WITH_LIBFIU
  fiu_enable("libc/mm/calloc", 1, NULL, 0);
  fail_unless(zathura_realpath("./plugin", &real_path) == ZATHURA_ERROR_OUT_OF_MEMORY);
  fiu_disable("libc/mm/calloc");
#endif
} END_TEST

START_TEST(test_zathura_guess_type) {
  char* type;

  /* basic invalid arguments */
  fail_unless(zathura_guess_type(NULL, NULL)  == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_guess_type(NULL, &type) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_guess_type("",   NULL)  == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_guess_type("a",  NULL)  == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_guess_type("files/empty.pdf", &type) == ZATHURA_ERROR_OK);
  fail_unless(type != NULL);
  fail_unless(strcmp(type, "application/pdf") == 0);
  free(type);
} END_TEST

START_TEST(test_zathura_guess_type_glib) {
  /* basic invalid arguments */
  fail_unless(guess_type_glib(NULL) == NULL);
  fail_unless(guess_type_glib("")   == NULL);
  fail_unless(guess_type_glib("a")  == NULL);

  /* valid arguments */
  char* content_type = guess_type_glib("files/empty.pdf");
  fail_unless(content_type != NULL);
  fail_unless(strcmp(content_type, "application/pdf") == 0);
  g_free(content_type);
} END_TEST

START_TEST(test_zathura_guess_type_file) {
  /* basic invalid arguments */
  fail_unless(guess_type_file(NULL) == NULL);
  fail_unless(guess_type_file("")   == NULL);

  /* valid arguments */
  char* content_type = guess_type_file("files/empty.pdf");
  fail_unless(content_type != NULL);
  fail_unless(strcmp(content_type, "application/pdf") == 0);
  g_free(content_type);
} END_TEST

#ifdef WITH_MAGIC
START_TEST(test_zathura_guess_type_magic) {
  /* basic invalid arguments */
  fail_unless(guess_type_magic(NULL) == NULL);
  fail_unless(guess_type_magic("")   == NULL);

  /* valid arguments */
  char* content_type = guess_type_magic("files/empty.pdf");
  fail_unless(content_type != NULL);
  fail_unless(strcmp(content_type, "application/pdf") == 0);
  g_free(content_type);
} END_TEST
#endif

Suite*
create_suite(void)
{
  TCase* tcase = NULL;
  Suite* suite = suite_create("internal");

  tcase = tcase_create("zathura_realpath");
  tcase_add_test(tcase, test_zathura_realpath);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("zathura_guess_type");
  tcase_add_test(tcase, test_zathura_guess_type);
  tcase_add_test(tcase, test_zathura_guess_type_glib);
  tcase_add_test(tcase, test_zathura_guess_type_file);
#ifdef WITH_MAGIC
  tcase_add_test(tcase, test_zathura_guess_type_magic);
#endif
  suite_add_tcase(suite, tcase);

  return suite;
}

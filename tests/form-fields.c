/* See LICENSE file for license and copyright information */

#include <check.h>
#include <limits.h>

#include "form-fields.h"
#include "plugin-api.h"

zathura_form_field_t* form_field;

static void teardown(void) {
  fail_unless(zathura_form_field_free(form_field) == ZATHURA_ERROR_OK);
  form_field = NULL;
}

START_TEST(test_form_field_free) {
  /* basic invalid arguments */
  fail_unless(zathura_form_field_free(NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_form_field_new) {
  zathura_form_field_t* form_field;

  /* basic invalid arguments */
  fail_unless(zathura_form_field_new(NULL, 0) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_new(&form_field, INT_MAX) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_form_field_new(&form_field, ZATHURA_FORM_FIELD_BUTTON) == ZATHURA_ERROR_OK);
  fail_unless(zathura_form_field_free(form_field) == ZATHURA_ERROR_OK);

  fail_unless(zathura_form_field_new(&form_field, ZATHURA_FORM_FIELD_TEXT) == ZATHURA_ERROR_OK);
  fail_unless(zathura_form_field_free(form_field) == ZATHURA_ERROR_OK);

  fail_unless(zathura_form_field_new(&form_field, ZATHURA_FORM_FIELD_CHOICE) == ZATHURA_ERROR_OK);
  fail_unless(zathura_form_field_free(form_field) == ZATHURA_ERROR_OK);

  fail_unless(zathura_form_field_new(&form_field, ZATHURA_FORM_FIELD_SIGNATURE) == ZATHURA_ERROR_OK);
  fail_unless(zathura_form_field_free(form_field) == ZATHURA_ERROR_OK);
} END_TEST

Suite*
suite_form_fields(void)
{
  TCase* tcase = NULL;
  Suite* suite = suite_create("form_field");

  tcase = tcase_create("basic");
  tcase_add_test(tcase, test_form_field_free);
  tcase_add_test(tcase, test_form_field_new);
  suite_add_tcase(suite, tcase);

  return suite;
}

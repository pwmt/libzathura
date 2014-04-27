/* See LICENSE file for license and copyright information */

#include <check.h>

#include "form-fields.h"

static void setup_form_field_text(void) {
  fail_unless(zathura_form_field_new(&form_field, ZATHURA_FORM_FIELD_TEXT) == ZATHURA_ERROR_OK);
}

#define TEST_FORM_FIELD_TEXT_SET_TYPE(form_field_var, type) \
  fail_unless(zathura_form_field_text_set_type((form_field_var), (type)) == ZATHURA_ERROR_OK);

#define TEST_FORM_FIELD_TEXT_GET_TYPE(form_field_var, type_var, type) \
  fail_unless(zathura_form_field_text_get_type((form_field_var), &(type_var)) == ZATHURA_ERROR_OK); \
  fail_unless((type_var) == (type)); \

START_TEST(test_form_field_text_get_type) {
  zathura_form_field_text_type_t type;

  /* invalid arguments */
  fail_unless(zathura_form_field_text_get_type(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_text_get_type(form_field, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_text_get_type(NULL, &type) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  TEST_FORM_FIELD_TEXT_SET_TYPE(form_field, ZATHURA_FORM_FIELD_TEXT_TYPE_NORMAL)
  TEST_FORM_FIELD_TEXT_GET_TYPE(form_field, type, ZATHURA_FORM_FIELD_TEXT_TYPE_NORMAL)

  TEST_FORM_FIELD_TEXT_SET_TYPE(form_field, ZATHURA_FORM_FIELD_TEXT_TYPE_MULTILINE)
  TEST_FORM_FIELD_TEXT_GET_TYPE(form_field, type, ZATHURA_FORM_FIELD_TEXT_TYPE_MULTILINE)

  TEST_FORM_FIELD_TEXT_SET_TYPE(form_field, ZATHURA_FORM_FIELD_TEXT_TYPE_FILE_SELECT)
  TEST_FORM_FIELD_TEXT_GET_TYPE(form_field, type, ZATHURA_FORM_FIELD_TEXT_TYPE_FILE_SELECT)
} END_TEST

START_TEST(test_form_field_text_set_type) {
  /* invalid arguments */
  fail_unless(zathura_form_field_text_set_type(NULL, ZATHURA_FORM_FIELD_TEXT_TYPE_NORMAL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_text_set_type(form_field, INT_MAX) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  TEST_FORM_FIELD_TEXT_SET_TYPE(form_field, ZATHURA_FORM_FIELD_TEXT_TYPE_NORMAL)
  TEST_FORM_FIELD_TEXT_SET_TYPE(form_field, ZATHURA_FORM_FIELD_TEXT_TYPE_MULTILINE)
  TEST_FORM_FIELD_TEXT_SET_TYPE(form_field, ZATHURA_FORM_FIELD_TEXT_TYPE_FILE_SELECT)
} END_TEST

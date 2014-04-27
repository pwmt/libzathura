/* See LICENSE file for license and copyright information */

#include <check.h>

#include "form-fields.h"

static void setup_form_field_choice(void) {
  fail_unless(zathura_form_field_new(&form_field, ZATHURA_FORM_FIELD_CHOICE) == ZATHURA_ERROR_OK);
}

#define TEST_FORM_FIELD_CHOICE_SET_TYPE(form_field_var, type) \
  fail_unless(zathura_form_field_choice_set_type((form_field_var), (type)) == ZATHURA_ERROR_OK);

#define TEST_FORM_FIELD_CHOICE_GET_TYPE(form_field_var, type_var, type) \
  fail_unless(zathura_form_field_choice_get_type((form_field_var), &(type_var)) == ZATHURA_ERROR_OK); \
  fail_unless((type_var) == (type)); \

START_TEST(test_form_field_choice_get_type) {
  zathura_form_field_choice_type_t type;

  /* invalid arguments */
  fail_unless(zathura_form_field_choice_get_type(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_choice_get_type(form_field, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_choice_get_type(NULL, &type) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  TEST_FORM_FIELD_CHOICE_SET_TYPE(form_field, ZATHURA_FORM_FIELD_CHOICE_TYPE_LIST)
  TEST_FORM_FIELD_CHOICE_GET_TYPE(form_field, type, ZATHURA_FORM_FIELD_CHOICE_TYPE_LIST)

  TEST_FORM_FIELD_CHOICE_SET_TYPE(form_field, ZATHURA_FORM_FIELD_CHOICE_TYPE_COMBO)
  TEST_FORM_FIELD_CHOICE_GET_TYPE(form_field, type, ZATHURA_FORM_FIELD_CHOICE_TYPE_COMBO)
} END_TEST

START_TEST(test_form_field_choice_set_type) {
  /* invalid arguments */
  fail_unless(zathura_form_field_choice_set_type(NULL, ZATHURA_FORM_FIELD_CHOICE_TYPE_LIST) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_choice_set_type(form_field, INT_MAX) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  TEST_FORM_FIELD_CHOICE_SET_TYPE(form_field, ZATHURA_FORM_FIELD_CHOICE_TYPE_LIST)
  TEST_FORM_FIELD_CHOICE_SET_TYPE(form_field, ZATHURA_FORM_FIELD_CHOICE_TYPE_COMBO)
} END_TEST


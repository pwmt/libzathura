/* See LICENSE file for license and copyright information */

#include <check.h>

#include "form-fields.h"

static void setup_form_field_button(void) {
  fail_unless(zathura_form_field_new(&form_field, ZATHURA_FORM_FIELD_BUTTON) == ZATHURA_ERROR_OK);
}

#define TEST_FORM_FIELD_BUTTON_SET_TYPE(form_field_var, type) \
  fail_unless(zathura_form_field_button_set_type((form_field_var), (type)) == ZATHURA_ERROR_OK);

#define TEST_FORM_FIELD_BUTTON_GET_TYPE(form_field_var, type_var, type) \
  fail_unless(zathura_form_field_button_get_type((form_field_var), &(type_var)) == ZATHURA_ERROR_OK); \
  fail_unless((type_var) == (type)); \

START_TEST(test_form_field_button_get_type) {
  zathura_form_field_button_type_t type;

  TEST_FORM_FIELD_BUTTON_SET_TYPE(form_field, ZATHURA_FORM_FIELD_BUTTON_TYPE_PUSH)
  TEST_FORM_FIELD_BUTTON_GET_TYPE(form_field, type, ZATHURA_FORM_FIELD_BUTTON_TYPE_PUSH)

  TEST_FORM_FIELD_BUTTON_SET_TYPE(form_field, ZATHURA_FORM_FIELD_BUTTON_TYPE_CHECK)
  TEST_FORM_FIELD_BUTTON_GET_TYPE(form_field, type, ZATHURA_FORM_FIELD_BUTTON_TYPE_CHECK)

  TEST_FORM_FIELD_BUTTON_SET_TYPE(form_field, ZATHURA_FORM_FIELD_BUTTON_TYPE_RADIO)
  TEST_FORM_FIELD_BUTTON_GET_TYPE(form_field, type, ZATHURA_FORM_FIELD_BUTTON_TYPE_RADIO)
} END_TEST

START_TEST(test_form_field_button_set_type) {
  TEST_FORM_FIELD_BUTTON_SET_TYPE(form_field, ZATHURA_FORM_FIELD_BUTTON_TYPE_PUSH)
  TEST_FORM_FIELD_BUTTON_SET_TYPE(form_field, ZATHURA_FORM_FIELD_BUTTON_TYPE_CHECK)
  TEST_FORM_FIELD_BUTTON_SET_TYPE(form_field, ZATHURA_FORM_FIELD_BUTTON_TYPE_RADIO)
} END_TEST

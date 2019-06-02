/* See LICENSE file for license and copyright information */

#include <check.h>

#include <libzathura/form-fields.h>

static void setup_form_field_button(void) {
  setup_document_plugin(&plugin_manager, &document);

  fail_unless(zathura_document_get_page(document, 0, &page) == ZATHURA_ERROR_OK);
  fail_unless(page != NULL);

  fail_unless(zathura_form_field_new(page, &form_field, ZATHURA_FORM_FIELD_BUTTON) == ZATHURA_ERROR_OK);
  fail_unless(form_field != NULL);
}

#define TEST_FORM_FIELD_BUTTON_SET_TYPE(form_field_var, type) \
  fail_unless(zathura_form_field_button_set_type((form_field_var), (type)) == ZATHURA_ERROR_OK);

#define TEST_FORM_FIELD_BUTTON_GET_TYPE(form_field_var, type_var, type) \
  fail_unless(zathura_form_field_button_get_type((form_field_var), &(type_var)) == ZATHURA_ERROR_OK); \
  fail_unless((type_var) == (type)); \

START_TEST(test_form_field_button_get_type) {
  zathura_form_field_button_type_t type;

  /* invalid arguments */
  fail_unless(zathura_form_field_button_get_type(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_button_get_type(form_field, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_button_get_type(NULL, &type) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */

  TEST_FORM_FIELD_BUTTON_SET_TYPE(form_field, ZATHURA_FORM_FIELD_BUTTON_TYPE_PUSH)
  TEST_FORM_FIELD_BUTTON_GET_TYPE(form_field, type, ZATHURA_FORM_FIELD_BUTTON_TYPE_PUSH)

  TEST_FORM_FIELD_BUTTON_SET_TYPE(form_field, ZATHURA_FORM_FIELD_BUTTON_TYPE_CHECK)
  TEST_FORM_FIELD_BUTTON_GET_TYPE(form_field, type, ZATHURA_FORM_FIELD_BUTTON_TYPE_CHECK)

  TEST_FORM_FIELD_BUTTON_SET_TYPE(form_field, ZATHURA_FORM_FIELD_BUTTON_TYPE_RADIO)
  TEST_FORM_FIELD_BUTTON_GET_TYPE(form_field, type, ZATHURA_FORM_FIELD_BUTTON_TYPE_RADIO)
} END_TEST

START_TEST(test_form_field_button_set_type) {
  /* invalid arguments */
  fail_unless(zathura_form_field_button_set_type(NULL, 0) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_button_set_type(form_field, INT_MAX) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  TEST_FORM_FIELD_BUTTON_SET_TYPE(form_field, ZATHURA_FORM_FIELD_BUTTON_TYPE_PUSH)
  TEST_FORM_FIELD_BUTTON_SET_TYPE(form_field, ZATHURA_FORM_FIELD_BUTTON_TYPE_CHECK)
  TEST_FORM_FIELD_BUTTON_SET_TYPE(form_field, ZATHURA_FORM_FIELD_BUTTON_TYPE_RADIO)
} END_TEST

START_TEST(test_form_field_button_get_state) {
  bool state;

  /* invalid arguments */
  fail_unless(zathura_form_field_button_get_state(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_button_get_state(NULL, &state) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_button_get_state(form_field, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_form_field_button_set_state(form_field, true) == ZATHURA_ERROR_OK);
  fail_unless(zathura_form_field_button_get_state(form_field, &state) == ZATHURA_ERROR_OK);
  fail_unless(state == true);

  fail_unless(zathura_form_field_button_set_state(form_field, false) == ZATHURA_ERROR_OK);
  fail_unless(zathura_form_field_button_get_state(form_field, &state) == ZATHURA_ERROR_OK);
  fail_unless(state == false);
} END_TEST

START_TEST(test_form_field_button_set_state) {
  /* invalid arguments */
  fail_unless(zathura_form_field_button_set_state(NULL, true) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_form_field_button_set_state(form_field, true) == ZATHURA_ERROR_OK);
  fail_unless(zathura_form_field_button_set_state(form_field, false) == ZATHURA_ERROR_OK);
} END_TEST

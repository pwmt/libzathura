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

#define TEST_FORM_FIELD_GET_TYPE(form_field_var, type_var, type) \
  fail_unless(zathura_form_field_new(&(form_field_var), (type)) == ZATHURA_ERROR_OK); \
  fail_unless(zathura_form_field_get_type((form_field_var), &(type_var)) == ZATHURA_ERROR_OK); \
  fail_unless((type_var) == (type)); \
  fail_unless(zathura_form_field_free((form_field_var)) == ZATHURA_ERROR_OK);

START_TEST(test_form_field_get_type) {
  /* invalid arguments */
  fail_unless(zathura_form_field_get_type(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  zathura_form_field_t* form_field;
  zathura_form_field_type_t type;

  TEST_FORM_FIELD_GET_TYPE(form_field, type, ZATHURA_FORM_FIELD_BUTTON)
  TEST_FORM_FIELD_GET_TYPE(form_field, type, ZATHURA_FORM_FIELD_TEXT)
  TEST_FORM_FIELD_GET_TYPE(form_field, type, ZATHURA_FORM_FIELD_CHOICE)
  TEST_FORM_FIELD_GET_TYPE(form_field, type, ZATHURA_FORM_FIELD_SIGNATURE)
} END_TEST

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

Suite*
suite_form_fields(void)
{
  TCase* tcase = NULL;
  Suite* suite = suite_create("form-fields");

  tcase = tcase_create("basic");
  tcase_add_test(tcase, test_form_field_free);
  tcase_add_test(tcase, test_form_field_new);
  tcase_add_test(tcase, test_form_field_get_type);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("button");
  tcase_add_checked_fixture(tcase, setup_form_field_button, teardown);
  tcase_add_test(tcase, test_form_field_button_get_type);
  tcase_add_test(tcase, test_form_field_button_set_type);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("text");
  tcase_add_checked_fixture(tcase, setup_form_field_text, teardown);
  tcase_add_test(tcase, test_form_field_text_get_type);
  tcase_add_test(tcase, test_form_field_text_set_type);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("choice");
  tcase_add_checked_fixture(tcase, setup_form_field_choice, teardown);
  tcase_add_test(tcase, test_form_field_choice_get_type);
  tcase_add_test(tcase, test_form_field_choice_set_type);
  suite_add_tcase(suite, tcase);

  return suite;
}

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

#define TEST_FORM_FIELD_TEXT_BOOLEAN(test_set_function, set_function, test_get_function, get_function) \
  START_TEST((test_set_function)) { \
    fail_unless((set_function)(NULL, true) == ZATHURA_ERROR_INVALID_ARGUMENTS); \
    \
    fail_unless((set_function)(form_field, true)  == ZATHURA_ERROR_OK); \
    fail_unless((set_function)(form_field, false) == ZATHURA_ERROR_OK); \
  } END_TEST \
  \
  START_TEST((test_get_function)) { \
    bool value; \
    \
    fail_unless((get_function)(NULL, NULL)       == ZATHURA_ERROR_INVALID_ARGUMENTS); \
    fail_unless((get_function)(NULL, &value)     == ZATHURA_ERROR_INVALID_ARGUMENTS); \
    fail_unless((get_function)(form_field, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS); \
    \
    fail_unless((set_function)(form_field, true) == ZATHURA_ERROR_OK); \
    fail_unless((get_function)(form_field, &value) == ZATHURA_ERROR_OK); \
    fail_unless(value == true);\
    fail_unless((set_function)(form_field, false) == ZATHURA_ERROR_OK); \
    fail_unless((get_function)(form_field, &value) == ZATHURA_ERROR_OK); \
    fail_unless(value == false);\
  } END_TEST

TEST_FORM_FIELD_TEXT_BOOLEAN(
    test_form_field_text_set_password, zathura_form_field_text_set_password,
    test_form_field_text_is_password, zathura_form_field_text_is_password
    )

TEST_FORM_FIELD_TEXT_BOOLEAN(
    test_form_field_text_set_rich_text, zathura_form_field_text_set_rich_text,
    test_form_field_text_is_rich_text, zathura_form_field_text_is_rich_text
    )

TEST_FORM_FIELD_TEXT_BOOLEAN(
    test_form_field_text_set_scroll, zathura_form_field_text_set_scroll,
    test_form_field_text_do_scroll, zathura_form_field_text_do_scroll
    )

TEST_FORM_FIELD_TEXT_BOOLEAN(
    test_form_field_text_set_spell_check, zathura_form_field_text_set_spell_check,
    test_form_field_text_do_spell_check, zathura_form_field_text_do_spell_check
    )

START_TEST(test_form_field_text_set_max_length) {
  /* invalid arguments */
  fail_unless(zathura_form_field_text_set_max_length(NULL, 0) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_form_field_text_set_max_length(form_field, 0) == ZATHURA_ERROR_OK);
  fail_unless(zathura_form_field_text_set_max_length(form_field, 1) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_form_field_text_get_max_length) {
  unsigned int max_length;
 
  /* invalid arguments */
  fail_unless(zathura_form_field_text_get_max_length(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_text_get_max_length(form_field, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_text_get_max_length(NULL, &max_length) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_form_field_text_get_max_length(form_field, &max_length) == ZATHURA_ERROR_OK);
  fail_unless(max_length == 0); // default

  fail_unless(zathura_form_field_text_set_max_length(form_field, 1) == ZATHURA_ERROR_OK);
  fail_unless(zathura_form_field_text_get_max_length(form_field, &max_length) == ZATHURA_ERROR_OK);
  fail_unless(max_length == 1);

  fail_unless(zathura_form_field_text_set_max_length(form_field, 0) == ZATHURA_ERROR_OK);
  fail_unless(zathura_form_field_text_get_max_length(form_field, &max_length) == ZATHURA_ERROR_OK);
  fail_unless(max_length == 0);
} END_TEST

START_TEST(test_form_field_text_set_text) {
  char* text = "test";

  /* invalid arguments */
  fail_unless(zathura_form_field_text_set_text(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_text_set_text(form_field, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_text_set_text(NULL, text) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_form_field_text_set_text(form_field, text) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_form_field_text_get_text) {
  char* text;
  char* input = "test";

  /* invalid arguments */
  fail_unless(zathura_form_field_text_get_text(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_text_get_text(form_field, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_text_get_text(NULL, &text) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_form_field_text_set_text(form_field, input) == ZATHURA_ERROR_OK);
  fail_unless(zathura_form_field_text_get_text(form_field, &text) == ZATHURA_ERROR_OK);
  fail_unless(g_strcmp0(input, "test") == 0);

  fail_unless(zathura_form_field_text_set_text(form_field, input) == ZATHURA_ERROR_OK);
  fail_unless(zathura_form_field_text_get_text(form_field, &text) == ZATHURA_ERROR_OK);
  fail_unless(g_strcmp0(input, "test") == 0);

  /* longer text than allowed */
  fail_unless(zathura_form_field_text_set_max_length(form_field, 1) == ZATHURA_ERROR_OK);
  fail_unless(zathura_form_field_text_set_text(form_field, input) == ZATHURA_ERROR_UNKNOWN);
} END_TEST

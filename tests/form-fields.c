/* See LICENSE file for license and copyright information */

#include <check.h>
#include <limits.h>
#include <fiu.h>

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

  /* fault injection */
  fiu_enable("libc/mm/calloc", 1, NULL, 0);
  fail_unless(zathura_form_field_new(&form_field, ZATHURA_FORM_FIELD_BUTTON) == ZATHURA_ERROR_OUT_OF_MEMORY);
  fail_unless(zathura_form_field_new(&form_field, ZATHURA_FORM_FIELD_TEXT) == ZATHURA_ERROR_OUT_OF_MEMORY);
  fail_unless(zathura_form_field_new(&form_field, ZATHURA_FORM_FIELD_CHOICE) == ZATHURA_ERROR_OUT_OF_MEMORY);
  fail_unless(zathura_form_field_new(&form_field, ZATHURA_FORM_FIELD_SIGNATURE) == ZATHURA_ERROR_OUT_OF_MEMORY);
  fiu_disable("libc/mm/calloc");
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

#include "form-fields/button.c"
#include "form-fields/text.c"
#include "form-fields/choice.c"
#include "form-fields/choice-item.c"

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
  tcase_add_test(tcase, test_form_field_button_set_type);
  tcase_add_test(tcase, test_form_field_button_get_type);
  tcase_add_test(tcase, test_form_field_button_set_state);
  tcase_add_test(tcase, test_form_field_button_get_state);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("text");
  tcase_add_checked_fixture(tcase, setup_form_field_text, teardown);
  tcase_add_test(tcase, test_form_field_text_set_type);
  tcase_add_test(tcase, test_form_field_text_get_type);
  tcase_add_test(tcase, test_form_field_text_set_max_length);
  tcase_add_test(tcase, test_form_field_text_get_max_length);
  tcase_add_test(tcase, test_form_field_text_set_text);
  tcase_add_test(tcase, test_form_field_text_get_text);
  tcase_add_test(tcase, test_form_field_text_is_password);
  tcase_add_test(tcase, test_form_field_text_set_password);
  tcase_add_test(tcase, test_form_field_text_is_rich_text);
  tcase_add_test(tcase, test_form_field_text_set_rich_text);
  tcase_add_test(tcase, test_form_field_text_do_scroll);
  tcase_add_test(tcase, test_form_field_text_set_scroll);
  tcase_add_test(tcase, test_form_field_text_do_spell_check);
  tcase_add_test(tcase, test_form_field_text_set_spell_check);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("choice-item");
  tcase_add_checked_fixture(tcase, setup_form_field_choice_item, teardown_form_field_choice_item);
  tcase_add_test(tcase, test_form_field_choice_item_new);
  tcase_add_test(tcase, test_form_field_choice_item_free);
  tcase_add_test(tcase, test_form_field_choice_item_select);
  tcase_add_test(tcase, test_form_field_choice_item_deselect);
  tcase_add_test(tcase, test_form_field_choice_item_is_selected);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("choice");
  tcase_add_checked_fixture(tcase, setup_form_field_choice, teardown);
  tcase_add_test(tcase, test_form_field_choice_set_type);
  tcase_add_test(tcase, test_form_field_choice_get_type);
  tcase_add_test(tcase, test_form_field_choice_set_editable);
  tcase_add_test(tcase, test_form_field_choice_is_editable);
  tcase_add_test(tcase, test_form_field_choice_set_sorted);
  tcase_add_test(tcase, test_form_field_choice_is_sorted);
  tcase_add_test(tcase, test_form_field_choice_set_multiselect);
  tcase_add_test(tcase, test_form_field_choice_is_multiselect);
  tcase_add_test(tcase, test_form_field_choice_set_spell_check);
  tcase_add_test(tcase, test_form_field_choice_do_spell_check);
  tcase_add_test(tcase, test_form_field_choice_set_items);
  tcase_add_test(tcase, test_form_field_choice_get_items);
  suite_add_tcase(suite, tcase);

  return suite;
}

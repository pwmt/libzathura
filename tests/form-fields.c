/* See LICENSE file for license and copyright information */

#include <check.h>
#include <limits.h>
#include <fiu.h>
#include <fiu-control.h>

#include "form-fields.h"
#include "plugin-api.h"
#include "utils.h"

zathura_form_field_t* form_field;
zathura_page_t* page;
zathura_document_t* document;
zathura_plugin_manager_t* plugin_manager;

static void setup(void) {
  setup_document_plugin(&plugin_manager, &document);

  fail_unless(zathura_document_get_page(document, 0, &page) == ZATHURA_ERROR_OK);
  fail_unless(page != NULL);

  fail_unless(zathura_form_field_new(page, &form_field, ZATHURA_FORM_FIELD_BUTTON) == ZATHURA_ERROR_OK);
  fail_unless(form_field != NULL);
}

static void teardown(void) {
  fail_unless(zathura_form_field_free(form_field) == ZATHURA_ERROR_OK);
  form_field = NULL;

  fail_unless(zathura_document_free(document) == ZATHURA_ERROR_OK);
  document = NULL;

  fail_unless(zathura_plugin_manager_free(plugin_manager) == ZATHURA_ERROR_OK);
  plugin_manager = NULL;
}

START_TEST(test_form_field_free) {
  /* basic invalid arguments */
  fail_unless(zathura_form_field_free(NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_form_field_new) {
  zathura_form_field_t* form_field;

  /* basic invalid arguments */
  fail_unless(zathura_form_field_new(NULL, NULL, 0) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_new(NULL, &form_field, INT_MAX) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_new(page, NULL, INT_MAX) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_new(page, &form_field, INT_MAX) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_form_field_new(page, &form_field, ZATHURA_FORM_FIELD_UNKNOWN) == ZATHURA_ERROR_OK);
  fail_unless(zathura_form_field_free(form_field) == ZATHURA_ERROR_OK);

  fail_unless(zathura_form_field_new(page, &form_field, ZATHURA_FORM_FIELD_BUTTON) == ZATHURA_ERROR_OK);
  fail_unless(zathura_form_field_free(form_field) == ZATHURA_ERROR_OK);

  fail_unless(zathura_form_field_new(page, &form_field, ZATHURA_FORM_FIELD_TEXT) == ZATHURA_ERROR_OK);
  fail_unless(zathura_form_field_free(form_field) == ZATHURA_ERROR_OK);

  fail_unless(zathura_form_field_new(page, &form_field, ZATHURA_FORM_FIELD_CHOICE) == ZATHURA_ERROR_OK);
  fail_unless(zathura_form_field_free(form_field) == ZATHURA_ERROR_OK);

  fail_unless(zathura_form_field_new(page, &form_field, ZATHURA_FORM_FIELD_SIGNATURE) == ZATHURA_ERROR_OK);
  fail_unless(zathura_form_field_free(form_field) == ZATHURA_ERROR_OK);

  /* fault injection */
  fiu_enable("libc/mm/calloc", 1, NULL, 0);
  fail_unless(zathura_form_field_new(page, &form_field, ZATHURA_FORM_FIELD_BUTTON) == ZATHURA_ERROR_OUT_OF_MEMORY);
  fail_unless(zathura_form_field_new(page, &form_field, ZATHURA_FORM_FIELD_TEXT) == ZATHURA_ERROR_OUT_OF_MEMORY);
  fail_unless(zathura_form_field_new(page, &form_field, ZATHURA_FORM_FIELD_CHOICE) == ZATHURA_ERROR_OUT_OF_MEMORY);
  fail_unless(zathura_form_field_new(page, &form_field, ZATHURA_FORM_FIELD_SIGNATURE) == ZATHURA_ERROR_OUT_OF_MEMORY);
  fiu_disable("libc/mm/calloc");
} END_TEST

#define TEST_FORM_FIELD_GET_TYPE(page, form_field_var, type_var, type) \
  fail_unless(zathura_form_field_new(page, &(form_field_var), (type)) == ZATHURA_ERROR_OK); \
  fail_unless(zathura_form_field_get_type((form_field_var), &(type_var)) == ZATHURA_ERROR_OK); \
  fail_unless((type_var) == (type)); \
  fail_unless(zathura_form_field_free((form_field_var)) == ZATHURA_ERROR_OK);

START_TEST(test_form_field_get_type) {
  zathura_form_field_t* form_field;
  zathura_form_field_type_t type;

  /* invalid arguments */
  fail_unless(zathura_form_field_get_type(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_get_type(form_field, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_get_type(NULL, &type) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  TEST_FORM_FIELD_GET_TYPE(page, form_field, type, ZATHURA_FORM_FIELD_BUTTON)
  TEST_FORM_FIELD_GET_TYPE(page, form_field, type, ZATHURA_FORM_FIELD_TEXT)
  TEST_FORM_FIELD_GET_TYPE(page, form_field, type, ZATHURA_FORM_FIELD_CHOICE)
  TEST_FORM_FIELD_GET_TYPE(page, form_field, type, ZATHURA_FORM_FIELD_SIGNATURE)
} END_TEST

START_TEST(test_form_field_set_name) {
  char* text = "test";

  /* invalid arguments */
  fail_unless(zathura_form_field_set_name(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_set_name(form_field, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_set_name(NULL, text) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_form_field_set_name(form_field, text) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_form_field_get_name) {
  char* text;
  char* input = "test";

  /* invalid arguments */
  fail_unless(zathura_form_field_get_name(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_get_name(form_field, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_get_name(NULL, &text) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_form_field_set_name(form_field, input) == ZATHURA_ERROR_OK);
  fail_unless(zathura_form_field_get_name(form_field, &text) == ZATHURA_ERROR_OK);
  fail_unless(g_strcmp0(input, "test") == 0);

  fail_unless(zathura_form_field_set_name(form_field, input) == ZATHURA_ERROR_OK);
  fail_unless(zathura_form_field_get_name(form_field, &text) == ZATHURA_ERROR_OK);
  fail_unless(g_strcmp0(input, "test") == 0);
} END_TEST

START_TEST(test_form_field_set_partial_name) {
  char* text = "test";

  /* invalid arguments */
  fail_unless(zathura_form_field_set_partial_name(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_set_partial_name(form_field, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_set_partial_name(NULL, text) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_form_field_set_partial_name(form_field, text) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_form_field_get_partial_name) {
  char* text;
  char* input = "test";

  /* invalid arguments */
  fail_unless(zathura_form_field_get_partial_name(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_get_partial_name(form_field, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_get_partial_name(NULL, &text) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_form_field_set_partial_name(form_field, input) == ZATHURA_ERROR_OK);
  fail_unless(zathura_form_field_get_partial_name(form_field, &text) == ZATHURA_ERROR_OK);
  fail_unless(g_strcmp0(input, "test") == 0);

  fail_unless(zathura_form_field_set_partial_name(form_field, input) == ZATHURA_ERROR_OK);
  fail_unless(zathura_form_field_get_partial_name(form_field, &text) == ZATHURA_ERROR_OK);
  fail_unless(g_strcmp0(input, "test") == 0);
} END_TEST

START_TEST(test_form_field_set_mapping_name) {
  char* text = "test";

  /* invalid arguments */
  fail_unless(zathura_form_field_set_mapping_name(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_set_mapping_name(form_field, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_set_mapping_name(NULL, text) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_form_field_set_mapping_name(form_field, text) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_form_field_get_mapping_name) {
  char* text;
  char* input = "test";

  /* invalid arguments */
  fail_unless(zathura_form_field_get_mapping_name(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_get_mapping_name(form_field, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_get_mapping_name(NULL, &text) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_form_field_set_mapping_name(form_field, input) == ZATHURA_ERROR_OK);
  fail_unless(zathura_form_field_get_mapping_name(form_field, &text) == ZATHURA_ERROR_OK);
  fail_unless(g_strcmp0(input, "test") == 0);

  fail_unless(zathura_form_field_set_mapping_name(form_field, input) == ZATHURA_ERROR_OK);
  fail_unless(zathura_form_field_get_mapping_name(form_field, &text) == ZATHURA_ERROR_OK);
  fail_unless(g_strcmp0(input, "test") == 0);
} END_TEST

START_TEST(test_form_field_set_flags) {
  zathura_form_field_flag_t flags = ZATHURA_FORM_FIELD_FLAG_NONE;

  /* invalid arguments */
  fail_unless(zathura_form_field_set_flags(NULL, flags) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_form_field_set_flags(form_field, flags) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_form_field_get_flags) {
  zathura_form_field_flag_t flags;

  /* invalid arguments */
  fail_unless(zathura_form_field_get_flags(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_get_flags(form_field, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_get_flags(NULL, &flags) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_form_field_get_flags(form_field, &flags) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_form_field_set_user_data) {
  void* user_data;

  /* invalid arguments */
  fail_unless(zathura_form_field_set_user_data(NULL, NULL)       == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_set_user_data(form_field, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_set_user_data(NULL, &user_data)      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_form_field_set_user_data(form_field, &user_data) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_form_field_get_user_data) {
  void* user_data = (void*) 0xCAFEBABE;

  /* invalid arguments */
  fail_unless(zathura_form_field_get_user_data(NULL, NULL)       == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_get_user_data(form_field, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_get_user_data(NULL, &user_data)      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_form_field_set_user_data(form_field, user_data)  == ZATHURA_ERROR_OK);

  void* user_data2;
  fail_unless(zathura_form_field_get_user_data(form_field, &user_data2) == ZATHURA_ERROR_OK);
  fail_unless(user_data == user_data2);
} END_TEST

START_TEST(test_form_field_save) {
  zathura_form_field_t* form_field;
  fail_unless(zathura_form_field_new(page, &form_field, ZATHURA_FORM_FIELD_TEXT) == ZATHURA_ERROR_OK);
  fail_unless(form_field != NULL);

  /* basic invalid arguments */
  fail_unless(zathura_form_field_save(NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_form_field_save(form_field) == ZATHURA_ERROR_OK);
  fail_unless(zathura_form_field_free(form_field) == ZATHURA_ERROR_OK);
} END_TEST

#include "form-fields/form-field-button.c"
#include "form-fields/form-field-text.c"
#include "form-fields/form-field-choice.c"
#include "form-fields/form-field-choice-item.c"
#include "form-fields/form-field-signature.c"

Suite*
suite_form_fields(void)
{
  TCase* tcase = NULL;
  Suite* suite = suite_create("form-fields");

  tcase = tcase_create("basic");
  tcase_add_checked_fixture(tcase, setup, teardown);
  tcase_add_test(tcase, test_form_field_free);
  tcase_add_test(tcase, test_form_field_new);
  tcase_add_test(tcase, test_form_field_get_type);
  tcase_add_test(tcase, test_form_field_set_name);
  tcase_add_test(tcase, test_form_field_get_name);
  tcase_add_test(tcase, test_form_field_set_partial_name);
  tcase_add_test(tcase, test_form_field_get_partial_name);
  tcase_add_test(tcase, test_form_field_set_mapping_name);
  tcase_add_test(tcase, test_form_field_get_mapping_name);
  tcase_add_test(tcase, test_form_field_set_flags);
  tcase_add_test(tcase, test_form_field_get_flags);
  tcase_add_test(tcase, test_form_field_set_user_data);
  tcase_add_test(tcase, test_form_field_get_user_data);
  tcase_add_test(tcase, test_form_field_save);
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
  tcase_add_test(tcase, test_form_field_choice_item_set_name);
  tcase_add_test(tcase, test_form_field_choice_item_get_name);
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
  tcase_add_test(tcase, test_form_field_choice_test_with_multiselect);
  tcase_add_test(tcase, test_form_field_choice_test_without_multiselect);
  tcase_add_test(tcase, test_form_field_choice_set_spell_check);
  tcase_add_test(tcase, test_form_field_choice_do_spell_check);
  tcase_add_test(tcase, test_form_field_choice_get_items_invalid);
  tcase_add_test(tcase, test_form_field_choice_get_items_empty);
  tcase_add_test(tcase, test_form_field_choice_get_items);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("signature");
  tcase_add_checked_fixture(tcase, setup_form_field_signature, teardown);
  tcase_add_test(tcase, test_form_field_signature_set_signature);
  tcase_add_test(tcase, test_form_field_signature_get_signature);
  suite_add_tcase(suite, tcase);

  return suite;
}

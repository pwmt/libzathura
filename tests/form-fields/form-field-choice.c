/* See LICENSE file for license and copyright information */

#include <check.h>
#include <stdio.h>

#include <libzathura/form-fields.h>
#include <libzathura/list.h>

static void setup_form_field_choice(void) {
  setup_document_plugin(&plugin_manager, &document);

  fail_unless(zathura_document_get_page(document, 0, &page) == ZATHURA_ERROR_OK);
  fail_unless(page != NULL);

  fail_unless(zathura_form_field_new(page, &form_field, ZATHURA_FORM_FIELD_CHOICE) == ZATHURA_ERROR_OK);
  fail_unless(form_field != NULL);
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

  /* valid arguments */
  TEST_FORM_FIELD_CHOICE_SET_TYPE(form_field, ZATHURA_FORM_FIELD_CHOICE_TYPE_LIST)
  TEST_FORM_FIELD_CHOICE_SET_TYPE(form_field, ZATHURA_FORM_FIELD_CHOICE_TYPE_COMBO)
} END_TEST

#define TEST_FORM_FIELD_CHOICE_BOOLEAN(test_set_function, set_function, test_get_function, get_function) \
  START_TEST(test_set_function) { \
    fail_unless((set_function)(NULL, true) == ZATHURA_ERROR_INVALID_ARGUMENTS); \
    \
    fail_unless((set_function)(form_field, true)  == ZATHURA_ERROR_OK); \
    fail_unless((set_function)(form_field, false) == ZATHURA_ERROR_OK); \
  } END_TEST \
  \
  START_TEST(test_get_function) { \
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

TEST_FORM_FIELD_CHOICE_BOOLEAN(
    test_form_field_choice_set_editable, zathura_form_field_choice_set_editable,
    test_form_field_choice_is_editable, zathura_form_field_choice_is_editable
    )

TEST_FORM_FIELD_CHOICE_BOOLEAN(
    test_form_field_choice_set_sorted, zathura_form_field_choice_set_sorted,
    test_form_field_choice_is_sorted, zathura_form_field_choice_is_sorted
    )

TEST_FORM_FIELD_CHOICE_BOOLEAN(
    test_form_field_choice_set_multiselect, zathura_form_field_choice_set_multiselect,
    test_form_field_choice_is_multiselect, zathura_form_field_choice_is_multiselect
    )

TEST_FORM_FIELD_CHOICE_BOOLEAN(
    test_form_field_choice_set_spell_check, zathura_form_field_choice_set_spell_check,
    test_form_field_choice_do_spell_check, zathura_form_field_choice_do_spell_check
    )

START_TEST(test_form_field_choice_test_with_multiselect) {
  fail_unless(zathura_form_field_choice_set_multiselect(form_field, true) == ZATHURA_ERROR_OK);

  zathura_form_field_choice_item_t* choice_item;
  fail_unless(zathura_form_field_choice_item_new(form_field, &choice_item, "Item") == ZATHURA_ERROR_OK);
  fail_unless(zathura_form_field_choice_item_select(choice_item) == ZATHURA_ERROR_OK);

  bool is_selected;
  fail_unless(zathura_form_field_choice_item_is_selected(choice_item, &is_selected) == ZATHURA_ERROR_OK);
  fail_unless(is_selected == true);

  zathura_form_field_choice_item_t* choice_item2;
  fail_unless(zathura_form_field_choice_item_new(form_field, &choice_item2, "Item 2") == ZATHURA_ERROR_OK);
  fail_unless(zathura_form_field_choice_item_select(choice_item2) == ZATHURA_ERROR_OK);

  fail_unless(zathura_form_field_choice_item_is_selected(choice_item2, &is_selected) == ZATHURA_ERROR_OK);
  fail_unless(is_selected == true);
  fail_unless(zathura_form_field_choice_item_is_selected(choice_item, &is_selected) == ZATHURA_ERROR_OK);
  fail_unless(is_selected == true);
} END_TEST

START_TEST(test_form_field_choice_test_without_multiselect) {
  fail_unless(zathura_form_field_choice_set_multiselect(form_field, false) == ZATHURA_ERROR_OK);

  zathura_form_field_choice_item_t* choice_item;
  fail_unless(zathura_form_field_choice_item_new(form_field, &choice_item, "Item") == ZATHURA_ERROR_OK);
  fail_unless(zathura_form_field_choice_item_select(choice_item) == ZATHURA_ERROR_OK);

  bool is_selected;
  fail_unless(zathura_form_field_choice_item_is_selected(choice_item, &is_selected) == ZATHURA_ERROR_OK);
  fail_unless(is_selected == true);

  zathura_form_field_choice_item_t* choice_item2;
  fail_unless(zathura_form_field_choice_item_new(form_field, &choice_item2, "Item 2") == ZATHURA_ERROR_OK);
  fail_unless(zathura_form_field_choice_item_select(choice_item2) == ZATHURA_ERROR_OK);

  fail_unless(zathura_form_field_choice_item_is_selected(choice_item2, &is_selected) == ZATHURA_ERROR_OK);
  fail_unless(is_selected == true);
  fail_unless(zathura_form_field_choice_item_is_selected(choice_item, &is_selected) == ZATHURA_ERROR_OK);
  fail_unless(is_selected == false);
} END_TEST

START_TEST(test_form_field_choice_get_items_invalid) {
  zathura_list_t* list = NULL;

  /* invalid arguments */
  fail_unless(zathura_form_field_choice_get_items(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_choice_get_items(form_field, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_choice_get_items(NULL, &list) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  zathura_list_free(list);
} END_TEST

START_TEST(test_form_field_choice_get_items_empty) {
  zathura_list_t* list = NULL;

  /* valid arguments */
  fail_unless(zathura_form_field_choice_get_items(form_field, &list) == ZATHURA_ERROR_OK);
  fail_unless(list == NULL);

  zathura_list_free(list);
} END_TEST

START_TEST(test_form_field_choice_get_items) {
  zathura_list_t* list = NULL;

  zathura_form_field_choice_item_t* choice_item;
  fail_unless(zathura_form_field_choice_item_new(form_field, &choice_item, "Item") == ZATHURA_ERROR_OK);

  /* valid arguments */
  fail_unless(zathura_form_field_choice_get_items(form_field, &list) == ZATHURA_ERROR_OK);
  fail_unless(list != NULL);
  fail_unless(zathura_list_length(list) == 1);
} END_TEST

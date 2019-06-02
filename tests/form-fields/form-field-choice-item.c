/* See LICENSE file for license and copyright information */

#include <check.h>
#include <stdio.h>
#include <fiu.h>

#include <libzathura/form-fields.h>
#include <libzathura/list.h>

zathura_form_field_t* form_field;
zathura_form_field_choice_item_t* choice_item;

static void setup_form_field_choice_item(void) {
  setup_document_plugin(&plugin_manager, &document);

  fail_unless(zathura_document_get_page(document, 0, &page) == ZATHURA_ERROR_OK);
  fail_unless(page != NULL);

  fail_unless(zathura_form_field_new(page, &form_field, ZATHURA_FORM_FIELD_CHOICE) == ZATHURA_ERROR_OK);
  fail_unless(form_field != NULL);

  fail_unless(zathura_form_field_choice_item_new(form_field, &choice_item, "Item") == ZATHURA_ERROR_OK);
}

static void teardown_form_field_choice_item(void) {
  fail_unless(zathura_form_field_free(form_field) == ZATHURA_ERROR_OK);
  choice_item = NULL;

  fail_unless(zathura_document_free(document) == ZATHURA_ERROR_OK);
  document = NULL;

  fail_unless(zathura_plugin_manager_free(plugin_manager) == ZATHURA_ERROR_OK);
  plugin_manager = NULL;
}

START_TEST(test_form_field_choice_item_new) {
  zathura_form_field_choice_item_t* item;

  /* invalid arguments */
  fail_unless(zathura_form_field_choice_item_new(NULL, NULL, NULL)         == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_choice_item_new(NULL, &item, NULL)        == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_choice_item_new(NULL, NULL, "name")       == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_choice_item_new(NULL, &item, "name")      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_choice_item_new(form_field, NULL, "name") == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_choice_item_new(form_field, &item, NULL)  == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_form_field_choice_item_new(form_field, &item, "name") == ZATHURA_ERROR_OK);
  fail_unless(item != NULL);

#ifdef WITH_LIBFIU
  fiu_enable("libc/mm/calloc", 1, NULL, 0);
  fail_unless(zathura_form_field_choice_item_new(form_field, &item, "name") == ZATHURA_ERROR_OUT_OF_MEMORY);
  fiu_disable("libc/mm/calloc");
#endif
} END_TEST

START_TEST(test_form_field_choice_item_free) {
  /* invalid arguments */
  fail_unless(zathura_form_field_choice_item_free(NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_form_field_choice_item_select) {
  /* invalid arguments */
  fail_unless(zathura_form_field_choice_item_select(NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid argument */
  fail_unless(zathura_form_field_choice_item_select(choice_item) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_form_field_choice_item_deselect) {
  /* invalid arguments */
  fail_unless(zathura_form_field_choice_item_deselect(NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid argument */
  fail_unless(zathura_form_field_choice_item_deselect(choice_item) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_form_field_choice_item_is_selected) {
  bool is_selected;

  /* invalid arguments */
  fail_unless(zathura_form_field_choice_item_is_selected(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_choice_item_is_selected(choice_item, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_choice_item_is_selected(NULL, &is_selected) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid argument */
  fail_unless(zathura_form_field_choice_item_is_selected(choice_item, &is_selected) == ZATHURA_ERROR_OK);
  fail_unless(is_selected == false);

  fail_unless(zathura_form_field_choice_item_select(choice_item) == ZATHURA_ERROR_OK);
  fail_unless(zathura_form_field_choice_item_is_selected(choice_item, &is_selected) == ZATHURA_ERROR_OK);
  fail_unless(is_selected == true);

  fail_unless(zathura_form_field_choice_item_deselect(choice_item) == ZATHURA_ERROR_OK);
  fail_unless(zathura_form_field_choice_item_is_selected(choice_item, &is_selected) == ZATHURA_ERROR_OK);
  fail_unless(is_selected == false);
} END_TEST

START_TEST(test_form_field_choice_item_set_name) {
  char* name = "test";

  /* invalid arguments */
  fail_unless(zathura_form_field_choice_item_set_name(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_choice_item_set_name(choice_item, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_choice_item_set_name(NULL, name) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_form_field_choice_item_set_name(choice_item, name) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_form_field_choice_item_get_name) {
  char* name;
  char* input = "test";

  /* invalid arguments */
  fail_unless(zathura_form_field_choice_item_get_name(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_choice_item_get_name(choice_item, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_choice_item_get_name(NULL, &name) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_form_field_choice_item_set_name(choice_item, input) == ZATHURA_ERROR_OK);
  fail_unless(zathura_form_field_choice_item_get_name(choice_item, &name) == ZATHURA_ERROR_OK);
  fail_unless(g_strcmp0(input, "test") == 0);

  fail_unless(zathura_form_field_choice_item_set_name(choice_item, input) == ZATHURA_ERROR_OK);
  fail_unless(zathura_form_field_choice_item_get_name(choice_item, &name) == ZATHURA_ERROR_OK);
  fail_unless(g_strcmp0(input, "test") == 0);
} END_TEST

/* See LICENSE file for license and copyright information */

#include <check.h>
#include <stdio.h>

#include "form-fields.h"
#include "list.h"

zathura_form_field_choice_item_t* choice_item;

static void setup_form_field_choice_item(void) {
  fail_unless(zathura_form_field_choice_item_new(&choice_item, "Item") == ZATHURA_ERROR_OK);
}

static void teardown_form_field_choice_item(void) {
  fail_unless(zathura_form_field_choice_item_free(choice_item) == ZATHURA_ERROR_OK);
  choice_item = NULL;
}

START_TEST(test_form_field_choice_item_new) {
  zathura_form_field_choice_item_t* item;

  /* invalid arguments */
  fail_unless(zathura_form_field_choice_item_new(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_choice_item_new(&item, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_choice_item_new(NULL, "name") == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_form_field_choice_item_new(&item, "name") == ZATHURA_ERROR_OK);
  fail_unless(item != NULL);
  fail_unless(zathura_form_field_choice_item_free(item) == ZATHURA_ERROR_OK);
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

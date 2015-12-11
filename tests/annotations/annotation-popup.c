/* See LICENSE file for license and copyright information */

#include <check.h>

#include "annotations.h"

static void setup_annotation_popup(void) {
  setup_document_plugin(&plugin_manager, &document);

  fail_unless(zathura_document_get_page(document, 0, &page) == ZATHURA_ERROR_OK);
  fail_unless(page != NULL);

  fail_unless(zathura_annotation_new(page, &annotation, ZATHURA_ANNOTATION_POPUP) == ZATHURA_ERROR_OK);
  fail_unless(annotation != NULL);
}

START_TEST(test_annotation_popup_new) {
} END_TEST

START_TEST(test_annotation_popup_init) {
  /* invalid arguments */
  fail_unless(zathura_annotation_popup_init(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_popup_init(annotation)
      == ZATHURA_ERROR_OK); // double initialization

  /* fault injection */
  fiu_enable("libc/mm/calloc", 1, NULL, 0);
  fail_unless(zathura_annotation_popup_init(annotation)
      == ZATHURA_ERROR_OUT_OF_MEMORY); // double initialization
  fiu_disable("libc/mm/calloc");
} END_TEST

START_TEST(test_annotation_popup_clear) {
  /* invalid arguments */
  fail_unless(zathura_annotation_popup_clear(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_annotation_popup_get_type) {
  zathura_annotation_type_t type;
  fail_unless(zathura_annotation_get_type(annotation, &type) == ZATHURA_ERROR_OK);
  fail_unless(type == ZATHURA_ANNOTATION_POPUP);
} END_TEST

START_TEST(test_annotation_popup_set_parent) {
  zathura_annotation_t* popup = (zathura_annotation_t*) 0xCAFEBABE;

  /* invalid arguments */
  fail_unless(zathura_annotation_popup_set_parent(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_popup_set_parent(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_popup_set_parent(NULL, popup) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_popup_set_parent(annotation, popup) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_popup_get_parent) {
  zathura_annotation_t* popup;

  /* invalid arguments */
  fail_unless(zathura_annotation_popup_get_parent(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_popup_get_parent(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_popup_get_parent(NULL, &popup) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_popup_get_parent(annotation, &popup) == ZATHURA_ERROR_OK);
  fail_unless(popup == NULL);

  fail_unless(zathura_annotation_popup_set_parent(annotation, (zathura_annotation_t*) 0xCAFEBABE) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_popup_get_parent(annotation, &popup) == ZATHURA_ERROR_OK);
  fail_unless(popup == (zathura_annotation_t*) 0xCAFEBABE);
} END_TEST

START_TEST(test_annotation_popup_set_open) {
  /* invalid arguments */
  fail_unless(zathura_annotation_popup_set_open(NULL, true) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_popup_set_open(annotation, true) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_popup_set_open(annotation, false) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_popup_is_open) {
  bool is_open = false;

  /* invalid arguments */
  fail_unless(zathura_annotation_popup_is_open(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_popup_is_open(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_popup_is_open(NULL, &is_open) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_popup_is_open(annotation, &is_open) == ZATHURA_ERROR_OK);
  fail_unless(is_open == false);

  fail_unless(zathura_annotation_popup_set_open(annotation, true) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_popup_is_open(annotation, &is_open) == ZATHURA_ERROR_OK);
  fail_unless(is_open == true);
} END_TEST

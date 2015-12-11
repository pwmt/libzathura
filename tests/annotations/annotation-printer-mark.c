/* See LICENSE file for license and copyright information */

#include <check.h>

#include "annotations.h"

static void setup_annotation_printer_mark(void) {
  setup_document_plugin(&plugin_manager, &document);

  fail_unless(zathura_document_get_page(document, 0, &page) == ZATHURA_ERROR_OK);
  fail_unless(page != NULL);

  fail_unless(zathura_annotation_new(page, &annotation, ZATHURA_ANNOTATION_PRINTER_MARK) == ZATHURA_ERROR_OK);
  fail_unless(annotation != NULL);
}

START_TEST(test_annotation_printer_mark_new) {
} END_TEST

START_TEST(test_annotation_printer_mark_get_type) {
  zathura_annotation_type_t type;
  fail_unless(zathura_annotation_get_type(annotation, &type) == ZATHURA_ERROR_OK);
  fail_unless(type == ZATHURA_ANNOTATION_PRINTER_MARK);
} END_TEST

START_TEST(test_annotation_printer_mark_init) {
  /* invalid arguments */
  fail_unless(zathura_annotation_printer_mark_init(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_printer_mark_init(annotation)
      == ZATHURA_ERROR_OK); // double initialization

  /* fault injection */
  fiu_enable("libc/mm/calloc", 1, NULL, 0);
  fail_unless(zathura_annotation_printer_mark_init(annotation)
      == ZATHURA_ERROR_OUT_OF_MEMORY); // double initialization
  fiu_disable("libc/mm/calloc");
} END_TEST

START_TEST(test_annotation_printer_mark_clear) {
  /* invalid arguments */
  fail_unless(zathura_annotation_printer_mark_clear(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_annotation_printer_mark_set_name) {
  /* invalid arguments */
  fail_unless(zathura_annotation_printer_mark_set_name(NULL, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_printer_mark_set_name(annotation, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_printer_mark_set_name(NULL, "test")
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_printer_mark_set_name(annotation, "test")
      == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_printer_mark_set_name(annotation, "test")
      == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_printer_mark_get_name) {
  char* name = NULL;

  /* invalid arguments */
  fail_unless(zathura_annotation_printer_mark_get_name(NULL, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_printer_mark_get_name(annotation, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_printer_mark_get_name(NULL, &name)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_printer_mark_get_name(annotation, &name)
      == ZATHURA_ERROR_OK);
  fail_unless(name == NULL);
  fail_unless(zathura_annotation_printer_mark_set_name(annotation, "test")
      == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_printer_mark_get_name(annotation, &name)
      == ZATHURA_ERROR_OK);
  fail_unless(g_strcmp0(name, "test") == 0);
} END_TEST

START_TEST(test_annotation_printer_mark_set_mark_style) {
  /* invalid arguments */
  fail_unless(zathura_annotation_printer_mark_set_mark_style(NULL, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_printer_mark_set_mark_style(annotation, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_printer_mark_set_mark_style(NULL, "test")
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_printer_mark_set_mark_style(annotation, "test")
      == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_printer_mark_set_mark_style(annotation, "test")
      == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_printer_mark_get_mark_style) {
  char* mark_style = NULL;

  /* invalid arguments */
  fail_unless(zathura_annotation_printer_mark_get_mark_style(NULL, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_printer_mark_get_mark_style(annotation, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_printer_mark_get_mark_style(NULL, &mark_style)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_printer_mark_get_mark_style(annotation, &mark_style)
      == ZATHURA_ERROR_OK);
  fail_unless(mark_style == NULL);
  fail_unless(zathura_annotation_printer_mark_set_mark_style(annotation, "test")
      == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_printer_mark_get_mark_style(annotation, &mark_style)
      == ZATHURA_ERROR_OK);
  fail_unless(g_strcmp0(mark_style, "test") == 0);
} END_TEST

START_TEST(test_annotation_printer_mark_set_colorants) {
  zathura_list_t* list = zathura_list_alloc();
  fail_unless(list != NULL);

  /* invalid arguments */
  fail_unless(zathura_annotation_printer_mark_set_colorants(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_printer_mark_set_colorants(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_printer_mark_set_colorants(NULL, list) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_printer_mark_set_colorants(annotation, list) == ZATHURA_ERROR_OK);
  zathura_list_free(list);
} END_TEST

START_TEST(test_annotation_printer_mark_get_colorants) {
  zathura_list_t* list;

  /* invalid arguments */
  fail_unless(zathura_annotation_printer_mark_get_colorants(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_printer_mark_get_colorants(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_printer_mark_get_colorants(NULL, &list) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_printer_mark_get_colorants(annotation, &list) == ZATHURA_ERROR_OK);
  fail_unless(list == NULL);
} END_TEST

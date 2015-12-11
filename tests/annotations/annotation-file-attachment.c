/* See LICENSE file for license and copyright information */

#include <check.h>
#include <glib.h>

#include "attachment.h"
#include "annotations.h"

static void setup_annotation_file(void) {
  setup_document_plugin(&plugin_manager, &document);

  fail_unless(zathura_document_get_page(document, 0, &page) == ZATHURA_ERROR_OK);
  fail_unless(page != NULL);

  fail_unless(zathura_annotation_new(page, &annotation, ZATHURA_ANNOTATION_FILE_ATTACHMENT) == ZATHURA_ERROR_OK);
  fail_unless(annotation != NULL);
}

START_TEST(test_annotation_file_new) {
} END_TEST

START_TEST(test_annotation_file_get_type) {
  zathura_annotation_type_t type;
  fail_unless(zathura_annotation_get_type(annotation, &type) == ZATHURA_ERROR_OK);
  fail_unless(type == ZATHURA_ANNOTATION_FILE_ATTACHMENT);
} END_TEST

START_TEST(test_annotation_file_init) {
  /* invalid arguments */
  fail_unless(zathura_annotation_file_init(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_file_init(annotation)
      == ZATHURA_ERROR_OK); // double initialization

  /* fault injection */
  fiu_enable("libc/mm/calloc", 1, NULL, 0);
  fail_unless(zathura_annotation_file_init(annotation)
      == ZATHURA_ERROR_OUT_OF_MEMORY); // double initialization
  fiu_disable("libc/mm/calloc");
} END_TEST

START_TEST(test_annotation_file_clear) {
  /* invalid arguments */
  fail_unless(zathura_annotation_file_clear(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_annotation_file_set_attachment) {
  zathura_attachment_t* attachment;
  fail_unless(zathura_attachment_new(&attachment) == ZATHURA_ERROR_OK);

  /* invalid arguments */
  fail_unless(zathura_annotation_file_set_attachment(NULL, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_file_set_attachment(annotation, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_file_set_attachment(NULL, attachment)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_file_set_attachment(annotation, attachment)
      == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_file_get_attachment) {
  zathura_attachment_t* attachment;
  zathura_attachment_t* attachment_tmp;

  /* invalid arguments */
  fail_unless(zathura_annotation_file_get_attachment(NULL, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_file_get_attachment(annotation, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_file_get_attachment(NULL, &attachment)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_attachment_new(&attachment_tmp) == ZATHURA_ERROR_OK);

  fail_unless(zathura_annotation_file_set_attachment(annotation, attachment_tmp)
      == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_file_get_attachment(annotation, &attachment)
      == ZATHURA_ERROR_OK);
  fail_unless(attachment == attachment_tmp);
} END_TEST

START_TEST(test_annotation_file_set_icon_name) {
  /* invalid arguments */
  fail_unless(zathura_annotation_file_set_icon_name(NULL, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_file_set_icon_name(annotation, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_file_set_icon_name(NULL, "test")
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_file_set_icon_name(annotation, "test")
      == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_file_set_icon_name(annotation, "test")
      == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_file_get_icon_name) {
  char* icon_name = NULL;

  /* invalid arguments */
  fail_unless(zathura_annotation_file_get_icon_name(NULL, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_file_get_icon_name(annotation, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_file_get_icon_name(NULL, &icon_name)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_file_get_icon_name(annotation, &icon_name)
      == ZATHURA_ERROR_OK);
  fail_unless(icon_name != NULL);
  fail_unless(strcmp(icon_name, "PushPin") == 0);
  fail_unless(zathura_annotation_file_set_icon_name(annotation, "test")
      == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_file_get_icon_name(annotation, &icon_name)
      == ZATHURA_ERROR_OK);
  fail_unless(g_strcmp0(icon_name, "test") == 0);
} END_TEST

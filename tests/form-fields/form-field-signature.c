/* See LICENSE file for license and copyright information */

#include <check.h>

#include <libzathura/form-fields.h>

static void setup_form_field_signature(void) {
  setup_document_plugin(&plugin_manager, &document);

  fail_unless(zathura_document_get_page(document, 0, &page) == ZATHURA_ERROR_OK);
  fail_unless(page != NULL);

  fail_unless(zathura_form_field_new(page, &form_field, ZATHURA_FORM_FIELD_SIGNATURE) == ZATHURA_ERROR_OK);
  fail_unless(form_field != NULL);
}

START_TEST(test_form_field_signature_set_signature) {
  zathura_signature_t* signature = (zathura_signature_t*) 0xCAFEBABE;

  /* invalid arguments */
  fail_unless(zathura_form_field_signature_set_signature(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_signature_set_signature(form_field, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_signature_set_signature(NULL, signature) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_form_field_signature_set_signature(form_field, signature) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_form_field_signature_get_signature) {
  zathura_signature_t* signature = (zathura_signature_t*) 0xCAFEBABE;

  /* invalid arguments */
  fail_unless(zathura_form_field_signature_get_signature(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_signature_get_signature(form_field, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_form_field_signature_get_signature(NULL, &signature) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_form_field_signature_get_signature(form_field, &signature) == ZATHURA_ERROR_OK);

  fail_unless(zathura_form_field_signature_set_signature(form_field, (zathura_signature_t*) 0xCAFED00D) == ZATHURA_ERROR_OK);
  fail_unless(zathura_form_field_signature_get_signature(form_field, &signature) == ZATHURA_ERROR_OK);
  fail_unless(signature == (zathura_signature_t*) 0xCAFED00D);
} END_TEST

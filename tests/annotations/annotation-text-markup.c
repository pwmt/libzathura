/* See LICENSE file for license and copyright information */

#include <check.h>
#include <limits.h>

#include <libzathura/annotations.h>

static void setup_annotation_text_markup(void) {
  setup_document_plugin(&plugin_manager, &document);

  fail_unless(zathura_document_get_page(document, 0, &page) == ZATHURA_ERROR_OK);
  fail_unless(page != NULL);

  fail_unless(zathura_annotation_new(page, &annotation, ZATHURA_ANNOTATION_UNDERLINE) == ZATHURA_ERROR_OK);
  fail_unless(annotation != NULL);
}

START_TEST(test_annotation_text_markup_new) {
} END_TEST

START_TEST(test_annotation_text_markup_init) {
  /* invalid arguments */
  fail_unless(zathura_annotation_text_markup_init(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_text_markup_init(annotation)
      == ZATHURA_ERROR_OK); // double initialization

  /* fault injection */
#ifdef WITH_LIBFIU
  fiu_enable("libc/mm/calloc", 1, NULL, 0);
  fail_unless(zathura_annotation_text_markup_init(annotation)
      == ZATHURA_ERROR_OUT_OF_MEMORY); // double initialization
  fiu_disable("libc/mm/calloc");
#endif
} END_TEST

START_TEST(test_annotation_text_markup_clear) {
  /* invalid arguments */
  fail_unless(zathura_annotation_text_markup_clear(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

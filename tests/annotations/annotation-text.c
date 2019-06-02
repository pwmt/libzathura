/* See LICENSE file for license and copyright information */

#include <check.h>

#include <libzathura/annotations.h>

static void setup_annotation_text(void) {
  setup_document_plugin(&plugin_manager, &document);

  fail_unless(zathura_document_get_page(document, 0, &page) == ZATHURA_ERROR_OK);
  fail_unless(page != NULL);

  fail_unless(zathura_annotation_new(page, &annotation, ZATHURA_ANNOTATION_TEXT) == ZATHURA_ERROR_OK);
  fail_unless(annotation != NULL);
}

START_TEST(test_annotation_text_new) {
} END_TEST

START_TEST(test_annotation_text_get_type) {
  zathura_annotation_type_t type;
  fail_unless(zathura_annotation_get_type(annotation, &type) == ZATHURA_ERROR_OK);
  fail_unless(type == ZATHURA_ANNOTATION_TEXT);
} END_TEST

START_TEST(test_annotation_text_init) {
  /* invalid arguments */
  fail_unless(zathura_annotation_text_init(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_text_init(annotation)
      == ZATHURA_ERROR_OK); // double initialization

  /* fault injection */
#ifdef WITH_LIBFIU
  fiu_enable("libc/mm/calloc", 1, NULL, 0);
  fail_unless(zathura_annotation_text_init(annotation)
      == ZATHURA_ERROR_OUT_OF_MEMORY); // double initialization
  fiu_disable("libc/mm/calloc");
#endif
} END_TEST

START_TEST(test_annotation_text_clear) {
  /* invalid arguments */
  fail_unless(zathura_annotation_text_clear(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_annotation_text_set_icon_name) {
  /* invalid arguments */
  fail_unless(zathura_annotation_text_set_icon_name(NULL, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_text_set_icon_name(annotation, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_text_set_icon_name(NULL, "test")
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_text_set_icon_name(annotation, "test")
      == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_text_set_icon_name(annotation, "test")
      == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_text_get_icon_name) {
  char* icon_name = NULL;

  /* invalid arguments */
  fail_unless(zathura_annotation_text_get_icon_name(NULL, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_text_get_icon_name(annotation, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_text_get_icon_name(NULL, &icon_name)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_text_get_icon_name(annotation, &icon_name)
      == ZATHURA_ERROR_OK);
  fail_unless(icon_name == NULL);
  fail_unless(zathura_annotation_text_set_icon_name(annotation, "test")
      == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_text_get_icon_name(annotation, &icon_name)
      == ZATHURA_ERROR_OK);
  fail_unless(g_strcmp0(icon_name, "test") == 0);
} END_TEST

START_TEST(test_annotation_text_set_open) {
  /* invalid arguments */
  fail_unless(zathura_annotation_text_set_open(NULL, true) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_text_set_open(annotation, true) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_text_set_open(annotation, false) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_text_is_open) {
  bool is_open = false;

  /* invalid arguments */
  fail_unless(zathura_annotation_text_is_open(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_text_is_open(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_text_is_open(NULL, &is_open) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_text_is_open(annotation, &is_open) == ZATHURA_ERROR_OK);
  fail_unless(is_open == false);

  fail_unless(zathura_annotation_text_set_open(annotation, true) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_text_is_open(annotation, &is_open) == ZATHURA_ERROR_OK);
  fail_unless(is_open == true);
} END_TEST

START_TEST(test_annotation_text_set_state) {
  zathura_annotation_text_state_t state = ZATHURA_ANNOTATION_TEXT_STATE_UNKNOWN;

  /* invalid arguments */
  fail_unless(zathura_annotation_text_set_state(NULL, state) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  fail_unless(zathura_annotation_text_set_state(annotation, state) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_text_get_state) {
  zathura_annotation_text_state_t state = ZATHURA_ANNOTATION_TEXT_STATE_UNKNOWN;

  /* invalid arguments */
  fail_unless(zathura_annotation_text_get_state(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_text_get_state(NULL, &state) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_text_get_state(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  fail_unless(zathura_annotation_text_get_state(annotation, &state) == ZATHURA_ERROR_OK);
  fail_unless(state == ZATHURA_ANNOTATION_TEXT_STATE_UNKNOWN);

  fail_unless(zathura_annotation_text_set_state(annotation, ZATHURA_ANNOTATION_TEXT_STATE_UNMARKED) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_text_get_state(annotation, &state) == ZATHURA_ERROR_OK);
  fail_unless(state == ZATHURA_ANNOTATION_TEXT_STATE_UNMARKED);
} END_TEST

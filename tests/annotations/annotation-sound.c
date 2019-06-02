/* See LICENSE file for license and copyright information */

#include <check.h>

#include <libzathura/annotations.h>

static void setup_annotation_sound(void) {
  setup_document_plugin(&plugin_manager, &document);

  fail_unless(zathura_document_get_page(document, 0, &page) == ZATHURA_ERROR_OK);
  fail_unless(page != NULL);

  fail_unless(zathura_annotation_new(page, &annotation, ZATHURA_ANNOTATION_SOUND) == ZATHURA_ERROR_OK);
  fail_unless(annotation != NULL);
}

START_TEST(test_annotation_sound_new) {
} END_TEST

START_TEST(test_annotation_sound_get_type) {
  zathura_annotation_type_t type;
  fail_unless(zathura_annotation_get_type(annotation, &type) == ZATHURA_ERROR_OK);
  fail_unless(type == ZATHURA_ANNOTATION_SOUND);
} END_TEST

START_TEST(test_annotation_sound_init) {
  /* invalid arguments */
  fail_unless(zathura_annotation_sound_init(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_sound_init(annotation)
      == ZATHURA_ERROR_OK); // double initialization

  /* fault injection */
#ifdef WITH_LIBFIU
  fiu_enable("libc/mm/calloc", 1, NULL, 0);
  fail_unless(zathura_annotation_sound_init(annotation)
      == ZATHURA_ERROR_OUT_OF_MEMORY); // double initialization
  fiu_disable("libc/mm/calloc");
#endif
} END_TEST

START_TEST(test_annotation_sound_clear) {
  /* invalid arguments */
  fail_unless(zathura_annotation_sound_clear(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_annotation_sound_set_sound) {
  zathura_sound_t* sound = (zathura_sound_t*) 0xCAFEBABE;

  /* invalid arguments */
  fail_unless(zathura_annotation_sound_set_sound(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_sound_set_sound(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_sound_set_sound(NULL, sound) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_sound_set_sound(annotation, sound) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_sound_get_sound) {
  zathura_sound_t* sound;

  /* invalid arguments */
  fail_unless(zathura_annotation_sound_get_sound(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_sound_get_sound(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_sound_get_sound(NULL, &sound) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_sound_get_sound(annotation, &sound) == ZATHURA_ERROR_OK);
  fail_unless(sound == NULL);

  fail_unless(zathura_annotation_sound_set_sound(annotation, (zathura_sound_t*) 0xCAFEBABE) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_sound_get_sound(annotation, &sound) == ZATHURA_ERROR_OK);
  fail_unless(sound == (zathura_sound_t*) 0xCAFEBABE);
} END_TEST

START_TEST(test_annotation_sound_set_icon_name) {
  /* invalid arguments */
  fail_unless(zathura_annotation_sound_set_icon_name(NULL, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_sound_set_icon_name(annotation, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_sound_set_icon_name(NULL, "test")
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_sound_set_icon_name(annotation, "test")
      == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_sound_set_icon_name(annotation, "test")
      == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_sound_get_icon_name) {
  char* icon_name = NULL;

  /* invalid arguments */
  fail_unless(zathura_annotation_sound_get_icon_name(NULL, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_sound_get_icon_name(annotation, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_sound_get_icon_name(NULL, &icon_name)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_sound_get_icon_name(annotation, &icon_name)
      == ZATHURA_ERROR_OK);
  fail_unless(icon_name != NULL);
  fail_unless(strcmp(icon_name, "Speaker") == 0);
  fail_unless(zathura_annotation_sound_set_icon_name(annotation, "test")
      == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_sound_get_icon_name(annotation, &icon_name)
      == ZATHURA_ERROR_OK);
  fail_unless(g_strcmp0(icon_name, "test") == 0);
} END_TEST

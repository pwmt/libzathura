/* See LICENSE file for license and copyright information */

#include <check.h>

#include <libzathura/annotations.h>

static void setup_annotation_squiggly(void) {
  setup_document_plugin(&plugin_manager, &document);

  fail_unless(zathura_document_get_page(document, 0, &page) == ZATHURA_ERROR_OK);
  fail_unless(page != NULL);

  fail_unless(zathura_annotation_new(page, &annotation, ZATHURA_ANNOTATION_SQUIGGLY) == ZATHURA_ERROR_OK);
  fail_unless(annotation != NULL);
}

START_TEST(test_annotation_squiggly_new) {
} END_TEST

START_TEST(test_annotation_squiggly_get_type) {
  zathura_annotation_type_t type;
  fail_unless(zathura_annotation_get_type(annotation, &type) == ZATHURA_ERROR_OK);
  fail_unless(type == ZATHURA_ANNOTATION_SQUIGGLY);
} END_TEST

START_TEST(test_annotation_squiggly_set_quad_points) {
  zathura_list_t* list = zathura_list_alloc();
  fail_unless(list != NULL);

  /* invalid arguments */
  fail_unless(zathura_annotation_squiggly_set_quad_points(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_squiggly_set_quad_points(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_squiggly_set_quad_points(NULL, list) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_squiggly_set_quad_points(annotation, list) == ZATHURA_ERROR_OK);
  zathura_list_free(list);
} END_TEST

START_TEST(test_annotation_squiggly_get_quad_points) {
  zathura_list_t* list;

  /* invalid arguments */
  fail_unless(zathura_annotation_squiggly_get_quad_points(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_squiggly_get_quad_points(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_squiggly_get_quad_points(NULL, &list) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_squiggly_get_quad_points(annotation, &list) == ZATHURA_ERROR_OK);
  fail_unless(list == NULL);
} END_TEST

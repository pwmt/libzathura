/* See LICENSE file for license and copyright information */

#include <check.h>

#include "annotations.h"

static void setup_annotation_3d(void) {
  fail_unless(zathura_annotation_new(&annotation, ZATHURA_ANNOTATION_3D) == ZATHURA_ERROR_OK);
  fail_unless(annotation != NULL);
}

START_TEST(test_annotation_3d_new) {
} END_TEST

START_TEST(test_annotation_3d_get_type) {
  zathura_annotation_type_t type;
  fail_unless(zathura_annotation_get_type(annotation, &type) == ZATHURA_ERROR_OK);
  fail_unless(type == ZATHURA_ANNOTATION_3D);
} END_TEST

START_TEST(test_annotation_3d_init) {
  /* invalid arguments */
  fail_unless(zathura_annotation_3d_init(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_3d_init(annotation)
      == ZATHURA_ERROR_OK); // double initialization

  /* fault injection */
  fiu_enable("libc/mm/calloc", 1, NULL, 0);
  fail_unless(zathura_annotation_3d_init(annotation)
      == ZATHURA_ERROR_OUT_OF_MEMORY); // double initialization
  fiu_disable("libc/mm/calloc");
} END_TEST

START_TEST(test_annotation_3d_clear) {
  /* invalid arguments */
  fail_unless(zathura_annotation_3d_clear(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_annotation_3d_set_artwork) {
  zathura_3d_t* artwork = (zathura_3d_t*) 0xCAFEBABE;

  /* invalid arguments */
  fail_unless(zathura_annotation_3d_set_artwork(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_3d_set_artwork(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_3d_set_artwork(NULL, artwork) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_3d_set_artwork(annotation, artwork) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_3d_get_artwork) {
  zathura_3d_t* artwork;

  /* invalid arguments */
  fail_unless(zathura_annotation_3d_get_artwork(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_3d_get_artwork(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_3d_get_artwork(NULL, &artwork) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_3d_get_artwork(annotation, &artwork) == ZATHURA_ERROR_OK);
  fail_unless(artwork == NULL);

  fail_unless(zathura_annotation_3d_set_artwork(annotation, (zathura_3d_t*) 0xCAFEBABE) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_3d_get_artwork(annotation, &artwork) == ZATHURA_ERROR_OK);
  fail_unless(artwork == (zathura_3d_t*) 0xCAFEBABE);
} END_TEST

START_TEST(test_annotation_3d_set_view_box) {
  zathura_rectangle_t rectangle = { {0, 0}, {0, 0} };

  /* invalid arguments */
  fail_unless(zathura_annotation_3d_set_view_box(NULL, rectangle) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_3d_set_view_box(annotation, rectangle) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_3d_get_view_box) {
  zathura_rectangle_t rectangle = { {0, 0}, {0, 0} };
  zathura_rectangle_t rectangle_input = { {1, 2}, {3, 4} };

  /* invalid arguments */
  fail_unless(zathura_annotation_3d_get_view_box(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_3d_get_view_box(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_3d_get_view_box(NULL, &rectangle) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_3d_get_view_box(annotation, &rectangle) == ZATHURA_ERROR_OK);
  fail_unless(rectangle.p1.x == 0);
  fail_unless(rectangle.p1.y == 0);
  fail_unless(rectangle.p2.x == 0);
  fail_unless(rectangle.p2.y == 0);

  fail_unless(zathura_annotation_3d_set_view_box(annotation, rectangle_input) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_3d_get_view_box(annotation, &rectangle) == ZATHURA_ERROR_OK);
  fail_unless(rectangle.p1.x == 1);
  fail_unless(rectangle.p1.y == 2);
  fail_unless(rectangle.p2.x == 3);
  fail_unless(rectangle.p2.y == 4);
} END_TEST

START_TEST(test_annotation_3d_set_interactive) {
  /* invalid arguments */
  fail_unless(zathura_annotation_3d_set_interactive(NULL, true) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_3d_set_interactive(annotation, true) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_3d_set_interactive(annotation, false) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_3d_is_interactive) {
  bool is_interactive = false;

  /* invalid arguments */
  fail_unless(zathura_annotation_3d_is_interactive(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_3d_is_interactive(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_3d_is_interactive(NULL, &is_interactive) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_3d_is_interactive(annotation, &is_interactive) == ZATHURA_ERROR_OK);
  fail_unless(is_interactive == false);

  fail_unless(zathura_annotation_3d_set_interactive(annotation, true) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_3d_is_interactive(annotation, &is_interactive) == ZATHURA_ERROR_OK);
  fail_unless(is_interactive == true);
} END_TEST

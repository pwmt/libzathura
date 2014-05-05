/* See LICENSE file for license and copyright information */

#include <check.h>

#include "annotations.h"

static void setup_annotation_square(void) {
  fail_unless(zathura_annotation_new(&annotation, ZATHURA_ANNOTATION_SQUARE) == ZATHURA_ERROR_OK);
  fail_unless(annotation != NULL);
}

START_TEST(test_annotation_square_new) {
} END_TEST

START_TEST(test_annotation_square_get_type) {
  zathura_annotation_type_t type;
  fail_unless(zathura_annotation_get_type(annotation, &type) == ZATHURA_ERROR_OK);
  fail_unless(type == ZATHURA_ANNOTATION_SQUARE);
} END_TEST

START_TEST(test_annotation_square_and_circle_init) {
  /* invalid arguments */
  fail_unless(zathura_annotation_square_and_circle_init(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_square_and_circle_init(annotation)
      == ZATHURA_ERROR_OK); // double initialization

  /* fault injection */
  fiu_enable("libc/mm/calloc", 1, NULL, 0);
  fail_unless(zathura_annotation_square_and_circle_init(annotation)
      == ZATHURA_ERROR_OUT_OF_MEMORY); // double initialization
  fiu_disable("libc/mm/calloc");
} END_TEST

START_TEST(test_annotation_square_and_circle_clear) {
  /* invalid arguments */
  fail_unless(zathura_annotation_square_and_circle_clear(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_annotation_square_set_rectangle) {
  zathura_rectangle_t rectangle = { 0, 0, 0, 0 };

  /* invalid arguments */
  fail_unless(zathura_annotation_square_set_rectangle(NULL, rectangle) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_square_set_rectangle(annotation, rectangle) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_square_get_rectangle) {
  zathura_rectangle_t rectangle = { 0, 0, 0, 0 };
  zathura_rectangle_t rectangle_input = { 1, 2, 3, 4 };

  /* invalid arguments */
  fail_unless(zathura_annotation_square_get_rectangle(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_square_get_rectangle(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_square_get_rectangle(NULL, &rectangle) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_square_get_rectangle(annotation, &rectangle) == ZATHURA_ERROR_OK);
  fail_unless(rectangle.p1.x == 0);
  fail_unless(rectangle.p1.y == 0);
  fail_unless(rectangle.p2.x == 0);
  fail_unless(rectangle.p2.y == 0);

  fail_unless(zathura_annotation_square_set_rectangle(annotation, rectangle_input) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_square_get_rectangle(annotation, &rectangle) == ZATHURA_ERROR_OK);
  fail_unless(rectangle.p1.x == 1);
  fail_unless(rectangle.p1.y == 2);
  fail_unless(rectangle.p2.x == 3);
  fail_unless(rectangle.p2.y == 4);
} END_TEST

START_TEST(test_annotation_square_set_color) {
  zathura_annotation_color_t color = { 0 };

  /* invalid arguments */
  fail_unless(zathura_annotation_square_set_color(NULL, color) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_square_set_color(annotation, color) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_square_get_color) {
  zathura_annotation_color_t color = { 0, 0, 0, 0 };
  zathura_annotation_color_t color_input = { 1, 2, 3, 4 };

  /* invalid arguments */
  fail_unless(zathura_annotation_square_get_color(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_square_get_color(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_square_get_color(NULL, &color) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_square_get_color(annotation, &color) == ZATHURA_ERROR_OK);

  fail_unless(zathura_annotation_square_set_color(annotation, color_input) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_square_get_color(annotation, &color) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_square_set_border) {
  zathura_annotation_border_t border = { 0 };

  /* invalid arguments */
  fail_unless(zathura_annotation_square_set_border(NULL, border) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_square_set_border(annotation, border) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_square_get_border) {
  zathura_annotation_border_t border = { 0 };
  zathura_annotation_border_t border_input = { 1, 2, 3, 4 };

  /* invalid arguments */
  fail_unless(zathura_annotation_square_get_border(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_square_get_border(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_square_get_border(NULL, &border) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_square_get_border(annotation, &border) == ZATHURA_ERROR_OK);

  fail_unless(zathura_annotation_square_set_border(annotation, border_input) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_square_get_border(annotation, &border) == ZATHURA_ERROR_OK);
} END_TEST

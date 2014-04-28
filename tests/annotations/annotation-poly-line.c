/* See LICENSE file for license and copyright information */

#include <check.h>

#include "annotations.h"

static void setup_annotation_poly_line(void) {
  fail_unless(zathura_annotation_new(&annotation, ZATHURA_ANNOTATION_POLY_LINE) == ZATHURA_ERROR_OK);
  fail_unless(annotation != NULL);
}

START_TEST(test_annotation_poly_line_new) {
} END_TEST

START_TEST(test_annotation_poly_line_get_type) {
  zathura_annotation_type_t type;
  fail_unless(zathura_annotation_get_type(annotation, &type) == ZATHURA_ERROR_OK);
  fail_unless(type == ZATHURA_ANNOTATION_POLY_LINE);
} END_TEST

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

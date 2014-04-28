/* See LICENSE file for license and copyright information */

#include <check.h>

#include "annotations.h"

static void setup_annotation_trap_net(void) {
  fail_unless(zathura_annotation_new(&annotation, ZATHURA_ANNOTATION_TRAP_NET) == ZATHURA_ERROR_OK);
  fail_unless(annotation != NULL);
}

START_TEST(test_annotation_trap_net_new) {
} END_TEST

START_TEST(test_annotation_trap_net_get_type) {
  zathura_annotation_type_t type;
  fail_unless(zathura_annotation_get_type(annotation, &type) == ZATHURA_ERROR_OK);
  fail_unless(type == ZATHURA_ANNOTATION_TRAP_NET);
} END_TEST

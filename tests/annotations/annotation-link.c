/* See LICENSE file for license and copyright information */

#include <check.h>

#include "annotations.h"

static void setup_annotation_link(void) {
  fail_unless(zathura_annotation_new(&annotation, ZATHURA_ANNOTATION_LINK) == ZATHURA_ERROR_OK);
  fail_unless(annotation != NULL);
}

START_TEST(test_annotation_link_new) {
} END_TEST

START_TEST(test_annotation_link_get_type) {
  zathura_annotation_type_t type;
  fail_unless(zathura_annotation_get_type(annotation, &type) == ZATHURA_ERROR_OK);
  fail_unless(type == ZATHURA_ANNOTATION_LINK);
} END_TEST

START_TEST(test_annotation_link_init) {
  /* invalid arguments */
  fail_unless(zathura_annotation_link_init(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_link_init(annotation)
      == ZATHURA_ERROR_OK); // double initialization

  /* fault injection */
  fiu_enable("libc/mm/calloc", 1, NULL, 0);
  fail_unless(zathura_annotation_link_init(annotation)
      == ZATHURA_ERROR_OUT_OF_MEMORY); // double initialization
  fiu_disable("libc/mm/calloc");
} END_TEST

START_TEST(test_annotation_link_clear) {
  /* invalid arguments */
  fail_unless(zathura_annotation_link_clear(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_annotation_link_set_action) {
  zathura_action_t* action;

  /* invalid arguments */
  fail_unless(zathura_annotation_link_set_action(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_link_set_action(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_link_set_action(NULL, action) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_link_set_action(annotation, action) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_link_get_action) {
  zathura_action_t* action;

  /* invalid arguments */
  fail_unless(zathura_annotation_link_get_action(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_link_get_action(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_link_get_action(NULL, &action) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_link_get_action(annotation, &action) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_link_set_highlighting_mode) {
  zathura_annotation_link_highlighting_mode_t highlighting_mode;

  /* invalid arguments */
  fail_unless(zathura_annotation_link_set_highlighting_mode(NULL, highlighting_mode) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_link_set_highlighting_mode(annotation, highlighting_mode) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_link_get_highlighting_mode) {
  zathura_annotation_link_highlighting_mode_t highlighting_mode;

  /* invalid arguments */
  fail_unless(zathura_annotation_link_get_highlighting_mode(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_link_get_highlighting_mode(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_link_get_highlighting_mode(NULL, &highlighting_mode) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_link_get_highlighting_mode(annotation, &highlighting_mode) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_link_set_quad_points) {
  zathura_list_t* list = zathura_list_alloc();
  fail_unless(list != NULL);

  /* invalid arguments */
  fail_unless(zathura_annotation_link_set_quad_points(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_link_set_quad_points(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_link_set_quad_points(NULL, list) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_link_set_quad_points(annotation, list) == ZATHURA_ERROR_OK);
  zathura_list_free(list);
} END_TEST

START_TEST(test_annotation_link_get_quad_points) {
  zathura_list_t* list;

  /* invalid arguments */
  fail_unless(zathura_annotation_link_get_quad_points(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_link_get_quad_points(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_link_get_quad_points(NULL, &list) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_link_get_quad_points(annotation, &list) == ZATHURA_ERROR_OK);
  fail_unless(list == NULL);
} END_TEST

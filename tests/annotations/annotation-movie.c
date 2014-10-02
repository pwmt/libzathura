/* See LICENSE file for license and copyright information */

#include <check.h>

#include "annotations.h"

static void setup_annotation_movie(void) {
  fail_unless(zathura_annotation_new(&annotation, ZATHURA_ANNOTATION_MOVIE) == ZATHURA_ERROR_OK);
  fail_unless(annotation != NULL);
}

START_TEST(test_annotation_movie_new) {
} END_TEST

START_TEST(test_annotation_movie_get_type) {
  zathura_annotation_type_t type;
  fail_unless(zathura_annotation_get_type(annotation, &type) == ZATHURA_ERROR_OK);
  fail_unless(type == ZATHURA_ANNOTATION_MOVIE);
} END_TEST

START_TEST(test_annotation_movie_init) {
  /* invalid arguments */
  fail_unless(zathura_annotation_movie_init(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_movie_init(annotation)
      == ZATHURA_ERROR_OK); // double initialization

  /* fault injection */
  fiu_enable("libc/mm/calloc", 1, NULL, 0);
  fail_unless(zathura_annotation_movie_init(annotation)
      == ZATHURA_ERROR_OUT_OF_MEMORY); // double initialization
  fiu_disable("libc/mm/calloc");
} END_TEST

START_TEST(test_annotation_movie_clear) {
  /* invalid arguments */
  fail_unless(zathura_annotation_movie_clear(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_annotation_movie_set_title) {
  /* invalid arguments */
  fail_unless(zathura_annotation_movie_set_title(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_movie_set_title(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_movie_set_title(NULL, "title") == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_movie_set_title(annotation, "title") == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_movie_set_title(annotation, "") == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_movie_get_title) {
  char* title = NULL;

  /* invalid arguments */
  fail_unless(zathura_annotation_movie_get_title(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_movie_get_title(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_movie_get_title(NULL, &title) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_movie_get_title(annotation, &title) == ZATHURA_ERROR_OK);
  fail_unless(title == NULL);
  fail_unless(zathura_annotation_movie_set_title(annotation, "title") == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_movie_get_title(annotation, &title) == ZATHURA_ERROR_OK);
  fail_unless(title != NULL);
  fail_unless(strcmp(title, "title") == 0);
} END_TEST

START_TEST(test_annotation_movie_set_movie) {
  zathura_movie_t* movie = 0xCAFEBABE;

  /* invalid arguments */
  fail_unless(zathura_annotation_movie_set_movie(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_movie_set_movie(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_movie_set_movie(NULL, movie) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_movie_set_movie(annotation, movie) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_movie_get_movie) {
  zathura_movie_t* movie;

  /* invalid arguments */
  fail_unless(zathura_annotation_movie_get_movie(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_movie_get_movie(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_movie_get_movie(NULL, &movie) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_movie_get_movie(annotation, &movie) == ZATHURA_ERROR_OK);
  fail_unless(movie == NULL);

  fail_unless(zathura_annotation_movie_set_movie(annotation, 0xCAFEBABE) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_movie_get_movie(annotation, &movie) == ZATHURA_ERROR_OK);
  fail_unless(movie == 0xCAFEBABE);
} END_TEST

START_TEST(test_annotation_movie_set_movie_activation) {
  zathura_movie_activation_t* activation = 0xCAFEBABE;

  /* invalid arguments */
  fail_unless(zathura_annotation_movie_set_movie_activation(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_movie_set_movie_activation(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_movie_set_movie_activation(NULL, activation) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_movie_set_movie_activation(annotation, activation) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_movie_get_movie_activation) {
  zathura_movie_activation_t* activation;

  /* invalid arguments */
  fail_unless(zathura_annotation_movie_get_movie_activation(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_movie_get_movie_activation(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_movie_get_movie_activation(NULL, &activation) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_movie_get_movie_activation(annotation, &activation) == ZATHURA_ERROR_OK);
  fail_unless(activation == NULL);

  fail_unless(zathura_annotation_movie_set_movie_activation(annotation, 0xCAFEBABE) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_movie_get_movie_activation(annotation, &activation) == ZATHURA_ERROR_OK);
  fail_unless(activation == 0xCAFEBABE);
} END_TEST

START_TEST(test_annotation_movie_set_play_if_activated) {
  /* invalid arguments */
  fail_unless(zathura_annotation_movie_set_play_if_activated(NULL, true) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_movie_set_play_if_activated(annotation, true) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_movie_set_play_if_activated(annotation, false) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_movie_get_play_if_activated) {
  bool play_if_activated = false;

  /* invalid arguments */
  fail_unless(zathura_annotation_movie_play_if_activated(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_movie_play_if_activated(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_movie_play_if_activated(NULL, &play_if_activated) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_movie_play_if_activated(annotation, &play_if_activated) == ZATHURA_ERROR_OK);
  fail_unless(play_if_activated == true);

  fail_unless(zathura_annotation_movie_set_play_if_activated(annotation, false) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_movie_play_if_activated(annotation, &play_if_activated) == ZATHURA_ERROR_OK);
  fail_unless(play_if_activated == false);
} END_TEST

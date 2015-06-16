/* See LICENSE file for license and copyright information */

#include <check.h>
#include <fiu.h>
#include <fiu-control.h>

#include "image.h"
#include "plugin-api.h"

zathura_image_t* image;

static void setup_image(void) {
  zathura_rectangle_t position = { {0, 0}, {100, 100} };
  fail_unless(zathura_image_new(&image, position) == ZATHURA_ERROR_OK);
}

static void teardown_image(void) {
  fail_unless(zathura_image_free(image) == ZATHURA_ERROR_OK);
  image = NULL;
}

START_TEST(test_image_new) {
  zathura_image_t* image;
  zathura_rectangle_t position = { {0, 0}, {100, 100} };

  /* basic invalid arguments */
  fail_unless(zathura_image_new(NULL, position) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* basic invalid arguments */
  fail_unless(zathura_image_new(&image, position) == ZATHURA_ERROR_OK);
  fail_unless(zathura_image_free(image) == ZATHURA_ERROR_OK);

  /* fault injection */
  fiu_enable("libc/mm/calloc", 1, NULL, 0);
  fail_unless(zathura_image_new(&image, position) == ZATHURA_ERROR_OUT_OF_MEMORY);
  fiu_disable("libc/mm/calloc");
} END_TEST

START_TEST(test_image_free) {
  /* basic invalid arguments */
  fail_unless(zathura_image_free(NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_image_get_position) {
  zathura_rectangle_t position;

  /* basic invalid arguments */
  fail_unless(zathura_image_get_position(NULL,  NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_image_get_position(image, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_image_get_position(NULL, &position) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_image_get_position(image, &position) == ZATHURA_ERROR_OK);
} END_TEST

zathura_error_t get_buffer(zathura_image_t* image, zathura_image_buffer_t** buffer)
{
  fail_unless(image != NULL);
  fail_unless(buffer != NULL);

  *buffer = (void*) 0xCAFEBABE;

  return ZATHURA_ERROR_OK;
}

START_TEST(test_image_set_get_buffer_function) {
  /* invalid arguments */
  fail_unless(zathura_image_set_get_buffer_function(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_image_set_get_buffer_function(NULL, get_buffer) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_image_set_get_buffer_function(image, get_buffer) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_image_get_buffer) {
  zathura_image_buffer_t* buffer;

  /* basic invalid arguments */
  fail_unless(zathura_image_get_buffer(NULL,  NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_image_get_buffer(image, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_image_get_buffer(NULL, &buffer) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_image_get_buffer(image, &buffer) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_image_set_get_buffer_function(image, get_buffer) == ZATHURA_ERROR_OK);
  fail_unless(zathura_image_get_buffer(image, &buffer) == ZATHURA_ERROR_OK);
  fail_unless(buffer == (void*) 0xCAFEBABE);
} END_TEST

START_TEST(test_image_set_user_data) {
  void* user_data;

  /* invalid arguments */
  fail_unless(zathura_image_set_user_data(NULL, NULL, NULL)       == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_image_set_user_data(image, NULL, NULL)      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_image_set_user_data(NULL, &user_data, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_image_set_user_data(image, &user_data, NULL) == ZATHURA_ERROR_OK);
} END_TEST

static void image_free_function(void* data) {
  fail_unless(data == (void*) 0xCAFEBABE);
}

START_TEST(test_image_get_user_data) {
  void* user_data = (void*) 0xCAFEBABE;

  /* invalid arguments */
  fail_unless(zathura_image_get_user_data(NULL, NULL)       == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_image_get_user_data(image, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_image_get_user_data(NULL, &user_data) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_image_set_user_data(image, user_data, NULL) == ZATHURA_ERROR_OK);

  void* user_data2;
  fail_unless(zathura_image_get_user_data(image, &user_data2) == ZATHURA_ERROR_OK);
  fail_unless(user_data == user_data2);
} END_TEST

START_TEST(test_image_set_user_data_free_function) {
  void* user_data = (void*) 0xCAFEBABE;
  zathura_image_t* image2;
  zathura_rectangle_t position = { {0, 0}, {100, 100} };

  fail_unless(zathura_image_new(&image2, position) == ZATHURA_ERROR_OK);
  fail_unless(zathura_image_set_user_data(image2, user_data, image_free_function) == ZATHURA_ERROR_OK);
  fail_unless(zathura_image_free(image2) == ZATHURA_ERROR_OK);

  /* valid arguments */
  fail_unless(zathura_image_new(&image2, position) == ZATHURA_ERROR_OK);
  fail_unless(zathura_image_set_user_data(image2, user_data, NULL) == ZATHURA_ERROR_OK);

  fail_unless(zathura_image_free(image2) == ZATHURA_ERROR_OK);
} END_TEST

#if HAVE_CAIRO
zathura_error_t get_cairo_surface(zathura_image_t* image, cairo_surface_t** surface)
{
  fail_unless(image != NULL);
  fail_unless(surface != NULL);

  *surface = (void*) 0xCAFEBABE;

  return ZATHURA_ERROR_OK;
}

START_TEST(test_image_set_get_cairo_surface_function) {
  /* invalid arguments */
  fail_unless(zathura_image_set_get_cairo_surface_function(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_image_set_get_cairo_surface_function(NULL, get_cairo_surface) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_image_set_get_cairo_surface_function(image, get_cairo_surface) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_image_get_cairo_surface) {
  cairo_surface_t* surface;

  /* basic invalid arguments */
  fail_unless(zathura_image_get_cairo_surface(NULL,  NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_image_get_cairo_surface(image, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_image_get_cairo_surface(NULL,  &surface) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_image_get_cairo_surface(image, &surface) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_image_set_get_cairo_surface_function(image, get_cairo_surface) == ZATHURA_ERROR_OK);
  fail_unless(zathura_image_get_cairo_surface(image, &surface) == ZATHURA_ERROR_OK);
  fail_unless(surface == (void*) 0xCAFEBABE);
} END_TEST
#endif

Suite*
suite_image(void)
{
  TCase* tcase = NULL;
  Suite* suite = suite_create("image");

  tcase = tcase_create("basic");
  tcase_add_test(tcase, test_image_free);
  tcase_add_test(tcase, test_image_new);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("properties");
  tcase_add_checked_fixture(tcase, setup_image, teardown_image);
  tcase_add_test(tcase, test_image_get_position);
  tcase_add_test(tcase, test_image_set_get_buffer_function);
  tcase_add_test(tcase, test_image_get_buffer);
  tcase_add_test(tcase, test_image_set_user_data);
  tcase_add_test(tcase, test_image_set_user_data_free_function);
  tcase_add_test(tcase, test_image_get_user_data);
#if HAVE_CAIRO
  tcase_add_test(tcase, test_image_set_get_cairo_surface_function);
  tcase_add_test(tcase, test_image_get_cairo_surface);
#endif
  suite_add_tcase(suite, tcase);

  return suite;
}

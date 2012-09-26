/* See LICENSE file for license and copyright information */

#include <check.h>

#include "image-buffer.h"

START_TEST(test_image_buffer_new) {
  zathura_image_buffer_t* buffer;

  /* basic invalid arguments */
  fail_unless(zathura_image_buffer_new(NULL,    0, 0) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_image_buffer_new(&buffer, 0, 0) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_image_buffer_new(&buffer, 1, 0) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_image_buffer_new(&buffer, 0, 1) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* invalid integers */
  fail_unless(zathura_image_buffer_new(&buffer, 0xFFFFFFFFUL, 0xFFFFFFFFUL) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_image_buffer_new(&buffer, 1, 1) == ZATHURA_ERROR_OK);
  fail_unless(zathura_image_buffer_free(buffer) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_image_buffer_free) {
  fail_unless(zathura_image_buffer_free(NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_image_buffer_get_data) {
  zathura_image_buffer_t* buffer;
  unsigned char* data;

  fail_unless(zathura_image_buffer_new(&buffer, 1, 1) == ZATHURA_ERROR_OK);
  fail_unless(zathura_image_buffer_get_data(buffer, &data) == ZATHURA_ERROR_OK);
  fail_unless(data != NULL);
  fail_unless(zathura_image_buffer_free(buffer) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_image_buffer_get_width) {
  zathura_image_buffer_t* buffer;
  unsigned int width;

  fail_unless(zathura_image_buffer_new(&buffer, 1, 1) == ZATHURA_ERROR_OK);
  fail_unless(zathura_image_buffer_get_width(buffer, &width) == ZATHURA_ERROR_OK);
  fail_unless(width == 1);
  fail_unless(zathura_image_buffer_free(buffer) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_image_buffer_get_height) {
  zathura_image_buffer_t* buffer;
  unsigned int height;

  fail_unless(zathura_image_buffer_new(&buffer, 1, 1) == ZATHURA_ERROR_OK);
  fail_unless(zathura_image_buffer_get_height(buffer, &height) == ZATHURA_ERROR_OK);
  fail_unless(height == 1);
  fail_unless(zathura_image_buffer_free(buffer) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_image_buffer_get_rowstride) {
  zathura_image_buffer_t* buffer;
  unsigned int rowstride;

  fail_unless(zathura_image_buffer_new(&buffer, 1, 1) == ZATHURA_ERROR_OK);
  fail_unless(zathura_image_buffer_get_rowstride(buffer, &rowstride) == ZATHURA_ERROR_OK);
  fail_unless(rowstride == ZATHURA_IMAGE_BUFFER_ROWSTRIDE);
  fail_unless(zathura_image_buffer_free(buffer) == ZATHURA_ERROR_OK);
} END_TEST

Suite*
suite_image_buffer(void)
{
  TCase* tcase = NULL;
  Suite* suite = suite_create("image-buffer");

  tcase = tcase_create("basic");
  tcase_add_test(tcase, test_image_buffer_free);
  tcase_add_test(tcase, test_image_buffer_new);
  tcase_add_test(tcase, test_image_buffer_get_data);
  tcase_add_test(tcase, test_image_buffer_get_width);
  tcase_add_test(tcase, test_image_buffer_get_height);
  tcase_add_test(tcase, test_image_buffer_get_rowstride);
  suite_add_tcase(suite, tcase);

  return suite;
}

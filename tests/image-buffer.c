/* See LICENSE file for license and copyright information */

#include <check.h>
#include <fiu.h>
#include <fiu-control.h>

#include "image-buffer.h"

static int cb_test_image_buffer_new_calloc(const char* name, int *failnum,
    void** failinfo, unsigned int* flags)
{
  static int i = 0;

  switch (++i) {
    case 1:
    case 3:
      return 1;
  }

  return 0;
}

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

  /* fault injection */
  fiu_enable_external("libc/mm/calloc", 1, NULL, 0, cb_test_image_buffer_new_calloc);
  fail_unless(zathura_image_buffer_new(&buffer, 1, 1) == ZATHURA_ERROR_OUT_OF_MEMORY);
  fail_unless(zathura_image_buffer_new(&buffer, 1, 1) == ZATHURA_ERROR_OUT_OF_MEMORY);
  fiu_disable("libc/mm/calloc");
} END_TEST

START_TEST(test_image_buffer_free) {
  fail_unless(zathura_image_buffer_free(NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_image_buffer_get_data) {
  zathura_image_buffer_t* buffer;
  unsigned char* data;

  /* invalid arguments  */
  fail_unless(zathura_image_buffer_get_data(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_image_buffer_get_data(NULL, &data) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  fail_unless(zathura_image_buffer_new(&buffer, 1, 1) == ZATHURA_ERROR_OK);
  fail_unless(zathura_image_buffer_get_data(buffer, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments  */
  fail_unless(zathura_image_buffer_get_data(buffer, &data) == ZATHURA_ERROR_OK);
  fail_unless(data != NULL);
  fail_unless(zathura_image_buffer_free(buffer) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_image_buffer_get_width) {
  zathura_image_buffer_t* buffer;
  unsigned int width;

  /* invalid arguments  */
  fail_unless(zathura_image_buffer_get_width(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_image_buffer_get_width(NULL, &width) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  fail_unless(zathura_image_buffer_new(&buffer, 1, 1) == ZATHURA_ERROR_OK);
  fail_unless(zathura_image_buffer_get_width(buffer, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments  */
  fail_unless(zathura_image_buffer_get_width(buffer, &width) == ZATHURA_ERROR_OK);
  fail_unless(width == 1);
  fail_unless(zathura_image_buffer_free(buffer) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_image_buffer_get_height) {
  zathura_image_buffer_t* buffer;
  unsigned int height;

  /* invalid arguments  */
  fail_unless(zathura_image_buffer_get_height(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_image_buffer_get_height(NULL, &height) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  fail_unless(zathura_image_buffer_new(&buffer, 1, 1) == ZATHURA_ERROR_OK);
  fail_unless(zathura_image_buffer_get_height(buffer, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments  */
  fail_unless(zathura_image_buffer_get_height(buffer, &height) == ZATHURA_ERROR_OK);
  fail_unless(height == 1);
  fail_unless(zathura_image_buffer_free(buffer) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_image_buffer_get_rowstride) {
  zathura_image_buffer_t* buffer;
  unsigned int rowstride;

  /* invalid arguments  */
  fail_unless(zathura_image_buffer_get_rowstride(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_image_buffer_get_rowstride(NULL, &rowstride) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  fail_unless(zathura_image_buffer_new(&buffer, 1, 1) == ZATHURA_ERROR_OK);
  fail_unless(zathura_image_buffer_get_rowstride(buffer, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments  */
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

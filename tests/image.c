/* See LICENSE file for license and copyright information */

#include <check.h>

#include "image.h"
#include "plugin-api.h"

START_TEST(test_image_free) {
  zathura_image_t* image;

  /* basic invalid arguments */
  fail_unless(zathura_image_free(NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_image_get_buffer) {
  zathura_image_t* image;
  zathura_image_buffer_t* buffer;

  /* basic invalid arguments */
  fail_unless(zathura_image_get_buffer(NULL,  NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_image_get_buffer(image, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_image_get_buffer(NULL, &buffer) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

Suite*
suite_image(void)
{
  TCase* tcase = NULL;
  Suite* suite = suite_create("image");

  tcase = tcase_create("basic");
  tcase_add_test(tcase, test_image_free);
  tcase_add_test(tcase, test_image_get_buffer);
  suite_add_tcase(suite, tcase);

  return suite;
}

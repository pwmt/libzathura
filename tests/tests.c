/* See LICENSE file for license and copyright information */

#include <check.h>

Suite* suite_image_buffer(void);
Suite* suite_plugin_manager(void);

int main(void)
{
  SRunner* suite_runner = srunner_create(NULL);
  int number_failed     = 0;

  srunner_add_suite(suite_runner, suite_image_buffer());
  srunner_add_suite(suite_runner, suite_plugin_manager());

  srunner_run_all(suite_runner, CK_ENV);
  number_failed += srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return (number_failed == 0) ? 0 : 1;
}

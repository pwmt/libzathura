/* See LICENSE file for license and copyright information */

#include <check.h>

Suite* suite_internal(void);
Suite* suite_image_buffer(void);
Suite* suite_plugin_manager(void);
Suite* suite_plugin(void);
Suite* suite_page(void);
Suite* suite_document(void);

int main(void)
{
  SRunner* suite_runner = srunner_create(NULL);
  int number_failed     = 0;

  srunner_add_suite(suite_runner, suite_internal());
  srunner_add_suite(suite_runner, suite_image_buffer());
  srunner_add_suite(suite_runner, suite_plugin_manager());
  srunner_add_suite(suite_runner, suite_plugin());
  srunner_add_suite(suite_runner, suite_page());
  srunner_add_suite(suite_runner, suite_document());

  srunner_run_all(suite_runner, CK_ENV);
  number_failed += srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return (number_failed == 0) ? 0 : 1;
}

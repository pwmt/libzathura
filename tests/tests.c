/* See LICENSE file for license and copyright information */

#include <check.h>

int main(void)
{
  SRunner* suite_runner = srunner_create(NULL);
  int number_failed     = 0;

  srunner_run_all(suite_runner, CK_ENV);
  number_failed += srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return (number_failed == 0) ? 0 : 1;
}

/* See LICENSE file for license and copyright information */

#include <check.h>
#include <fiu.h>

Suite* suite_internal(void);
Suite* suite_actions(void);
Suite* suite_image_buffer(void);
Suite* suite_plugin_manager(void);
Suite* suite_plugin(void);
Suite* suite_page(void);
Suite* suite_document(void);
Suite* suite_image(void);
Suite* suite_attachment(void);
Suite* suite_transition(void);
Suite* suite_form_fields(void);
Suite* suite_annotations(void);

int main(void)
{
  /* initialize libfiu */
#ifdef FIU_ENABLE
  fiu_init(0);
#endif

  /* setup test suite */
  SRunner* suite_runner = srunner_create(NULL);
  srunner_set_fork_status(suite_runner, CK_NOFORK);

  srunner_add_suite(suite_runner, suite_internal());
  srunner_add_suite(suite_runner, suite_image_buffer());
  srunner_add_suite(suite_runner, suite_plugin_manager());
  srunner_add_suite(suite_runner, suite_plugin());
  srunner_add_suite(suite_runner, suite_page());
  srunner_add_suite(suite_runner, suite_document());
  srunner_add_suite(suite_runner, suite_image());
  srunner_add_suite(suite_runner, suite_attachment());
  srunner_add_suite(suite_runner, suite_transition());
  srunner_add_suite(suite_runner, suite_form_fields());
  srunner_add_suite(suite_runner, suite_annotations());
  srunner_add_suite(suite_runner, suite_actions());

  int number_failed = 0;
  srunner_run_all(suite_runner, CK_ENV);
  number_failed += srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return (number_failed == 0) ? 0 : 1;
}

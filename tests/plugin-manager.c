/* See LICENSE file for license and copyright information */

#include <check.h>

#include "plugin-manager.h"

START_TEST(test_plugin_manager_new) {
  zathura_plugin_manager_t* plugin_manager;

  /* basic invalid arguments */
  fail_unless(zathura_plugin_manager_new(NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_plugin_manager_new(&plugin_manager) == ZATHURA_ERROR_OK);
  fail_unless(plugin_manager != NULL);
  fail_unless(zathura_plugin_manager_free(plugin_manager) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_plugin_manager_free) {
  fail_unless(zathura_plugin_manager_free(NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_plugin_manager_add_dir) {
  zathura_plugin_manager_t* plugin_manager;
  fail_unless(zathura_plugin_manager_new(&plugin_manager) == ZATHURA_ERROR_OK);
  fail_unless(plugin_manager != NULL);

  /* invalid parameter */
  fail_unless(zathura_plugin_manager_add_dir(NULL,           NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_plugin_manager_add_dir(plugin_manager, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid parameter */
  fail_unless(zathura_plugin_manager_add_dir(plugin_manager, "/usr/lib") == ZATHURA_ERROR_OK); // TODO: fix path

  fail_unless(zathura_plugin_manager_free(plugin_manager) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_plugin_manager_load) {
  zathura_plugin_manager_t* plugin_manager;
  fail_unless(zathura_plugin_manager_new(&plugin_manager) == ZATHURA_ERROR_OK);
  fail_unless(plugin_manager != NULL);

  /* invalid parameter */
  fail_unless(zathura_plugin_manager_load(NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid parameter */
  fail_unless(zathura_plugin_manager_load(plugin_manager) == ZATHURA_ERROR_OK);

  fail_unless(zathura_plugin_manager_free(plugin_manager) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_plugin_manager_get_plugins) {
  zathura_plugin_manager_t* plugin_manager;
  zathura_list_t* list;
  fail_unless(zathura_plugin_manager_new(&plugin_manager) == ZATHURA_ERROR_OK);
  fail_unless(plugin_manager != NULL);

  /* invalid parameter */
  fail_unless(zathura_plugin_manager_get_plugins(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_plugin_manager_get_plugins(plugin_manager, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid parameter */
  fail_unless(zathura_plugin_manager_get_plugins(plugin_manager, &list) == ZATHURA_ERROR_OK);
  fail_unless(list != NULL);

  fail_unless(zathura_plugin_manager_free(plugin_manager) == ZATHURA_ERROR_OK);
} END_TEST

Suite*
suite_plugin_manager(void)
{
  TCase* tcase = NULL;
  Suite* suite = suite_create("plugin-manager");

  tcase = tcase_create("basic");
  tcase_add_test(tcase, test_plugin_manager_free);
  tcase_add_test(tcase, test_plugin_manager_new);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("add-dir");
  tcase_add_test(tcase, test_plugin_manager_add_dir);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("load");
  tcase_add_test(tcase, test_plugin_manager_load);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("get-plugins");
  tcase_add_test(tcase, test_plugin_manager_get_plugins);
  suite_add_tcase(suite, tcase);

  return suite;
}

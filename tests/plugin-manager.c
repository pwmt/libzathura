/* See LICENSE file for license and copyright information */

#include <check.h>
#include <fiu.h>
#include <stdio.h>
#include <fiu-control.h>

#include <libzathura/plugin-manager.h>
#include <libzathura/internal.h>

#include "tests.h"
#include "utils.h"

START_TEST(test_plugin_manager_new) {
  zathura_plugin_manager_t* plugin_manager = NULL;

  /* basic invalid arguments */
  fail_unless(zathura_plugin_manager_new(NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_plugin_manager_new(&plugin_manager) == ZATHURA_ERROR_OK);
  fail_unless(plugin_manager != NULL);
  fail_unless(zathura_plugin_manager_free(plugin_manager) == ZATHURA_ERROR_OK);

  /* fault injection */
#ifdef WITH_LIBFIU
  fiu_enable("libc/mm/calloc", 1, NULL, 0);
  fail_unless(zathura_plugin_manager_new(&plugin_manager) == ZATHURA_ERROR_OUT_OF_MEMORY);
  fiu_disable("libc/mm/calloc");
#endif
} END_TEST

START_TEST(test_plugin_manager_free) {
  fail_unless(zathura_plugin_manager_free(NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_plugin_manager_load) {
  zathura_plugin_manager_t* plugin_manager = NULL;
  fail_unless(zathura_plugin_manager_new(&plugin_manager) == ZATHURA_ERROR_OK);
  fail_unless(plugin_manager != NULL);

  /* invalid parameter */
  fail_unless(zathura_plugin_manager_load(NULL,           NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_plugin_manager_load(plugin_manager, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_plugin_manager_load(plugin_manager, "")   == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid parameter */
  fail_unless(zathura_plugin_manager_load(plugin_manager, get_plugin_path()) == ZATHURA_ERROR_OK);

  fail_unless(zathura_plugin_manager_free(plugin_manager) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_plugin_manager_load_dir) {
  zathura_plugin_manager_t* plugin_manager = NULL;
  fail_unless(zathura_plugin_manager_new(&plugin_manager) == ZATHURA_ERROR_OK);
  fail_unless(plugin_manager != NULL);

  /* invalid parameter */
  fail_unless(zathura_plugin_manager_load_dir(NULL,           NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_plugin_manager_load_dir(plugin_manager, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_plugin_manager_load_dir(plugin_manager, "")   == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid parameter */
  fail_unless(zathura_plugin_manager_load_dir(plugin_manager, get_plugin_dir_path()) == ZATHURA_ERROR_OK);

  fail_unless(zathura_plugin_manager_free(plugin_manager) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_plugin_manager_get_plugins) {
  zathura_plugin_manager_t* plugin_manager = NULL;
  zathura_list_t* list;
  fail_unless(zathura_plugin_manager_new(&plugin_manager) == ZATHURA_ERROR_OK);
  fail_unless(plugin_manager != NULL);

  /* invalid parameter */
  fail_unless(zathura_plugin_manager_get_plugins(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_plugin_manager_get_plugins(plugin_manager, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* empty list */
  fail_unless(zathura_plugin_manager_get_plugins(plugin_manager, &list) == ZATHURA_ERROR_OK);
  fail_unless(list == NULL);

  /* load plugins */
  fail_unless(zathura_plugin_manager_load_dir(plugin_manager, get_plugin_dir_path()) == ZATHURA_ERROR_OK);
  fail_unless(zathura_plugin_manager_get_plugins(plugin_manager, &list) == ZATHURA_ERROR_OK);
  fail_unless(list != NULL);
  fail_unless(zathura_list_length(list) == 1);

  fail_unless(zathura_plugin_manager_free(plugin_manager) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_plugin_manager_get_plugin) {
  zathura_plugin_manager_t* plugin_manager = NULL;
  zathura_plugin_t* plugin = NULL;
  fail_unless(zathura_plugin_manager_new(&plugin_manager) == ZATHURA_ERROR_OK);
  fail_unless(plugin_manager != NULL);

  /* invalid parameter */
  fail_unless(zathura_plugin_manager_get_plugin(NULL, NULL, NULL)           == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_plugin_manager_get_plugin(plugin_manager, NULL, NULL)   == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_plugin_manager_get_plugin(plugin_manager, NULL, "xx") == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_plugin_manager_get_plugin(plugin_manager, NULL, "") == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* load plugins */
  fail_unless(zathura_plugin_manager_load_dir(plugin_manager, get_plugin_dir_path()) == ZATHURA_ERROR_OK);
  fail_unless(zathura_plugin_manager_get_plugin(plugin_manager, &plugin, "libzathura/test-plugin") == ZATHURA_ERROR_OK);
  fail_unless(plugin != NULL);

  /* corrupt data */
  zathura_list_t* list;
  fail_unless(zathura_plugin_manager_get_plugins(plugin_manager, &list) == ZATHURA_ERROR_OK);
  fail_unless(list != NULL);
  plugin_manager->plugins = NULL;

  fail_unless(zathura_plugin_manager_get_plugin(plugin_manager, &plugin, "libzathura/test-plugin") == ZATHURA_ERROR_UNKNOWN);
  plugin_manager->plugins = list;


  fail_unless(zathura_plugin_manager_free(plugin_manager) == ZATHURA_ERROR_OK);
} END_TEST

Suite*
create_suite(void)
{
  TCase* tcase = NULL;
  Suite* suite = suite_create("plugin-manager");

  tcase = tcase_create("basic");
  tcase_add_test(tcase, test_plugin_manager_free);
  tcase_add_test(tcase, test_plugin_manager_new);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("load");
  tcase_add_test(tcase, test_plugin_manager_load);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("load-dir");
  tcase_add_test(tcase, test_plugin_manager_load_dir);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("get-plugin");
  tcase_add_test(tcase, test_plugin_manager_get_plugins);
  tcase_add_test(tcase, test_plugin_manager_get_plugin);
  suite_add_tcase(suite, tcase);

  return suite;
}

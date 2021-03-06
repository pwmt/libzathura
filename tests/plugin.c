/* See LICENSE file for license and copyright information */

#include <check.h>
#include <stdio.h>
#include <string.h>
#include <fiu.h>
#include <fiu-control.h>

#if HAVE_CAIRO
#include <cairo.h>
#endif

#include <libzathura/error.h>
#include <libzathura/macros.h>
#include <libzathura/plugin.h>
#include <libzathura/plugin-api.h>
#include <libzathura/plugin-manager.h>
#include <libzathura/internal.h>

#include "tests.h"
#include "utils.h"

zathura_plugin_manager_t* plugin_manager;
zathura_plugin_t* plugin;

static void setup(void) {
  zathura_list_t* list;

  /* setup plugin manager */
  fail_unless(zathura_plugin_manager_new(&plugin_manager) == ZATHURA_ERROR_OK);
  fail_unless(plugin_manager != NULL);
  fail_unless(zathura_plugin_manager_load(plugin_manager, get_plugin_path()) == ZATHURA_ERROR_OK);

  /* get example plugin */
  fail_unless(zathura_plugin_manager_get_plugins(plugin_manager, &list) == ZATHURA_ERROR_OK);
  fail_unless(list != NULL);
  fail_unless(zathura_list_length(list) == 1);
  plugin = (zathura_plugin_t*) zathura_list_nth_data(list, 0);
  fail_unless(plugin != NULL);
}

static void teardown(void) {
  fail_unless(zathura_plugin_manager_free(plugin_manager) == ZATHURA_ERROR_OK);
  plugin_manager = NULL;
  plugin = NULL;
}

START_TEST(test_plugin_set_name) {
  const char* name = "plugin";

  /* invalid parameter */
  fail_unless(zathura_plugin_set_name(NULL,   NULL)  == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_plugin_set_name(plugin, NULL)  == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_plugin_set_name(NULL,   name)  == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_plugin_set_name(plugin, "")    == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid parameter */
  fail_unless(zathura_plugin_set_name(plugin,  name) == ZATHURA_ERROR_OK);
  fail_unless(zathura_plugin_get_name(plugin, &name) == ZATHURA_ERROR_OK);
  fail_unless(strcmp(name, "plugin") == 0);
} END_TEST

START_TEST(test_plugin_get_name) {
  const char* name;

  /* invalid parameter */
  fail_unless(zathura_plugin_get_name(NULL,   NULL)  == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_plugin_get_name(plugin, NULL)  == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_plugin_get_name(NULL,   &name) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid parameter */
  fail_unless(zathura_plugin_get_name(plugin, &name)  == ZATHURA_ERROR_OK);
  fail_unless(strcmp(name, "plugin") == 0);

  /* corrupt plugin */
  plugin->name = NULL;
  fail_unless(zathura_plugin_get_name(plugin, &name)  == ZATHURA_ERROR_UNKNOWN);
  plugin->name = (char*) name;
} END_TEST

START_TEST(test_plugin_get_path) {
  const char* path;

  /* invalid parameter */
  fail_unless(zathura_plugin_get_path(NULL,   NULL)  == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_plugin_get_path(plugin, NULL)  == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_plugin_get_path(NULL,   &path) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid parameter */
  fail_unless(zathura_plugin_get_path(plugin, &path)  == ZATHURA_ERROR_OK);
  fail_unless(strstr(path, "plugin/plugin.so") != NULL);

  /* corrupt plugin */
  plugin->path = NULL;
  const char* null_path;
  fail_unless(zathura_plugin_get_path(plugin, &null_path)  == ZATHURA_ERROR_UNKNOWN);
  plugin->path = (char*) path;
} END_TEST

START_TEST(test_plugin_get_version) {
  zathura_plugin_version_t version;

  /* invalid parameter */
  fail_unless(zathura_plugin_get_version(NULL,   NULL)     == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_plugin_get_version(plugin, NULL)     == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_plugin_get_version(NULL,   &version) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid parameter */
  fail_unless(zathura_plugin_get_version(plugin, &version) == ZATHURA_ERROR_OK);
  fail_unless(version.major == 0);
  fail_unless(version.minor == 0);
  fail_unless(version.rev == 0);
} END_TEST

START_TEST(test_plugin_set_register_function) {
  zathura_plugin_register_function_t function = (zathura_plugin_register_function_t) 0x1;

  /* invalid parameter */
  fail_unless(zathura_plugin_set_register_function(NULL,   NULL)     == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_plugin_set_register_function(plugin, NULL)     == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_plugin_set_register_function(NULL,   function) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid parameter */
  fail_unless(zathura_plugin_set_register_function(plugin, function) == ZATHURA_ERROR_OK);
} END_TEST


START_TEST(test_plugin_get_functions) {
  zathura_plugin_functions_t* functions = NULL;

  /* invalid parameter */
  fail_unless(zathura_plugin_get_functions(NULL,   NULL)       == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_plugin_get_functions(plugin, NULL)       == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_plugin_get_functions(NULL,   &functions) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid parameter */
  fail_unless(zathura_plugin_get_functions(plugin, &functions) == ZATHURA_ERROR_OK);
  fail_unless(functions != NULL);
} END_TEST

START_TEST(test_plugin_add_mime_type) {
  /* invalid parameter */
  fail_unless(zathura_plugin_add_mimetype(NULL,   NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_plugin_add_mimetype(plugin, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_plugin_add_mimetype(NULL,   "xx") == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_plugin_add_mimetype(plugin, "")   == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid parameter */
  fail_unless(zathura_plugin_add_mimetype(plugin, "application/pdf") == ZATHURA_ERROR_OK);
} END_TEST

#ifdef WITH_LIBFIU
static int cb_test_plugin_document_open_calloc(const char* UNUSED(name), int *UNUSED(failnum),
    void** UNUSED(failinfo), unsigned int* UNUSED(flags))
{
  static int i = 0;

  switch (i++) {
    case 1:
    case 4:
      return 1;
  }

  return 0;
}
#endif

START_TEST(test_plugin_open_document) {
  zathura_document_t* document;

  /* invalid parameter */
  fail_unless(zathura_plugin_open_document(NULL,   NULL, NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_plugin_open_document(plugin, NULL, NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_plugin_open_document(plugin, &document, NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_plugin_open_document(plugin, &document, NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_plugin_open_document(plugin, &document, "", NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid parameter */
  fail_unless(zathura_plugin_open_document(plugin, &document, "DoesNotExist", NULL) == ZATHURA_ERROR_DOCUMENT_DOES_NOT_EXIST);
  fail_unless(zathura_plugin_open_document(plugin, &document, TEST_FILE_PATH, NULL) == ZATHURA_ERROR_OK);
  fail_unless(zathura_document_free(document) == ZATHURA_ERROR_OK);

  /* fault injection */
#ifdef WITH_LIBFIU
  fiu_enable_external("libc/mm/calloc", 1, NULL, 0, cb_test_plugin_document_open_calloc);
  fail_unless(zathura_plugin_open_document(plugin, &document, TEST_FILE_PATH, NULL) == ZATHURA_ERROR_OUT_OF_MEMORY);
  fiu_disable("libc/mm/calloc");
#endif

#ifdef WITH_LIBFIU
  fiu_enable_external("libc/mm/calloc", 2, NULL, 0, cb_test_plugin_document_open_calloc);
  fail_unless(zathura_plugin_open_document(plugin, &document, TEST_FILE_PATH, NULL) == ZATHURA_ERROR_OUT_OF_MEMORY);
  fiu_disable("libc/mm/calloc");
#endif

  /* unset document_open function */
  plugin->functions.document_open = NULL;
  fail_unless(zathura_plugin_open_document(plugin, &document, TEST_FILE_PATH, NULL) == ZATHURA_ERROR_PLUGIN_NOT_IMPLEMENTED);
} END_TEST


Suite*
create_suite(void)
{
  TCase* tcase = NULL;
  Suite* suite = suite_create("plugin");

  tcase = tcase_create("basic");
  tcase_add_checked_fixture(tcase, setup, teardown);
  tcase_add_test(tcase, test_plugin_set_name);
  tcase_add_test(tcase, test_plugin_get_name);
  tcase_add_test(tcase, test_plugin_get_path);
  tcase_add_test(tcase, test_plugin_get_version);
  tcase_add_test(tcase, test_plugin_set_register_function);
  tcase_add_test(tcase, test_plugin_get_functions);
  tcase_add_test(tcase, test_plugin_add_mime_type);
  tcase_add_test(tcase, test_plugin_open_document);
  suite_add_tcase(suite, tcase);

  return suite;
}

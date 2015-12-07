/* See LICENSE file for license and copyright information */

#include <check.h>
#ifdef FIU_ENABLE
#include <fiu.h>
#include <fiu-control.h>
#endif

#include "options.h"

zathura_options_t* options = NULL;

static void
setup_options(void)
{
  fail_unless(zathura_options_new(&options) == ZATHURA_ERROR_OK);
}

static void
teardown_options(void)
{
  fail_unless(zathura_options_free(options) == ZATHURA_ERROR_OK);
  options = NULL;
}

START_TEST(test_options_new_invalid)
{
  /* basic invalid arguments */
  fail_unless(zathura_options_new(NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_options_new)
{
  zathura_options_t* options = NULL;

  /* basic valid arguments */
  fail_unless(zathura_options_new(&options) == ZATHURA_ERROR_OK);
  fail_unless(options != NULL);
  fail_unless(zathura_options_free(options) == ZATHURA_ERROR_OK);
} END_TEST

#ifdef FIU_ENABLE
START_TEST(test_options_new_fault)
{
  /* fault injection */
  fiu_enable("libc/mm/calloc", 1, NULL, 0);
  fail_unless(zathura_options_new(&options) == ZATHURA_ERROR_OUT_OF_MEMORY);
  fiu_disable("libc/mm/calloc");
} END_TEST
#endif

START_TEST(test_options_free)
{
  /* basic invalid arguments */
  fail_unless(zathura_options_free(NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_options_add_invalid)
{
  fail_unless(zathura_options_add(options, NULL, ZATHURA_OPTION_INT) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_options_add)
{
  fail_unless(zathura_options_add(options, "test", ZATHURA_OPTION_INT) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_options_add_twice)
{
  fail_unless(zathura_options_add(options, "test", ZATHURA_OPTION_INT) == ZATHURA_ERROR_OK);
  fail_unless(zathura_options_add(options, "test", ZATHURA_OPTION_INT) == ZATHURA_ERROR_OPTIONS_ALREADY_EXISTS);
} END_TEST

#ifdef FIU_ENABLE
START_TEST(test_options_add_fault)
{
  fiu_enable("libc/mm/calloc", 1, NULL, 0);
  fail_unless(zathura_options_add(options, "test", ZATHURA_OPTION_INT) == ZATHURA_ERROR_OUT_OF_MEMORY);
  fiu_disable("libc/mm/calloc");
} END_TEST
#endif

START_TEST(test_options_add_int)
{
  fail_unless(zathura_options_add(options, "test", ZATHURA_OPTION_INT) == ZATHURA_ERROR_OK);

  bool is_set = false;
  fail_unless(zathura_options_is_set(options, "test", &is_set) == ZATHURA_ERROR_OK);
  fail_unless(is_set == false);

  int value = 0;
  fail_unless(zathura_options_get_value_int(options, "test", &value) == ZATHURA_ERROR_OPTIONS_NOT_SET);

  fail_unless(zathura_options_set_value_int(options, "test", 1024) == ZATHURA_ERROR_OK);
  fail_unless(zathura_options_is_set(options, "test", &is_set) == ZATHURA_ERROR_OK);
  fail_unless(is_set == true);

  fail_unless(zathura_options_get_value_int(options, "test", &value) == ZATHURA_ERROR_OK);
  fail_unless(value == 1024);
} END_TEST

START_TEST(test_options_add_uint)
{
  fail_unless(zathura_options_add(options, "test", ZATHURA_OPTION_UINT) == ZATHURA_ERROR_OK);

  bool is_set = false;
  fail_unless(zathura_options_is_set(options, "test", &is_set) == ZATHURA_ERROR_OK);
  fail_unless(is_set == false);

  unsigned int value = 0;
  fail_unless(zathura_options_get_value_uint(options, "test", &value) == ZATHURA_ERROR_OPTIONS_NOT_SET);

  fail_unless(zathura_options_set_value_uint(options, "test", 1024) == ZATHURA_ERROR_OK);
  fail_unless(zathura_options_is_set(options, "test", &is_set) == ZATHURA_ERROR_OK);
  fail_unless(is_set == true);

  fail_unless(zathura_options_get_value_uint(options, "test", &value) == ZATHURA_ERROR_OK);
  fail_unless(value == 1024);
} END_TEST

START_TEST(test_options_add_bool)
{
  fail_unless(zathura_options_add(options, "test", ZATHURA_OPTION_BOOL) == ZATHURA_ERROR_OK);

  bool is_set = false;
  fail_unless(zathura_options_is_set(options, "test", &is_set) == ZATHURA_ERROR_OK);
  fail_unless(is_set == false);

  bool value = false;
  fail_unless(zathura_options_get_value_bool(options, "test", &value) == ZATHURA_ERROR_OPTIONS_NOT_SET);

  fail_unless(zathura_options_set_value_bool(options, "test", true) == ZATHURA_ERROR_OK);
  fail_unless(zathura_options_is_set(options, "test", &is_set) == ZATHURA_ERROR_OK);
  fail_unless(is_set == true);

  fail_unless(zathura_options_get_value_bool(options, "test", &value) == ZATHURA_ERROR_OK);
  fail_unless(value == true);
} END_TEST

START_TEST(test_options_add_float)
{
  fail_unless(zathura_options_add(options, "test", ZATHURA_OPTION_FLOAT) == ZATHURA_ERROR_OK);

  bool is_set = false;
  fail_unless(zathura_options_is_set(options, "test", &is_set) == ZATHURA_ERROR_OK);
  fail_unless(is_set == false);

  float value = 0.0f;
  fail_unless(zathura_options_get_value_float(options, "test", &value) == ZATHURA_ERROR_OPTIONS_NOT_SET);

  fail_unless(zathura_options_set_value_float(options, "test", 1.0f) == ZATHURA_ERROR_OK);
  fail_unless(zathura_options_is_set(options, "test", &is_set) == ZATHURA_ERROR_OK);
  fail_unless(is_set == true);

  fail_unless(zathura_options_get_value_float(options, "test", &value) == ZATHURA_ERROR_OK);
  fail_unless(value == 1.0f);
} END_TEST

START_TEST(test_options_add_pointer)
{
  fail_unless(zathura_options_add(options, "test", ZATHURA_OPTION_POINTER) == ZATHURA_ERROR_OK);

  bool is_set = false;
  fail_unless(zathura_options_is_set(options, "test", &is_set) == ZATHURA_ERROR_OK);
  fail_unless(is_set == false);

  void* value = NULL;
  fail_unless(zathura_options_get_value_pointer(options, "test", &value) == ZATHURA_ERROR_OPTIONS_NOT_SET);

  fail_unless(zathura_options_set_value_pointer(options, "test", (void*) 0x1234) == ZATHURA_ERROR_OK);
  fail_unless(zathura_options_is_set(options, "test", &is_set) == ZATHURA_ERROR_OK);
  fail_unless(is_set == true);

  fail_unless(zathura_options_get_value_pointer(options, "test", &value) == ZATHURA_ERROR_OK);
  fail_unless(value == (void*) 0x1234);
} END_TEST

START_TEST(test_options_add_string)
{
  fail_unless(zathura_options_add(options, "test", ZATHURA_OPTION_STRING) == ZATHURA_ERROR_OK);

  bool is_set = false;
  fail_unless(zathura_options_is_set(options, "test", &is_set) == ZATHURA_ERROR_OK);
  fail_unless(is_set == false);

  const char* value = NULL;
  fail_unless(zathura_options_get_value_string(options, "test", &value) == ZATHURA_ERROR_OPTIONS_NOT_SET);

  fail_unless(zathura_options_set_value_string(options, "test", "1234") == ZATHURA_ERROR_OK);
  fail_unless(zathura_options_is_set(options, "test", &is_set) == ZATHURA_ERROR_OK);
  fail_unless(is_set == true);

  fail_unless(zathura_options_get_value_string(options, "test", &value) == ZATHURA_ERROR_OK);
  fail_unless(value != NULL);
  fail_unless(strcmp(value, "1234") == 0);
} END_TEST

START_TEST(test_options_description_unset)
{
  fail_unless(zathura_options_add(options, "test", ZATHURA_OPTION_STRING) == ZATHURA_ERROR_OK);

  const char* description = NULL;
  fail_unless(zathura_options_get_description(options, "test", &description) == ZATHURA_ERROR_OK);
  fail_unless(description == NULL);
} END_TEST

START_TEST(test_options_description)
{
  fail_unless(zathura_options_add(options, "test", ZATHURA_OPTION_STRING) == ZATHURA_ERROR_OK);
  fail_unless(zathura_options_set_description(options, "test", "test description") == ZATHURA_ERROR_OK);

  const char* description = NULL;
  fail_unless(zathura_options_get_description(options, "test", &description) == ZATHURA_ERROR_OK);
  fail_unless(description != NULL);
  fail_unless(strcmp(description, "test description") == 0);
} END_TEST

START_TEST(test_options_set_invalid_type)
{
  fail_unless(zathura_options_add(options, "test int", ZATHURA_OPTION_INT) == ZATHURA_ERROR_OK);
  fail_unless(zathura_options_add(options, "test uint", ZATHURA_OPTION_UINT) == ZATHURA_ERROR_OK);

  fail_unless(zathura_options_set_value_bool(options, "test int", true) == ZATHURA_ERROR_OPTIONS_INVALID_TYPE);
  fail_unless(zathura_options_set_value_uint(options, "test int", 1) == ZATHURA_ERROR_OPTIONS_INVALID_TYPE);
  fail_unless(zathura_options_set_value_float(options, "test int", 1.0f) == ZATHURA_ERROR_OPTIONS_INVALID_TYPE);
  fail_unless(zathura_options_set_value_pointer(options, "test int", NULL) == ZATHURA_ERROR_OPTIONS_INVALID_TYPE);
  fail_unless(zathura_options_set_value_string(options, "test int", "") == ZATHURA_ERROR_OPTIONS_INVALID_TYPE);
  fail_unless(zathura_options_set_value_int(options, "test uint", 1) == ZATHURA_ERROR_OPTIONS_INVALID_TYPE);
} END_TEST

START_TEST(test_options_get_invalid_type)
{
  fail_unless(zathura_options_add(options, "test int", ZATHURA_OPTION_INT) == ZATHURA_ERROR_OK);
  fail_unless(zathura_options_add(options, "test uint", ZATHURA_OPTION_UINT) == ZATHURA_ERROR_OK);

  fail_unless(zathura_options_set_value_int(options, "test int", 1) == ZATHURA_ERROR_OK);
  fail_unless(zathura_options_set_value_uint(options, "test uint", 1) == ZATHURA_ERROR_OK);

  bool b = false;
  fail_unless(zathura_options_get_value_bool(options, "test int", &b) == ZATHURA_ERROR_OPTIONS_INVALID_TYPE);
  unsigned int u = 0;
  fail_unless(zathura_options_get_value_uint(options, "test int", &u) == ZATHURA_ERROR_OPTIONS_INVALID_TYPE);
  float f = 0;
  fail_unless(zathura_options_get_value_float(options, "test int", &f) == ZATHURA_ERROR_OPTIONS_INVALID_TYPE);
  void* p = NULL;
  fail_unless(zathura_options_get_value_pointer(options, "test int", &p) == ZATHURA_ERROR_OPTIONS_INVALID_TYPE);
  const char* s = NULL;
  fail_unless(zathura_options_get_value_string(options, "test int", &s) == ZATHURA_ERROR_OPTIONS_INVALID_TYPE);
  int i = 0;
  fail_unless(zathura_options_get_value_int(options, "test uint", &i) == ZATHURA_ERROR_OPTIONS_INVALID_TYPE);
} END_TEST


Suite*
suite_options(void)
{
  TCase* tcase = NULL;
  Suite* suite = suite_create("options");

  tcase = tcase_create("basic");
  tcase_add_test(tcase, test_options_free);
  tcase_add_test(tcase, test_options_new);
  tcase_add_test(tcase, test_options_new_invalid);
#ifdef FIU_ENABLE
  tcase_add_test(tcase, test_options_new_fault);
#endif
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("options");
  tcase_add_checked_fixture(tcase, setup_options, teardown_options);
  tcase_add_test(tcase, test_options_add_invalid);
  tcase_add_test(tcase, test_options_add);
  tcase_add_test(tcase, test_options_add_twice);
#ifdef FIU_ENABLE
  tcase_add_test(tcase, test_options_add_fault);
#endif
  tcase_add_test(tcase, test_options_add_int);
  tcase_add_test(tcase, test_options_add_uint);
  tcase_add_test(tcase, test_options_add_bool);
  tcase_add_test(tcase, test_options_add_float);
  tcase_add_test(tcase, test_options_add_pointer);
  tcase_add_test(tcase, test_options_add_string);
  tcase_add_test(tcase, test_options_description_unset);
  tcase_add_test(tcase, test_options_description);
  tcase_add_test(tcase, test_options_set_invalid_type);
  tcase_add_test(tcase, test_options_get_invalid_type);
  suite_add_tcase(suite, tcase);

  return suite;
}

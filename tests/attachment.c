/* See LICENSE file for license and copyright information */

#include <check.h>
#include <fiu.h>
#include <stdio.h>

#include "attachment.h"
#include "plugin-api.h"

#define CHECKSUM "ABCDABCDABCDABCD"
#define DESCRIPTION "description"
#define NAME "name"

zathura_attachment_t* attachment;

static void setup(void) {
  fail_unless(zathura_attachment_new(&attachment) == ZATHURA_ERROR_OK);
}

static void teardown(void) {
  fail_unless(zathura_attachment_free(attachment) == ZATHURA_ERROR_OK);
  attachment = NULL;
}

START_TEST(test_attachment_free) {
  /* basic invalid arguments */
  fail_unless(zathura_attachment_free(NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_attachment_new) {
  /* basic invalid arguments */
  fail_unless(zathura_attachment_new(NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  zathura_attachment_t* tmp;
  fail_unless(zathura_attachment_new(&tmp) == ZATHURA_ERROR_OK);
  fail_unless(zathura_attachment_free(tmp) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_attachment_set_data) {
  void* data;

  /* invalid arguments */
  fail_unless(zathura_attachment_set_data(NULL, NULL)       == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_attachment_set_data(attachment, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_attachment_set_data(NULL, &data)      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_attachment_set_data(attachment, &data) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_attachment_get_data) {
  void* data = (void*) 0xCAFEBABE;

  /* invalid arguments */
  fail_unless(zathura_attachment_get_data(NULL, NULL)       == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_attachment_get_data(attachment, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_attachment_get_data(NULL, &data)      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_attachment_set_data(attachment, data)  == ZATHURA_ERROR_OK);

  void* data2;
  fail_unless(zathura_attachment_get_data(attachment, &data2) == ZATHURA_ERROR_OK);
  fail_unless(data == data2);
} END_TEST

START_TEST(test_attachment_set_name) {
  /* invalid arguments */
  fail_unless(zathura_attachment_set_name(NULL, NULL)     == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_attachment_set_name(attachment, "") == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_attachment_set_name(attachment, NULL)   == ZATHURA_ERROR_OK);
  fail_unless(zathura_attachment_set_name(attachment, NAME) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_attachment_get_name) {
  const char* name;

  /* invalid arguments */
  fail_unless(zathura_attachment_get_name(NULL, NULL)       == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_attachment_get_name(attachment, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_attachment_get_name(NULL, &name)      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid parameter */
  fail_unless(zathura_attachment_set_name(attachment, NAME) == ZATHURA_ERROR_OK);
  fail_unless(zathura_attachment_get_name(attachment, &name) == ZATHURA_ERROR_OK);
  fail_unless(strcmp(NAME, name) == 0);

  /* do it again */
  fail_unless(zathura_attachment_set_name(attachment, NAME) == ZATHURA_ERROR_OK);
  fail_unless(zathura_attachment_get_name(attachment, &name) == ZATHURA_ERROR_OK);
  fail_unless(strcmp(NAME, name) == 0);
} END_TEST

START_TEST(test_attachment_set_description) {
  /* invalid arguments */
  fail_unless(zathura_attachment_set_description(NULL, NULL)     == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_attachment_set_description(attachment, "") == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_attachment_set_description(attachment, NULL)        == ZATHURA_ERROR_OK);
  fail_unless(zathura_attachment_set_description(attachment, DESCRIPTION) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_attachment_get_description) {
  const char* description;

  /* invalid arguments */
  fail_unless(zathura_attachment_get_description(NULL, NULL)         == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_attachment_get_description(attachment, NULL)   == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_attachment_get_description(NULL, &description) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguents */
  const char* description2;
  fail_unless(zathura_attachment_set_description(attachment, DESCRIPTION) == ZATHURA_ERROR_OK);
  fail_unless(zathura_attachment_get_description(attachment, &description2) == ZATHURA_ERROR_OK);
  fail_unless(strcmp(DESCRIPTION, description2) == 0);

  /* do it again */
  fail_unless(zathura_attachment_set_description(attachment, DESCRIPTION) == ZATHURA_ERROR_OK);
  fail_unless(zathura_attachment_get_description(attachment, &description2) == ZATHURA_ERROR_OK);
  fail_unless(strcmp(DESCRIPTION, description2) == 0);
} END_TEST

START_TEST(test_attachment_set_size) {
  /* invalid arguments */
  fail_unless(zathura_attachment_set_size(NULL, 0) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_attachment_set_size(attachment, 0) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_attachment_get_size) {
  unsigned int size = 0;

  /* invalid arguments */
  fail_unless(zathura_attachment_get_size(NULL, NULL)       == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_attachment_get_size(attachment, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_attachment_get_size(NULL, &size)      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  unsigned int size2 = 1;
  fail_unless(zathura_attachment_set_size(attachment, size)   == ZATHURA_ERROR_OK);
  fail_unless(zathura_attachment_get_size(attachment, &size2) == ZATHURA_ERROR_OK);
  fail_unless(size == size2);
} END_TEST

START_TEST(test_attachment_set_creation_time) {
  time_t creation_time = time(NULL);

  /* invalid arguments */
  fail_unless(zathura_attachment_set_creation_time(NULL, creation_time) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_attachment_set_creation_time(attachment, creation_time) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_attachment_get_creation_time) {
  time_t creation_time = time(NULL);

  /* invalid arguments */
  fail_unless(zathura_attachment_get_creation_time(NULL, NULL)               == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_attachment_get_creation_time(attachment, NULL)         == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_attachment_get_creation_time(NULL, &creation_time) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  time_t creation_time2;
  fail_unless(zathura_attachment_set_creation_time(attachment, creation_time) == ZATHURA_ERROR_OK);
  fail_unless(zathura_attachment_get_creation_time(attachment, &creation_time2) == ZATHURA_ERROR_OK);
  fail_unless(difftime(creation_time, creation_time2) == 0);
} END_TEST

START_TEST(test_attachment_set_modification_time) {
  time_t modification_time = time(NULL);

  /* invalid arguments */
  fail_unless(zathura_attachment_set_modification_time(NULL, modification_time) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_attachment_set_modification_time(attachment, modification_time) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_attachment_get_modification_time) {
  time_t modification_time = time(NULL);

  /* invalid arguments */
  fail_unless(zathura_attachment_get_modification_time(NULL, NULL)               == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_attachment_get_modification_time(attachment, NULL)         == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_attachment_get_modification_time(NULL, &modification_time) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  time_t modification_time2;
  fail_unless(zathura_attachment_set_modification_time(attachment, modification_time) == ZATHURA_ERROR_OK);
  fail_unless(zathura_attachment_get_modification_time(attachment, &modification_time2) == ZATHURA_ERROR_OK);
  fail_unless(difftime(modification_time, modification_time2) == 0);
} END_TEST

START_TEST(test_attachment_set_checksum) {
  /* invalid arguments */
  fail_unless(zathura_attachment_set_checksum(NULL, NULL)              == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_attachment_set_checksum(NULL, CHECKSUM)          == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_attachment_set_checksum(attachment, "")          == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_attachment_set_checksum(attachment, "checksum")  == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_attachment_set_checksum(attachment, CHECKSUM"2") == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_attachment_set_checksum(attachment, NULL)     == ZATHURA_ERROR_OK);
  fail_unless(zathura_attachment_set_checksum(attachment, CHECKSUM) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_attachment_get_checksum) {
  const char* checksum;

  /* invalid arguments */
  fail_unless(zathura_attachment_get_checksum(NULL, NULL)       == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_attachment_get_checksum(attachment, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_attachment_get_checksum(NULL, &checksum)  == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_attachment_set_checksum(attachment, CHECKSUM)  == ZATHURA_ERROR_OK);
  fail_unless(zathura_attachment_get_checksum(attachment, &checksum) == ZATHURA_ERROR_OK);
  fail_unless(strcmp(checksum, CHECKSUM) == 0);

  /* do it again */
  fail_unless(zathura_attachment_set_checksum(attachment, CHECKSUM)  == ZATHURA_ERROR_OK);
  fail_unless(zathura_attachment_get_checksum(attachment, &checksum) == ZATHURA_ERROR_OK);
  fail_unless(strcmp(checksum, CHECKSUM) == 0);
} END_TEST

START_TEST(test_attachment_save) {
  /* invalid arguments */
  fail_unless(zathura_attachment_save(NULL, NULL)       == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_attachment_save(NULL, "")         == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_attachment_save(NULL, "/path")    == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_attachment_save(attachment, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_attachment_save(attachment, "")   == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

Suite*
suite_attachment(void)
{
  TCase* tcase = NULL;
  Suite* suite = suite_create("attachment");

  tcase = tcase_create("basic");
  tcase_add_test(tcase, test_attachment_free);
  tcase_add_test(tcase, test_attachment_new);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("properties");
  tcase_add_checked_fixture(tcase, setup, teardown);
  tcase_add_test(tcase, test_attachment_set_data);
  tcase_add_test(tcase, test_attachment_get_data);
  tcase_add_test(tcase, test_attachment_set_name);
  tcase_add_test(tcase, test_attachment_get_name);
  tcase_add_test(tcase, test_attachment_set_description);
  tcase_add_test(tcase, test_attachment_get_description);
  tcase_add_test(tcase, test_attachment_set_checksum);
  tcase_add_test(tcase, test_attachment_get_checksum);
  tcase_add_test(tcase, test_attachment_set_size);
  tcase_add_test(tcase, test_attachment_get_size);
  tcase_add_test(tcase, test_attachment_set_creation_time);
  tcase_add_test(tcase, test_attachment_get_creation_time);
  tcase_add_test(tcase, test_attachment_set_modification_time);
  tcase_add_test(tcase, test_attachment_get_modification_time);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("save");
  tcase_add_checked_fixture(tcase, setup, teardown);
  tcase_add_test(tcase, test_attachment_save);
  suite_add_tcase(suite, tcase);

  return suite;
}

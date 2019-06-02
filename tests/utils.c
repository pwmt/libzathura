/* See LICENSE file for license and copyright information */

#include <check.h>
#include <stdio.h>
#include <stdbool.h>
#include <libgen.h>

#include "utils.h"

const char*
get_plugin_path(void)
{
  return TEST_PLUGIN_FILE_PATH;
}

const char*
get_plugin_dir_path(void)
{
  return TEST_PLUGIN_DIR_PATH;
}

void setup_document_plugin(zathura_plugin_manager_t** plugin_manager, zathura_document_t** document) {
  fail_unless(zathura_plugin_manager_new(plugin_manager) == ZATHURA_ERROR_OK);
  fail_unless(*plugin_manager != NULL);
  fail_unless(zathura_plugin_manager_load(*plugin_manager, get_plugin_path()) == ZATHURA_ERROR_OK);

  zathura_plugin_t* plugin = NULL;
  fail_unless(zathura_plugin_manager_get_plugin(*plugin_manager, &plugin, "libzathura/test-plugin") == ZATHURA_ERROR_OK);
  fail_unless(plugin != NULL);

  fail_unless(zathura_plugin_open_document(plugin, document, TEST_FILE_PATH, NULL) == ZATHURA_ERROR_OK);
  fail_unless(document != NULL);
}


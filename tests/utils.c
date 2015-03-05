/* See LICENSE file for license and copyright information */

#include <check.h>
#include <stdio.h>

#include "utils.h"

const char*
get_plugin_path(void)
{
#ifdef BUILD_DEBUG
  return "./plugin/plugin.so";
#elif BUILD_GCOV
  return "./plugin/plugin.so";
#else
  return "./plugin/plugin.so";
#endif
}

void setup_document_plugin(zathura_plugin_manager_t** plugin_manager, zathura_document_t** document) {
  fail_unless(zathura_plugin_manager_new(plugin_manager) == ZATHURA_ERROR_OK);
  fail_unless(*plugin_manager != NULL);
  fail_unless(zathura_plugin_manager_load(*plugin_manager, get_plugin_path()) == ZATHURA_ERROR_OK);

  zathura_plugin_t* plugin = NULL;
  fail_unless(zathura_plugin_manager_get_plugin(*plugin_manager, &plugin, "libzathura/test-plugin") == ZATHURA_ERROR_OK);
  fail_unless(plugin != NULL);

  fail_unless(zathura_plugin_open_document(plugin, document, "Makefile", NULL) == ZATHURA_ERROR_OK);
  fail_unless(document != NULL);
}


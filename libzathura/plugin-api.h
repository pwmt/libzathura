/* See LICENSE file for license and copyright information */

#ifndef PLUGIN_API_H
#define PLUGIN_API_H

#include "error.h"
#include "plugin.h"
#include "page.h"

/* plugin */
#define PLUGIN_REGISTER_FUNCTION         "zathura_plugin_register"
#define PLUGIN_API_VERSION_FUNCTION      "zathura_plugin_api_version"
#define PLUGIN_ABI_VERSION_FUNCTION      "zathura_plugin_abi_version"
#define PLUGIN_VERSION_MAJOR_FUNCTION    "zathura_plugin_version_major"
#define PLUGIN_VERSION_MINOR_FUNCTION    "zathura_plugin_version_minor"
#define PLUGIN_VERSION_REVISION_FUNCTION "zathura_plugin_version_revision"

#define ZATHURA_PLUGIN_REGISTER(plugin_name, major, minor, rev, register_functions, mimetypes) \
  unsigned int PLUGIN_VERSION_MAJOR_FUNCTION(void) { return major; } \
  unsigned int PLUGIN_VERSION_MINOR_FUNCTION(void) { return minor; } \
  unsigned int PLUGIN_VERSION_REVISION_FUNCTION(void) { return rev; } \
  unsigned int PLUGIN_API_VERSION_FUNCTION(void) { return ZATHURA_API_VERSION; } \
  unsigned int PLUGIN_ABI_VERSION_FUNCTION(void) { return ZATHURA_ABI_VERSION; } \
  \
  void \
  PLUGIN_REGISTER_FUNCTION(zathura_plugin_t* plugin) \
  { \
    if (plugin == NULL) { \
      return; \
    } \
    \
    zathura_plugin_set_register_functions_function(plugin, register_functions); \
    zathura_plugin_set_name(plugin, plugin_name); \
    \
    static const char* mime_types[] = mimetypes; \
    for (size_t s = 0; s != sizeof(mime_types) / sizeof(const char*); ++s) { \
      zathura_plugin_add_mimetype(plugin, mime_types[s]); \
    } \
  } \

#define ZATHURA_PLUGIN_MIMETYPES(...) __VA_ARGS__

typedef void (*zathura_plugin_register_function_t)(zathura_plugin_functions_t* functions);

zathura_error_t zathura_plugin_set_name(zathura_plugin_t* plugin, const char* name);
zathura_error_t zathura_plugin_set_register_function(zathura_plugin_t* plugin, zathura_plugin_register_function_t function);
zathura_error_t zathura_plugin_add_mimetype(zathura_plugin_t* plugin, const char* mime_type);

/* page */
zathura_error_t zathura_page_new(zathura_page_t** page);

#endif /* PLUGIN_API_H */

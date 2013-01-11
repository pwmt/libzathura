/* See LICENSE file for license and copyright information */

#ifndef PLUGIN_API_H
#define PLUGIN_API_H

#include "error.h"
#include "plugin.h"
#include "page.h"
#include "version.h"

#define PLUGIN_REGISTER_FUNCTION         "zathura_plugin_register"
#define PLUGIN_VERSION_MAJOR_FUNCTION    "zathura_plugin_version_major"
#define PLUGIN_VERSION_MINOR_FUNCTION    "zathura_plugin_version_minor"
#define PLUGIN_VERSION_REVISION_FUNCTION "zathura_plugin_version_revision"
#define PLUGIN_API_VERSION_FUNCTION      "zathura_plugin_api_version"
#define PLUGIN_ABI_VERSION_FUNCTION      "zathura_plugin_abi_version"

/* plugin */
#define ZATHURA_PLUGIN_REGISTER(plugin_name, major, minor, rev, register_functions, mimetypes) \
  unsigned int zathura_plugin_version_major(void) { return major; } \
  unsigned int zathura_plugin_version_minor(void) { return minor; } \
  unsigned int zathura_plugin_version_revision(void) { return rev; } \
  unsigned int zathura_plugin_api_version(void) { return ZATHURA_API_VERSION; } \
  unsigned int zathura_plugin_abi_version(void) { return ZATHURA_ABI_VERSION; } \
  \
  void zathura_plugin_register(zathura_plugin_t* plugin) \
  { \
    if (plugin == NULL) { \
      return; \
    } \
    zathura_plugin_set_register_function(plugin, register_functions); \
    zathura_plugin_set_name(plugin, plugin_name); \
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
zathura_error_t zathura_page_free(zathura_page_t* page);
zathura_error_t zathura_page_set_index(zathura_page_t* page, unsigned int index);
zathura_error_t zathura_page_set_width(zathura_page_t* page, unsigned int width);
zathura_error_t zathura_page_set_height(zathura_page_t* page, unsigned int height);
zathura_error_t zathura_page_set_label(zathura_page_t* page, const char* label);

#endif /* PLUGIN_API_H */

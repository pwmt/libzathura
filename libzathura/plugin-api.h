/* See LICENSE file for license and copyright information */

#ifndef PLUGIN_API_H
#define PLUGIN_API_H

#include "error.h"
#include "plugin.h"
#include "page.h"
#include "version.h"
#include "attachment.h"
#include "list.h"
#include "image.h"
#include "types.h"
#include "libzathura.h"

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

typedef zathura_error_t (*zathura_plugin_document_open_t)(zathura_document_t* document);
typedef zathura_error_t (*zathura_plugin_document_free_t)(zathura_document_t* document);
typedef zathura_error_t (*zathura_plugin_document_save_as_t)(zathura_document_t* document, const char* path);
typedef zathura_error_t (*zathura_plugin_document_get_outline_t)(zathura_document_t* document, zathura_node_t** outline);
typedef zathura_error_t (*zathura_plugin_document_get_attachments_t)(zathura_document_t* document, zathura_list_t** attachments);
typedef zathura_error_t (*zathura_plugin_document_get_metadata_t)(zathura_document_t* document, zathura_list_t** metadata);

typedef zathura_error_t (*zathura_plugin_page_init_t)(zathura_page_t* page);
typedef zathura_error_t (*zathura_plugin_page_clear_t)(zathura_page_t* page);
typedef zathura_error_t (*zathura_plugin_page_search_text_t)(zathura_page_t* page, const char* text, zathura_search_flag_t flags, zathura_list_t** results);
typedef zathura_error_t (*zathura_plugin_page_get_text_t)(zathura_page_t* page, char** text);
typedef zathura_error_t (*zathura_plugin_page_get_selected_text_t)(zathura_page_t* page, char** text, zathura_rectangle_t rectangle);
typedef zathura_error_t (*zathura_plugin_page_get_links_t)(zathura_page_t* page, zathura_list_t** links);
typedef zathura_error_t (*zathura_plugin_page_get_form_fields_t)(zathura_page_t* page, zathura_list_t** form_fields);
typedef zathura_error_t (*zathura_plugin_page_get_images_t)(zathura_page_t* page, zathura_list_t** images);
typedef zathura_error_t (*zathura_plugin_page_get_annotations_t)(zathura_page_t* page, zathura_list_t** annotations);
typedef zathura_error_t (*zathura_plugin_page_render_t)(zathura_page_t* page, zathura_image_buffer_t** buffer, double scale, int rotation, int flags);
#ifdef HAVE_CAIRO
typedef zathura_error_t (*zathura_plugin_page_render_cairo_t)(zathura_page_t* page, cairo_t* cairo, double scale, int rotation, int flags);
#endif

struct zathura_plugin_functions_s {
  zathura_plugin_document_open_t document_open;
  zathura_plugin_document_free_t document_free;
  zathura_plugin_document_save_as_t document_save_as;
  zathura_plugin_document_get_outline_t document_get_outline;
  zathura_plugin_document_get_attachments_t document_get_attachments;
  zathura_plugin_document_get_metadata_t document_get_metadata;

  zathura_plugin_page_init_t page_init;
  zathura_plugin_page_clear_t page_clear;
  zathura_plugin_page_search_text_t page_search_text;
  zathura_plugin_page_get_text_t page_get_text;
  zathura_plugin_page_get_selected_text_t page_get_selected_text;
  zathura_plugin_page_get_links_t page_get_links;
  zathura_plugin_page_get_form_fields_t page_get_form_fields;
  zathura_plugin_page_get_images_t page_get_images;
  zathura_plugin_page_get_annotations_t page_get_annotations;
  zathura_plugin_page_render_t page_render;
#ifdef HAVE_CAIRO
  zathura_plugin_page_render_cairo_t page_render_cairo;
#endif
};

zathura_error_t zathura_plugin_set_name(zathura_plugin_t* plugin, const char* name);
zathura_error_t zathura_plugin_set_register_function(zathura_plugin_t* plugin, zathura_plugin_register_function_t function);
zathura_error_t zathura_plugin_add_mimetype(zathura_plugin_t* plugin, const char* mime_type);

#include "plugin-api/attachment.h"
#include "plugin-api/document.h"
#include "plugin-api/form-fields.h"
#include "plugin-api/outline.h"
#include "plugin-api/page.h"
#include "plugin-api/metadata.h"
#include "plugin-api/transition.h"
#include "plugin-api/image.h"

#endif /* PLUGIN_API_H */

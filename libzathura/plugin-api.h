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

typedef zathura_error_t (*zathura_plugin_document_open_t)(zathura_document_t* document);
typedef zathura_error_t (*zathura_plugin_document_free_t)(zathura_document_t* document, void* data);
typedef zathura_error_t (*zathura_plugin_document_save_as)(zathura_document_t* document, const char* path);
typedef zathura_error_t (*zathura_plugin_document_get_index)(zathura_document_t* document, zathura_node_t** index);
typedef zathura_error_t (*zathura_plugin_document_get_attachments)(zathura_document_t* document, zathura_list_t** attachments);
typedef zathura_error_t (*zathura_plugin_document_get_information)(zathura_document_t* document, zathura_list_t** information);

typedef zathura_error_t (*zathura_plugin_page_init_t)(zathura_page_t* page);
typedef zathura_error_t (*zathura_plugin_page_clear_t)(zathura_page_t* page, void* data);

//typedef girara_tree_node_t* (*zathura_plugin_document_index_generate_t)(zathura_document_t* document, void* data, zathura_error_t* error);

//typedef zathura_error_t (*zathura_plugin_document_save_as_t)(zathura_document_t* document, void* data, const char* path);
//typedef girara_list_t* (*zathura_plugin_document_attachments_get_t)(zathura_document_t* document, void* data, zathura_error_t* error);
//typedef zathura_error_t (*zathura_plugin_document_attachment_save_t)(zathura_document_t* document, void* data, const char* attachment, const char* file);
//typedef girara_list_t* (*zathura_plugin_document_get_information_t)(zathura_document_t* document, void* data, zathura_error_t* error);
//typedef zathura_error_t (*zathura_plugin_page_init_t)(zathura_page_t* page);
//typedef zathura_error_t (*zathura_plugin_page_clear_t)(zathura_page_t* page, void* data);
//typedef girara_list_t* (*zathura_plugin_page_search_text_t)(zathura_page_t* page, void* data, const char* text, zathura_error_t* error);
//typedef girara_list_t* (*zathura_plugin_page_links_get_t)(zathura_page_t* page, void* data, zathura_error_t* error);
//typedef girara_list_t* (*zathura_plugin_page_form_fields_get_t)(zathura_page_t* page, void* data, zathura_error_t* error);
//typedef girara_list_t* (*zathura_plugin_page_images_get_t)(zathura_page_t* page, void* data, zathura_error_t* error);
//typedef cairo_surface_t* (*zathura_plugin_page_image_get_cairo_t)(zathura_page_t* page, void* data, zathura_image_t* image, zathura_error_t* error);
//typedef char* (*zathura_plugin_page_get_text_t)(zathura_page_t* page, void* data, zathura_rectangle_t rectangle, zathura_error_t* error);
//typedef zathura_image_buffer_t* (*zathura_plugin_page_render_t)(zathura_page_t* page, void* data, zathura_error_t* error);
//typedef zathura_error_t (*zathura_plugin_page_render_cairo_t)(zathura_page_t* page, void* data, cairo_t* cairo, bool printing);

/* plugin */
zathura_error_t zathura_plugin_set_name(zathura_plugin_t* plugin, const char* name);
zathura_error_t zathura_plugin_set_register_function(zathura_plugin_t* plugin, zathura_plugin_register_function_t function);
zathura_error_t zathura_plugin_add_mimetype(zathura_plugin_t* plugin, const char* mime_type);

/* document */
zathura_error_t zathura_document_set_number_of_pages(zathura_document_t* document, unsigned int number_of_pages);

/* page */
zathura_error_t zathura_page_new(zathura_page_t** page);
zathura_error_t zathura_page_set_data(zathura_page_t* page, void* data);
zathura_error_t zathura_page_get_data(zathura_page_t* page, void** data);
zathura_error_t zathura_page_set_index(zathura_page_t* page, unsigned int index);
zathura_error_t zathura_page_set_width(zathura_page_t* page, unsigned int width);
zathura_error_t zathura_page_set_height(zathura_page_t* page, unsigned int height);
zathura_error_t zathura_page_set_label(zathura_page_t* page, const char* label);
zathura_error_t zathura_page_set_transition(zathura_page_t* page, zathura_page_transition_t* transition);

#endif /* PLUGIN_API_H */

/* See LICENSE file for license and copyright information */
#ifndef LIBZATHURA_INTERNAL_H
#define LIBZATHURA_INTERNAL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <gmodule.h>

#include "document.h"
#include "plugin-api.h"
#include "error.h"
#include "transition.h"

struct zathura_plugin_manager_s {
  zathura_list_t* plugins; /**< List of pluins */
};

struct zathura_plugin_s {
  GModule* handle;
  zathura_plugin_register_function_t register_function;
  zathura_plugin_functions_t functions;
  zathura_plugin_version_t version;
  zathura_list_t* mimetypes;
  char* name;
  char* path;
};

struct zathura_document_s {
  char* path;
  char* password;
  unsigned int number_of_pages;
  zathura_page_t** pages;
  zathura_plugin_t* plugin;

  zathura_page_layout_t page_layout;
  zathura_page_mode_t page_mode;
  zathura_document_permission_t permissions;

  void* user_data;
};

struct zathura_page_s {
  zathura_document_t* document;
  unsigned int index;
  unsigned int width;
  unsigned int height;
  char* label;
  zathura_page_transition_t* transition;
  zathura_rectangle_t crop_box;
  unsigned int duration;

  void* user_data;
};

struct zathura_document_meta_entry_s {
  zathura_document_meta_type_t type;
  char* value;
};

zathura_error_t zathura_document_new(zathura_document_t** document);

/**
 * Creates a new page object
 *
 * @param[out] page
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_page_new(zathura_page_t** page);
zathura_error_t zathura_page_free(zathura_page_t* page);
zathura_error_t zathura_page_set_document(zathura_page_t* page, zathura_document_t* document);

zathura_error_t zathura_realpath(const char* path, char** realpath);
zathura_error_t zathura_guess_type(const char* path, char** type);

#ifdef __cplusplus
}
#endif

#endif /* INTERNAL_H */

/* See LICENSE file for license and copyright information */

#ifndef INTERNAL_H
#define INTERNAL_H

#include "document.h"
#include "plugin-api.h"
#include "error.h"

struct zathura_plugin_s {
  zathura_plugin_register_function_t register_function;
  zathura_plugin_functions_t functions;
  zathura_plugin_version_t version;
  char* name;
  char* path;
};

struct zathura_document_s {
  char* path;
  char* password;
  unsigned int number_of_pages;
  zathura_page_t** pages;
  zathura_plugin_t* plugin;
};

struct zathura_page_s {
  zathura_document_t* document;
  unsigned int width;
  unsigned int height;
  char* label;
};

zathura_error_t zathura_page_free(zathura_page_t* page);

zathura_error_t zathura_realpath(const char* path, char** realpath);
zathura_error_t zathura_guess_type(const char* path, char** type);

#endif /* INTERNAL_H */

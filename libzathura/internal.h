/* See LICENSE file for license and copyright information */

#ifndef INTERNAL_H
#define INTERNAL_H

#include "document.h"
#include "plugin-api.h"
#include "error.h"

struct zathura_plugin_s {
  zathura_plugin_functions_t* functions;
  char* path;
};

struct zathura_page_s {
  zathura_document_t* document;
  unsigned int width;
  unsigned int height;
  char* label;
};

zathura_error_t zathura_realpath(const char* path, char** realpath);

#endif /* INTERNAL_H */

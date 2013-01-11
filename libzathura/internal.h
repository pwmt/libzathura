/* See LICENSE file for license and copyright information */

#ifndef INTERNAL_H
#define INTERNAL_H

#include "document.h"

struct zathura_plugin_s {
  char* path;
};

struct zathura_page_s {
  zathura_document_t* document;
  unsigned int width;
  unsigned int height;
  char* label;
};

#endif /* INTERNAL_H */

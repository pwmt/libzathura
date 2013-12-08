/* See LICENSE file for license and copyright information */

#ifndef PLUGIN_API_DOCUMENT_H
#define PLUGIN_API_DOCUMENT_H

#include "../error.h"
#include "../document.h"

zathura_error_t zathura_document_set_number_of_pages(zathura_document_t* document, unsigned int number_of_pages);

#endif /* PLUGIN_API_DOCUMENT_H */

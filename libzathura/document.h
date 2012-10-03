/* See LICENSE file for license and copyright information */

#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "error.h"
#include "list.h"
#include "node.h"

typedef struct zathura_document_s zathura_document_t;

zathura_error_t zathura_document_free(zathura_document_t* document);
zathura_error_t zathura_document_save_as(zathura_document_t* document, const char* path);

zathura_error_t zathura_document_get_path(zathura_document_t* document, char** path);
zathura_error_t zathura_document_get_password(zathura_document_t* document, char** password);
zathura_error_t zathura_document_get_number_of_pages(zathura_document_t* document, unsigned int *number_of_pages);

zathura_error_t zathura_document_get_page(zathura_document_t* document, unsigned int index, zathura_page_t** page);

zathura_error_t zathura_document_get_index(zathura_document_t* document, zathura_node_t** index);
zathura_error_t zathura_document_get_attachments(zathura_document_t* document, zathura_list_t** attachments);
zathura_error_t zathura_document_get_information(zathura_document_t* document, zathura_list_t** information);

#endif /* DOCUMENT_H */

/* See LICENSE file for license and copyright information */

#include <stdlib.h>
#include <string.h>

#include "document.h"

zathura_error_t
zathura_document_free(zathura_document_t* document)
{
  if (document == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_document_save_as(zathura_document_t* document, const char* path)
{
  if (document == NULL || path == NULL || strlen(path) == 0) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_document_get_path(zathura_document_t* document, char** path)
{
  if (document == NULL || path == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_document_get_number_of_pages(zathura_document_t* document, unsigned int *number_of_pages)
{
  if (document == NULL || number_of_pages == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_document_get_page(zathura_document_t* document, unsigned int index, zathura_page_t** page)
{
  if (document == NULL || page == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_document_get_page_by_label(zathura_document_t* document, const char* label, zathura_page_t** page)
{
  if (document == NULL || label == NULL || strlen(label) == 0 || page == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_document_get_index(zathura_document_t* document, zathura_node_t** index)
{
  if (document == NULL || index == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_document_get_attachments(zathura_document_t* document, zathura_list_t** attachments)
{
  if (document == NULL || attachments == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_document_get_information(zathura_document_t* document, zathura_list_t** information)
{
  if (document == NULL || information == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  return ZATHURA_ERROR_OK;
}

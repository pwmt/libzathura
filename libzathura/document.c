/* See LICENSE file for license and copyright information */

#include <stdlib.h>
#include <string.h>

#include "internal.h"
#include "document.h"
#include "macros.h"

zathura_error_t
zathura_document_free(zathura_document_t* document)
{
  if (document == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  /* free pages */
  if (document->pages != NULL) {
    for (unsigned int pid = 0; pid < document->number_of_pages; pid++) {
      zathura_page_free(document->pages[pid]);
    }

    free(document->pages);
  }

  free(document->password);
  free(document->path);

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
zathura_document_get_page(zathura_document_t* document, unsigned int
    UNUSED(index), zathura_page_t** page)
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
zathura_document_get_page_mode(zathura_document_t* document,
    zathura_page_mode_t* page_mode)
{
  if (document == NULL || page_mode == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_document_get_page_layout(zathura_document_t* document,
    zathura_page_layout_t* page_layout)
{
  if (document == NULL || page_layout == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  return ZATHURA_ERROR_OK;

}

zathura_error_t
zathura_document_get_outline(zathura_document_t* document, zathura_node_t** outline)
{
  if (document == NULL || outline == NULL) {
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
zathura_document_get_metadata(zathura_document_t* document, zathura_list_t**
    metadata)
{
  if (document == NULL || metadata == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_document_get_permissions(zathura_document_t* document,
    zathura_document_permission_t* permissions)
{
  if (document == NULL || permissions == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  return ZATHURA_ERROR_OK;
}

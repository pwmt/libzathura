/* See LICENSE file for license and copyright information */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "internal.h"
#include "document.h"
#include "macros.h"

#define CHECK_IF_IMPLEMENTED(document, function) \
  if ((document)->plugin == NULL || \
      (document)->plugin->functions.function == NULL) { \
    return ZATHURA_ERROR_PLUGIN_NOT_IMPLEMENTED; \
  }

zathura_error_t
zathura_document_new(zathura_document_t** document)
{
  if (document == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *document = calloc(1, sizeof(zathura_document_t));
  if (*document == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  return ZATHURA_ERROR_OK;
}

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

  if (document->plugin != NULL && document->plugin->functions.document_free != NULL) {
    document->plugin->functions.document_free(document);
  }

  free(document);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_document_set_data(zathura_document_t* document,
    void* data)
{
  if (document == NULL || data == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  document->data = data;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_document_get_data(zathura_document_t* document,
    void** data)
{
  if (document == NULL || data == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *data = document->data;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_document_get_path(zathura_document_t* document, char** path)
{
  if (document == NULL || path == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *path = document->path;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_document_get_password(zathura_document_t* document,
    char** password)
{
  if (document == NULL || password == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *password = document->password;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_document_set_number_of_pages(zathura_document_t* document, unsigned int number_of_pages)
{
  if (document == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  document->number_of_pages = number_of_pages;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_document_get_number_of_pages(zathura_document_t* document, unsigned int *number_of_pages)
{
  if (document == NULL || number_of_pages == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *number_of_pages = document->number_of_pages;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_document_get_page(zathura_document_t* document, unsigned int index,
    zathura_page_t** page)
{
  if (document == NULL || page == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_IF_IMPLEMENTED(document, page_init)

  if (index >= document->number_of_pages) {
    return ZATHURA_ERROR_DOCUMENT_INVALID_INDEX;
  }

  if (document->pages[index] == NULL) {
    zathura_error_t error = ZATHURA_ERROR_OK;
    error = zathura_page_new(&(document->pages[index]));
    if (error != ZATHURA_ERROR_OK) {
      return error;
    }

    error = zathura_page_set_document(document->pages[index], document);
    if (error != ZATHURA_ERROR_OK) {
      return error;
    }

    error = zathura_page_set_index(document->pages[index], index);
    if (error != ZATHURA_ERROR_OK) {
      return error;
    }

    error = document->plugin->functions.page_init(document->pages[index]);
    if (error != ZATHURA_ERROR_OK) {
      return error;
    }
  } else {
    *page = document->pages[index];
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_document_get_page_by_label(zathura_document_t* document, const char* label, zathura_page_t** page)
{
  if (document == NULL || label == NULL || strlen(label) == 0 || page == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  for (unsigned int i = 0; i < document->number_of_pages; i++) {
    if (document->pages[i]->label != NULL && strcmp(document->pages[i]->label, label) == 0) {
      *page = document->pages[i];
      return ZATHURA_ERROR_OK;
    }
  }

  return ZATHURA_ERROR_DOCUMENT_INVALID_LABEL;
}

zathura_error_t
zathura_document_set_page_mode(zathura_document_t* document,
    zathura_page_mode_t page_mode)
{
  if (document == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  document->page_mode = page_mode;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_document_get_page_mode(zathura_document_t* document,
    zathura_page_mode_t* page_mode)
{
  if (document == NULL || page_mode == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *page_mode = document->page_mode;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_document_set_page_layout(zathura_document_t* document,
    zathura_page_layout_t page_layout)
{
  if (document == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  document->page_layout = page_layout;

  return ZATHURA_ERROR_OK;

}

zathura_error_t
zathura_document_get_page_layout(zathura_document_t* document,
    zathura_page_layout_t* page_layout)
{
  if (document == NULL || page_layout == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *page_layout = document->page_layout;

  return ZATHURA_ERROR_OK;

}

zathura_error_t
zathura_document_set_permissions(zathura_document_t* document,
    zathura_document_permission_t permissions)
{
  if (document == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  document->permissions = permissions;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_document_get_permissions(zathura_document_t* document,
    zathura_document_permission_t* permissions)
{
  if (document == NULL || permissions == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *permissions = document->permissions;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_document_save_as(zathura_document_t* document, const char* path)
{
  if (document == NULL || path == NULL || strlen(path) == 0) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_IF_IMPLEMENTED(document, document_save_as)

  return document->plugin->functions.document_save_as(document, path);
}

zathura_error_t
zathura_document_get_outline(zathura_document_t* document, zathura_node_t** outline)
{
  if (document == NULL || outline == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_IF_IMPLEMENTED(document, document_get_outline)

  return document->plugin->functions.document_get_outline(document, outline);
}

zathura_error_t
zathura_document_get_attachments(zathura_document_t* document, zathura_list_t** attachments)
{
  if (document == NULL || attachments == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_IF_IMPLEMENTED(document, document_get_attachments)

  return document->plugin->functions.document_get_attachments(document, attachments);
}

zathura_error_t
zathura_document_get_metadata(zathura_document_t* document, zathura_list_t**
    metadata)
{
  if (document == NULL || metadata == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_IF_IMPLEMENTED(document, document_get_metadata)

  return document->plugin->functions.document_get_metadata(document, metadata);
}

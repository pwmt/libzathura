/* See LICENSE file for license and copyright information */

#include "libzathura/plugin-api.h"
#include "libzathura/macros.h"
#include <stdio.h>

/* forward declarations */
void register_functions(zathura_plugin_functions_t* functions);
zathura_error_t document_open(zathura_document_t* document);
zathura_error_t document_free(zathura_document_t* document);
zathura_error_t document_save_as(zathura_document_t* document, const char* path);
zathura_error_t document_get_outline(zathura_document_t* document, zathura_node_t** outline);
zathura_error_t document_get_attachments(zathura_document_t* document, zathura_list_t** attachments);
zathura_error_t document_get_metadata(zathura_document_t* document, zathura_list_t** metadata);
zathura_error_t page_init(zathura_page_t* page);
zathura_error_t page_clear(zathura_page_t* page);

/* register plugin */
ZATHURA_PLUGIN_REGISTER(
  "plugin",
  0,
  0,
  0,
  register_functions,
  ZATHURA_PLUGIN_MIMETYPES({
    "libzathura/test-plugin",
  })
)

/* functions implementation */
void
register_functions(zathura_plugin_functions_t* functions)
{
  functions->document_open = document_open;
  functions->document_free = document_free;
  functions->document_save_as = document_save_as;
  functions->document_get_outline = document_get_outline;
  functions->document_get_attachments = document_get_attachments;
  functions->document_get_metadata = document_get_metadata;

  functions->page_init = page_init;
  functions->page_clear = page_clear;
}

zathura_error_t
document_open(zathura_document_t* document)
{
  if (document == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  zathura_error_t error = ZATHURA_ERROR_OK;

  if ((error = zathura_document_set_number_of_pages(document, 10))
      != ZATHURA_ERROR_OK) {
    return error;
  }

  if ((error = zathura_document_set_page_mode(document, ZATHURA_PAGE_MODE_USE_NONE))
      != ZATHURA_ERROR_OK) {
    return error;
  }

  if ((error = zathura_document_set_page_layout(document, ZATHURA_PAGE_LAYOUT_SINGLE_PAGE))
      != ZATHURA_ERROR_OK) {
    return error;
  }

  if ((error = zathura_document_set_permissions(document, ZATHURA_PERMISSION_PRINT))
      != ZATHURA_ERROR_OK) {
    return error;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
document_free(zathura_document_t* UNUSED(document))
{
  return ZATHURA_ERROR_OK;
}

zathura_error_t
page_init(zathura_page_t* page)
{
  if (page == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  unsigned int index;
  if (zathura_page_get_index(page, &index) == ZATHURA_ERROR_OK && index == 0) {
    zathura_page_set_label(page, "abc");
  }

  if (zathura_page_set_width(page, 600) != ZATHURA_ERROR_OK) {
    return ZATHURA_ERROR_UNKNOWN;
  }

  if (zathura_page_set_height(page, 800) != ZATHURA_ERROR_OK) {
    return ZATHURA_ERROR_UNKNOWN;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
page_clear(zathura_page_t* UNUSED(page))
{
  return ZATHURA_ERROR_OK;
}

zathura_error_t
document_save_as(zathura_document_t* UNUSED(document), const char* UNUSED(path))
{
  return ZATHURA_ERROR_OK;
}

zathura_error_t
document_get_outline(zathura_document_t* UNUSED(document), zathura_node_t** UNUSED(outline))
{
  return ZATHURA_ERROR_OK;
}

zathura_error_t
document_get_attachments(zathura_document_t* UNUSED(document), zathura_list_t** UNUSED(attachments))
{
  return ZATHURA_ERROR_OK;
}

zathura_error_t
document_get_metadata(zathura_document_t* UNUSED(document), zathura_list_t** UNUSED(metadata))
{
  return ZATHURA_ERROR_OK;
}

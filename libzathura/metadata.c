/* See LICENSE file for license and copyright information */

#include <stdlib.h>

#include "metadata.h"
#include "internal.h"
#include "plugin-api/metadata.h"

zathura_error_t
zathura_document_meta_entry_new(zathura_document_meta_entry_t**
    entry, zathura_document_meta_type_t type, const char* value)
{
  if (entry == NULL || value == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *entry = calloc(1, sizeof(**entry));
  if (*entry == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  (*entry)->value = g_strdup(value);
  (*entry)->type = type;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_document_meta_entry_free(zathura_document_meta_entry_t*
    entry)
{
  if (entry == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  if (entry->value != NULL) {
    g_free(entry->value);
    entry->value = NULL;
  }

  free(entry);

  return ZATHURA_ERROR_OK;
}


zathura_error_t
zathura_document_meta_entry_get_type(zathura_document_meta_entry_t* entry,
    zathura_document_meta_type_t* type)
{
  if (entry == NULL || type == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *type = entry->type;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_document_meta_entry_get_value(zathura_document_meta_entry_t* entry,
    const char** value)
{
  if (entry == NULL || value == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *value = entry->value;

  return ZATHURA_ERROR_OK;
}

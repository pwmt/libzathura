/* See LICENSE file for license and copyright information */

#ifndef METADATA_H
#define METADATA_H

#include "error.h"

typedef enum zathura_document_meta_type_e {
  ZATHURA_DOCUMENT_META_OTHER,
  ZATHURA_DOCUMENT_META_TITLE,
  ZATHURA_DOCUMENT_META_AUTHOR,
  ZATHURA_DOCUMENT_META_SUBJECT,
  ZATHURA_DOCUMENT_META_KEYWORDS,
  ZATHURA_DOCUMENT_META_CREATOR,
  ZATHURA_DOCUMENT_META_PRODUCER,
  ZATHURA_DOCUMENT_META_CREATION_DATE,
  ZATHURA_DOCUMENT_META_MODIFICATION_DATE,
} zathura_document_meta_type_t;

typedef struct zathura_document_meta_entry_s zathura_document_meta_entry_t;

zathura_error_t zathura_document_meta_entry_get_type(zathura_document_meta_entry_t*
    entry, zathura_document_meta_type_t* type);
zathura_error_t zathura_document_meta_entry_get_value(zathura_document_meta_entry_t*
    entry, const char** value);

#endif /* METADATA_H */

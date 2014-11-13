/* See LICENSE file for license and copyright information */

#ifndef PLUGIN_API_METADATA_H
#define PLUGIN_API_METADATA_H

#include "../error.h"
#include "../metadata.h"

zathura_error_t zathura_document_meta_entry_new(zathura_document_meta_entry_t**
    entry, zathura_document_meta_type_t type, const char* value);

zathura_error_t zathura_document_meta_entry_free(zathura_document_meta_entry_t*
    entry);

#endif /* PLUGIN_API_METADATA_H */

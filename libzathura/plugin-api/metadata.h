/* See LICENSE file for license and copyright information */

#ifndef LIBZATHURA_PLUGIN_API_METADATA_H
#define LIBZATHURA_PLUGIN_API_METADATA_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../error.h"
#include "../metadata.h"

zathura_error_t zathura_document_meta_entry_new(zathura_document_meta_entry_t**
    entry, zathura_document_meta_type_t type, const char* value);

zathura_error_t zathura_document_meta_entry_free(zathura_document_meta_entry_t*
    entry);

#ifdef __cplusplus
}
#endif

#endif /* PLUGIN_API_METADATA_H */

/* See LICENSE file for license and copyright information */

#ifndef LIBZATHURA_PLUGIN_API_DOCUMENT_H
#define LIBZATHURA_PLUGIN_API_DOCUMENT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../error.h"
#include "../document.h"

/**
 * Sets the number of pages that the document has.
 *
 * @param[in] document The document object
 * @param[in] number_of_pages The number of pages
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_document_set_number_of_pages(zathura_document_t* document, unsigned int number_of_pages);

zathura_error_t zathura_document_set_page_mode(zathura_document_t* document,
    zathura_page_mode_t page_mode);

zathura_error_t
zathura_document_set_page_layout(zathura_document_t* document,
    zathura_page_layout_t page_layout);

zathura_error_t
zathura_document_set_permissions(zathura_document_t* document,
    zathura_document_permission_t permissions);

zathura_error_t
zathura_document_set_user_data(zathura_document_t* document,
    void* user_data);

zathura_error_t
zathura_document_get_user_data(zathura_document_t* document,
    void** user_data);

zathura_error_t
zathura_document_get_password(zathura_document_t* document,
    char** password);

#ifdef __cplusplus
}
#endif

#endif /* PLUGIN_API_DOCUMENT_H */

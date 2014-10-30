/* See LICENSE file for license and copyright information */

#ifndef PLUGIN_API_DOCUMENT_H
#define PLUGIN_API_DOCUMENT_H

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
zathura_document_set_data(zathura_document_t* document,
    void* data);

zathura_error_t
zathura_document_get_data(zathura_document_t* document,
    void** data);

#endif /* PLUGIN_API_DOCUMENT_H */

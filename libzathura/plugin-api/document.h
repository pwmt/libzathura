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

#endif /* PLUGIN_API_DOCUMENT_H */

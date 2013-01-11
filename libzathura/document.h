/* See LICENSE file for license and copyright information */

#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "error.h"
#include "list.h"
#include "node.h"
#include "page.h"

typedef struct zathura_document_s zathura_document_t;

/**
 * Frees the given document
 *
 * @param[in] document The zathura document object
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_document_free(zathura_document_t* document);

/**
 * Saves a copy of the given @a document to the specified @a path
 *
 * @param[in] document The zathura document object
 * @param[in] path The path where the new file should be stored
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 * @return ZATHURA_ERROR_PLUGIN_NOT_IMPLEMENTED This feature is not implemented
 *  by the plugin
 */
zathura_error_t zathura_document_save_as(zathura_document_t* document, const char* path);

/**
 * Returns the path of the @a document
 *
 * @param[in] document The zathura document object
 * @param[out] path The path of the @a document
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_document_get_path(zathura_document_t* document, char** path);

/**
 * Returns the number of pages of the @a document
 *
 * @param[in] document The zathura document object
 * @param[out] number_of_pages The number of pages of the document
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_document_get_number_of_pages(zathura_document_t* document, unsigned int *number_of_pages);

/**
 * Returns the page object specified by the given @a id
 *
 * @param[in] document The zathura document object
 * @param[in] index The index of the page that should be returned
 * @param[out] page The page that should be returned
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 * @return ZATHURA_ERROR_DOCUMENT_INVALID_INDEX Invalid index passed
 */
zathura_error_t zathura_document_get_page(zathura_document_t* document, unsigned int index, zathura_page_t** page);

/**
 * Returns the page object specified by the given @a label
 *
 * @param[in] document The zathura document object
 * @param[in] label The label of the page that should be returned
 * @param[out] page The page that should be returned
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 * @return ZATHURA_ERROR_DOCUMENT_INVALID_LABEL Invalid label
 */
zathura_error_t zathura_document_get_page_by_label(zathura_document_t* document, const char* label, zathura_page_t** page);

zathura_error_t zathura_document_get_index(zathura_document_t* document, zathura_node_t** index);
zathura_error_t zathura_document_get_attachments(zathura_document_t* document, zathura_list_t** attachments);
zathura_error_t zathura_document_get_information(zathura_document_t* document, zathura_list_t** information);

#endif /* DOCUMENT_H */

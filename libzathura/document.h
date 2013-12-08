/* See LICENSE file for license and copyright information */

#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "error.h"
#include "list.h"
#include "node.h"
#include "page.h"

typedef enum zathura_page_layout_e {
  /**
   * Display one page at the time
   */
  ZATHURA_PAGE_LAYOUT_SINGLE_PAGE = 0,

  /**
   * Display the pages in one column
   */
  ZATHURA_PAGE_LAYOUT_ONE_COLUMN,

  /**
   * Display the pages in two columns, with odd-numbered pages on the left
   */
  ZATHURA_PAGE_LAYOUT_TWO_COLUMN_LEFT,

  /**
   * Display the pages in two columns, with odd-numbered pages on the right
   */
  ZATHURA_PAGE_LAYOUT_TWO_COLUMN_RIGHT,

  /**
   * Display the pages two at a time, with odd-numbered pages on the left
   */
  ZATHURA_PAGE_LAYOUT_TWO_PAGE_LEFT,

  /**
   * Display the pages two at a time, with odd-numbered pages on the right
   */
  ZATHURA_PAGE_LAYOUT_TWO_PAGE_RIGHT
} zathura_page_layout_t;

typedef enum zathura_page_mode_e {
  /**
   * Neither document outline nor thumbnail images visible
   */
  ZATHURA_PAGE_MODE_USE_NONE = 0,

  /**
   * Document outline visible
   */
  ZATHURA_PAGE_MODE_USE_OUTLINES,

  /**
   * Thumbnail images visible
   */
  ZATHURA_PAGE_MODE_USE_THUMBS,

  /**
   * Full-screen mode, with no menu bar, window controls, or any other window
   * visible
   */
  ZATHURA_PAGE_MODE_FULL_SCREEN,

  /**
   * Optional content group panel visible
   */
  ZATHURA_PAGE_MODE_USE_CONTENT_GROUP,

  /**
   * Attachments panel visible
   */
  ZATHURA_PAGE_MODE_USE_ATTACHMENTS
} zathura_page_mode_t;

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
zathura_error_t zathura_document_save_as(zathura_document_t* document, const
    char* path);

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
zathura_error_t zathura_document_get_path(zathura_document_t* document, char**
    path);

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
zathura_error_t zathura_document_get_number_of_pages(zathura_document_t*
    document, unsigned int *number_of_pages);

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
zathura_error_t zathura_document_get_page(zathura_document_t* document, unsigned
    int index, zathura_page_t** page);

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
zathura_error_t zathura_document_get_page_by_label(zathura_document_t* document,
    const char* label, zathura_page_t** page);

/**
 * Returns the page mode that specifies how the document should be displayed
 * when opened.
 *
 * @param[in] document The zathura document object
 * @param[out] page_mode The page mode of the document
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_document_get_page_mode(zathura_document_t* document,
    zathura_page_mode_t* page_mode);

/**
 * Returns the page layout that should be used when the document has been
 * opened.
 *
 * @param[in] document The zathura document object
 * @param[out] page_layout The page layout of the document
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_document_get_page_layout(zathura_document_t* document,
    zathura_page_layout_t* page_layout);

/**
 * Returns the outline of the document
 *
 * @param[in] document The zathura document object
 * @param[out] outline The outline of the document
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_document_get_outline(zathura_document_t* document,
    zathura_node_t** index);

/**
 * Returns the list of the attached files of this document
 *
 * @param[in] document The zathura document object
 * @param[out] index List of files attached to this document
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_document_get_attachments(zathura_document_t* document,
    zathura_list_t** attachments);

/**
 * Returns the list of the meta data information of this document
 *
 * @param[in] document The zathura document object
 * @param[out] meta_data List of meta data information
 * *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_document_get_meta_data(zathura_document_t* document,
    zathura_list_t** meta_data);

#endif /* DOCUMENT_H */

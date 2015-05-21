/* See LICENSE file for license and copyright information */

#ifndef DOCUMENT_H
#define DOCUMENT_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct zathura_document_s zathura_document_t;

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

typedef enum zathura_document_permission_e {
  /**
   * Print the document (possibly not at the highest quality level.
  */
  ZATHURA_PERMISSION_PRINT = 1 << 3,

  /**
   * Modify the contents of the document by operations other than those
   * controlled by bits 6, 9, and 11.
   */
  ZATHURA_PERMISSION_MODIFY = 1 << 4,

  /**
   * Copy or otherwise extract text and graphics from the document by operations
   * other than that controlled by bit 10.
  */
  ZATHURA_PERMISSION_COPY = 1 << 5,

  /**
   * Add or modify text annotations, fill in interactive form fields, and, if
   * bit 4 is also set, create or modify interactive form fields (including
   * signature fields).
   */
  ZATHURA_PERMISSION_ANNOTATIONS = 1 << 6,

  /**
   * Fill in existing interactive form fields (including signature fields), even
   * if bit 6 is clear.
   */
  ZATHURA_PERMISSION_FILL_FORM = 1 << 9,

  /**
   * Extract text and graphics (in support of accessibility to users with
   * disabilities or for other purposes).
   */
  ZATHURA_PERMISSION_ACCESSIBILITY = 1 << 10,

  /**
   * Assemble the document (insert, rotate, or delete pages and create bookmarks
   * or thumbnail images), even if bit 4 is clear.
   */
  ZATHURA_PERMISSION_ASSEMBLE = 1 << 11,

  /**
   * Print the document to a representation from which a faithful digital copy
   * of the PDF content could be generated. When this bit is clear (and bit 3 is
   * set), printing is limited to a low-level representation of the appearance,
   * possibly of degraded quality.
    */
  ZATHURA_PERMISSION_HIGH_RES_PRINT = 1 << 12,
} zathura_document_permission_t;

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
    zathura_node_t** outline);

/**
 * Returns the list of the attached files of this document
 *
 * @param[in] document The zathura document object
 * @param[out] attachments List of files attached to this document
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
 * @param[out] metadata List of meta data information
 * *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_document_get_metadata(zathura_document_t* document,
    zathura_list_t** metadata);

/**
 * Returns the permissions of the document
 *
 * @param[in] document The zathura document object
 * @param[out] permissions The permissions of the document
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_document_get_permissions(zathura_document_t* document,
    zathura_document_permission_t* permissions);

#ifdef __cplusplus
}
#endif

#endif /* DOCUMENT_H */

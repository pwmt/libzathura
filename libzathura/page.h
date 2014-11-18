/* See LICENSE file for license and copyright information */

#ifndef PAGE_H
#define PAGE_H

typedef struct zathura_page_s zathura_page_t;

#if HAVE_CAIRO
#include <cairo.h>
#endif

#include "error.h"
#include "document.h"
#include "types.h"
#include "image-buffer.h"
#include "transition.h"

/**
 * Returns the index of the page.
 *
 * @param[in] page The used page object
 * @param[out] index The index of the page
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_page_get_index(zathura_page_t* page, unsigned int* index);

/**
 * Returns the document of the page.
 *
 * @param[in] page The used page object
 * @param[out] document The document of the page
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_page_get_document(zathura_page_t* page, zathura_document_t** document);

/**
 * Returns the width of the page.
 *
 * @param[in] page The used page object
 * @param[out] width The width of the page
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_page_get_width(zathura_page_t* page, unsigned int* width);

/**
 * Returns the height of the page.
 *
 * @param[in] page The used page object
 * @param[out] height The height of the page
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_page_get_height(zathura_page_t* page, unsigned int* height);

/**
 * Returns the label of the page.
 *
 * @param[in] page The used page object
 * @param[out] label The label of the page
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_page_get_label(zathura_page_t* page, const char** label);

/**
 * Returns the transition information object of the page.
 *
 * @param[in] page The used page object
 * @param[out] transition The transition information of the page
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_page_get_transition(zathura_page_t* page, zathura_page_transition_t** transition);

/**
 * Returns the duration of the page.
 *
 * The page’s display duration (also called its advance timing): the maximum
 * length of time, in seconds, that the page is displayed during presentations
 * before the viewer application automatically advances to the next page By
 * default, the viewer does not advance automatically.
 *
 * @param[in] page The used page object
 * @param[out] duration The duration of the page
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_page_get_duration(zathura_page_t* page, unsigned int* duration);

/**
 * Returns a list of matching search results of the page.
 *
 * @param[in] page The used page object
 * @param[in] text The search item
 * @param[out] results The search results
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_page_search_text(zathura_page_t* page, const char* text,
    zathura_search_flag_t flags, zathura_list_t** results);

/**
 * Returns the text of the @a page.
 *
 * @param[in] page The used page object
 * @param[out] text The text of the page that lies within the given rectangle
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_page_get_text(zathura_page_t* page, char** text);

/**
 * Returns the text of the @a page that lies within the given @a rectangle.
 *
 * @param[in] page The used page object
 * @param[out] text The text of the page that lies within the given rectangle
 * @param[in] rectangle The rectangle on the page
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_page_get_selected_text(zathura_page_t* page, char** text,
    zathura_rectangle_t rectangle);

/**
 * Returns a list of the links of the page.
 *
 * @param[in] page The used page object
 * @param[out] links List of links of the page
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_page_get_links(zathura_page_t* page, zathura_list_t** links);

/**
 * Returns a list of form fields of the page.
 *
 * @param[in] page The used page object
 * @param[out] form_fields List of form fields of the page
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_page_get_form_fields(zathura_page_t* page, zathura_list_t** form_fields);

/**
 * Returns a list of the images of the page.
 *
 * @param[in] page The used page object
 * @param[out] images List of images of the page
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_page_get_images(zathura_page_t* page, zathura_list_t** images);

/**
 * Returns a list of annotations of the page.
 *
 * @param[in] page The used page object
 * @param[out] annotations List of annotations of the page
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_page_get_annotations(zathura_page_t* page, zathura_list_t** annotations);

/**
 * Returns the crop box of the page
 *
 * A rectangle, expressed in default user space units, defining the visible
 * region of default user space. When the page is displayed or printed, its
 * contents are to be clipped (cropped) to this rectangle and then imposed on
 * the output medium in some implementation- defined manner
 *
 * @param[in] page The used page object
 * @param[out] crop_box The crop box of the page
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_page_get_crop_box(zathura_page_t* page, zathura_rectangle_t* crop_box);

/**
 * Renders the page to a @a ::zathura_image_buffer_t image buffer
 *
 * @param[in] page The used page object
 * @param[out] buffer The image buffer
 * @param[in] scale Scale level
 * @param[in] rotation Rotation angle
 * @param[in] flags Additional flags for rendering FIXME
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_page_render(zathura_page_t* page,
    zathura_image_buffer_t** buffer, double scale, int rotation, int flags);

#ifdef HAVE_CAIRO
/**
 * Renders the page to a cairo object
 *
 * @param[in] page The used page object
 * @param[out] cairo The cairo object
 * @param[in] scale Scale level
 * @param[in] rotation Rotation angle
 * @param[in] flags Additional flags for rendering FIXME
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_page_render_cairo(zathura_page_t* page, cairo_t* cairo,
    double scale, int rotation, int flags);
#endif

#endif /* PAGE_H */

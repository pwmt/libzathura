/* See LICENSE file for license and copyright information */

#ifndef LIBZATHURA_PLUGIN_API_PAGE_H
#define LIBZATHURA_PLUGIN_API_PAGE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../error.h"
#include "../page.h"

/**
 * Sets the custom user data of the page object
 *
 * @param[in] page The page object
 * @param[in] user_data The custom user data
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_page_set_user_data(zathura_page_t* page, void* user_data);

/**
 * Returns the custom user data of the page object
 *
 * @param[in] page The page object
 * @param[out] user_data The custom user data
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_page_get_user_data(zathura_page_t* page, void** user_data);

/**
 * Sets the index of the page
 *
 * @param[in] page The page object
 * @param[in] index The index
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_page_set_index(zathura_page_t* page, unsigned int index);

/**
 * Sets the width of the page
 *
 * @param[in] page The page object
 * @param[in] width The width of the page
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_page_set_width(zathura_page_t* page, unsigned int width);

/**
 * Sets the height of the page
 *
 * @param[in] page The page object
 * @param[in] height THe height of the page
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_page_set_height(zathura_page_t* page, unsigned int height);

/**
 * Sets the label of the page
 *
 * @param[in] page The page object
 * @param[in] label The label
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_page_set_label(zathura_page_t* page, const char* label);

/**
 * Sets the transition object of the page
 *
 * @param[in] page The page object
 * @param[in] transition The transition object
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_page_set_transition(zathura_page_t* page, zathura_page_transition_t* transition);

zathura_error_t zathura_page_set_duration(zathura_page_t* page, unsigned int duration);
zathura_error_t zathura_page_set_crop_box(zathura_page_t* page, zathura_rectangle_t crop_box);
#ifdef __cplusplus
}
#endif

#endif /* PLUGIN_API_PAGE_H */

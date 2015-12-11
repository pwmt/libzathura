/* See LICENSE file for license and copyright information */

#ifndef LIBZATHURA_PLUGIN_API_ANNOTATIONS_H
#define LIBZATHURA_PLUGIN_API_ANNOTATIONS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../error.h"
#include "../annotations.h"

/**
 * Sets the custom data of an annotation object
 *
 * @param[in] annotation The annotation object
 * @param[in] data The custom data
 * @param[in] free_function Free function for the custom data
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_set_user_data(zathura_annotation_t*
    annotation, void* data, zathura_free_function_t free_function);

/**
 * Returns the custom data of an annotation object
 *
 * @param[in] annotation The annotation object
 * @param[out] data The custom data
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_get_user_data(zathura_annotation_t* annotation, void** data);

#ifdef __cplusplus
}
#endif

#endif /* PLUGIN_API_ANNOTATIONS_H */

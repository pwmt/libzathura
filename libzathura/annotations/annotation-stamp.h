/* See LICENSE file for license and copyright information */

#ifndef ANNOTATION_STAMP_H
#define ANNOTATION_STAMP_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../annotations.h"
#include "../error.h"

/**
 * Returns the icon name of this stamp annotation
 *
 * @param[in] annotation The annotation
 * @param[in] icon_name The attachment
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_stamp_set_icon_name(zathura_annotation_t*
    annotation, char* icon_name);

/**
 * Returns the icon name of this stamp annotation
 *
 * @param[in] annotation The annotation
 * @param[out] icon_name The attachment
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_stamp_get_icon_name(zathura_annotation_t*
    annotation, char** icon_name);

#ifdef __cplusplus
}
#endif

#endif //ANNOTATION_STAMP_H

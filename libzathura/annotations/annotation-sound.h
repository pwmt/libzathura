/* See LICENSE file for license and copyright information */

#ifndef ANNOTATION_SOUND_H
#define ANNOTATION_SOUND_H

#include "../annotations.h"
#include "../sound.h"

/**
 * Sets the actual sound of this sound annotation
 *
 * @param[in] annotation The annotation
 * @param[in] sound The sound object
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_sound_set_sound(zathura_annotation_t*
    annotation, zathura_sound_t* sound);

/**
 * Returns the actual sound of this sound annotation
 *
 * @param[in] annotation The annotation
 * @param[out] sound The sound object
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_sound_get_sound(zathura_annotation_t*
    annotation, zathura_sound_t** sound);

/**
 * Returns the icon name of this sound annotation
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
zathura_error_t zathura_annotation_sound_set_icon_name(zathura_annotation_t*
    annotation, char* icon_name);

/**
 * Returns the icon name of this sound annotation
 *
 * @param[in] annotation The annotation
 * @param[out] icon_name The attachment
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_sound_get_icon_name(zathura_annotation_t*
    annotation, char** icon_name);

#endif //ANNOTATION_SOUND_H

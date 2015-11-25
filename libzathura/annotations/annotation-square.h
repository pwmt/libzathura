/* See LICENSE file for license and copyright information */

#ifndef LIBZATHURA_ANNOTATION_SQUARE_H
#define LIBZATHURA_ANNOTATION_SQUARE_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Sets the rectangle of the square annotation
 *
 * @param[in] annotation The annotation
 * @param[in] rectangle The rectangle
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_square_set_rectangle(zathura_annotation_t*
    annotation, zathura_rectangle_t rectangle);

/**
 * Returns the rectangle of the square annotation
 *
 * @param[in] annotation The annotation
 * @param[out] rectangle The rectangle
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_square_get_rectangle(zathura_annotation_t*
    annotation, zathura_rectangle_t* rectangle);

/**
 * Sets the color of the square annotation
 *
 * @param[in] annotation The annotation
 * @param[in] color The color
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_square_set_color(zathura_annotation_t*
    annotation, zathura_annotation_color_t color);

/**
 * Returns the color of the square annotation
 *
 * @param[in] annotation The annotation
 * @param[out] color The color
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_square_get_color(zathura_annotation_t*
    annotation, zathura_annotation_color_t* color);

/**
 * Sets the border of the square annotation
 *
 * @param[in] annotation The annotation
 * @param[in] border The border
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */

zathura_error_t zathura_annotation_square_set_border(zathura_annotation_t*
    annotation, zathura_annotation_border_t border);
/**
 * Returns the border of the square annotation
 *
 * @param[in] annotation The annotation
 * @param[out] border The border
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_square_get_border(zathura_annotation_t*
    annotation, zathura_annotation_border_t* border);

#ifdef __cplusplus
}
#endif

#endif // ANNOTATION_SQUARE_H

/* See LICENSE file for license and copyright information */

#ifndef ANNOTATION_SQUARE_H
#define ANNOTATION_SQUARE_H

/**
 * Returns the rectangle of the square annotation
 *
 * @param[in] annotation The annotation
 * @param[out] symbol The symbol
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_square_get_rectangle(zathura_annotation_t*
    annotation, zathura_rectangle_t* rectangle);

/**
 * Returns the color of the square annotation
 *
 * @param[in] annotation The annotation
 * @param[out] symbol The symbol
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_square_get_color(zathura_annotation_t*
    annotation, zathura_annotation_color_t* color);

/**
 * Returns the border of the square annotation
 *
 * @param[in] annotation The annotation
 * @param[out] symbol The symbol
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_square_get_border(zathura_annotation_t*
    annotation, zathura_annotation_border_t* border);

#endif // ANNOTATION_SQUARE_H

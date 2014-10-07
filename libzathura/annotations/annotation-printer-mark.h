/* See LICENSE file for license and copyright information */

#ifndef ANNOTATION_PRINTER_MARK_H
#define ANNOTATION_PRINTER_MARK_H

#include "../annotations.h"
#include "../error.h"

/**
 * Sets an arbitrary name identifying the type of printer’s mark, such as
 * ColorBar or RegistrationTarget.
 *
 * @param[in] annotation The annotation
 * @param[in] name The name
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_printer_mark_set_name(zathura_annotation_t*
    annotation, const char* name);

/**
 * Returns an arbitrary name identifying the type of printer’s mark, such as
 * ColorBar or RegistrationTarget.
 *
 * @param[in] annotation The annotation
 * @param[out] name The name
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_printer_mark_get_name(zathura_annotation_t*
    annotation, char** name);

/**
 * Sets a text string representing the printer’s mark in human-readable form and
 * suitable for presentation to the user on the screen.
 *
 * @param[in] annotation The annotation
 * @param[in] mark_style The mark style
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_printer_mark_set_mark_style(zathura_annotation_t*
    annotation, const char* mark_style);

/**
 * Returns a text string representing the printer’s mark in human-readable form
 * and suitable for presentation to the user on the screen.
 *
 * @param[in] annotation The annotation
 * @param[out] mark_style The mark style
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_printer_mark_get_mark_style(zathura_annotation_t*
    annotation, char** mark_style);

/**
 * Sets a list identifying the individual colorants associated with a
 * printer’s mark, such as a color bar. For each entry in this dictionary, the
 * key is a colorant name and the value is an array defining a Separation color
 * space for that colorant.
 *
 * @param[in] annotation The annotation
 * @param[in] colorants The list of points
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_printer_mark_set_colorants(zathura_annotation_t* annotation, zathura_list_t* colorants);

/**
 * Returns a list identifying the individual colorants associated with a
 * printer’s mark, such as a color bar. For each entry in this dictionary, the
 * key is a colorant name and the value is an array defining a Separation color
 * space for that colorant.
 *
 * @param[in] annotation The annotation
 * @param[out] colorants The list of quad points
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_printer_mark_get_colorants(zathura_annotation_t* annotation, zathura_list_t** colorants);

#endif // ANNOTATION_PRINTER_MARK_H

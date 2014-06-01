/* See LICENSE file for license and copyright information */

#ifndef ANNOTATION_CARET_H
#define ANNOTATION_CARET_H

#include "../annotations.h"
#include "types.h"

/**
 * Specifying a symbol to be associated with the caret.
 */
typedef enum zathura_annotation_caret_symbol_e {
  /**
   * No symbol should be associated with the caret.
   */
  ZATHURA_ANNOTATION_CARET_SYMBOL_NONE,

  /**
   * A new paragraph symbol (¶) should be associated with the caret.
   */
  ZATHURA_ANNOTATION_CARET_SYMBOL_PARAGRAPH,
} zathura_annotation_caret_symbol_t;

/**
 * Sets the symbol of this caret annotation
 *
 * @param[in] annotation The annotation
 * @param[in] symbol The symbol
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_caret_set_symbol(zathura_annotation_t*
    annotation, zathura_annotation_caret_symbol_t symbol);

/**
 * Returns the symbol of this caret annotation
 *
 * @param[in] annotation The annotation
 * @param[out] symbol The symbol
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_caret_get_symbol(zathura_annotation_t*
    annotation, zathura_annotation_caret_symbol_t* symbol);

/**
 * Sets the padding of this caret annotation
 *
 * @param[in] annotation The annotation
 * @param[out] padding The padding
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_caret_set_padding(zathura_annotation_t*
    annotation, zathura_annotation_padding_t padding);

/**
 * Returns the padding of this caret annotation
 *
 * @param[in] annotation The annotation
 * @param[out] padding The padding
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_caret_get_padding(zathura_annotation_t*
    annotation, zathura_annotation_padding_t* padding);

#endif // ANNOTATION_CARET_H

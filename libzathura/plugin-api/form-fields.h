/* See LICENSE file for license and copyright information */

#ifndef PLUGIN_API_FORM_FIELDS_H
#define PLUGIN_API_FORM_FIELDS_H

#include "../error.h"
#include "../form-fields.h"

/**
 * Creates a new form field of the given type.
 *
 * @param[out] form_field The form field
 * @param[in] type The type
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_new(zathura_form_field_t** form_field,
    zathura_form_field_type_t type);

/**
 * Frees the given form field..
 *
 * @param[in] form_field The form field
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_free(zathura_form_field_t* form_field);

/**
 * Sets the name of the form field
 *
 * @param[in] form_field
 * @param[in] name The name
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_set_name(zathura_form_field_t* form_field,
    const char* name);

/**
 * Sets the partial name of the form field
 *
 * @param[in] form_field
 * @param[in] partial_name The partial name
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_set_partial_name(zathura_form_field_t*
    form_field, const char* partial_name);

/**
 * Sets the mapping name of the form field
 *
 * @param[in] form_field
 * @param[in] mapping_name The mapping name
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_set_mapping_name(zathura_form_field_t*
    form_field, const char* mapping_name);

/**
 * Sets the flags of the form field
 *
 * @param[in] form_field
 * @param[in] flags The flags
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_set_flags(zathura_form_field_t* form_field,
    zathura_form_field_flag_t flags);

#include "form-fields/form-field-button.h"
#include "form-fields/form-field-choice.h"
#include "form-fields/form-field-choice-item.h"
#include "form-fields/form-field-signature.h"
#include "form-fields/form-field-text.h"

#endif /* PLUGIN_API_FORM_FIELDS_H */

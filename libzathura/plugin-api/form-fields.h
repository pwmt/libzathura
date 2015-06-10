/* See LICENSE file for license and copyright information */

#ifndef PLUGIN_API_FORM_FIELDS_H
#define PLUGIN_API_FORM_FIELDS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../error.h"
#include "../form-fields.h"

/**
 * Creates a new form field of the given type.
 *
 * @param[in] page The page that is associated with this form field
 * @param[out] form_field The form field
 * @param[in] type The type
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_new(zathura_page_t* page, zathura_form_field_t** form_field,
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

/**
 * Sets the custom data of an form field object
 *
 * @param[in] form_field The form field object
 * @param[in] data The custom data
 * @param[in] free_function Free function for the custom data
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_set_user_data(zathura_form_field_t*
    form_field, void* data, zathura_free_function_t free_function);

/**
 * Returns the custom data of an form field object
 *
 * @param[in] form_field The form field object
 * @param[out] data The custom data
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_get_user_data(zathura_form_field_t* form_field, void** data);

#include "form-fields/form-field-button.h"
#include "form-fields/form-field-choice.h"
#include "form-fields/form-field-choice-item.h"
#include "form-fields/form-field-signature.h"
#include "form-fields/form-field-text.h"

#ifdef __cplusplus
}
#endif

#endif /* PLUGIN_API_FORM_FIELDS_H */

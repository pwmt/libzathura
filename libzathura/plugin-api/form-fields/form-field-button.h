/* See LICENSE file for license and copyright information */

#ifndef PLUGIN_API_FORM_FIELD_BUTTON_H
#define PLUGIN_API_FORM_FIELD_BUTTON_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Sets the button type of the button form field.
 *
 * @param[in] form_field The form field
 * @param[in] type The button type of the form field
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_button_set_type( zathura_form_field_t*
    form_field, zathura_form_field_button_type_t type);

#ifdef __cplusplus
}
#endif

#endif /* PLUGIN_API_FORM_FIELD_BUTTON_H */

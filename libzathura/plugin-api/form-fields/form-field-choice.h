/* See LICENSE file for license and copyright information */

#ifndef PLUGIN_API_FORM_FIELD_CHOICE_H
#define PLUGIN_API_FORM_FIELD_CHOICE_H

/**
 * Sets the choice type of the choice form field.
 *
 * @param[in] form_field The form field
 * @param[in] type The choice type of the form field
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_choice_set_type(zathura_form_field_t*
    form_field, zathura_form_field_choice_type_t type);

/**
 * Sets if the choice form field is editable or not.
 *
 * @param[in] form_field The form field
 * @param[out] value If the choice form field is editable
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_choice_set_editable(zathura_form_field_t*
    form_field, bool value);

/**
 * Sets if the choices should be sorted alphabetically and is indented for
 * use by form authoring tools, not by viewer applications.
 *
 * @param[in] form_field The form field
 * @param[in] value If the choice form field is sorted or not
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_choice_set_sorted(zathura_form_field_t*
    form_field, bool value);

/**
 * Sets if more than one of the field's options items may be selected
 * simultaneously. If false, no more than one item at a time may be selected.
 *
 * @param[in] form_field The form field
 * @param[in] value If the choice form field is a multi-select choice
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_choice_set_multiselect(zathura_form_field_t*
    form_field, bool value);

/**
 * Sets if spell-checking should be performed on the entered value or not.
 * This flag is meaningful only if the field choice type is @a
 * ZATHURA_FORM_FIELD_CHOICE_TYPE_COMBO and editable is set to true.
 *
 * @param[in] form_field The form field
 * @param[out] value If spell-checking should be performed on the text field
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_choice_set_spell_check(zathura_form_field_t*
    form_field, bool value);

#endif /* PLUGIN_API_FORM_FIELD_CHOICE_H */

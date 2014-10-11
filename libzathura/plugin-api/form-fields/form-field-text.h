/* See LICENSE file for license and copyright information */

#ifndef PLUGIN_API_FORM_FIELD_TEXT_H
#define PLUGIN_API_FORM_FIELD_TEXT_H

/**
 * Sets the text type of the text form field.
 *
 * @param[in] form_field The form field
 * @param[in] type The text type of the form field
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_text_set_type(zathura_form_field_t*
    form_field, zathura_form_field_text_type_t type);

/**
 * Sets the maximal length of the text field. If length is unlimited, the
 * value stored in length is 0.
 *
 * @param[in] form_field The form field
 * @param[in] length The maximal length of the entry
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_text_set_max_length(zathura_form_field_t*
    form_field, unsigned int length);

/**
 * Sets if the text field is a password or not.
 *
 * @param[in] form_field The form field
 * @param[in] value If the text field is a password
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_text_set_password(zathura_form_field_t*
    form_field, bool value);

/**
 * Sets if the text field is a rich text string or not.
 *
 * @param[in] form_field The form field
 * @param[in] value If the text field is a rich text string
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_text_set_rich_text(zathura_form_field_t*
    form_field, bool value);

/**
 * Sets if the text field does scroll (horizontally for single-line fields,
 * vertically for multiple-line fields).
 *
 * @param[in] form_field The form field
 * @param[in] value If the text field scrolls or not
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_text_set_scroll(zathura_form_field_t*
    form_field, bool value);

/**
 * Sets if spell-checking should be performed on the entered text or not.
 *
 * @param[in] form_field The form field
 * @param[in] value If spell-checking should be performed on the text field
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_text_set_spell_check(zathura_form_field_t*
    form_field, bool value);

#endif /* PLUGIN_API_FORM_FIELD_TEXT_H */

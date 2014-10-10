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

/**
 * Sets the list of options of the choice form field.
 *
 * @param[in] form_field The form field
 * @param[in] items the list of options
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_choice_set_items(zathura_form_field_t*
    form_field, zathura_list_t* items);

/**
 * Creates a new form field choice item
 *
 * @param[in] item The new form field choice item
 * @param[in] name The name of the choice item
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t
zathura_form_field_choice_item_new(zathura_form_field_choice_item_t** item,
    const char* name);

/**
 * Frees the form field choice item
 *
 * @param[in] item The form field choice item
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t
zathura_form_field_choice_item_free(zathura_form_field_choice_item_t* item);

/**
 * Sets the name of the choice item
 *
 * @param[in] item The new form field choice item
 * @param[in] name The name of the choice item
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t
zathura_form_field_choice_item_set_name(zathura_form_field_choice_item_t* item,
    const char* name);

#endif /* PLUGIN_API_FORM_FIELDS_H */

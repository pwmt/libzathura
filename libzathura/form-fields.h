/* See LICENSE file for license and copyright information */

#ifndef FORM_FIELDS_H
#define FORM_FIELDS_H

/**
 * Interactive forms support the following field types:
 */
typedef enum zathura_form_field_type_e {
  /**
   * Represents interactive controls on the screen that the user can manipulate
   * with the mouse. They include pushbuttons, check boxes and radio buttons.
   */
  ZATHURA_FORM_FIELD_BUTTON,

  /**
   * Are boxes or spaces in which the user can enter text from the key-board
   */
  ZATHURA_FORM_FIELD_TEXT,

  /**
   * Contain several text items, at most one of which maybe selected as the
   * field value. They include scrollable list boxes and combo boxes.
   */
  ZATHURA_FORM_FIELD_CHOICE,

  /**
   * Represents electronic signatures for authenticating the identity of a user
   * and the validity of the document's contents.
   */
  ZATHURA_FORM_FIELD_SIGNATURE,
} zathura_form_field_type_t;

/**
 * A button field represents an interactive control on the screen that the user
 * can manipulate with the mouse. There are three types of button fields:
 */
typedef enum zathura_form_field_button_type_e {
  /**
   * A pushbutton is a purely interactive control that responds immediately to
   * user input without retaining a permanent value.
   * */
  ZATHURA_FORM_FIELD_BUTTON_TYPE_PUSH,

  /**
   * A check box toggles between two states, on and off
   */
  ZATHURA_FORM_FIELD_BUTTON_TYPE_CHECK,

  /**
   * Radio button fields contain a set of related buttons that can each be on or
   * off. Typically, at most one radio button in a set may be on at any given
   * time, and selecting any one of the buttons automatically deselects all the
   * others.
   */
  ZATHURA_FORM_FIELD_BUTTON_TYPE_RADIO
} zathura_form_field_button_type_t;

typedef enum zathura_form_field_text_type_e {
  /**
   * The field is restricted to a single line of text.
   */
  ZATHURA_FORM_FIELD_TEXT_TYPE_NORMAL,

  /**
   * The field can contain multiple lines of text.
   */
  ZATHURA_FORM_FIELD_TEXT_TYPE_MULTILINE,

  /**
   * Text entered in the field represents the pathname of a file whose contents
   * are to be submitted as the value of the field.
   */
  ZATHURA_FORM_FIELD_TEXT_TYPE_FILE_SELECT,
} zathura_form_field_text_type_t;

/**
 * A choice field (field type Ch ) contains several text items, one or more of
 * which
 * may be selected as the field value. The items may be presented to the user in
 * either of two forms:
 * choice
 */
typedef enum zathura_form_field_choice_type_e {
  /**
   * A scrollable list box
   */
  ZATHURA_FORM_FIELD_CHOICE_TYPE_LIST,

  /**
   * A combo box consisting of a drop-down list optionally accompanied by an
   * edit-able text box in which the user can type a value other than the
   * predefined.
   */
  ZATHURA_FORM_FIELD_CHOICE_TYPE_COMBO
} zathura_form_field_choice_t;

/**
 * Returns the button type of the button form field.
 *
 * @param[in] form_field The form field
 * @param[out] type The button type of the form field
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_button_get_type( zathura_form_field_t*
    form_field, zathura_form_field_button_type_t* type);

/**
 * Returns the state of the button form field.
 *
 * @param[in] form_field The form field
 * @param[out] value The state of the form field
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_button_get_state( zathura_form_field_t*
    form_field, bool* value);

/**
 * Sets the state of the button form field.
 *
 * @param[in] form_field The form field
 * @param[in] value The state of the form field
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_button_set_state(zathura_form_field_t*
    form_field, bool value);

/**
 * Returns the text type of the text form field.
 *
 * @param[in] form_field The form field
 * @param[out] type The text type of the form field
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_text_get_type(zathura_form_field_t*
    form_field, zathura_form_field_text_type_t* type);

/**
 * Returns the text of the text form field.
 *
 * @param[in] form_field The form field
 * @param[out] text The text of the field
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_text_get_text(zathura_form_field_t*
    form_field, char** text);

/**
 * Sets the text of the text form field.
 *
 * @param[in] form_field The form field
 * @param[in] text The text of the field
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_text_set_text(zathura_form_field_t*
    form_field, const char* text);

/**
 * Returns the maximal length of the text field. If length is unlimited, the
 * value stored in length is 0.
 *
 * @param[in] form_field The form field
 * @param[out] length The maximal length of the entry
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_text_get_max_length(zathura_form_field_t*
    form_field, unsigned int* length);

/**
 * Returns if the text field is a password or not.
 *
 * @param[in] form_field The form field
 * @param[out] value If the text field is a password
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_text_is_password(zathura_form_field_t*
    form_field, bool* value);

/**
 * Returns if the text field is a rich text string or not.
 *
 * @param[in] form_field The form field
 * @param[out] value If the text field is a rich text string
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_text_is_rich_text(zathura_form_field_t*

/**
 * Returns if the text field does scroll (horizontally for single-line fields,
 * vertically for multiple-line fields).
 *
 * @param[in] form_field The form field
 * @param[out] value If the text field scrolls or not
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_text_do_scroll(zathura_form_field_t*
    form_field, bool* value);

/**
 * Returns if spell-checking should be performed on the entered text or not.
 *
 * @param[in] form_field The form field
 * @param[out] value If spell-checking should be performed on the text field
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_text_do_spell_check(zathura_form_field_t*
    form_field, bool* value);

/**
 * Returns the choice type of the choice form field.
 *
 * @param[in] form_field The form field
 * @param[out] type The choice type of the form field
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_choice_get_type(zathura_form_field_t*
    form_field, zathura_form_field_choice_type_t* type);

/**
 * Returns if the choice form field is editable or not.
 *
 * @param[in] form_field The form field
 * @param[out] value If the choice form field is editable
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_choice_is_editable(zathura_form_field_t*
    form_field, bool* value);

/**
 * Returns if the choices should be sorted alphabetically and is indented for
 * use by form authoring tools, not by viewer applications.
 *
 * @param[in] form_field The form field
 * @param[out] value If the choice form field is sorted or not
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_choice_is_sorted(zathura_form_field_t*
    form_field, bool* value);

/**
 * Returns if more than one of the field's options items may be selected
 * simultaneously. If false, no more than one item at a time may be selected.
 *
 * @param[in] form_field The form field
 * @param[out] value If the choice form field is a multi-select choice
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_choice_is_multiselect(zathura_form_field_t*
    form_field, bool* value);

/**
 * Returns if spell-checking should be performed on the entered value or not.
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
zathura_error_t zathura_form_field_choice_do_spell_check(zathura_form_field_t*
    form_field, bool* value);

/**
 * Returns the list of options of the choice form field.
 *
 * @param[in] form_field The form field
 * @param[out] items Returns the list of options
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_choice_get_items(zathura_form_field_t*
    form_field, zathura_list_t** items);

/**
 * Selects the option at the given index of the form field
 *
 * @param[in] form_field The form field
 * @param[in] index The index of the option
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_choice_select_item(zathura_form_field_t*
    form_field, unsigned int index);

/**
 * Deselects the option at the given index of the form field
 *
 * @param[in] form_field The form field
 * @param[in] index The index of the option
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_choice_deselect_item(zathura_form_field_t*
    form_field, unsigned int index);

/**
 * Returns if the option at the given index of the form field is selected or
 * not.
 *
 * @param[in] form_field The form field
 * @param[in] index The index of the option
 * @param[out] selected If the index is selected
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_choice_item_is_selected(zathura_form_field_t*
    form_field, unsigned int index, bool* selected);

#endif /* FORM_FIELDS_H */

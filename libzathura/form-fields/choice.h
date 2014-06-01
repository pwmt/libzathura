/* See LICENSE file for license and copyright information */

#ifndef FORM_FIELD_CHOICE_H
#define FORM_FIELD_CHOICE_H

#include <stdbool.h>

#include "../form-fields.h"
#include "../list.h"

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
} zathura_form_field_choice_type_t;

/**
 * An item of the choice form field
 */
typedef struct zathura_form_field_choice_item_s zathura_form_field_choice_item_t;

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
 * @param[out] is_editable If the choice form field is editable
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_choice_is_editable(zathura_form_field_t*
    form_field, bool* is_editable);

/**
 * Returns if the choices should be sorted alphabetically and is indented for
 * use by form authoring tools, not by viewer applications.
 *
 * @param[in] form_field The form field
 * @param[out] is_sorted If the choice form field is sorted or not
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_choice_is_sorted(zathura_form_field_t*
    form_field, bool* is_sorted);

/**
 * Returns if more than one of the field's options items may be selected
 * simultaneously. If false, no more than one item at a time may be selected.
 *
 * @param[in] form_field The form field
 * @param[out] is_multiselect If the choice form field is a multi-select choice
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_choice_is_multiselect(zathura_form_field_t*
    form_field, bool* is_multiselect);

/**
 * Returns if spell-checking should be performed on the entered value or not.
 * This flag is meaningful only if the field choice type is @a
 * ZATHURA_FORM_FIELD_CHOICE_TYPE_COMBO and editable is set to true.
 *
 * @param[in] form_field The form field
 * @param[out] do_spell_check If spell-checking should be performed on the text field
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_choice_do_spell_check(zathura_form_field_t*
    form_field, bool* do_spell_check);

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
 * Selects the option
 *
 * @param[in] choice_item The choice item
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_choice_item_deselect(zathura_form_field_choice_item_t*
  choice_item);

/**
 * Deselects the option
 *
 * @param[in] choice_item The choice item
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_choice_item_select(zathura_form_field_choice_item_t*
    choice_item);

/**
 * Returns if the option at the given index of the form field is selected or
 * not.
 *
 * @param[in] choice_item The choice item
 * @param[out] is_selected If the index is selected
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_choice_item_is_selected(zathura_form_field_choice_item_t*
    choice_item, bool* is_selected);

#endif /* FORM_FIELD_CHOICE_H */

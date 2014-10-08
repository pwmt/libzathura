/* See LICENSE file for license and copyright information */

#ifndef FORM_FIELD_BUTTON_H
#define FORM_FIELD_BUTTON_H

#include <stdbool.h>

#include "../form-fields.h"

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

/*
 * Returns the button type of the button form field.
 *
 * @param[in] form_field The form field
 * @param[out] type The button type of the form field
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_button_get_type(zathura_form_field_t*
    form_field, zathura_form_field_button_type_t* type);

/**
 * Returns the state of the button form field.
 *
 * @param[in] form_field The form field
 * @param[out] state The state of the form field
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_button_get_state(zathura_form_field_t*
    form_field, bool* state);

/**
 * Sets the state of the button form field.
 *
 * @param[in] form_field The form field
 * @param[in] state The state of the form field
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_button_set_state(zathura_form_field_t*
    form_field, bool state);

#endif /* FORM_FIELD_BUTTON_H */

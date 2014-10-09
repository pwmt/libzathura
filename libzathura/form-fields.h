/* See LICENSE file for license and copyright information */

#ifndef FORM_FIELDS_H
#define FORM_FIELDS_H

#include <stdbool.h>

#include "error.h"

/**
 * An interactive form is a collection of fields for gathering information
 * interactively from the user. A document may contain any number of fields
 * appearing on any combination of pages, all of which make up a single, global
 * interactive form spanning the entire document.
 */
typedef struct zathura_form_field_s zathura_form_field_t;

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
 * Returns the type of the form field
 *
 * @param[in] form_field
 * @param[out] type The type of the form field
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_get_type(zathura_form_field_t* form_field,
    zathura_form_field_type_t* type);

#include "form-fields/form-field-button.h"
#include "form-fields/form-field-text.h"
#include "form-fields/form-field-choice.h"
#include "form-fields/form-field-signature.h"

#endif /* FORM_FIELDS_H */

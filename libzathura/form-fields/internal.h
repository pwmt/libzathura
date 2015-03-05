/* See LICENSE file for license and copyright information */

#ifndef INTERNAL_FORM_FIELDS_H
#define INTERNAL_FORM_FIELDS_H

#include "../form-fields.h"
#include "../page.h"

#include "internal/form-field-button.h"
#include "internal/form-field-text.h"
#include "internal/form-field-choice.h"
#include "internal/form-field-signature.h"

#define CHECK_FORM_FIELD_TYPE(form_field, type) \
  zathura_form_field_type_t form_field_type; \
  if (zathura_form_field_get_type((form_field), &form_field_type) != ZATHURA_ERROR_OK) { \
    return ZATHURA_ERROR_INVALID_ARGUMENTS; \
  } \
  if (form_field_type != (type)) { \
    return ZATHURA_ERROR_INVALID_ARGUMENTS; \
  } \

/**
 * Describes the form field
 */
struct zathura_form_field_s {
  /**
   * The type of the form field
   */
  zathura_form_field_type_t type;

  /**
   * An alternate field name to be used in place of the actual field name
   * wherever the field must be identified in the user interface (such as in
   * error or status messages referring to the field). This text is also useful
   * when extracting the document’s contents in support of accessibility to
   * users with disabilities or for other purposes.
   */
  char* name;

  /**
   * The partial field name.
   */
  char* partial_name;

  /**
   * The mapping name to be used when exporting interactive form field data from
   * the document.
   */
  char* mapping_name;

  /**
   * A set of flags specifying various characteristics of the field.
   */
  zathura_form_field_flag_t flags;

  /**
   * Fields to store specific data
   */
  union {
    struct zathura_form_field_button_s button;
    struct zathura_form_field_text_s text;
    struct zathura_form_field_choice_s choice;
    struct zathura_form_field_signature_s signature;
  } data;

  /**
   * The page that is associated with this form field
   */
  zathura_page_t* page;

  /**
   * User data
   */
  void* user_data;
};

#endif /* INTERNAL_FORM_FIELDS_H */

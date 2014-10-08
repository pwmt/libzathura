/* See LICENSE file for license and copyright information */

#ifndef INTERNAL_FORM_FIELDS_H
#define INTERNAL_FORM_FIELDS_H

#include "../form-fields.h"

#include "internal/form-field-button.h"
#include "internal/form-field-text.h"
#include "internal/form-field-choice.h"

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

  union {
    struct zathura_form_field_button_s button;
    struct zathura_form_field_text_s text;
    struct zathura_form_field_choice_s choice;
  } data;
};

#endif /* INTERNAL_FORM_FIELDS_H */

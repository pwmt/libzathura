/* See LICENSE file for license and copyright information */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "form-field-button.h"
#include "../plugin-api/form-fields/form-field-button.h"
#include "internal.h"

zathura_error_t
zathura_form_field_button_set_type(zathura_form_field_t* form_field,
    zathura_form_field_button_type_t type)
{
  if (form_field == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_FORM_FIELD_TYPE(form_field, ZATHURA_FORM_FIELD_BUTTON)

  switch (type) {
    case ZATHURA_FORM_FIELD_BUTTON_TYPE_PUSH:
    case ZATHURA_FORM_FIELD_BUTTON_TYPE_CHECK:
    case ZATHURA_FORM_FIELD_BUTTON_TYPE_RADIO:
      break;
    default:
      return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  form_field->data.button.type = type;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_button_get_type(zathura_form_field_t* form_field,
    zathura_form_field_button_type_t * type)
{
  if (form_field == NULL || type == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_FORM_FIELD_TYPE(form_field, ZATHURA_FORM_FIELD_BUTTON)

  *type = form_field->data.button.type;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_button_get_state(zathura_form_field_t* form_field, bool*
    state) {
  if (form_field == NULL || state == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_FORM_FIELD_TYPE(form_field, ZATHURA_FORM_FIELD_BUTTON)

  *state = form_field->data.button.state;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_button_set_state(zathura_form_field_t* form_field, bool
    state)
{
  if (form_field == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_FORM_FIELD_TYPE(form_field, ZATHURA_FORM_FIELD_BUTTON)

  form_field->data.button.state = state;

  return ZATHURA_ERROR_OK;
}


/* See LICENSE file for license and copyright information */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "form-fields.h"
#include "form-fields/internal.h"

zathura_error_t
zathura_form_field_new(zathura_form_field_t** form_field, zathura_form_field_type_t type)
{
  if (form_field == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  switch (type) {
    case ZATHURA_FORM_FIELD_BUTTON:
    case ZATHURA_FORM_FIELD_TEXT:
    case ZATHURA_FORM_FIELD_CHOICE:
    case ZATHURA_FORM_FIELD_SIGNATURE:
      break;
    default:
      return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *form_field = calloc(1, sizeof(zathura_form_field_t));
  if (*form_field == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  switch (type) {
    case ZATHURA_FORM_FIELD_BUTTON:
      (*form_field)->data.button.type = ZATHURA_FORM_FIELD_BUTTON_TYPE_PUSH;
      (*form_field)->data.button.state = false;
      break;
    case ZATHURA_FORM_FIELD_TEXT:
      (*form_field)->data.text.type = ZATHURA_FORM_FIELD_TEXT_TYPE_NORMAL;
      (*form_field)->data.text.max_length = 0;
      (*form_field)->data.text.is_password = false;
      (*form_field)->data.text.is_rich_text = false;
      (*form_field)->data.text.do_scroll = false;
      (*form_field)->data.text.do_spell_check = false;
      break;
    case ZATHURA_FORM_FIELD_CHOICE:
      (*form_field)->data.choice.type = ZATHURA_FORM_FIELD_CHOICE_TYPE_LIST;
      (*form_field)->data.choice.is_editable = false;
      (*form_field)->data.choice.is_sorted = false;
      (*form_field)->data.choice.is_multiselect = false;
      (*form_field)->data.choice.do_spell_check = false;
      (*form_field)->data.choice.items = NULL;
      break;
    case ZATHURA_FORM_FIELD_SIGNATURE:
      break;
  }

  (*form_field)->type = type;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_free(zathura_form_field_t* form_field)
{
  if (form_field == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  if (form_field->data.text.text != NULL) {
    g_free(form_field->data.text.text);
  }

  free(form_field);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_get_type(zathura_form_field_t* form_field,
    zathura_form_field_type_t* type)
{
  if (form_field == NULL || type == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *type = form_field->type;

  return ZATHURA_ERROR_OK;
}


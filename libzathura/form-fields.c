/* See LICENSE file for license and copyright information */

#include <stdlib.h>

#include "form-fields.h"

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
    /**
     * Button form field
     */
    struct {
      /**
       * The type of the button field
       */
      zathura_form_field_button_type_t type;
    } button;
  } data;
};

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

  (*form_field)->type = type;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_free(zathura_form_field_t* form_field)
{
  if (form_field == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
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

zathura_error_t
zathura_form_field_button_set_type(zathura_form_field_t* form_field,
    zathura_form_field_button_type_t type)
{
  if (form_field == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_FORM_FIELD_TYPE(form_field, ZATHURA_FORM_FIELD_BUTTON)

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
    value) {
  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_button_set_state(zathura_form_field_t* form_field, bool value)
{
  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_text_set_type(zathura_form_field_t* form_field, zathura_form_field_text_type_t type)
{
  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_text_get_type(zathura_form_field_t* form_field,
    zathura_form_field_text_type_t * type)
{
  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_text_set_max_length(zathura_form_field_t* form_field, unsigned int length)
{
  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_text_get_max_length(zathura_form_field_t* form_field,
    unsigned int* length)
{
  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_text_set_password(zathura_form_field_t* form_field, bool value)
{
  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_text_is_password(zathura_form_field_t* form_field, bool*
    value)
{
  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_text_set_rich_text(zathura_form_field_t* form_field, bool value)
{
  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_text_is_rich_text(zathura_form_field_t* zathura_error_t, bool*
    value)
{
  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_text_set_scroll(zathura_form_field_t* form_field, bool value)
{
  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_text_do_scroll(zathura_form_field_t* form_field, bool* value)
{
  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_text_set_spell_check(zathura_form_field_t* form_field, bool value)
{
  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_text_do_spell_check(zathura_form_field_t* form_field, bool*
    value)
{
  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_text_set_text(zathura_form_field_t* form_field, const char*
    text)
{
  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_text_get_text(zathura_form_field_t* form_field, char** text)
{
  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_choice_set_type(zathura_form_field_t* form_field,
    zathura_form_field_choice_type_t type)
{
  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_choice_get_type(zathura_form_field_t* form_field,
    zathura_form_field_choice_type_t* type)
{
  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_choice_set_items(zathura_form_field_t* form_field, zathura_list_t* items)
{
  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_choice_get_items(zathura_form_field_t* form_field, zathura_list_t**
    items)
{
  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_choice_item_is_selected(zathura_form_field_t* form_field,
    unsigned int index, bool* selected)
{
  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_choice_select_item(zathura_form_field_t* form_field, unsigned
    int index)
{
  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_choice_deselect_item(zathura_form_field_t* form_field,
    unsigned int index)
{
  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_choice_set_editable(zathura_form_field_t* form_field, bool value)
{
  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_choice_is_editable(zathura_form_field_t* form_field, bool*
    value)
{
  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_choice_set_sorted(zathura_form_field_t* form_field, bool value)
{
  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_choice_is_sorted(zathura_form_field_t* form_field, bool*
    value)
{
  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_choice_set_multiselect(zathura_form_field_t* form_field, bool value)
{
  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_choice_is_multiselect(zathura_form_field_t* form_field, bool*
    value)
{
  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_choice_set_spell_check(zathura_form_field_t* form_field, bool value)
{
  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_choice_do_spell_check(zathura_form_field_t* form_field, bool*
    value)
{
  return ZATHURA_ERROR_OK;
}

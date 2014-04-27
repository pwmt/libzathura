/* See LICENSE file for license and copyright information */

#include <stdlib.h>
#include <stdio.h>

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

      /**
       * The state of the button
       */
      bool state;
    } button;

    /**
     * Text form field
     */
    struct {
      /**
       * The type of the text field
       */
      zathura_form_field_text_type_t type;

      /**
       * Maximal length
       */
      unsigned int max_length;

      /**
       * If the text form is a password
       */
      bool is_password;

      /**
       * If text is a rich text
       */
      bool is_rich_text;

      /**
       * If scrolling is allowed
       */
      bool do_scroll;

      /**
       * If spell-checking should be performed
       */
      bool do_spell_check;

      /**
       * The text
       */
      char* text;
    } text;

    /**
     * Choice form field
     */
    struct {
      /**
       * The type of the choice field
       */
      zathura_form_field_choice_type_t type;

      /**
       * If the choice form is editable
       */
      bool is_editable;

      /**
       * If the options should be sorted alphabetically
       */
      bool is_sorted;

      /**
       * If multiple selections are allowed
       */
      bool is_multiselect;

      /**
       * If spell-checking should be performed
       */
      bool do_spell_check;

      /**
       * List of choices
       */
      zathura_list_t* items;
    } choice;
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

  if (form_field->data.choice.items != NULL) {
    zathura_list_free(form_field->data.choice.items);
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

zathura_error_t
zathura_form_field_text_set_type(zathura_form_field_t* form_field, zathura_form_field_text_type_t type)
{
  if (form_field == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_FORM_FIELD_TYPE(form_field, ZATHURA_FORM_FIELD_TEXT)

  switch (type) {
    case ZATHURA_FORM_FIELD_TEXT_TYPE_NORMAL:
    case ZATHURA_FORM_FIELD_TEXT_TYPE_MULTILINE:
    case ZATHURA_FORM_FIELD_TEXT_TYPE_FILE_SELECT:
      break;
    default:
      return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  form_field->data.text.type = type;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_text_get_type(zathura_form_field_t* form_field,
    zathura_form_field_text_type_t* type)
{
  if (form_field == NULL || type == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_FORM_FIELD_TYPE(form_field, ZATHURA_FORM_FIELD_TEXT)

  *type = form_field->data.text.type;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_text_set_max_length(zathura_form_field_t* form_field,
    unsigned int max_length)
{
  if (form_field == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_FORM_FIELD_TYPE(form_field, ZATHURA_FORM_FIELD_TEXT)

  form_field->data.text.max_length = max_length;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_text_get_max_length(zathura_form_field_t* form_field,
    unsigned int* max_length)
{
  if (form_field == NULL || max_length == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_FORM_FIELD_TYPE(form_field, ZATHURA_FORM_FIELD_TEXT)

  *max_length = form_field->data.text.max_length;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_text_set_password(zathura_form_field_t* form_field, bool is_password)
{
  if (form_field == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_FORM_FIELD_TYPE(form_field, ZATHURA_FORM_FIELD_TEXT)

  form_field->data.text.is_password = is_password;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_text_is_password(zathura_form_field_t* form_field, bool*
    is_password)
{
  if (form_field == NULL || is_password == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_FORM_FIELD_TYPE(form_field, ZATHURA_FORM_FIELD_TEXT)

  *is_password = form_field->data.text.is_password;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_text_set_rich_text(zathura_form_field_t* form_field, bool is_rich_text)
{
  if (form_field == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_FORM_FIELD_TYPE(form_field, ZATHURA_FORM_FIELD_TEXT)

  form_field->data.text.is_rich_text = is_rich_text;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_text_is_rich_text(zathura_form_field_t* form_field, bool*
    is_rich_text)
{
  if (form_field == NULL || is_rich_text == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_FORM_FIELD_TYPE(form_field, ZATHURA_FORM_FIELD_TEXT)

  *is_rich_text = form_field->data.text.is_rich_text;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_text_set_scroll(zathura_form_field_t* form_field, bool do_scroll)
{
  if (form_field == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_FORM_FIELD_TYPE(form_field, ZATHURA_FORM_FIELD_TEXT)

  form_field->data.text.do_scroll = do_scroll;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_text_do_scroll(zathura_form_field_t* form_field, bool* do_scroll)
{
  if (form_field == NULL || do_scroll == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_FORM_FIELD_TYPE(form_field, ZATHURA_FORM_FIELD_TEXT)

  *do_scroll = form_field->data.text.do_scroll;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_text_set_spell_check(zathura_form_field_t* form_field, bool do_spell_check)
{
  if (form_field == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_FORM_FIELD_TYPE(form_field, ZATHURA_FORM_FIELD_TEXT)

  form_field->data.text.do_spell_check = do_spell_check;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_text_do_spell_check(zathura_form_field_t* form_field, bool*
    do_spell_check)
{
  if (form_field == NULL || do_spell_check == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_FORM_FIELD_TYPE(form_field, ZATHURA_FORM_FIELD_TEXT)

  *do_spell_check = form_field->data.text.do_spell_check;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_text_set_text(zathura_form_field_t* form_field, const char*
    text)
{
  if (form_field == NULL || text == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_FORM_FIELD_TYPE(form_field, ZATHURA_FORM_FIELD_TEXT)

  unsigned int max_length = 0;
  if (zathura_form_field_text_get_max_length(form_field, &max_length) != ZATHURA_ERROR_OK) {
    return ZATHURA_ERROR_UNKNOWN;
  }

  /* Given text is longer than allowed */
  if (max_length != 0 && strlen(text) > max_length) {
    return ZATHURA_ERROR_UNKNOWN;
  }

  if (form_field->data.text.text != NULL) {
    g_free(form_field->data.text.text);
  }

  form_field->data.text.text = g_strdup(text);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_text_get_text(zathura_form_field_t* form_field, char** text)
{
  if (form_field == NULL || text == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_FORM_FIELD_TYPE(form_field, ZATHURA_FORM_FIELD_TEXT)

  *text = form_field->data.text.text;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_choice_set_type(zathura_form_field_t* form_field,
    zathura_form_field_choice_type_t type)
{
  if (form_field == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_FORM_FIELD_TYPE(form_field, ZATHURA_FORM_FIELD_CHOICE)

  switch (type) {
    case ZATHURA_FORM_FIELD_CHOICE_TYPE_LIST:
    case ZATHURA_FORM_FIELD_CHOICE_TYPE_COMBO:
      break;
    default:
      return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  form_field->data.choice.type = type;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_choice_get_type(zathura_form_field_t* form_field,
    zathura_form_field_choice_type_t* type)
{
  if (form_field == NULL || type == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_FORM_FIELD_TYPE(form_field, ZATHURA_FORM_FIELD_CHOICE)

  *type = form_field->data.choice.type;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_choice_set_items(zathura_form_field_t* form_field, zathura_list_t* items)
{
  if (form_field == NULL || items == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_FORM_FIELD_TYPE(form_field, ZATHURA_FORM_FIELD_CHOICE)

  form_field->data.choice.items = items;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_choice_get_items(zathura_form_field_t* form_field, zathura_list_t**
    items)
{
  if (form_field == NULL || items == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_FORM_FIELD_TYPE(form_field, ZATHURA_FORM_FIELD_CHOICE)

  *items = form_field->data.choice.items;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_choice_item_is_selected(zathura_form_field_t* form_field,
    unsigned int index, bool* selected)
{
  if (form_field == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_FORM_FIELD_TYPE(form_field, ZATHURA_FORM_FIELD_CHOICE)

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_choice_select_item(zathura_form_field_t* form_field, unsigned
    int index)
{
  if (form_field == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_FORM_FIELD_TYPE(form_field, ZATHURA_FORM_FIELD_CHOICE)

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_choice_deselect_item(zathura_form_field_t* form_field,
    unsigned int index)
{
  if (form_field == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_FORM_FIELD_TYPE(form_field, ZATHURA_FORM_FIELD_CHOICE)

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_choice_set_editable(zathura_form_field_t* form_field, bool
    is_editable)
{
  if (form_field == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_FORM_FIELD_TYPE(form_field, ZATHURA_FORM_FIELD_CHOICE)


  form_field->data.choice.is_editable = is_editable;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_choice_is_editable(zathura_form_field_t* form_field, bool*
    is_editable)
{
  if (form_field == NULL || is_editable == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_FORM_FIELD_TYPE(form_field, ZATHURA_FORM_FIELD_CHOICE)

  *is_editable = form_field->data.choice.is_editable;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_choice_set_sorted(zathura_form_field_t* form_field, bool
    is_sorted)
{
  if (form_field == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_FORM_FIELD_TYPE(form_field, ZATHURA_FORM_FIELD_CHOICE)

  form_field->data.choice.is_sorted = is_sorted;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_choice_is_sorted(zathura_form_field_t* form_field, bool*
    is_sorted)
{
  if (form_field == NULL || is_sorted == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_FORM_FIELD_TYPE(form_field, ZATHURA_FORM_FIELD_CHOICE)

  *is_sorted = form_field->data.choice.is_sorted;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_choice_set_multiselect(zathura_form_field_t* form_field, bool
    is_multiselect)
{
  if (form_field == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_FORM_FIELD_TYPE(form_field, ZATHURA_FORM_FIELD_CHOICE)

  form_field->data.choice.is_multiselect = is_multiselect;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_choice_is_multiselect(zathura_form_field_t* form_field, bool*
    is_multiselect)
{
  if (form_field == NULL || is_multiselect == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_FORM_FIELD_TYPE(form_field, ZATHURA_FORM_FIELD_CHOICE)

  *is_multiselect = form_field->data.choice.is_multiselect;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_choice_set_spell_check(zathura_form_field_t* form_field, bool
    do_spell_check)
{
  if (form_field == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_FORM_FIELD_TYPE(form_field, ZATHURA_FORM_FIELD_CHOICE)

  form_field->data.choice.do_spell_check = do_spell_check;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_choice_do_spell_check(zathura_form_field_t* form_field, bool*
    do_spell_check)
{
  if (form_field == NULL || do_spell_check == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_FORM_FIELD_TYPE(form_field, ZATHURA_FORM_FIELD_CHOICE)

  *do_spell_check =form_field->data.choice.do_spell_check;

  return ZATHURA_ERROR_OK;
}

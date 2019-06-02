/* See LICENSE file for license and copyright information */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "form-field-text.h"
#include "../plugin-api/form-fields/form-field-text.h"
#include "internal.h"

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

  /* Given text is longer than allowed */
  unsigned int max_length = form_field->data.text.max_length;
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


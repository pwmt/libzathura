/* See LICENSE file for license and copyright information */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "internal.h"
#include "form-fields.h"
#include "form-fields/internal.h"

zathura_error_t
zathura_form_field_new(zathura_page_t* page, zathura_form_field_t** form_field, zathura_form_field_type_t type)
{
  if (page == NULL || form_field == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  switch (type) {
    case ZATHURA_FORM_FIELD_UNKNOWN:
    case ZATHURA_FORM_FIELD_BUTTON:
    case ZATHURA_FORM_FIELD_TEXT:
    case ZATHURA_FORM_FIELD_CHOICE:
    case ZATHURA_FORM_FIELD_SIGNATURE:
      break;
    default:
      return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *form_field = calloc(1, sizeof(**form_field));
  if (*form_field == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  switch (type) {
    case ZATHURA_FORM_FIELD_UNKNOWN:
      break;
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
      (*form_field)->data.signature.signature = NULL;
      break;
  }

  (*form_field)->type = type;
  (*form_field)->page = page;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_free(zathura_form_field_t* form_field)
{
  if (form_field == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  if (form_field->name != NULL) {
    g_free(form_field->name);
  }

  if (form_field->partial_name != NULL) {
    g_free(form_field->partial_name);
  }

  if (form_field->mapping_name != NULL) {
    g_free(form_field->mapping_name);
  }

  if (form_field->user_data != NULL && form_field->user_data_free_function) {
    form_field->user_data_free_function(form_field->user_data);
  }

  switch (form_field->type) {
    case ZATHURA_FORM_FIELD_UNKNOWN:
      break;
    case ZATHURA_FORM_FIELD_BUTTON:
      break;
    case ZATHURA_FORM_FIELD_TEXT:
      if (form_field->data.text.text != NULL) {
        g_free(form_field->data.text.text);
      }
      break;
    case ZATHURA_FORM_FIELD_CHOICE:
      if (form_field->data.choice.items != NULL) {
        zathura_list_free_full(form_field->data.choice.items, (zathura_free_function_t) zathura_form_field_choice_item_free);
        form_field->data.choice.items = NULL;
      }
      break;
    case ZATHURA_FORM_FIELD_SIGNATURE:
      /* (*form_field)->data.signature.signature = NULL; */
      break;
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
zathura_form_field_set_name(zathura_form_field_t* form_field, const char* name)
{
  if (form_field == NULL || name == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  if (form_field->name != NULL) {
    g_free(form_field->name);
  }

  form_field->name = g_strdup(name);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_get_name(zathura_form_field_t* form_field, char** name)
{
  if (form_field == NULL || name == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *name = form_field->name;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_set_partial_name(zathura_form_field_t* form_field, const char* partial_name)
{
  if (form_field == NULL || partial_name == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  if (form_field->partial_name != NULL) {
    g_free(form_field->partial_name);
  }

  form_field->partial_name = g_strdup(partial_name);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_get_partial_name(zathura_form_field_t* form_field, char** partial_name)
{
  if (form_field == NULL || partial_name == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *partial_name = form_field->partial_name;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_set_mapping_name(zathura_form_field_t* form_field, const char* mapping_name)
{
  if (form_field == NULL || mapping_name == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  if (form_field->mapping_name != NULL) {
    g_free(form_field->mapping_name);
  }

  form_field->mapping_name = g_strdup(mapping_name);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_get_mapping_name(zathura_form_field_t* form_field, char**
    mapping_name)
{
  if (form_field == NULL || mapping_name == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *mapping_name = form_field->mapping_name;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_set_flags(zathura_form_field_t* form_field,
    zathura_form_field_flag_t flags)
{
  if (form_field == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  form_field->flags = flags;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_get_flags(zathura_form_field_t* form_field,
    zathura_form_field_flag_t* flags)
{
  if (form_field == NULL || flags == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *flags = form_field->flags;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_set_user_data(zathura_form_field_t*
    form_field, void* data, zathura_free_function_t free_function)
{
  if (form_field == NULL || data == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  if (form_field->user_data != NULL && form_field->user_data_free_function) {
    form_field->user_data_free_function(form_field->user_data);
  }

  form_field->user_data = data;
  form_field->user_data_free_function = free_function;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_get_user_data(zathura_form_field_t* form_field, void** user_data)
{
  if (form_field == NULL || user_data == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *user_data = form_field->user_data;

  return ZATHURA_ERROR_OK;
}

#define CHECK_IF_IMPLEMENTED(page, function) \
  if ((page)->document == NULL || \
      (page)->document->plugin == NULL || \
      (page)->document->plugin->functions.function == NULL) { \
    return ZATHURA_ERROR_PLUGIN_NOT_IMPLEMENTED; \
  }

zathura_error_t
zathura_form_field_save(zathura_form_field_t* form_field)
{
  if (form_field == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_IF_IMPLEMENTED(form_field->page, form_field_save)

  return form_field->page->document->plugin->functions.form_field_save(form_field);
}

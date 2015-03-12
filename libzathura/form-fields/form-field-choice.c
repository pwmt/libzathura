/* See LICENSE file for license and copyright information */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "form-field-choice.h"
#include "internal.h"

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
zathura_form_field_choice_item_set_name(zathura_form_field_choice_item_t*
  choice_item, const char* name)
{
  if (choice_item == NULL || name == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  if (choice_item->name != NULL) {
    g_free(choice_item->name);
  }

  choice_item->name = g_strdup(name);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_choice_item_get_name(zathura_form_field_choice_item_t*
  choice_item, char** name)
{
  if (choice_item == NULL || name == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *name = choice_item->name;

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

  *do_spell_check = form_field->data.choice.do_spell_check;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_choice_item_new(zathura_form_field_t* form_field,
    zathura_form_field_choice_item_t** item, const char* name)
{
  if (form_field == NULL || item == NULL || name == NULL || strlen(name) == 0) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *item = calloc(1, sizeof(zathura_form_field_choice_item_t));
  if (*item == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  (*item)->form_field = form_field;
  (*item)->selected   = false;
  (*item)->name       = g_strdup(name);

  form_field->data.choice.items = zathura_list_append(form_field->data.choice.items, *item);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_choice_item_free(zathura_form_field_choice_item_t* item)
{
  if (item == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  g_free(item->name);
  free(item);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_choice_item_is_selected(zathura_form_field_choice_item_t*
    choice_item, bool* is_selected)
{
  if (choice_item == NULL || is_selected == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *is_selected = choice_item->selected;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_choice_item_select(zathura_form_field_choice_item_t* choice_item)
{
  if (choice_item == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  /* Unselect all if field is not a multi select field */
  if (choice_item->form_field->data.choice.is_multiselect == false) {
    zathura_form_field_choice_item_t* tmp_choice_item;
    ZATHURA_LIST_FOREACH(tmp_choice_item, choice_item->form_field->data.choice.items) {
      tmp_choice_item->selected = false;
    }
  }

  choice_item->selected = true;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_choice_item_deselect(zathura_form_field_choice_item_t*
  choice_item)
{
  if (choice_item == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  choice_item->selected = false;

  return ZATHURA_ERROR_OK;
}


/* See LICENSE file for license and copyright information */

#ifndef LIBZATHURA_INTERNAL_FORM_FIELD_CHOICE_H
#define LIBZATHURA_INTERNAL_FORM_FIELD_CHOICE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../list.h"

/**
 * A form field choice item
 */
struct zathura_form_field_choice_item_s {
  /**
   * The corresponding form field
   */
  zathura_form_field_t* form_field;

  /**
   * The name of the item
   */
  char* name;

  /**
   * If the item is selected
   */
  bool selected;
};

/**
 * Choice form field
 */
struct zathura_form_field_choice_s {
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
};

#ifdef __cplusplus
}
#endif

#endif /* INTERNAL_FORM_FIELD_CHOICE_H */

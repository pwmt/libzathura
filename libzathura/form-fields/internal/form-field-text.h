/* See LICENSE file for license and copyright information */

#ifndef INTERNAL_FORM_FIELD_TEXT_H
#define INTERNAL_FORM_FIELD_TEXT_H

#include "../form-field-text.h"

struct zathura_form_field_text_s {
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
};

#endif /* INTERNAL_FORM_FIELD_TEXT_H */

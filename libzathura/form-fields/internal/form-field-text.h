/* See LICENSE file for license and copyright information */

#ifndef LIBZATHURA_INTERNAL_FORM_FIELD_TEXT_H
#define LIBZATHURA_INTERNAL_FORM_FIELD_TEXT_H

#ifdef __cplusplus
extern "C" {
#endif

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

#ifdef __cplusplus
}
#endif

#endif /* INTERNAL_FORM_FIELD_TEXT_H */

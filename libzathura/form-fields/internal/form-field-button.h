/* See LICENSE file for license and copyright information */

#ifndef INTERNAL_FORM_FIELD_BUTTON_H
#define INTERNAL_FORM_FIELD_BUTTON_H

/**
 * Button form field
 */
struct zathura_form_field_button_s {
  /**
   * The type of the button field
   */
  zathura_form_field_button_type_t type;

  /**
   * The state of the button
   */
  bool state;
};

#endif /* INTERNAL_FORM_FIELD_BUTTON_H */


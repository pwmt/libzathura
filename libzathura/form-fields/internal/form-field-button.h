/* See LICENSE file for license and copyright information */

#ifndef LIBZATHURA_INTERNAL_FORM_FIELD_BUTTON_H
#define LIBZATHURA_INTERNAL_FORM_FIELD_BUTTON_H

#ifdef __cplusplus
extern "C" {
#endif

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

#ifdef __cplusplus
}
#endif

#endif /* INTERNAL_FORM_FIELD_BUTTON_H */

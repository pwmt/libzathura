/* See LICENSE file for license and copyright information */

#ifndef LIBZATHURA_FORM_FIELD_TEXT_H
#define LIBZATHURA_FORM_FIELD_TEXT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "../form-fields.h"

typedef enum zathura_form_field_text_type_e {
  /**
   * The field is restricted to a single line of text.
   */
  ZATHURA_FORM_FIELD_TEXT_TYPE_NORMAL,

  /**
   * The field can contain multiple lines of text.
   */
  ZATHURA_FORM_FIELD_TEXT_TYPE_MULTILINE,

  /**
   * Text entered in the field represents the pathname of a file whose contents
   * are to be submitted as the value of the field.
   */
  ZATHURA_FORM_FIELD_TEXT_TYPE_FILE_SELECT,
} zathura_form_field_text_type_t;

/**
 * Returns the text type of the text form field.
 *
 * @param[in] form_field The form field
 * @param[out] type The text type of the form field
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_text_get_type(zathura_form_field_t*
    form_field, zathura_form_field_text_type_t* type);

/**
 * Returns the text of the text form field.
 *
 * @param[in] form_field The form field
 * @param[out] text The text of the field
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_text_get_text(zathura_form_field_t*
    form_field, char** text);

/**
 * Sets the text of the text form field.
 *
 * @param[in] form_field The form field
 * @param[in] text The text of the field
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_text_set_text(zathura_form_field_t*
    form_field, const char* text);

/**
 * Returns the maximal length of the text field. If length is unlimited, the
 * value stored in length is 0.
 *
 * @param[in] form_field The form field
 * @param[out] length The maximal length of the entry
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_text_get_max_length(zathura_form_field_t*
    form_field, unsigned int* length);

/**
 * Returns if the text field is a password or not.
 *
 * @param[in] form_field The form field
 * @param[out] is_password If the text field is a password
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_text_is_password(zathura_form_field_t*
    form_field, bool* is_password);

/**
 * Returns if the text field is a rich text string or not.
 *
 * @param[in] form_field The form field
 * @param[out] is_rich_text If the text field is a rich text string
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_text_is_rich_text(zathura_form_field_t*
    form_field, bool* is_rich_text);

/**
 * Returns if the text field does scroll (horizontally for single-line fields,
 * vertically for multiple-line fields).
 *
 * @param[in] form_field The form field
 * @param[out] do_scroll If the text field scrolls or not
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_text_do_scroll(zathura_form_field_t*
    form_field, bool* do_scroll);

/**
 * Returns if spell-checking should be performed on the entered text or not.
 *
 * @param[in] form_field The form field
 * @param[out] do_spell_check If spell-checking should be performed on the text field
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_text_do_spell_check(zathura_form_field_t*
    form_field, bool* do_spell_check);

#ifdef __cplusplus
}
#endif

#endif /* FORM_FIELD_TEXT_H */

/* See LICENSE file for license and copyright information */

#ifndef LIBZATHURA_FORM_FIELDS_H
#define LIBZATHURA_FORM_FIELDS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#ifdef HAVE_CAIRO
#include <cairo.h>
#endif

#include "image-buffer.h"
#include "page.h"
#include "error.h"

/* Forward declaration */
typedef struct zathura_rectangle_s zathura_rectangle_t;

/**
 * An interactive form is a collection of fields for gathering information
 * interactively from the user. A document may contain any number of fields
 * appearing on any combination of pages, all of which make up a single, global
 * interactive form spanning the entire document.
 */
typedef struct zathura_form_field_s zathura_form_field_t;

/**
 * Interactive forms support the following field types:
 */
typedef enum zathura_form_field_type_e {
  /**
   * Unknown form field type
   */
  ZATHURA_FORM_FIELD_UNKNOWN = 0,

  /**
   * Represents interactive controls on the screen that the user can manipulate
   * with the mouse. They include pushbuttons, check boxes and radio buttons.
   */
  ZATHURA_FORM_FIELD_BUTTON,

  /**
   * Are boxes or spaces in which the user can enter text from the key-board
   */
  ZATHURA_FORM_FIELD_TEXT,

  /**
   * Contain several text items, at most one of which maybe selected as the
   * field value. They include scrollable list boxes and combo boxes.
   */
  ZATHURA_FORM_FIELD_CHOICE,

  /**
   * Represents electronic signatures for authenticating the identity of a user
   * and the validity of the document's contents.
   */
  ZATHURA_FORM_FIELD_SIGNATURE,
} zathura_form_field_type_t;

typedef enum zathura_form_field_flag_s {
  ZATHURA_FORM_FIELD_FLAG_NONE = 0,
  ZATHURA_FORM_FIELD_FLAG_READ_ONLY,
  ZATHURA_FORM_FIELD_FLAG_REQUIRED,
  ZATHURA_FORM_FIELD_FLAG_NO_EXPORT
} zathura_form_field_flag_t;

/**
 * Returns the type of the form field
 *
 * @param[in] form_field
 * @param[out] type The type of the form field
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_get_type(zathura_form_field_t* form_field,
    zathura_form_field_type_t* type);

/**
 * Sets the position of the form field defining the location of the form field
 * on the page in default user space units.
 *
 * @param[in] annotation The annotation
 * @param[in] position The position defining the location of the form field on
 *  the page in default user space units
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_set_position(zathura_form_field_t* form_field,
    zathura_rectangle_t position);

/**
 * Returns the position of the form field defining the location of the form field
 * on the page in default user space units.
 *
 * @param[in] form_field The form field
 * @param[out] position The position defining the location of the form field on
 *  the page in default user space units
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_get_position(zathura_form_field_t* form_field,
    zathura_rectangle_t* position);

/**
 * Returns the page associated with this form field
 *
 * @param[in] annotation The form field
 * @param[out] page The associated page
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_get_page(zathura_form_field_t* form_field,
    zathura_page_t** page);

/**
 * Returns the name of the form field
 *
 * @param[in] form_field
 * @param[out] name The name
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_get_name(zathura_form_field_t* form_field, char** name);

/**
 * Returns the partial name of the form field
 *
 * @param[in] form_field
 * @param[out] partial_name The partial name
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_get_partial_name(zathura_form_field_t* form_field, char** partial_name);

/**
 * Returns the mapping name of the form field
 *
 * @param[in] form_field
 * @param[out] mapping_name The mapping name
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_get_mapping_name(zathura_form_field_t* form_field, char** mapping_name);

/**
 * Returns the flags of the form field
 *
 * @param[in] form_field
 * @param[out] flags The flags
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_get_flags(zathura_form_field_t* form_field, zathura_form_field_flag_t* flags);

/**
 * Saves the form field back to the plugin
 *
 * @param[in] form_field The form field
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_save(zathura_form_field_t* form_field);

/**
 * Renders the form field to a @a ::zathura_image_buffer_t image buffer
 *
 * @param[in] annotation The form field
 * @param[out] buffer The image buffer
 * @param[in] scale Scale level
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_render(zathura_form_field_t* form_field,
    zathura_image_buffer_t** buffer, double scale);

#ifdef HAVE_CAIRO
/**
 * Renders the form field to a cairo object
 *
 * @param[in] annotation The used form field object
 * @param[out] cairo The cairo object
 * @param[in] scale Scale level
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_render_cairo(zathura_form_field_t*
    form_field, cairo_t* cairo, double scale);
#endif

#include "form-fields/form-field-button.h"
#include "form-fields/form-field-text.h"
#include "form-fields/form-field-choice.h"
#include "form-fields/form-field-signature.h"

#ifdef __cplusplus
}
#endif

#endif /* FORM_FIELDS_H */

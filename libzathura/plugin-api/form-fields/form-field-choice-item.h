/* See LICENSE file for license and copyright information */

#ifndef LIBZATHURA_PLUGIN_API_FORM_FIELD_CHOICE_ITEM_H
#define LIBZATHURA_PLUGIN_API_FORM_FIELD_CHOICE_ITEM_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Creates a new form field choice item
 *
 * @param[in] form_field The form field that is associated with the choice item
 * @param[out] item The new form field choice item
 * @param[in] name The name of the choice item
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t
zathura_form_field_choice_item_new(zathura_form_field_t* form_field, zathura_form_field_choice_item_t** item,
    const char* name);

/**
 * Frees the form field choice item
 *
 * @param[in] item The form field choice item
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t
zathura_form_field_choice_item_free(zathura_form_field_choice_item_t* item);

/**
 * Sets the name of the choice item
 *
 * @param[in] item The new form field choice item
 * @param[in] name The name of the choice item
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t
zathura_form_field_choice_item_set_name(zathura_form_field_choice_item_t* item,
    const char* name);

#ifdef __cplusplus
}
#endif

#endif /* PLUGIN_API_FORM_FIELD_CHOICE_ITEM_H */

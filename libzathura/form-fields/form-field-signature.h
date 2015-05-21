/* See LICENSE file for license and copyright information */

#ifndef FORM_FIELD_SIGNATURE_H
#define FORM_FIELD_SIGNATURE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "../form-fields.h"
#include "../crypto/signature.h"

/**
 * Sets the signature of the given signature form field.
 *
 * @param[in] form_field The form field
 * @param[in] signature The signature of the form field
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_signature_set_signature(zathura_form_field_t*
    form_field, zathura_signature_t* signature);

/**
 * Returns the signature of the given signature form field.
 *
 * @param[in] form_field The form field
 * @param[out] signature The signature of the form field
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_form_field_signature_get_signature(zathura_form_field_t*
    form_field, zathura_signature_t** signature);

#ifdef __cplusplus
}
#endif

#endif /* FORM_FIELD_SIGNATURE_H */

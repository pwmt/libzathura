/* See LICENSE file for license and copyright information */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "form-field-signature.h"
#include "internal.h"

zathura_error_t
zathura_form_field_signature_set_signature(zathura_form_field_t* form_field,
    zathura_signature_t* signature)
{
  if (form_field == NULL || signature == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_FORM_FIELD_TYPE(form_field, ZATHURA_FORM_FIELD_SIGNATURE)

  form_field->data.signature.signature = signature;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_form_field_signature_get_signature(zathura_form_field_t* form_field,
    zathura_signature_t** signature)
{
  if (form_field == NULL || signature == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_FORM_FIELD_TYPE(form_field, ZATHURA_FORM_FIELD_SIGNATURE)

  *signature = form_field->data.signature.signature;

  return ZATHURA_ERROR_OK;
}

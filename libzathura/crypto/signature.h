/* See LICENSE file for license and copyright information */

#ifndef LIBZATHURA_CRYPTO_SIGNATURE_H
#define LIBZATHURA_CRYPTO_SIGNATURE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "certificate.h"
#include "private-key.h"

typedef struct zathura_signature_s zathura_signature_t;

zathura_error_t zathura_signature_new(zathura_signature_t** signature);

zathura_error_t zathura_signature_free(zathura_signature_t* signature);

zathura_error_t zathura_signature_set_data(zathura_signature_t* signature, unsigned char* data, size_t dlen);

zathura_error_t zathura_signature_get_data(zathura_signature_t* signature, unsigned char** data, size_t* dlen);

zathura_error_t zathura_signature_set_certificate(zathura_signature_t* signature, zathura_certificate_t* certificate);
zathura_error_t zathura_signature_get_certificate(zathura_signature_t* signature, zathura_certificate_t** certificate);

zathura_error_t zathura_signature_set_private_key(zathura_signature_t* signature, zathura_private_key_t* private_key);
zathura_error_t zathura_signature_get_private_key(zathura_signature_t* signature, zathura_private_key_t** private_key);

zathura_error_t zathura_signature_sign(zathura_signature_t* signature, unsigned char** data, size_t* dlen);

zathura_error_t zathura_signature_verify(zathura_signature_t* signature, bool* is_valid, unsigned char* data, size_t dlen);

#ifdef __cplusplus
}
#endif

#endif /* CRYPTO_SIGNATURE_H */

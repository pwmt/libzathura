/* See LICENSE file for license and copyright information */

#ifndef PLUGIN_API_ATTACHMENT_H
#define PLUGIN_API_ATTACHMENT_H

#include "../error.h"
#include "../attachment.h"

zathura_error_t zathura_attachment_new(zathura_attachment_t** attachment);
zathura_error_t zathura_attachment_free(zathura_attachment_t* attachment);
zathura_error_t zathura_attachment_set_data(zathura_attachment_t* attachment, void* data);
zathura_error_t zathura_attachment_get_data(zathura_attachment_t* attachment, void** data);
zathura_error_t zathura_attachment_set_name(zathura_attachment_t* attachment, const char* name);
zathura_error_t zathura_attachment_set_description(zathura_attachment_t* attachment, const char* description);
zathura_error_t zathura_attachment_set_size(zathura_attachment_t* attachment, unsigned int size);
zathura_error_t zathura_attachment_set_creation_time(zathura_attachment_t* attachment, time_t creation_time);
zathura_error_t zathura_attachment_set_modification_time(zathura_attachment_t* attachment, time_t modification_time);
zathura_error_t zathura_attachment_set_checksum(zathura_attachment_t* attachment, const char* checksum);

#endif /* PLUGIN_API_ATTACHMENT_H */

/* See LICENSE file for license and copyright information */

#define _XOPEN_SOURCE 500

#include <string.h>
#include <stdlib.h>

#include "attachment.h"
#include "plugin-api/attachment.h"

struct zathura_attachment_s {
  /**
   * The name of the attachment.
   */
  char* name;

  /**
   * The description of the attachment.
   */
  char* description;

  /**
   * The size of the attachment in bytes.
   */
  unsigned int size;

  /**
   * The date and time when the attachment was created.
   */
  time_t creation_time;

  /**
   * The date and time when the attachment was last modified.
   */
  time_t modification_time;

  /**
   * A 16-byte string that is the checksum of the bytes of the uncompressed
   * attachment. The checksum is calculated by applying the standard  MD5
   * message-digest algorithm (described in Internet RFC 1321, The MD5
   * Message-Digest Algorithmto the bytes of the attachment stream.
   */
  char* checksum;

  /**
   * Custom data of the plugin
   */
  char* data;

  /**
   * Custom data of the plugin
   */
  void* user_data;

  /**
   * Free function of the plugin custom data
   */
  zathura_free_function_t user_data_free_function;

  /**
   * Custom save function
   */
  zathura_attachment_save_function_t save_function;
};

zathura_error_t
zathura_attachment_new(zathura_attachment_t** attachment)
{
  if (attachment == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *attachment = calloc(1, sizeof(**attachment));
  if (*attachment == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_attachment_free(zathura_attachment_t* attachment)
{
  if (attachment == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  if (attachment->user_data != NULL && attachment->user_data_free_function) {
    attachment->user_data_free_function(attachment->user_data);
  }

  free(attachment);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_attachment_save(zathura_attachment_t* attachment, const char* path)
{
  if (attachment == NULL || path == NULL || strlen(path) == 0) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  if (attachment->save_function != NULL) {
    return attachment->save_function(attachment, path, attachment->user_data);
  }

	return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_attachment_set_data(zathura_attachment_t* attachment, const char* data, unsigned int size)
{
  if (attachment == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  if (attachment->data != NULL) {
    free(attachment->data);
  }

  attachment->size = size;

  if (size == 0) {
    attachment->data = NULL;
  } else {
    attachment->data = calloc(size, sizeof(*(attachment->data)));
    if (attachment->data == NULL) {
      return ZATHURA_ERROR_OUT_OF_MEMORY;
    }

    if (memcpy(attachment->data, data, size) != attachment->data) {
      return ZATHURA_ERROR_UNKNOWN;
    }
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_attachment_get_data(zathura_attachment_t* attachment, char** data)
{
  if (attachment == NULL || data == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *data = attachment->data;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_attachment_set_name(zathura_attachment_t* attachment, const char* name)
{
  if (attachment == NULL || (name != NULL && strlen(name) == 0)) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  if (attachment->name != NULL) {
    free(attachment->name);
    attachment->name = NULL;
  }

  if (name != NULL) {
    attachment->name = strdup(name);
    if (attachment->name == NULL) {
      return ZATHURA_ERROR_OUT_OF_MEMORY;
    }
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_attachment_get_name(zathura_attachment_t* attachment, const char** name)
{
  if (attachment == NULL || name == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *name = attachment->name;

	return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_attachment_set_description(zathura_attachment_t* attachment, const char* description)
{
  if (attachment == NULL || (description != NULL && strlen(description) == 0)) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  if (attachment->description != NULL) {
    free(attachment->description);
    attachment->description = NULL;
  }

  if (description != NULL) {
    attachment->description = strdup(description);
    if (attachment->description == NULL) {
      return ZATHURA_ERROR_OUT_OF_MEMORY;
    }
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_attachment_get_description(zathura_attachment_t* attachment, const
    char** description)
{
  if (attachment == NULL || description == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *description = attachment->description;

	return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_attachment_get_size(zathura_attachment_t* attachment, unsigned int*
    size)
{
  if (attachment == NULL || size == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *size = attachment->size;

	return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_attachment_set_creation_time(zathura_attachment_t* attachment, time_t creation_time)
{
  if (attachment == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  attachment->creation_time = creation_time;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_attachment_get_creation_time(zathura_attachment_t* attachment, time_t*
    creation_time)
{
  if (attachment == NULL || creation_time == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *creation_time = attachment->creation_time;

	return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_attachment_set_modification_time(zathura_attachment_t* attachment, time_t modification_time)
{
  if (attachment == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  attachment->modification_time = modification_time;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_attachment_get_modification_time(zathura_attachment_t* attachment,
    time_t* modification_time)
{
  if (attachment == NULL || modification_time == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *modification_time = attachment->modification_time;

	return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_attachment_set_checksum(zathura_attachment_t* attachment, const char* checksum)
{
  if (attachment == NULL || (checksum != NULL && strlen(checksum) != 16)) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  if (attachment->checksum != NULL) {
    free(attachment->checksum);
    attachment->checksum = NULL;
  }

  if (checksum != NULL) {
    attachment->checksum = strdup(checksum);
    if (attachment->checksum == NULL) {
      return ZATHURA_ERROR_OUT_OF_MEMORY;
    }
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_attachment_get_checksum(zathura_attachment_t* attachment, const char**
    checksum)
{
  if (attachment == NULL || checksum == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *checksum = attachment->checksum;

	return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_attachment_set_user_data(zathura_attachment_t* attachment, void* user_data, zathura_free_function_t free_function)
{
  if (attachment == NULL || user_data == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  if (attachment->user_data != NULL && attachment->user_data_free_function) {
    attachment->user_data_free_function(attachment->user_data);
  }

  attachment->user_data = user_data;
  attachment->user_data_free_function = free_function;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_attachment_get_user_data(zathura_attachment_t* attachment, void** user_data)
{
  if (attachment == NULL || user_data == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *user_data = attachment->user_data;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_attachment_set_save_function(zathura_attachment_t* attachment,
    zathura_attachment_save_function_t save_function)
{
  if (attachment == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  attachment->save_function = save_function;

  return ZATHURA_ERROR_OK;
}

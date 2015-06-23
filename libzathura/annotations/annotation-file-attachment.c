/* See LICENSE file for license and copyright information */

#include <stdlib.h>

#include "annotation-file-attachment.h"
#include "../attachment.h"
#include "../annotations.h"
#include "../error.h"

#include "internal.h"

#define ANNOTATION_FILE_CHECK_TYPE() \
  if (annotation->type != ZATHURA_ANNOTATION_FILE_ATTACHMENT) { \
    return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE; \
  }

#define ANNOTATION_FILE_CHECK_DATA() \
  if (annotation->data.file == NULL) { \
    return ZATHURA_ERROR_UNKNOWN; \
  }

#define ANNOTATION_FILE_CHECK_TYPE_AND_DATA() \
  ANNOTATION_FILE_CHECK_TYPE() \
  ANNOTATION_FILE_CHECK_DATA()

zathura_error_t
zathura_annotation_file_init(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_FILE_CHECK_TYPE()

  if (annotation->data.file != NULL) {
    free(annotation->data.file);
    annotation->data.file = NULL;
  }

  annotation->data.file = calloc(1, sizeof(zathura_annotation_file_t));
  if (annotation->data.file == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  annotation->data.file->file = NULL;
  annotation->data.file->icon_name = g_strdup("PushPin");

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_file_clear(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_FILE_CHECK_TYPE()

  if (annotation->data.file != NULL) {
    zathura_attachment_free(annotation->data.file->file);
    g_free(annotation->data.file->icon_name);
  }

  free(annotation->data.file);
  annotation->data.file = NULL;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_file_set_attachment(zathura_annotation_t*
    annotation, zathura_attachment_t* attachment)
{
  if (annotation == NULL || attachment == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_FILE_CHECK_TYPE_AND_DATA()

  annotation->data.file->file = attachment;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_file_get_attachment(zathura_annotation_t*
    annotation, zathura_attachment_t** attachment)
{
  if (annotation == NULL || attachment == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_FILE_CHECK_TYPE_AND_DATA()

  *attachment = annotation->data.file->file;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_file_set_icon_name(zathura_annotation_t*
    annotation, char* icon_name)
{
  if (annotation == NULL || icon_name == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_FILE_CHECK_TYPE_AND_DATA()

  if (annotation->data.file->icon_name != NULL) {
    g_free(annotation->data.file->icon_name);
  }

  annotation->data.file->icon_name = g_strdup(icon_name);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_file_get_icon_name(zathura_annotation_t*
    annotation, char** icon_name)
{
  if (annotation == NULL || icon_name == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_FILE_CHECK_TYPE_AND_DATA()

  *icon_name = annotation->data.file->icon_name;

  return ZATHURA_ERROR_OK;
}

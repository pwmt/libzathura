/* See LICENSE file for license and copyright information */

#include <stdlib.h>

#include "annotation-stamp.h"
#include "../annotations.h"
#include "../error.h"

#include "internal.h"

#define ANNOTATION_STAMP_CHECK_TYPE() \
  if (annotation->type != ZATHURA_ANNOTATION_STAMP) { \
    return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE; \
  }

#define ANNOTATION_STAMP_CHECK_DATA() \
  if (annotation->data.stamp == NULL) { \
    return ZATHURA_ERROR_UNKNOWN; \
  }

#define ANNOTATION_STAMP_CHECK_TYPE_AND_DATA() \
  ANNOTATION_STAMP_CHECK_TYPE() \
  ANNOTATION_STAMP_CHECK_DATA()

zathura_error_t
zathura_annotation_stamp_init(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_STAMP_CHECK_TYPE()

  if (annotation->data.stamp != NULL) {
    free(annotation->data.stamp);
    annotation->data.stamp = NULL;
  }

  annotation->data.stamp = calloc(1, sizeof(zathura_annotation_stamp_t));
  if (annotation->data.stamp == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  annotation->data.stamp->icon_name = NULL;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_stamp_clear(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_STAMP_CHECK_TYPE()

  if (annotation->data.stamp != NULL) {
    g_free(annotation->data.stamp->icon_name);
  }

  free(annotation->data.stamp);
  annotation->data.stamp = NULL;

  return ZATHURA_ERROR_OK;
}


zathura_error_t
zathura_annotation_stamp_set_icon_name(zathura_annotation_t*
    annotation, char* icon_name)
{
  if (annotation == NULL || icon_name == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_STAMP_CHECK_TYPE_AND_DATA()

  if (annotation->data.stamp->icon_name != NULL) {
    g_free(annotation->data.stamp->icon_name);
  }

  annotation->data.stamp->icon_name = g_strdup(icon_name);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_stamp_get_icon_name(zathura_annotation_t*
    annotation, char** icon_name)
{
  if (annotation == NULL || icon_name == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_STAMP_CHECK_TYPE_AND_DATA()

  *icon_name = annotation->data.stamp->icon_name;

  return ZATHURA_ERROR_OK;
}

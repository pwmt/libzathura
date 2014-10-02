/* See LICENSE file for license and copyright information */

#include <stdlib.h>

#include "annotation-popup.h"
#include "internal.h"
#include "internal/annotation-popup.h"

#define ANNOTATION_POPUP_CHECK_TYPE() \
  if (annotation->type != ZATHURA_ANNOTATION_POPUP) { \
    return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE; \
  }

#define ANNOTATION_POPUP_CHECK_DATA() \
  if (annotation->data.popup == NULL) { \
    return ZATHURA_ERROR_UNKNOWN; \
  }

#define ANNOTATION_POPUP_CHECK_TYPE_AND_DATA() \
  ANNOTATION_POPUP_CHECK_TYPE() \
  ANNOTATION_POPUP_CHECK_DATA()

zathura_error_t
zathura_annotation_popup_init(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_POPUP_CHECK_TYPE()

  if (annotation->data.popup != NULL) {
    free(annotation->data.popup);
    annotation->data.popup = NULL;
  }

  annotation->data.popup = calloc(1, sizeof(zathura_annotation_popup_t));
  if (annotation->data.popup == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  annotation->data.popup->is_open = false;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_popup_clear(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_POPUP_CHECK_TYPE()

  if (annotation->data.popup != NULL) {
    free(annotation->data.popup);
    annotation->data.popup = NULL;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t 
zathura_annotation_popup_set_parent(zathura_annotation_t* annotation, zathura_annotation_t* parent)
{
  if (annotation == NULL || parent == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_POPUP_CHECK_TYPE_AND_DATA()

  annotation->data.popup->parent = parent;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_popup_get_parent(zathura_annotation_t* annotation, zathura_annotation_t** parent)
{
  if (annotation == NULL || parent == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_POPUP_CHECK_TYPE_AND_DATA()

  *parent = annotation->data.popup->parent;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_popup_set_open(zathura_annotation_t* annotation, bool is_open)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_POPUP_CHECK_TYPE_AND_DATA()

  annotation->data.popup->is_open = is_open;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_popup_is_open(zathura_annotation_t* annotation, bool* is_open)
{
  if (annotation == NULL || is_open == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_POPUP_CHECK_TYPE_AND_DATA()

  *is_open = annotation->data.popup->is_open;

  return ZATHURA_ERROR_OK;
}

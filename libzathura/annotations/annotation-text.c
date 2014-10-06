/* See LICENSE file for license and copyright information */

#include <string.h>
#include <stdlib.h>

#include "annotation-text.h"
#include "../annotations.h"
#include "internal.h"
#include "internal/annotation-text.h"

#define ANNOTATION_TEXT_CHECK_TYPE() \
  if (annotation->type != ZATHURA_ANNOTATION_TEXT) { \
    return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE; \
  }

#define ANNOTATION_TEXT_CHECK_DATA() \
  if (annotation->data.text == NULL) { \
    return ZATHURA_ERROR_UNKNOWN; \
  }

#define ANNOTATION_TEXT_CHECK_TYPE_AND_DATA() \
  ANNOTATION_TEXT_CHECK_TYPE() \
  ANNOTATION_TEXT_CHECK_DATA()

zathura_error_t
zathura_annotation_text_init(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_TEXT_CHECK_TYPE()

  if (annotation->data.text != NULL) {
    free(annotation->data.text);
    annotation->data.text = NULL;
  }

  annotation->data.text = calloc(1, sizeof(zathura_annotation_text_t));
  if (annotation->data.text == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_text_clear(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_TEXT_CHECK_TYPE()

  if (annotation->data.text != NULL) {
    g_free(annotation->data.text->icon_name);
    free(annotation->data.text);
    annotation->data.text = NULL;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_text_set_icon_name(zathura_annotation_t*
    annotation, const char* icon_name)
{
  if (annotation == NULL || icon_name == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_TEXT_CHECK_TYPE_AND_DATA()

  if (annotation->data.text->icon_name != NULL) {
    g_free(annotation->data.text->icon_name);
  }

  annotation->data.text->icon_name = g_strdup(icon_name);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_text_get_icon_name(zathura_annotation_t*
    annotation, char** icon_name)
{
  if (annotation == NULL || icon_name == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_TEXT_CHECK_TYPE_AND_DATA()

  *icon_name = annotation->data.text->icon_name;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_text_set_open(zathura_annotation_t* annotation, bool is_open)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_TEXT_CHECK_TYPE_AND_DATA()

  annotation->data.text->is_open = is_open;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_text_is_open(zathura_annotation_t* annotation, bool* is_open)
{
  if (annotation == NULL || is_open == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_TEXT_CHECK_TYPE_AND_DATA()

  *is_open = annotation->data.text->is_open;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_text_set_state(zathura_annotation_t* annotation, zathura_annotation_text_state_t state)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_TEXT_CHECK_TYPE_AND_DATA()

  annotation->data.text->state = state;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_text_get_state(zathura_annotation_t* annotation, zathura_annotation_text_state_t* state)
{
  if (annotation == NULL || state == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_TEXT_CHECK_TYPE_AND_DATA()

  *state = annotation->data.text->state;

  return ZATHURA_ERROR_OK;
}

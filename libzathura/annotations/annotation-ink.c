/* See LICENSE file for license and copyright information */

#include <string.h>
#include <stdlib.h>

#include "annotation-ink.h"
#include "internal.h"
#include "internal/annotation-ink.h"

#define ANNOTATION_INK_CHECK_TYPE() \
  if (annotation->type != ZATHURA_ANNOTATION_INK) { \
    return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE; \
  }

#define ANNOTATION_INK_CHECK_DATA() \
  if (annotation->data.ink == NULL) { \
    return ZATHURA_ERROR_UNKNOWN; \
  }

#define ANNOTATION_INK_CHECK_TYPE_AND_DATA() \
  ANNOTATION_INK_CHECK_TYPE() \
  ANNOTATION_INK_CHECK_DATA()

zathura_error_t
zathura_annotation_ink_init(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_INK_CHECK_TYPE()

  if (annotation->data.ink != NULL) {
    free(annotation->data.ink);
    annotation->data.ink = NULL;
  }

  annotation->data.ink = calloc(1, sizeof(zathura_annotation_ink_t));
  if (annotation->data.ink == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_ink_clear(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_INK_CHECK_TYPE()

  if (annotation->data.ink != NULL) {
    zathura_list_free(annotation->data.ink->paths);
    free(annotation->data.ink);
    annotation->data.ink = NULL;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_ink_set_paths(zathura_annotation_t* annotation,
    zathura_list_t* paths)
{
  if (annotation == NULL || paths == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_INK_CHECK_TYPE_AND_DATA()

  annotation->data.ink->paths = paths;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_ink_get_paths(zathura_annotation_t* annotation,
    zathura_list_t** paths)
{
  if (annotation == NULL || paths == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_INK_CHECK_TYPE_AND_DATA()

  *paths = annotation->data.ink->paths;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_ink_set_border(zathura_annotation_t*
    annotation, zathura_annotation_border_t border)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_INK_CHECK_TYPE_AND_DATA()

  memcpy(&(annotation->data.ink->border), &border, sizeof(zathura_annotation_border_t));

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_ink_get_border(zathura_annotation_t*
    annotation, zathura_annotation_border_t* border)
{
  if (annotation == NULL || border == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_INK_CHECK_TYPE_AND_DATA()

  memcpy(border, &(annotation->data.ink->border), sizeof(zathura_annotation_border_t));

  return ZATHURA_ERROR_OK;
}

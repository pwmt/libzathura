/* See LICENSE file for license and copyright information */

#include <stdlib.h>
#include <stdio.h>

#include "annotation-caret.h"
#include "../annotations.h"
#include "internal.h"

#define ANNOTATION_CARET_CHECK_TYPE() \
  if (annotation->type != ZATHURA_ANNOTATION_CARET) { \
    return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE; \
  }

#define ANNOTATION_CARET_CHECK_DATA() \
  if (annotation->data.caret == NULL) { \
    return ZATHURA_ERROR_UNKNOWN; \
  }

#define ANNOTATION_CARET_CHECK_TYPE_AND_DATA() \
  ANNOTATION_CARET_CHECK_TYPE() \
  ANNOTATION_CARET_CHECK_DATA()

zathura_error_t
zathura_annotation_caret_init(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_CARET_CHECK_TYPE()

  if (annotation->data.caret != NULL) {
    free(annotation->data.caret);
  }

  annotation->data.caret = calloc(1, sizeof(zathura_annotation_caret_t));
  if (annotation->data.caret == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  annotation->data.caret->symbol = ZATHURA_ANNOTATION_CARET_SYMBOL_NONE;

  annotation->data.caret->padding.left   = 0;
  annotation->data.caret->padding.top    = 0;
  annotation->data.caret->padding.right  = 0;
  annotation->data.caret->padding.bottom = 0;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_caret_clear(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_CARET_CHECK_TYPE()

  free(annotation->data.caret);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_caret_get_symbol(zathura_annotation_t* annotation,
    zathura_annotation_caret_symbol_t* symbol)
{
  if (annotation == NULL || symbol == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_CARET_CHECK_TYPE_AND_DATA()

  *symbol = annotation->data.caret->symbol;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_caret_set_symbol(zathura_annotation_t* annotation,
    zathura_annotation_caret_symbol_t symbol)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  switch (symbol) {
    case ZATHURA_ANNOTATION_CARET_SYMBOL_NONE:
    case ZATHURA_ANNOTATION_CARET_SYMBOL_PARAGRAPH:
      break;
    default:
      return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_CARET_CHECK_TYPE_AND_DATA()

  annotation->data.caret->symbol = symbol;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_caret_get_padding(zathura_annotation_t* annotation,
    zathura_annotation_caret_padding_t* padding)
{
  if (annotation == NULL || padding == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_CARET_CHECK_TYPE_AND_DATA()

  padding->left   = annotation->data.caret->padding.left;
  padding->top    = annotation->data.caret->padding.top;
  padding->right  = annotation->data.caret->padding.right;
  padding->bottom = annotation->data.caret->padding.bottom;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_caret_set_padding(zathura_annotation_t* annotation,
    zathura_annotation_caret_padding_t padding)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_CARET_CHECK_TYPE_AND_DATA()

  annotation->data.caret->padding.left   = padding.left;
  annotation->data.caret->padding.top    = padding.top;
  annotation->data.caret->padding.right  = padding.right;
  annotation->data.caret->padding.bottom = padding.bottom;

  return ZATHURA_ERROR_OK;
}

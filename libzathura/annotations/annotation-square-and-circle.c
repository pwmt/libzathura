/* See LICENSE file for license and copyright information */

#include <stdlib.h>

#include "../annotations.h"
#include "annotation-caret.h"
#include "annotation-square.h"
#include "annotation-circle.h"
#include "internal/annotation-square-and-circle.h"
#include "internal.h"

#define ANNOTATION_SQUARE_AND_CIRCLE_CHECK_TYPE() \
  if (annotation->type != ZATHURA_ANNOTATION_SQUARE && \
      annotation->type != ZATHURA_ANNOTATION_CIRCLE ) { \
    return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE; \
  }

#define ANNOTATION_SQUARE_AND_CIRCLE_CHECK_DATA() \
  if (annotation->data.square_and_circle == NULL) { \
    return ZATHURA_ERROR_UNKNOWN; \
  }

#define ANNOTATION_SQUARE_AND_CIRCLE_CHECK_TYPE_AND_DATA() \
  ANNOTATION_SQUARE_AND_CIRCLE_CHECK_TYPE() \
  ANNOTATION_SQUARE_AND_CIRCLE_CHECK_DATA()

zathura_error_t
zathura_annotation_square_and_circle_init(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_SQUARE_AND_CIRCLE_CHECK_TYPE()

  if (annotation->data.square_and_circle != NULL) {
    free(annotation->data.square_and_circle);
  }

  annotation->data.square_and_circle = calloc(1, sizeof(zathura_annotation_square_and_circle_t));
  if (annotation->data.square_and_circle == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_square_and_circle_clear(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_SQUARE_AND_CIRCLE_CHECK_TYPE()

  free(annotation->data.square_and_circle);
  annotation->data.square_and_circle = NULL;

  return ZATHURA_ERROR_OK;
}

/* See LICENSE file for license and copyright information */

#include <string.h>
#include <stdlib.h>

#include "../internal.h"
#include "annotation-text-markup.h"

#define ANNOTATION_TEXT_MARKUP_CHECK_TYPE() \
  if (annotation->type != ZATHURA_ANNOTATION_HIGHLIGHT \
    && annotation->type != ZATHURA_ANNOTATION_SQUIGGLY \
    && annotation->type != ZATHURA_ANNOTATION_STRIKE_OUT \
    && annotation->type != ZATHURA_ANNOTATION_UNDERLINE \
  ) { \
    return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE; \
  }

#define ANNOTATION_TEXT_MARKUP_CHECK_DATA() \
  if (annotation->data.text_markup == NULL) { \
    return ZATHURA_ERROR_UNKNOWN; \
  }

#define ANNOTATION_TEXT_MARKUP_CHECK_TYPE_AND_DATA() \
  ANNOTATION_TEXT_MARKUP_CHECK_TYPE() \
  ANNOTATION_TEXT_MARKUP_CHECK_DATA()

zathura_error_t
zathura_annotation_text_markup_init(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_TEXT_MARKUP_CHECK_TYPE()

  if (annotation->data.text_markup != NULL) {
    free(annotation->data.text_markup);
    annotation->data.text_markup = NULL;
  }

  annotation->data.text_markup = calloc(1, sizeof(zathura_annotation_text_markup_t));
  if (annotation->data.text_markup == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_text_markup_clear(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_TEXT_MARKUP_CHECK_TYPE()

  if (annotation->data.text_markup != NULL) {
    free(annotation->data.text_markup);
    annotation->data.text_markup = NULL;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_text_markup_set_quad_points(zathura_annotation_t* annotation,
    zathura_list_t* quad_points)
{
  if (annotation == NULL || quad_points == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_TEXT_MARKUP_CHECK_TYPE()

  annotation->data.text_markup->quad_points = quad_points;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_text_markup_get_quad_points(zathura_annotation_t* annotation,
    zathura_list_t** quad_points)
{
  if (annotation == NULL || quad_points == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_TEXT_MARKUP_CHECK_TYPE()

  *quad_points = annotation->data.text_markup->quad_points;

  return ZATHURA_ERROR_OK;
}

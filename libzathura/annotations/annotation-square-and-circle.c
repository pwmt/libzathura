/* See LICENSE file for license and copyright information */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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

zathura_error_t
zathura_annotation_circle_set_rectangle(zathura_annotation_t*
    annotation, zathura_rectangle_t rectangle)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_SQUARE_AND_CIRCLE_CHECK_TYPE_AND_DATA()

  memcpy(&(annotation->data.square_and_circle->rectangle), &rectangle, sizeof(zathura_rectangle_t));

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_circle_get_rectangle(zathura_annotation_t*
    annotation, zathura_rectangle_t* rectangle)
{
  if (annotation == NULL || rectangle == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_SQUARE_AND_CIRCLE_CHECK_TYPE_AND_DATA()

  memcpy(rectangle, &(annotation->data.square_and_circle->rectangle), sizeof(zathura_rectangle_t));


  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_circle_set_color(zathura_annotation_t*
    annotation, zathura_annotation_color_t color)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_SQUARE_AND_CIRCLE_CHECK_TYPE_AND_DATA()

  memcpy(&(annotation->data.square_and_circle->color), &color, sizeof(zathura_annotation_color_t));

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_circle_get_color(zathura_annotation_t*
    annotation, zathura_annotation_color_t* color)
{
  if (annotation == NULL || color == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_SQUARE_AND_CIRCLE_CHECK_TYPE_AND_DATA()

  memcpy(color, &(annotation->data.square_and_circle->color), sizeof(zathura_annotation_color_t));

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_circle_set_border(zathura_annotation_t*
    annotation, zathura_annotation_border_t border)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_SQUARE_AND_CIRCLE_CHECK_TYPE_AND_DATA()

  memcpy(&(annotation->data.square_and_circle->border), &border, sizeof(zathura_annotation_border_t));

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_circle_get_border(zathura_annotation_t*
    annotation, zathura_annotation_border_t* border)
{
  if (annotation == NULL || border == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_SQUARE_AND_CIRCLE_CHECK_TYPE_AND_DATA()

  memcpy(border, &(annotation->data.square_and_circle->border), sizeof(zathura_annotation_border_t));

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_square_set_rectangle(zathura_annotation_t*
    annotation, zathura_rectangle_t rectangle)
{
  return zathura_annotation_circle_set_rectangle(annotation, rectangle);
}

zathura_error_t
zathura_annotation_square_get_rectangle(zathura_annotation_t*
    annotation, zathura_rectangle_t* rectangle)
{
  return zathura_annotation_circle_get_rectangle(annotation, rectangle);
}

zathura_error_t
zathura_annotation_square_set_color(zathura_annotation_t*
    annotation, zathura_annotation_color_t color)
{
  return zathura_annotation_circle_set_color(annotation, color);
}

zathura_error_t
zathura_annotation_square_get_color(zathura_annotation_t*
    annotation, zathura_annotation_color_t* color)
{
  return zathura_annotation_circle_get_color(annotation, color);
}

zathura_error_t
zathura_annotation_square_set_border(zathura_annotation_t*
    annotation, zathura_annotation_border_t border)
{
  return zathura_annotation_circle_set_border(annotation, border);
}

zathura_error_t
zathura_annotation_square_get_border(zathura_annotation_t*
    annotation, zathura_annotation_border_t* border)
{
  return zathura_annotation_circle_get_border(annotation, border);
}


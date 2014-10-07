/* See LICENSE file for license and copyright information */

#include <string.h>
#include <stdlib.h>

#include "annotation-polyline.h"
#include "internal.h"
#include "internal/annotation-polyline.h"

#define ANNOTATION_POLY_LINE_CHECK_TYPE() \
  if (annotation->type != ZATHURA_ANNOTATION_POLY_LINE) { \
    return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE; \
  }

#define ANNOTATION_POLY_LINE_CHECK_DATA() \
  if (annotation->data.poly_line == NULL) { \
    return ZATHURA_ERROR_UNKNOWN; \
  }

#define ANNOTATION_POLY_LINE_CHECK_TYPE_AND_DATA() \
  ANNOTATION_POLY_LINE_CHECK_TYPE() \
  ANNOTATION_POLY_LINE_CHECK_DATA()

zathura_error_t
zathura_annotation_poly_line_init(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_POLY_LINE_CHECK_TYPE()

  if (annotation->data.poly_line != NULL) {
    free(annotation->data.poly_line);
    annotation->data.poly_line = NULL;
  }

  annotation->data.poly_line = calloc(1, sizeof(zathura_annotation_poly_line_t));
  if (annotation->data.poly_line == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_poly_line_clear(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_POLY_LINE_CHECK_TYPE()

  if (annotation->data.poly_line != NULL) {
    free(annotation->data.poly_line);
    annotation->data.poly_line = NULL;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_poly_line_set_vertices(zathura_annotation_t* annotation,
    zathura_list_t* vertices)
{
  if (annotation == NULL || vertices == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_POLY_LINE_CHECK_TYPE_AND_DATA()

  annotation->data.poly_line->vertices = vertices;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_poly_line_get_vertices(zathura_annotation_t* annotation,
    zathura_list_t** vertices)
{
  if (annotation == NULL || vertices == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_POLY_LINE_CHECK_TYPE_AND_DATA()

  *vertices = annotation->data.poly_line->vertices;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_poly_line_set_line_ending(zathura_annotation_t*
    annotation, zathura_annotation_line_ending_t line_ending[2])
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_POLY_LINE_CHECK_TYPE_AND_DATA()

  annotation->data.poly_line->line_endings[0] = line_ending[0];
  annotation->data.poly_line->line_endings[1] = line_ending[1];

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_poly_line_get_line_ending(zathura_annotation_t*
    annotation, zathura_annotation_line_ending_t line_ending[2])
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_POLY_LINE_CHECK_TYPE_AND_DATA()

  line_ending[0] = annotation->data.poly_line->line_endings[0];
  line_ending[1] = annotation->data.poly_line->line_endings[1];

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_poly_line_set_borders(zathura_annotation_t* annotation,
    zathura_list_t* borders)
{
  if (annotation == NULL || borders == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_POLY_LINE_CHECK_TYPE_AND_DATA()

  annotation->data.poly_line->borders = borders;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_poly_line_get_borders(zathura_annotation_t* annotation,
    zathura_list_t** borders)
{
  if (annotation == NULL || borders == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_POLY_LINE_CHECK_TYPE_AND_DATA()

  *borders = annotation->data.poly_line->borders;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_poly_line_set_interior_color(zathura_annotation_t*
    annotation, zathura_annotation_color_t interior_color)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_POLY_LINE_CHECK_TYPE_AND_DATA()

  memcpy(&(annotation->data.poly_line->interior_color), &interior_color, sizeof(zathura_annotation_color_t));

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_poly_line_get_interior_color(zathura_annotation_t*
    annotation, zathura_annotation_color_t* interior_color)
{
  if (annotation == NULL || interior_color == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_POLY_LINE_CHECK_TYPE_AND_DATA()

  memcpy(interior_color, &(annotation->data.poly_line->interior_color), sizeof(zathura_annotation_color_t));

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_poly_line_set_intent(zathura_annotation_t*
    annotation, zathura_annotation_markup_intent_t intent)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_POLY_LINE_CHECK_TYPE_AND_DATA()

  annotation->data.poly_line->intent = intent;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_poly_line_get_intent(zathura_annotation_t*
    annotation, zathura_annotation_markup_intent_t* intent)
{
  if (annotation == NULL || intent == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_POLY_LINE_CHECK_TYPE_AND_DATA()

  *intent = annotation->data.poly_line->intent;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_poly_line_set_measure(zathura_annotation_t*
    annotation, zathura_annotation_measure_t* measure)
{
  if (annotation == NULL || measure == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_POLY_LINE_CHECK_TYPE_AND_DATA()

  annotation->data.poly_line->measure = measure;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_poly_line_get_measure(zathura_annotation_t*
    annotation, zathura_annotation_measure_t** measure)
{
  if (annotation == NULL || measure == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_POLY_LINE_CHECK_TYPE_AND_DATA()

  *measure = annotation->data.poly_line->measure;

  return ZATHURA_ERROR_OK;
}

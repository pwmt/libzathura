/* See LICENSE file for license and copyright information */

#include <string.h>
#include <stdlib.h>

#include "annotation-polygon.h"
#include "internal.h"
#include "internal/annotation-polygon.h"

#define ANNOTATION_POLYGON_CHECK_TYPE() \
  if (annotation->type != ZATHURA_ANNOTATION_POLYGON) { \
    return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE; \
  }

#define ANNOTATION_POLYGON_CHECK_DATA() \
  if (annotation->data.polygon == NULL) { \
    return ZATHURA_ERROR_UNKNOWN; \
  }

#define ANNOTATION_POLYGON_CHECK_TYPE_AND_DATA() \
  ANNOTATION_POLYGON_CHECK_TYPE() \
  ANNOTATION_POLYGON_CHECK_DATA()

zathura_error_t
zathura_annotation_polygon_init(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_POLYGON_CHECK_TYPE()

  if (annotation->data.polygon != NULL) {
    free(annotation->data.polygon);
    annotation->data.polygon = NULL;
  }

  annotation->data.polygon = calloc(1, sizeof(zathura_annotation_polygon_t));
  if (annotation->data.polygon == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_polygon_clear(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_POLYGON_CHECK_TYPE()

  if (annotation->data.polygon != NULL) {
    free(annotation->data.polygon);
    annotation->data.polygon = NULL;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_polygon_set_vertices(zathura_annotation_t* annotation,
    zathura_list_t* vertices)
{
  if (annotation == NULL || vertices == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_POLYGON_CHECK_TYPE_AND_DATA()

  annotation->data.polygon->vertices = vertices;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_polygon_get_vertices(zathura_annotation_t* annotation,
    zathura_list_t** vertices)
{
  if (annotation == NULL || vertices == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_POLYGON_CHECK_TYPE_AND_DATA()

  *vertices = annotation->data.polygon->vertices;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_polygon_set_border(zathura_annotation_t* annotation,
    zathura_annotation_border_t border)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_POLYGON_CHECK_TYPE_AND_DATA()

  annotation->data.polygon->border = border;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_polygon_get_border(zathura_annotation_t* annotation,
    zathura_annotation_border_t* border)
{
  if (annotation == NULL || border == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_POLYGON_CHECK_TYPE_AND_DATA()

  *border = annotation->data.polygon->border;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_polygon_set_interior_color(zathura_annotation_t*
    annotation, zathura_annotation_color_t interior_color)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_POLYGON_CHECK_TYPE_AND_DATA()

  memcpy(&(annotation->data.polygon->interior_color), &interior_color, sizeof(zathura_annotation_color_t));

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_polygon_get_interior_color(zathura_annotation_t*
    annotation, zathura_annotation_color_t* interior_color)
{
  if (annotation == NULL || interior_color == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_POLYGON_CHECK_TYPE_AND_DATA()

  memcpy(interior_color, &(annotation->data.polygon->interior_color), sizeof(zathura_annotation_color_t));

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_polygon_set_intent(zathura_annotation_t*
    annotation, zathura_annotation_markup_intent_t intent)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_POLYGON_CHECK_TYPE_AND_DATA()

  annotation->data.polygon->intent = intent;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_polygon_get_intent(zathura_annotation_t*
    annotation, zathura_annotation_markup_intent_t* intent)
{
  if (annotation == NULL || intent == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_POLYGON_CHECK_TYPE_AND_DATA()

  *intent = annotation->data.polygon->intent;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_polygon_set_measure(zathura_annotation_t*
    annotation, zathura_annotation_measure_t* measure)
{
  if (annotation == NULL || measure == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_POLYGON_CHECK_TYPE_AND_DATA()

  annotation->data.polygon->measure = measure;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_polygon_get_measure(zathura_annotation_t*
    annotation, zathura_annotation_measure_t** measure)
{
  if (annotation == NULL || measure == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_POLYGON_CHECK_TYPE_AND_DATA()

  *measure = annotation->data.polygon->measure;

  return ZATHURA_ERROR_OK;
}

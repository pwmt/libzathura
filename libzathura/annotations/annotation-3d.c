/* See LICENSE file for license and copyright information */

#include <string.h>
#include <stdlib.h>

#include "annotation-3d.h"
#include "internal.h"
#include "internal/annotation-3d.h"

#define ANNOTATION_3D_CHECK_TYPE() \
  if (annotation->type != ZATHURA_ANNOTATION_3D) { \
    return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE; \
  }

#define ANNOTATION_3D_CHECK_DATA() \
  if (annotation->data.d3d == NULL) { \
    return ZATHURA_ERROR_UNKNOWN; \
  }

#define ANNOTATION_3D_CHECK_TYPE_AND_DATA() \
  ANNOTATION_3D_CHECK_TYPE() \
  ANNOTATION_3D_CHECK_DATA()

zathura_error_t
zathura_annotation_3d_init(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_3D_CHECK_TYPE()

  if (annotation->data.d3d != NULL) {
    free(annotation->data.d3d);
    annotation->data.d3d = NULL;
  }

  annotation->data.d3d = calloc(1, sizeof(zathura_annotation_3d_t));
  if (annotation->data.d3d == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_3d_clear(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_3D_CHECK_TYPE()

  if (annotation->data.d3d != NULL) {
    free(annotation->data.d3d);
    annotation->data.d3d = NULL;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_3d_set_artwork(zathura_annotation_t* annotation,
    zathura_3d_t* artwork)
{
  if (annotation == NULL || artwork == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_3D_CHECK_TYPE_AND_DATA()

  annotation->data.d3d->artwork = artwork;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_3d_get_artwork(zathura_annotation_t* annotation,
    zathura_3d_t** artwork)
{
  if (annotation == NULL || artwork == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_3D_CHECK_TYPE_AND_DATA()

  *artwork = annotation->data.d3d->artwork;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_3d_set_view_box(zathura_annotation_t*
    annotation, zathura_rectangle_t view_box)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_3D_CHECK_TYPE_AND_DATA()

  memcpy(&(annotation->data.d3d->view_box), &view_box, sizeof(zathura_rectangle_t));

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_3d_get_view_box(zathura_annotation_t*
    annotation, zathura_rectangle_t* view_box)
{
  if (annotation == NULL || view_box == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  memcpy(view_box, &(annotation->data.d3d->view_box), sizeof(zathura_rectangle_t));

  ANNOTATION_3D_CHECK_TYPE_AND_DATA()

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_3d_set_interactive(zathura_annotation_t* annotation, bool is_interactive)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_3D_CHECK_TYPE_AND_DATA()

  annotation->data.d3d->is_interactive = is_interactive;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_3d_is_interactive(zathura_annotation_t* annotation, bool* is_interactive)
{
  if (annotation == NULL || is_interactive == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_3D_CHECK_TYPE_AND_DATA()

  *is_interactive = annotation->data.d3d->is_interactive;

  return ZATHURA_ERROR_OK;
}

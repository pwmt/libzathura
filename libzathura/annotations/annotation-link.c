/* See LICENSE file for license and copyright information */

#include <stdlib.h>

#include "annotation-link.h"
#include "../annotations.h"
#include "../list.h"
#include "internal.h"

#define ANNOTATION_LINK_CHECK_TYPE() \
  if (annotation->type != ZATHURA_ANNOTATION_LINK) { \
    return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE; \
  }

#define ANNOTATION_LINK_CHECK_DATA() \
  if (annotation->data.link == NULL) { \
    return ZATHURA_ERROR_UNKNOWN; \
  }

#define ANNOTATION_LINK_CHECK_TYPE_AND_DATA() \
  ANNOTATION_LINK_CHECK_TYPE() \
  ANNOTATION_LINK_CHECK_DATA()

zathura_error_t
zathura_annotation_link_init(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_LINK_CHECK_TYPE()

  if (annotation->data.link != NULL) {
    free(annotation->data.link);
  }

  annotation->data.link = calloc(1, sizeof(zathura_annotation_link_t));
  if (annotation->data.link == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  annotation->data.link->highlighting_mode = ZATHURA_ANNOTATION_HIGHLIGHTING_INVERT;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_link_clear(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_LINK_CHECK_TYPE()

  if (annotation->data.link != NULL) {
    free(annotation->data.link);
    annotation->data.link = NULL;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_link_set_action(zathura_annotation_t* annotation,
    zathura_action_t* action)
{
  if (annotation == NULL || action == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_LINK_CHECK_TYPE()

  annotation->data.link->action = action;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_link_get_action(zathura_annotation_t* annotation,
    zathura_action_t** action)
{
  if (annotation == NULL || action == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_LINK_CHECK_TYPE()

  *action = annotation->data.link->action;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_link_set_highlighting_mode(zathura_annotation_t* annotation,
    zathura_annotation_highlighting_mode_t mode)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_LINK_CHECK_TYPE()

  annotation->data.link->highlighting_mode = mode;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_link_get_highlighting_mode(zathura_annotation_t* annotation, zathura_annotation_highlighting_mode_t* mode)

{
  if (annotation == NULL || mode == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_LINK_CHECK_TYPE()

  *mode = annotation->data.link->highlighting_mode;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_link_set_quad_points(zathura_annotation_t* annotation, zathura_list_t* quad_points)
{
  if (annotation == NULL || quad_points == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_LINK_CHECK_TYPE()
  annotation->data.link->quad_points = quad_points;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_link_get_quad_points(zathura_annotation_t* annotation, zathura_list_t** quad_points)
{
  if (annotation == NULL || quad_points == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_LINK_CHECK_TYPE()

  *quad_points = annotation->data.link->quad_points;

  return ZATHURA_ERROR_OK;
}

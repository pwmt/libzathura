/* See LICENSE file for license and copyright information */

#include <stdlib.h>
#include <stdio.h>

#include "annotation-widget.h"
#include "../annotations.h"
#include "internal.h"

#define ANNOTATION_WIDGET_CHECK_TYPE() \
  if (annotation->type != ZATHURA_ANNOTATION_WIDGET) { \
    return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE; \
  }

#define ANNOTATION_WIDGET_CHECK_DATA() \
  if (annotation->data.widget == NULL) { \
    return ZATHURA_ERROR_UNKNOWN; \
  }

#define ANNOTATION_WIDGET_CHECK_TYPE_AND_DATA() \
  ANNOTATION_WIDGET_CHECK_TYPE() \
  ANNOTATION_WIDGET_CHECK_DATA()

zathura_error_t
zathura_annotation_widget_init(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_WIDGET_CHECK_TYPE()

  if (annotation->data.widget != NULL) {
    free(annotation->data.widget);
  }

  annotation->data.widget = calloc(1, sizeof(zathura_annotation_widget_t));
  if (annotation->data.widget == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_widget_clear(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_WIDGET_CHECK_TYPE()

  if (annotation->data.widget != NULL) {
    g_free(annotation->data.widget->caption);
    g_free(annotation->data.widget->rollover_caption);
    g_free(annotation->data.widget->alternate_caption);

    free(annotation->data.widget);
    annotation->data.widget = NULL;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_widget_set_form_field(zathura_annotation_t* annotation,
    zathura_form_field_t* form_field)
{
  if (annotation == NULL || form_field == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_WIDGET_CHECK_TYPE_AND_DATA()

  annotation->data.widget->form_field = form_field;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_widget_get_form_field(zathura_annotation_t* annotation,
    zathura_form_field_t** form_field)
{
  if (annotation == NULL || form_field == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_WIDGET_CHECK_TYPE_AND_DATA()

  *form_field = annotation->data.widget->form_field;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_widget_set_highlighting_mode(zathura_annotation_t* annotation,
    zathura_annotation_highlighting_mode_t highlighting_mode)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_WIDGET_CHECK_TYPE_AND_DATA()

  annotation->data.widget->highlighting_mode = highlighting_mode;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_widget_get_highlighting_mode(zathura_annotation_t*
    annotation, zathura_annotation_highlighting_mode_t* highlighting_mode)
{
  if (annotation == NULL || highlighting_mode == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_WIDGET_CHECK_TYPE_AND_DATA()

  *highlighting_mode = annotation->data.widget->highlighting_mode;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_widget_set_action(zathura_annotation_t* annotation,
    zathura_action_t* action)
{
  if (annotation == NULL || action == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_WIDGET_CHECK_TYPE_AND_DATA()

  annotation->data.widget->action = action;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_widget_get_action(zathura_annotation_t* annotation,
    zathura_action_t** action)
{
  if (annotation == NULL || action == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_WIDGET_CHECK_TYPE_AND_DATA()

  *action = annotation->data.widget->action;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_widget_set_additional_actions(zathura_annotation_t*
    annotation, zathura_list_t* additional_actions)
{
  if (annotation == NULL || additional_actions == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_WIDGET_CHECK_TYPE_AND_DATA()

  annotation->data.widget->additional_actions = additional_actions;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_widget_get_additional_actions(zathura_annotation_t*
    annotation, zathura_list_t** additional_actions)
{
  if (annotation == NULL || additional_actions == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_WIDGET_CHECK_TYPE_AND_DATA()

  *additional_actions = annotation->data.widget->additional_actions;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_widget_set_border(zathura_annotation_t*
    annotation, zathura_annotation_border_t border)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_WIDGET_CHECK_TYPE_AND_DATA()

  annotation->data.widget->border = border;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_widget_get_border(zathura_annotation_t*
    annotation, zathura_annotation_border_t* border)
{
  if (annotation == NULL || border == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_WIDGET_CHECK_TYPE_AND_DATA()

  *border = annotation->data.widget->border;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_widget_set_background_color(zathura_annotation_t*
    annotation, zathura_annotation_color_t background_color)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_WIDGET_CHECK_TYPE_AND_DATA()

  annotation->data.widget->background_color = background_color;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_widget_get_background_color(zathura_annotation_t*
    annotation, zathura_annotation_color_t* background_color)
{
  if (annotation == NULL || background_color == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_WIDGET_CHECK_TYPE_AND_DATA()

  *background_color = annotation->data.widget->background_color;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_widget_set_rotation(zathura_annotation_t*
    annotation, int rotation)
{
  if (annotation == NULL || rotation % 90 != 0) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_WIDGET_CHECK_TYPE_AND_DATA()

  annotation->data.widget->rotation = rotation;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_widget_get_rotation(zathura_annotation_t*
    annotation, int* rotation)
{
  if (annotation == NULL || rotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_WIDGET_CHECK_TYPE_AND_DATA()

  *rotation = annotation->data.widget->rotation;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_widget_set_caption(zathura_annotation_t*
    annotation, char* caption)
{
  if (annotation == NULL || caption == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_WIDGET_CHECK_TYPE_AND_DATA()

  if (annotation->data.widget->caption != NULL) {
    g_free(annotation->data.widget->caption);
  }

  annotation->data.widget->caption = g_strdup(caption);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_widget_get_caption(zathura_annotation_t*
    annotation, char** caption)
{
  if (annotation == NULL || caption == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_WIDGET_CHECK_TYPE_AND_DATA()

  *caption = annotation->data.widget->caption;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_widget_set_rollover_caption(zathura_annotation_t*
    annotation, char* rollover_caption)
{
  if (annotation == NULL || rollover_caption == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_WIDGET_CHECK_TYPE_AND_DATA()

  if (annotation->data.widget->rollover_caption != NULL) {
    g_free(annotation->data.widget->rollover_caption);
  }

  annotation->data.widget->rollover_caption = g_strdup(rollover_caption);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_widget_get_rollover_caption(zathura_annotation_t*
    annotation, char** rollover_caption)
{
  if (annotation == NULL || rollover_caption == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_WIDGET_CHECK_TYPE_AND_DATA()

  *rollover_caption = annotation->data.widget->rollover_caption;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_widget_set_alternate_caption(zathura_annotation_t*
    annotation, char* alternate_caption)
{
  if (annotation == NULL || alternate_caption == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_WIDGET_CHECK_TYPE_AND_DATA()

  if (annotation->data.widget->alternate_caption != NULL) {
    g_free(annotation->data.widget->alternate_caption);
  }

  annotation->data.widget->alternate_caption = g_strdup(alternate_caption);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_widget_get_alternate_caption(zathura_annotation_t*
    annotation, char** alternate_caption)
{
  if (annotation == NULL || alternate_caption == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_WIDGET_CHECK_TYPE_AND_DATA()

  *alternate_caption = annotation->data.widget->alternate_caption;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_widget_set_caption_position(zathura_annotation_t*
    annotation, zathura_annotation_widget_caption_position_t caption_position)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_WIDGET_CHECK_TYPE_AND_DATA()

  annotation->data.widget->caption_position = caption_position;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_widget_get_caption_position(zathura_annotation_t*
    annotation, zathura_annotation_widget_caption_position_t* caption_position)
{
  if (annotation == NULL || caption_position == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_WIDGET_CHECK_TYPE_AND_DATA()

  *caption_position = annotation->data.widget->caption_position;

  return ZATHURA_ERROR_OK;
}

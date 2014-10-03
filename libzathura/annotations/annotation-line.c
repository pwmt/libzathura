/* See LICENSE file for license and copyright information */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "../types.h"

#include "color.h"
#include "border.h"
#include "annotation-line.h"
#include "annotation-markup.h"
#include "internal.h"

#define ANNOTATION_LINE_CHECK_TYPE() \
  if (annotation->type != ZATHURA_ANNOTATION_LINE) { \
    return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE; \
  }

#define ANNOTATION_LINE_CHECK_DATA() \
  if (annotation->data.line == NULL) { \
    return ZATHURA_ERROR_UNKNOWN; \
  }

#define ANNOTATION_LINE_CHECK_TYPE_AND_DATA() \
  ANNOTATION_LINE_CHECK_TYPE() \
  ANNOTATION_LINE_CHECK_DATA()

zathura_error_t
zathura_annotation_line_init(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_LINE_CHECK_TYPE()

  if (annotation->data.line != NULL) {
    free(annotation->data.line);
    annotation->data.line = NULL;
  }

  annotation->data.line = calloc(1, sizeof(zathura_annotation_line_t));
  if (annotation->data.line == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_line_clear(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_LINE_CHECK_TYPE()

  free(annotation->data.line);
  annotation->data.line = NULL;

  return ZATHURA_ERROR_OK;
}

zathura_error_t zathura_annotation_line_set_coordinates(zathura_annotation_t*
    annotation, zathura_point_t coordinates[2])
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_LINE_CHECK_TYPE_AND_DATA()

  annotation->data.line->coordinates.start = coordinates[0];
  annotation->data.line->coordinates.end   = coordinates[1];

  return ZATHURA_ERROR_OK;
}

zathura_error_t zathura_annotation_line_get_coordinates(zathura_annotation_t*
    annotation, zathura_point_t coordinates[2])
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_LINE_CHECK_TYPE_AND_DATA()

  coordinates[0] = annotation->data.line->coordinates.start;
  coordinates[1] = annotation->data.line->coordinates.end;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_line_set_border(zathura_annotation_t*
    annotation, zathura_annotation_border_t border)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_LINE_CHECK_TYPE_AND_DATA()

  memcpy(&(annotation->data.line->border), &border, sizeof(zathura_annotation_border_t));

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_line_get_border(zathura_annotation_t*
    annotation, zathura_annotation_border_t* border)
{
  if (annotation == NULL || border == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_LINE_CHECK_TYPE_AND_DATA()

  memcpy(border, &(annotation->data.line->border), sizeof(zathura_annotation_border_t));

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_line_set_line_ending(zathura_annotation_t*
    annotation, zathura_annotation_line_ending_t line_ending[2])
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_LINE_CHECK_TYPE_AND_DATA()

  annotation->data.line->line_endings[0] = line_ending[0];
  annotation->data.line->line_endings[1] = line_ending[1];

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_line_get_line_ending(zathura_annotation_t*
    annotation, zathura_annotation_line_ending_t line_ending[2])
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_LINE_CHECK_TYPE_AND_DATA()

  line_ending[0] = annotation->data.line->line_endings[0];
  line_ending[1] = annotation->data.line->line_endings[1];

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_line_set_color(zathura_annotation_t*
    annotation, zathura_annotation_color_t color)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_LINE_CHECK_TYPE_AND_DATA()

  memcpy(&(annotation->data.line->color), &color, sizeof(zathura_annotation_color_t));

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_line_get_color(zathura_annotation_t*
    annotation, zathura_annotation_color_t* color)
{
  if (annotation == NULL || color == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_LINE_CHECK_TYPE_AND_DATA()

  memcpy(color, &(annotation->data.line->color), sizeof(zathura_annotation_color_t));

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_line_set_leader_lines_length(zathura_annotation_t*
    annotation, int leader_lines_length)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_LINE_CHECK_TYPE_AND_DATA()

  annotation->data.line->leader_lines_length = leader_lines_length;
  
  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_line_get_leader_lines_length(zathura_annotation_t*
    annotation, int* leader_lines_length)
{
  if (annotation == NULL || leader_lines_length == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_LINE_CHECK_TYPE_AND_DATA()

  *leader_lines_length = annotation->data.line->leader_lines_length;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_line_set_leader_line_extensions_length(zathura_annotation_t*
    annotation, unsigned int leader_line_extensions_length)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_LINE_CHECK_TYPE_AND_DATA()

  annotation->data.line->leader_line_extensions_length = leader_line_extensions_length;
  
  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_line_get_leader_line_extensions_length(zathura_annotation_t*
    annotation, unsigned int* leader_line_extensions_length)
{
  if (annotation == NULL || leader_line_extensions_length == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_LINE_CHECK_TYPE_AND_DATA()

  *leader_line_extensions_length = annotation->data.line->leader_line_extensions_length;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_line_set_leader_line_offset(zathura_annotation_t*
    annotation, unsigned int leader_line_offset)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_LINE_CHECK_TYPE_AND_DATA()

  annotation->data.line->leader_line_offset = leader_line_offset;
  
  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_line_get_leader_line_offset(zathura_annotation_t*
    annotation, unsigned int* leader_line_offset)
{
  if (annotation == NULL || leader_line_offset == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_LINE_CHECK_TYPE_AND_DATA()

  *leader_line_offset = annotation->data.line->leader_line_offset;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_line_set_caption(zathura_annotation_t* annotation, bool has_caption)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_LINE_CHECK_TYPE_AND_DATA()

  annotation->data.line->has_caption = has_caption;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_line_has_caption(zathura_annotation_t* annotation, bool* has_caption)
{
  if (annotation == NULL || has_caption == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_LINE_CHECK_TYPE_AND_DATA()

  *has_caption = annotation->data.line->has_caption;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_line_set_intent(zathura_annotation_t*
    annotation, zathura_annotation_markup_intent_t intent)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_LINE_CHECK_TYPE_AND_DATA()

  annotation->data.line->intent = intent;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_line_get_intent(zathura_annotation_t*
    annotation, zathura_annotation_markup_intent_t* intent)
{
  if (annotation == NULL || intent == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_LINE_CHECK_TYPE_AND_DATA()

  *intent = annotation->data.line->intent;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_line_set_caption_position(zathura_annotation_t*
    annotation, zathura_annotation_line_caption_position_t caption_position)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_LINE_CHECK_TYPE_AND_DATA()

  annotation->data.line->caption_position = caption_position;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_line_get_caption_position(zathura_annotation_t*
    annotation, zathura_annotation_line_caption_position_t* caption_position)
{
  if (annotation == NULL || caption_position == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_LINE_CHECK_TYPE_AND_DATA()

  *caption_position = annotation->data.line->caption_position;

  return ZATHURA_ERROR_OK;
}

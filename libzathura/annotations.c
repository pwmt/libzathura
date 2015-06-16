/* See LICENSE file for license and copyright information */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "annotations.h"
#include "annotations/internal.h"

zathura_error_t
zathura_annotation_new(zathura_annotation_t** annotation, zathura_annotation_type_t type)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *annotation = calloc(1, sizeof(**annotation));
  if (*annotation == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  switch (type) {
      case ZATHURA_ANNOTATION_UNKNOWN:
      case ZATHURA_ANNOTATION_TEXT:
      case ZATHURA_ANNOTATION_LINK:
      case ZATHURA_ANNOTATION_FREE_TEXT:
      case ZATHURA_ANNOTATION_LINE:
      case ZATHURA_ANNOTATION_SQUARE:
      case ZATHURA_ANNOTATION_CIRCLE:
      case ZATHURA_ANNOTATION_POLYGON:
      case ZATHURA_ANNOTATION_POLY_LINE:
      case ZATHURA_ANNOTATION_HIGHLIGHT:
      case ZATHURA_ANNOTATION_UNDERLINE:
      case ZATHURA_ANNOTATION_SQUIGGLY:
      case ZATHURA_ANNOTATION_STRIKE_OUT:
      case ZATHURA_ANNOTATION_STAMP:
      case ZATHURA_ANNOTATION_CARET:
      case ZATHURA_ANNOTATION_INK:
      case ZATHURA_ANNOTATION_POPUP:
      case ZATHURA_ANNOTATION_FILE_ATTACHMENT:
      case ZATHURA_ANNOTATION_SOUND:
      case ZATHURA_ANNOTATION_MOVIE:
      case ZATHURA_ANNOTATION_WIDGET:
      case ZATHURA_ANNOTATION_SCREEN:
      case ZATHURA_ANNOTATION_PRINTER_MARK:
      case ZATHURA_ANNOTATION_TRAP_NET:
      case ZATHURA_ANNOTATION_WATERMARK:
      case ZATHURA_ANNOTATION_3D:
      break;
    default:
      free(*annotation);
      return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  (*annotation)->type = type;

  /* Initialize sub types */
  zathura_error_t error = ZATHURA_ERROR_OK;

  switch (type) {
    case ZATHURA_ANNOTATION_UNKNOWN:
      break;
    case ZATHURA_ANNOTATION_TEXT:
      error = zathura_annotation_text_init(*annotation);
      break;
    case ZATHURA_ANNOTATION_LINK:
      error = zathura_annotation_link_init(*annotation);
      break;
    case ZATHURA_ANNOTATION_FREE_TEXT:
      error = zathura_annotation_free_text_init(*annotation);
      break;
    case ZATHURA_ANNOTATION_LINE:
      error = zathura_annotation_line_init(*annotation);
      break;
    case ZATHURA_ANNOTATION_SQUARE:
    case ZATHURA_ANNOTATION_CIRCLE:
      error = zathura_annotation_square_and_circle_init(*annotation);
      break;
    case ZATHURA_ANNOTATION_POLYGON:
      error = zathura_annotation_polygon_init(*annotation);
      break;
    case ZATHURA_ANNOTATION_POLY_LINE:
      error = zathura_annotation_poly_line_init(*annotation);
      break;
    case ZATHURA_ANNOTATION_HIGHLIGHT:
    case ZATHURA_ANNOTATION_UNDERLINE:
    case ZATHURA_ANNOTATION_SQUIGGLY:
    case ZATHURA_ANNOTATION_STRIKE_OUT:
      error = zathura_annotation_text_markup_init(*annotation);
      break;
    case ZATHURA_ANNOTATION_STAMP:
      error = zathura_annotation_stamp_init(*annotation);
      break;
    case ZATHURA_ANNOTATION_CARET:
      error = zathura_annotation_caret_init(*annotation);
      break;
    case ZATHURA_ANNOTATION_INK:
      error = zathura_annotation_ink_init(*annotation);
      break;
    case ZATHURA_ANNOTATION_POPUP:
      error = zathura_annotation_popup_init(*annotation);
      break;
    case ZATHURA_ANNOTATION_FILE_ATTACHMENT:
      error = zathura_annotation_file_init(*annotation);
      break;
    case ZATHURA_ANNOTATION_SOUND:
      error = zathura_annotation_sound_init(*annotation);
      break;
    case ZATHURA_ANNOTATION_MOVIE:
      error = zathura_annotation_movie_init(*annotation);
      break;
    case ZATHURA_ANNOTATION_WIDGET:
      error = zathura_annotation_widget_init(*annotation);
      break;
    case ZATHURA_ANNOTATION_SCREEN:
      error = zathura_annotation_screen_init(*annotation);
      break;
    case ZATHURA_ANNOTATION_PRINTER_MARK:
      error = zathura_annotation_printer_mark_init(*annotation);
      break;
    case ZATHURA_ANNOTATION_TRAP_NET:
      break;
    case ZATHURA_ANNOTATION_WATERMARK:
      break;
    case ZATHURA_ANNOTATION_3D:
      error = zathura_annotation_3d_init(*annotation);
      break;
  }

  bool is_markup_annotation = false;
  if (error == ZATHURA_ERROR_OK &&
      zathura_annotation_is_markup_annotation(*annotation, &is_markup_annotation) == ZATHURA_ERROR_OK && is_markup_annotation == true) {
    zathura_annotation_markup_init(*annotation);
  }

  if (error != ZATHURA_ERROR_OK) {
    free(*annotation);
    return error;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_free(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  zathura_error_t error = ZATHURA_ERROR_OK;

  switch (annotation->type) {
      case ZATHURA_ANNOTATION_UNKNOWN:
        break;
      case ZATHURA_ANNOTATION_TEXT:
        error = zathura_annotation_text_clear(annotation);
        break;
      case ZATHURA_ANNOTATION_LINK:
        error = zathura_annotation_link_clear(annotation);
        break;
      case ZATHURA_ANNOTATION_FREE_TEXT:
        error = zathura_annotation_free_text_clear(annotation);
        break;
      case ZATHURA_ANNOTATION_LINE:
        error = zathura_annotation_line_clear(annotation);
        break;
      case ZATHURA_ANNOTATION_SQUARE:
      case ZATHURA_ANNOTATION_CIRCLE:
        error = zathura_annotation_square_and_circle_clear(annotation);
        break;
      case ZATHURA_ANNOTATION_POLYGON:
        error = zathura_annotation_polygon_clear(annotation);
        break;
      case ZATHURA_ANNOTATION_POLY_LINE:
        error = zathura_annotation_poly_line_clear(annotation);
        break;
      case ZATHURA_ANNOTATION_HIGHLIGHT:
      case ZATHURA_ANNOTATION_UNDERLINE:
      case ZATHURA_ANNOTATION_SQUIGGLY:
      case ZATHURA_ANNOTATION_STRIKE_OUT:
        error = zathura_annotation_text_markup_clear(annotation);
        break;
      case ZATHURA_ANNOTATION_STAMP:
        error = zathura_annotation_stamp_clear(annotation);
        break;
      case ZATHURA_ANNOTATION_CARET:
        error = zathura_annotation_caret_clear(annotation);
        break;
      case ZATHURA_ANNOTATION_INK:
        error = zathura_annotation_ink_clear(annotation);
        break;
      case ZATHURA_ANNOTATION_POPUP:
        error = zathura_annotation_popup_clear(annotation);
        break;
      case ZATHURA_ANNOTATION_FILE_ATTACHMENT:
        error = zathura_annotation_file_clear(annotation);
        break;
      case ZATHURA_ANNOTATION_SOUND:
        error = zathura_annotation_sound_clear(annotation);
        break;
      case ZATHURA_ANNOTATION_MOVIE:
        error = zathura_annotation_movie_clear(annotation);
        break;
      case ZATHURA_ANNOTATION_WIDGET:
        error = zathura_annotation_widget_clear(annotation);
        break;
      case ZATHURA_ANNOTATION_SCREEN:
        error = zathura_annotation_screen_clear(annotation);
        break;
      case ZATHURA_ANNOTATION_PRINTER_MARK:
        error = zathura_annotation_printer_mark_clear(annotation);
        break;
      case ZATHURA_ANNOTATION_TRAP_NET:
      case ZATHURA_ANNOTATION_WATERMARK:
        break;
      case ZATHURA_ANNOTATION_3D:
        error = zathura_annotation_3d_clear(annotation);
        break;
      default:
        error = ZATHURA_ERROR_INVALID_ARGUMENTS;
        break;
  }

  bool is_markup_annotation = false;
  if (error == ZATHURA_ERROR_OK &&
      zathura_annotation_is_markup_annotation(annotation, &is_markup_annotation) == ZATHURA_ERROR_OK) {
      if (is_markup_annotation == true) {
        error = zathura_annotation_markup_clear(annotation);
      }
  }

  if (annotation->name != NULL) {
    free(annotation->name);
  }

  if (annotation->content != NULL) {
    free(annotation->content);
  }

  free(annotation);

  if (error != ZATHURA_ERROR_OK) {
    return error;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_get_type(zathura_annotation_t* annotation, zathura_annotation_type_t* type)
{
  if (annotation == NULL || type == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *type = annotation->type;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_set_position(zathura_annotation_t* annotation,
    zathura_rectangle_t position)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  annotation->position = position;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_get_position(zathura_annotation_t* annotation,
    zathura_rectangle_t* position)
{
  if (annotation == NULL || position == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *position = annotation->position;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_set_content(zathura_annotation_t* annotation,
    const char* content)
{
  if (annotation == NULL || content == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  if (annotation->content != NULL) {
    g_free(annotation->content);
  }

  annotation->content = g_strdup(content);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_get_content(zathura_annotation_t* annotation,
    char** content)
{
  if (annotation == NULL || content == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *content = annotation->content;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_set_name(zathura_annotation_t* annotation,
    const char* name)
{
  if (annotation == NULL || name == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  if (annotation->name != NULL) {
    g_free(annotation->name);
  }

  annotation->name = g_strdup(name);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_get_name(zathura_annotation_t* annotation,
    char** name)
{
  if (annotation == NULL || name == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *name = annotation->name;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_set_modification_date(zathura_annotation_t*
    annotation, time_t modification_date)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  annotation->modification_date = modification_date;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_get_modification_date(zathura_annotation_t*
    annotation, time_t* modification_date)
{
  if (annotation == NULL || modification_date == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *modification_date = annotation->modification_date;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_set_flags(zathura_annotation_t* annotation,
    zathura_annotation_flag_t flags)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  annotation->flags = flags;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_get_flags(zathura_annotation_t* annotation,
    zathura_annotation_flag_t* flags)
{
  if (annotation == NULL || flags == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *flags = annotation->flags;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_set_color(zathura_annotation_t* annotation,
    zathura_annotation_color_t color)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  annotation->color = color;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_get_color(zathura_annotation_t* annotation,
    zathura_annotation_color_t* color)
{
  if (annotation == NULL || color == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *color = annotation->color;

  return ZATHURA_ERROR_OK;
}

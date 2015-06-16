/* See LICENSE file for license and copyright information */

#include <stdlib.h>

#include "../annotations.h"
#include "internal.h"
#include "internal/annotation-markup.h"

static int
check_if_markup_annotation(zathura_annotation_t* annotation)
{
  switch (annotation->type) {
    case ZATHURA_ANNOTATION_UNKNOWN:
    case ZATHURA_ANNOTATION_LINK:
    case ZATHURA_ANNOTATION_POPUP:
    case ZATHURA_ANNOTATION_MOVIE:
    case ZATHURA_ANNOTATION_WIDGET:
    case ZATHURA_ANNOTATION_SCREEN:
    case ZATHURA_ANNOTATION_PRINTER_MARK:
    case ZATHURA_ANNOTATION_TRAP_NET:
    case ZATHURA_ANNOTATION_WATERMARK:
    case ZATHURA_ANNOTATION_3D:
      return 1;
    case ZATHURA_ANNOTATION_TEXT:
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
    case ZATHURA_ANNOTATION_FILE_ATTACHMENT:
    case ZATHURA_ANNOTATION_SOUND:
      return 0;
    default:
      return -1;
  }
}

#define ANNOTATION_MARKUP_CHECK_TYPE() \
  if (check_if_markup_annotation(annotation) != 0) { \
    return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE; \
  }

#define ANNOTATION_MARKUP_CHECK_DATA() \
  if (annotation->markup == NULL) { \
    return ZATHURA_ERROR_UNKNOWN; \
  }

#define ANNOTATION_MARKUP_CHECK_TYPE_AND_DATA() \
  ANNOTATION_MARKUP_CHECK_TYPE() \
  ANNOTATION_MARKUP_CHECK_DATA()

zathura_error_t
zathura_annotation_is_markup_annotation(zathura_annotation_t* annotation, bool*
    is_markup_annotation)
{
  if (annotation == NULL || is_markup_annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }
  
  int result = check_if_markup_annotation(annotation);
  if (result == -1) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  } else if (result == 1) {
    *is_markup_annotation = false;
  } else {
    *is_markup_annotation = true;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_markup_init(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_MARKUP_CHECK_TYPE()

  if (annotation->markup != NULL) {
    free(annotation->markup);
    annotation->markup = NULL;
  }

  annotation->markup = calloc(1, sizeof(zathura_annotation_markup_t));
  if (annotation->markup == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  annotation->markup->opacity = 1.0;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_markup_clear(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_MARKUP_CHECK_TYPE()

  if (annotation->markup != NULL) {
    g_free(annotation->markup->label);
    g_free(annotation->markup->text);

    free(annotation->markup);
    annotation->markup = NULL;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t zathura_annotation_markup_set_label(zathura_annotation_t*
    annotation, char* label)
{
  if (annotation == NULL || label == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_MARKUP_CHECK_TYPE_AND_DATA()

  if (annotation->markup->label != NULL) {
    g_free(annotation->markup->label);
  }

  annotation->markup->label = g_strdup(label);

  return ZATHURA_ERROR_OK;
}

zathura_error_t zathura_annotation_markup_get_label(zathura_annotation_t*
    annotation, char** label)
{
  if (annotation == NULL || label == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_MARKUP_CHECK_TYPE_AND_DATA()

  *label = annotation->markup->label;

  return ZATHURA_ERROR_OK;
}

zathura_error_t zathura_annotation_markup_set_opacity(zathura_annotation_t*
    annotation, double opacity)
{
  if (annotation == NULL || opacity < 0.0 || opacity > 1.0) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_MARKUP_CHECK_TYPE_AND_DATA()

  annotation->markup->opacity = opacity;

  return ZATHURA_ERROR_OK;
}

zathura_error_t zathura_annotation_markup_get_opacity(zathura_annotation_t*
    annotation, double* opacity)
{
  if (annotation == NULL || opacity == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_MARKUP_CHECK_TYPE_AND_DATA()

  *opacity = annotation->markup->opacity;

  return ZATHURA_ERROR_OK;
}

zathura_error_t zathura_annotation_markup_set_popup_annotation(zathura_annotation_t* annotation, zathura_annotation_t* popup_annotation)
{
  if (annotation == NULL || popup_annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_MARKUP_CHECK_TYPE_AND_DATA()

  annotation->markup->popup_annotation = popup_annotation;

  return ZATHURA_ERROR_OK;
}

zathura_error_t zathura_annotation_markup_get_popup_annotation(zathura_annotation_t* annotation, zathura_annotation_t** popup_annotation)
{
  if (annotation == NULL || popup_annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_MARKUP_CHECK_TYPE_AND_DATA()

  *popup_annotation = annotation->markup->popup_annotation;

  return ZATHURA_ERROR_OK;
}

zathura_error_t zathura_annotation_markup_set_text(zathura_annotation_t*
    annotation, char* text)
{
  if (annotation == NULL || text == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_MARKUP_CHECK_TYPE_AND_DATA()

  if (annotation->markup->text != NULL) {
    g_free(annotation->markup->text);
  }

  annotation->markup->text = g_strdup(text);

  return ZATHURA_ERROR_OK;
}

zathura_error_t zathura_annotation_markup_get_text(zathura_annotation_t*
    annotation, char** text)
{
  if (annotation == NULL || text == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_MARKUP_CHECK_TYPE_AND_DATA()

  *text = annotation->markup->text;

  return ZATHURA_ERROR_OK;
}

zathura_error_t zathura_annotation_markup_set_creation_date(zathura_annotation_t*
    annotation, time_t creation_date)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_MARKUP_CHECK_TYPE_AND_DATA()

  annotation->markup->creation_date = creation_date;

  return ZATHURA_ERROR_OK;
}

zathura_error_t zathura_annotation_markup_get_creation_date(zathura_annotation_t*
    annotation, time_t* creation_date)
{
  if (annotation == NULL || creation_date == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_MARKUP_CHECK_TYPE_AND_DATA()

  *creation_date = annotation->markup->creation_date;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_markup_set_reply_to_annotation(zathura_annotation_t*
    annotation, zathura_annotation_t* reply_to_annotation)
{
  if (annotation == NULL || reply_to_annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_MARKUP_CHECK_TYPE_AND_DATA()

  annotation->markup->reply_to_annotation = reply_to_annotation;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_markup_get_reply_to_annotation(zathura_annotation_t*
    annotation, zathura_annotation_t** reply_to_annotation)
{
  if (annotation == NULL || reply_to_annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_MARKUP_CHECK_TYPE_AND_DATA()

  *reply_to_annotation = annotation->markup->reply_to_annotation;

  return ZATHURA_ERROR_OK;
}

zathura_error_t zathura_annotation_markup_set_reply_type(zathura_annotation_t* annotation,
    zathura_annotation_markup_reply_type_t reply_type)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_MARKUP_CHECK_TYPE_AND_DATA()

  annotation->markup->reply_type = reply_type;

  return ZATHURA_ERROR_OK;
}

zathura_error_t zathura_annotation_markup_get_reply_type(zathura_annotation_t* annotation,
    zathura_annotation_markup_reply_type_t* reply_type)
{
  if (annotation == NULL || reply_type == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_MARKUP_CHECK_TYPE_AND_DATA()

  *reply_type = annotation->markup->reply_type;

  return ZATHURA_ERROR_OK;
}

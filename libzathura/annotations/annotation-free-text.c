/* See LICENSE file for license and copyright information */

#include <stdlib.h>

#include "../annotations.h"
#include "../macros.h"
#include "annotation-free-text.h"
#include "annotation-markup.h"
#include "annotation-line.h"
#include "border.h"
#include "internal.h"
#include "internal/annotation-free-text.h"

#define ANNOTATION_FREE_TEXT_CHECK_TYPE() \
  if (annotation->type != ZATHURA_ANNOTATION_FREE_TEXT) { \
    return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE; \
  }

#define ANNOTATION_FREE_TEXT_CHECK_DATA() \
  if (annotation->data.free_text == NULL) { \
    return ZATHURA_ERROR_UNKNOWN; \
  }

#define ANNOTATION_FREE_TEXT_CHECK_TYPE_AND_DATA() \
  ANNOTATION_FREE_TEXT_CHECK_TYPE() \
  ANNOTATION_FREE_TEXT_CHECK_DATA()

zathura_error_t
zathura_annotation_free_text_init(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_FREE_TEXT_CHECK_TYPE()

  if (annotation->data.free_text != NULL) {
    free(annotation->data.free_text);
    annotation->data.free_text = NULL;
  }

  annotation->data.free_text = calloc(1, sizeof(zathura_annotation_free_text_t));
  if (annotation->data.free_text == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_free_text_clear(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_FREE_TEXT_CHECK_TYPE()

  if (annotation->data.free_text != NULL) {
    free(annotation->data.free_text->text);
    annotation->data.free_text->text = NULL;

    free(annotation->data.free_text->rich_text);
    annotation->data.free_text->rich_text = NULL;

    free(annotation->data.free_text);
    annotation->data.free_text = NULL;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_free_text_set_text(zathura_annotation_t*
    annotation, const char* text)
{
  if (annotation == NULL || text == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_FREE_TEXT_CHECK_TYPE_AND_DATA()

  if (annotation->data.free_text->text != NULL) {
    free(annotation->data.free_text->text);
  }

  annotation->data.free_text->text = g_strdup(text);
  if (annotation->data.free_text->text == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_free_text_get_text(zathura_annotation_t*
    annotation, char** text)
{
  if (annotation == NULL || text == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_FREE_TEXT_CHECK_TYPE_AND_DATA()

  if (annotation->data.free_text->text == NULL) {
    *text = "";
  } else {
    *text = annotation->data.free_text->text;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_free_text_set_justification(zathura_annotation_t*
    annotation, zathura_annotation_justification_t UNUSED(justification))
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_FREE_TEXT_CHECK_TYPE_AND_DATA()

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_free_text_get_justification(zathura_annotation_t*
    annotation, zathura_annotation_justification_t* justification)
{
  if (annotation == NULL || justification == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_FREE_TEXT_CHECK_TYPE_AND_DATA()

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_free_text_set_rich_text(zathura_annotation_t*
    annotation, const char* rich_text)
{
  if (annotation == NULL || rich_text == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_FREE_TEXT_CHECK_TYPE_AND_DATA()

  if (annotation->data.free_text->rich_text != NULL) {
    free(annotation->data.free_text->rich_text);
  }

  annotation->data.free_text->rich_text = g_strdup(rich_text);
  if (annotation->data.free_text->rich_text == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_free_text_get_rich_text(zathura_annotation_t*
    annotation, char** rich_text)
{
  if (annotation == NULL || rich_text == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_FREE_TEXT_CHECK_TYPE_AND_DATA()

  if (annotation->data.free_text->rich_text == NULL) {
    *rich_text = "";
  } else {
    *rich_text = annotation->data.free_text->rich_text;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_free_text_set_style_string(zathura_annotation_t*
    annotation, const char* style_string)
{
  if (annotation == NULL || style_string == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_FREE_TEXT_CHECK_TYPE_AND_DATA()

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_free_text_get_style_string(zathura_annotation_t*
    annotation, char** style_string)
{
  if (annotation == NULL || style_string == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_FREE_TEXT_CHECK_TYPE_AND_DATA()

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_free_text_set_callout_line(zathura_annotation_t*
    annotation, zathura_annotation_callout_line_t UNUSED(callout_line))
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_FREE_TEXT_CHECK_TYPE_AND_DATA()

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_free_text_get_callout_line(zathura_annotation_t*
    annotation, zathura_annotation_callout_line_t* callout_line)
{
  if (annotation == NULL || callout_line == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_FREE_TEXT_CHECK_TYPE_AND_DATA()

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_free_text_set_border(zathura_annotation_t*
    annotation, zathura_annotation_border_t UNUSED(border))
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_FREE_TEXT_CHECK_TYPE_AND_DATA()

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_free_text_get_border(zathura_annotation_t*
    annotation, zathura_annotation_border_t* border)
{
  if (annotation == NULL || border == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_FREE_TEXT_CHECK_TYPE_AND_DATA()

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_free_text_set_intent(zathura_annotation_t*
    annotation, zathura_annotation_markup_intent_t UNUSED(intent))
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_FREE_TEXT_CHECK_TYPE_AND_DATA()

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_free_text_get_intent(zathura_annotation_t*
    annotation, zathura_annotation_markup_intent_t* intent)
{
  if (annotation == NULL || intent == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_FREE_TEXT_CHECK_TYPE_AND_DATA()

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_free_text_set_padding(zathura_annotation_t*
    annotation, zathura_annotation_padding_t UNUSED(padding))
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_FREE_TEXT_CHECK_TYPE_AND_DATA()

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_free_text_get_padding(zathura_annotation_t*
    annotation, zathura_annotation_padding_t* padding)
{
  if (annotation == NULL || padding == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_FREE_TEXT_CHECK_TYPE_AND_DATA()

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_free_text_set_line_ending(zathura_annotation_t*
    annotation, zathura_annotation_line_ending_t UNUSED(line_ending[2]))
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_FREE_TEXT_CHECK_TYPE_AND_DATA()

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_free_text_get_line_ending(zathura_annotation_t*
    annotation, zathura_annotation_line_ending_t* line_ending[2])
{
  if (annotation == NULL || line_ending == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_FREE_TEXT_CHECK_TYPE_AND_DATA()

  return ZATHURA_ERROR_OK;
}


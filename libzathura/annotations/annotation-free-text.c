/* See LICENSE file for license and copyright information */

#include <stdlib.h>
#include <string.h>

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

    free(annotation->data.free_text->style_string);
    annotation->data.free_text->style_string = NULL;

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
    annotation, zathura_annotation_justification_t justification)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_FREE_TEXT_CHECK_TYPE_AND_DATA()

  annotation->data.free_text->justification = justification;

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

  *justification = annotation->data.free_text->justification;

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
    g_free(annotation->data.free_text->rich_text);
  }

  annotation->data.free_text->rich_text = g_strdup(rich_text);

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

  if (annotation->data.free_text->style_string != NULL) {
    g_free(annotation->data.free_text->style_string);
  }

  annotation->data.free_text->style_string = g_strdup(style_string);

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

  if (annotation->data.free_text->style_string == NULL) {
    *style_string = "";
  } else {
    *style_string = annotation->data.free_text->style_string;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_free_text_set_callout_line(zathura_annotation_t*
    annotation, zathura_annotation_callout_line_t callout_line)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_FREE_TEXT_CHECK_TYPE_AND_DATA()

  if (memcpy(&(annotation->data.free_text->callout_line), &callout_line, sizeof(zathura_annotation_callout_line_t)) != &(annotation->data.free_text->callout_line)) {
    return ZATHURA_ERROR_UNKNOWN;
  }

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

  if (memcpy(callout_line, &(annotation->data.free_text->callout_line), sizeof(zathura_annotation_callout_line_t)) != callout_line) {
    return ZATHURA_ERROR_UNKNOWN;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_free_text_set_border(zathura_annotation_t*
    annotation, zathura_annotation_border_t border)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_FREE_TEXT_CHECK_TYPE_AND_DATA()

  memcpy(&(annotation->data.free_text->border), &border, sizeof(zathura_annotation_border_t));

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

  memcpy(border, &(annotation->data.free_text->border), sizeof(zathura_annotation_border_t));

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_free_text_set_intent(zathura_annotation_t*
    annotation, zathura_annotation_markup_intent_t intent)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_FREE_TEXT_CHECK_TYPE_AND_DATA()

  annotation->data.free_text->intent = intent;

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

  *intent = annotation->data.free_text->intent;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_free_text_set_padding(zathura_annotation_t*
    annotation, zathura_annotation_padding_t padding)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_FREE_TEXT_CHECK_TYPE_AND_DATA()

  annotation->data.free_text->padding.left   = padding.left;
  annotation->data.free_text->padding.top    = padding.top;
  annotation->data.free_text->padding.right  = padding.right;
  annotation->data.free_text->padding.bottom = padding.bottom;

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

  padding->left   = annotation->data.free_text->padding.left;
  padding->top    = annotation->data.free_text->padding.top;
  padding->right  = annotation->data.free_text->padding.right;
  padding->bottom = annotation->data.free_text->padding.bottom;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_free_text_set_line_ending(zathura_annotation_t*
    annotation, zathura_annotation_line_ending_t line_ending[2])
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_FREE_TEXT_CHECK_TYPE_AND_DATA()

  annotation->data.free_text->line_endings[0] = line_ending[0];
  annotation->data.free_text->line_endings[1] = line_ending[1];

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_free_text_get_line_ending(zathura_annotation_t*
    annotation, zathura_annotation_line_ending_t line_ending[2])
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_FREE_TEXT_CHECK_TYPE_AND_DATA()

  line_ending[0] = annotation->data.free_text->line_endings[0];
  line_ending[1] = annotation->data.free_text->line_endings[1];

  return ZATHURA_ERROR_OK;
}

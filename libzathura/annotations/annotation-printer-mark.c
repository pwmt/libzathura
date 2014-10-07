/* See LICENSE file for license and copyright information */

#include <stdlib.h>
#include <stdio.h>

#include "annotation-printer-mark.h"
#include "../annotations.h"
#include "internal.h"

#define ANNOTATION_PRINTER_MARK_CHECK_TYPE() \
  if (annotation->type != ZATHURA_ANNOTATION_PRINTER_MARK) { \
    return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE; \
  }

#define ANNOTATION_PRINTER_MARK_CHECK_DATA() \
  if (annotation->data.printer_mark == NULL) { \
    return ZATHURA_ERROR_UNKNOWN; \
  }

#define ANNOTATION_PRINTER_MARK_CHECK_TYPE_AND_DATA() \
  ANNOTATION_PRINTER_MARK_CHECK_TYPE() \
  ANNOTATION_PRINTER_MARK_CHECK_DATA()

zathura_error_t
zathura_annotation_printer_mark_init(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_PRINTER_MARK_CHECK_TYPE()

  if (annotation->data.printer_mark != NULL) {
    free(annotation->data.printer_mark);
  }

  annotation->data.printer_mark = calloc(1, sizeof(zathura_annotation_printer_mark_t));
  if (annotation->data.printer_mark == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_printer_mark_clear(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_PRINTER_MARK_CHECK_TYPE()

  free(annotation->data.printer_mark);
  annotation->data.printer_mark = NULL;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_printer_mark_set_name(zathura_annotation_t*
    annotation, const char* name)
{
  if (annotation == NULL || name == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_PRINTER_MARK_CHECK_TYPE_AND_DATA()

  if (annotation->data.printer_mark->name != NULL) {
    g_free(annotation->data.printer_mark->name);
  }

  annotation->data.printer_mark->name = g_strdup(name);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_printer_mark_get_name(zathura_annotation_t*
    annotation, char** name)
{
  if (annotation == NULL || name == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_PRINTER_MARK_CHECK_TYPE_AND_DATA()

  *name = annotation->data.printer_mark->name;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_printer_mark_set_mark_style(zathura_annotation_t*
    annotation, const char* mark_style)
{
  if (annotation == NULL || mark_style == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_PRINTER_MARK_CHECK_TYPE_AND_DATA()

  if (annotation->data.printer_mark->mark_style != NULL) {
    g_free(annotation->data.printer_mark->mark_style);
  }

  annotation->data.printer_mark->mark_style = g_strdup(mark_style);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_printer_mark_get_mark_style(zathura_annotation_t*
    annotation, char** mark_style)
{
  if (annotation == NULL || mark_style == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_PRINTER_MARK_CHECK_TYPE_AND_DATA()

  *mark_style = annotation->data.printer_mark->mark_style;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_printer_mark_set_colorants(zathura_annotation_t* annotation, zathura_list_t* colorants)
{
  if (annotation == NULL || colorants == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_PRINTER_MARK_CHECK_TYPE_AND_DATA()

  annotation->data.printer_mark->colorants = colorants;

  return ZATHURA_ERROR_OK;
}

zathura_error_t 
zathura_annotation_printer_mark_get_colorants(zathura_annotation_t* annotation, zathura_list_t** colorants)
{
  if (annotation == NULL || colorants == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_PRINTER_MARK_CHECK_TYPE_AND_DATA()

  *colorants = annotation->data.printer_mark->colorants;

  return ZATHURA_ERROR_OK;
}

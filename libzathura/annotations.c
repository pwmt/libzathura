/* See LICENSE file for license and copyright information */

#include <stdlib.h>
#include <string.h>

#include "annotations.h"
#include "annotations/internal.h"

zathura_error_t
zathura_annotation_new(zathura_annotation_t** annotation, zathura_annotation_type_t type)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
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
      return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *annotation = calloc(1, sizeof(zathura_annotation_t));
  if (*annotation == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  (*annotation)->type = type;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_free(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  free(annotation);

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

/* See LICENSE file for license and copyright information */

#include "border.h"

zathura_error_t
zathura_annotation_border_init(zathura_annotation_border_t* annotation_border)
{
  if (annotation_border == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  annotation_border->width = 1;
  annotation_border->style = ZATHURA_ANNOTATION_BORDER_STYLE_SOLID;
  annotation_border->dash_pattern.dash_array = NULL;
  annotation_border->dash_pattern.dash_phase = 0;
  annotation_border->effect = ZATHURA_ANNOTATION_BORDER_EFFECT_NONE;
  annotation_border->intensity = 0;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_border_clear(zathura_annotation_border_t* annotation_border)
{
  if (annotation_border == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  if (annotation_border->dash_pattern.dash_array != NULL) {
    zathura_list_free(annotation_border->dash_pattern.dash_array);
    annotation_border->dash_pattern.dash_array = NULL;
  }

  return ZATHURA_ERROR_OK;
}

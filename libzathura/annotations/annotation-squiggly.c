/* See LICENSE file for license and copyright information */

#include <string.h>
#include <stdlib.h>

#include "annotation-squiggly.h"
#include "internal.h"
#include "internal/annotation-text-markup.h"

zathura_error_t
zathura_annotation_squiggly_set_quad_points(zathura_annotation_t* annotation,
    zathura_list_t* quad_points)
{
  return zathura_annotation_text_markup_set_quad_points(annotation, quad_points);
}

zathura_error_t
zathura_annotation_squiggly_get_quad_points(zathura_annotation_t* annotation,
    zathura_list_t** quad_points)
{
  return zathura_annotation_text_markup_get_quad_points(annotation, quad_points);
}

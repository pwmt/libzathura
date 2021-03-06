/* See LICENSE file for license and copyright information */

#ifndef LIBZATHURA_TYPES_H
#define LIBZATHURA_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#include "list.h"
#include "node.h"

typedef struct zathura_point_s {
  float x;
  float y;
} zathura_point_t;

typedef struct zathura_rectangle_s {
  zathura_point_t p1;
  zathura_point_t p2;
} zathura_rectangle_t;

typedef struct zathura_quad_point_s {
  zathura_point_t p1;
  zathura_point_t p2;
  zathura_point_t p3;
  zathura_point_t p4;
} zathura_quad_point_t;

typedef enum zathura_search_flag_e {
  ZATHURA_SEARCH_DEFAULT           = 0,
  ZATHURA_SEARCH_CASE_SENSITIVE    = 1 << 0,
  ZATHURA_SEARCH_WHOLE_WORDS_ONLY = 1 << 1
} zathura_search_flag_t;

typedef struct zathura_path_s {
  zathura_list_t* points;
} zathura_path_t;

#include "action.h"

typedef struct zathura_link_mapping_s {
  zathura_rectangle_t position;
  zathura_action_t* action;
} zathura_link_mapping_t;

#include "form-fields.h"

typedef struct zathura_form_field_s zathura_form_field_t;

typedef struct zathura_form_field_mapping_s {
  zathura_rectangle_t position;
  zathura_form_field_t* form_field;
} zathura_form_field_mapping_t;

typedef void (*zathura_free_function_t)(void* data);

typedef enum zathura_blend_mode_e {
  ZATHURA_BLEND_MODE_NORMAL,
  ZATHURA_BLEND_MODE_MULTIPLY,
  ZATHURA_BLEND_MODE_SCREEN,
  ZATHURA_BLEND_MODE_OVERLAY,
  ZATHURA_BLEND_MODE_DARKEN,
  ZATHURA_BLEND_MODE_LIGHTEN,
  ZATHURA_BLEND_MODE_COLOR_DODGE,
  ZATHURA_BLEND_MODE_COLOR_BURN,
  ZATHURA_BLEND_MODE_HARD_LIGHT,
  ZATHURA_BLEND_MODE_SOFT_LIGHT,
  ZATHURA_BLEND_MODE_DIFFERENCE,
  ZATHURA_BLEND_MODE_EXCLUSION
} zathura_blend_mode_t;

#ifdef __cplusplus
}
#endif

#endif /* TYPES_H */

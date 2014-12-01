/* See LICENSE file for license and copyright information */

#ifndef TYPES_H
#define TYPES_H

#include "list.h"
#include "node.h"
#include "action.h"
#include "form-fields.h"

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

typedef struct zathura_link_mapping_s {
  zathura_rectangle_t position;
  zathura_action_t* action;
} zathura_link_mapping_t;

typedef struct zathura_form_field_mapping_s {
  zathura_rectangle_t position;
  zathura_form_field_t* form_field;
} zathura_form_field_mapping_t;

typedef struct zathura_annotation_mapping_s {
  zathura_rectangle_t position;
  zathura_annotation_t* annotation;
} zathura_annotation_mapping_t;

#endif /* TYPES_H */

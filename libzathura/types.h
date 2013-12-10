/* See LICENSE file for license and copyright information */

#ifndef TYPES_H
#define TYPES_H

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
#endif /* TYPES_H */

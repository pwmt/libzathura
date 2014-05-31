/* See LICENSE file for license and copyright information */

#ifndef ANNOTATION_MARKUP_H
#define ANNOTATION_MARKUP_H

typedef struct zathura_annotation_markup_s zathura_annotation_markup_t;

#include "../annotations.h"

zathura_error_t zathura_annotation_is_markup_annotation(zathura_annotation_t*
    annotation, bool* is_markup_annotation);

#endif // ANOTATION_MARKUP_H

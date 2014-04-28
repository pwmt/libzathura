/* See LICENSE file for license and copyright information */

#ifndef ANNOTATION_MARKUP_H
#define ANNOTATION_MARKUP_H

#include "../annotations.h"

/**
 * Describing the intent of the markup annotation. Intents allow viewer
 * applications to distinguish between different uses and behaviors of a single
 * markup annotation type. If this entry is not present or its value is the same
 * as the annotation type, the annotation has no explicit intent and should
 * behave in a generic manner in a viewer application.
 */
typedef enum zathura_annotation_markup_intent_e {
  /**
   * No intent defined.
   */
  ZATHURA_ANNOTATION_MARKUP_INTENT_NONE,

  /**
   * The annotation is intended to function as a callout.
   */
  ZATHURA_ANNOTATION_MARKUP_INTENT_FREE_TEXT_CALL_OUT,

  /**
   * The annotation is intended to function as a click-to-type or typewriter
   * object.
   */
  ZATHURA_ANNOTATION_MARKUP_INTENT_FREE_TEXT_TYPE_WRITER,

  /**
   * The annotation is intended to function as an arrow.
   */
  ZATHURA_ANNOTATION_MARKUP_INTENT_LINE_ARROW,

  /**
   * The annotation is intended to function as a dimension line.
   */
  ZATHURA_ANNOTATION_MARKUP_INTENT_LINE_DIMENSION,

  /**
   * The annotation is intended to function as a cloud object.
   */
  ZATHURA_ANNOTATION_MARKUP_INTENT_LINE_POLYGON_CLOUD,

  /**
   * The polygon annotation is intended to function as a dimension.
   */
  ZATHURA_ANNOTATION_MARKUP_INTENT_LINE_POLYGON_DIMENSION,

  /**
   * The polyline annotation is intended to function as a dimension
   */
  ZATHURA_ANNOTATION_MARKUP_INTENT_LINE_POLYLINE_DIMENSION,
} zathura_annotation_markup_intent_t;

/**
 * A type specifying the relationship (the “reply type”) between this annotation
 * and one specified by @a ::reply_type.
 */
typedef enum zathura_annotation_markup_reply_type_e {
  /**
   * The annotation is considered a reply to the annotation specified by
   * @a ::reply_type.
   */
  ZATHURA_ANNOTATION_REPLY_TYPE_REPLY,

  /**
   * The annotation is grouped with the annotation specified by
   * @a ::reply_type.
   */
  ZATHURA_ANNOTATION_REPLY_TYPE_GROUP
} zathura_annotation_markup_reply_type_t;

typedef struct zathura_annotation_markup_s zathura_annotation_markup_t;

zathura_error_t zathura_annotation_is_markup_annotation(zathura_annotation_t*
    annotation, bool* is_markup_annotation);

#endif // ANOTATION_MARKUP_H

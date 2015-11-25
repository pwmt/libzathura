/* See LICENSE file for license and copyright information */

#ifndef LIBZATHURA_ANNOTATION_TEXT_H
#define LIBZATHURA_ANNOTATION_TEXT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../annotations.h"
#include "../error.h"

/**
 * Annotations may have an author-specific state associated with them. The state
 * is not specified in the annotation itself but in a separate text annotation
 * that refers to the original annotation by means of its reply_to (“in reply to”)
 * entry.
 */
typedef enum zathura_annotation_text_state_s {
  /**
   * Unknown state
   */
  ZATHURA_ANNOTATION_TEXT_STATE_UNKNOWN,

  /**
   * The user has indicated nothing about the change (the default).
   */
  ZATHURA_ANNOTATION_TEXT_STATE_NONE,

  /**
   * The annotation has been marked by the user.
   */
  ZATHURA_ANNOTATION_TEXT_STATE_MARKED,

  /**
   * The annotation has not been marked by the user (the default).
   */
  ZATHURA_ANNOTATION_TEXT_STATE_UNMARKED,

  /**
   * The user agrees with the change.
   */
  ZATHURA_ANNOTATION_TEXT_STATE_ACCEPTED,

  /**
   * The user disagrees with the change.
   */
  ZATHURA_ANNOTATION_TEXT_STATE_REJECTED,

  /**
   * The change has been cancelled.
   */
  ZATHURA_ANNOTATION_TEXT_STATE_CANCELLED,

  /**
   * The change has been completed.
   */
  ZATHURA_ANNOTATION_TEXT_STATE_COMPLETED
} zathura_annotation_text_state_t;

// TODO: Should we map this to the name field of a text annotation?
typedef enum zathura_annotation_text_icon_s {
  ZATHURA_ANNOTATION_TEXT_ICON_UNKNOWN,
  ZATHURA_ANNOTATION_TEXT_ICON_NOTE,
  ZATHURA_ANNOTATION_TEXT_ICON_COMMENT,
  ZATHURA_ANNOTATION_TEXT_ICON_KEY,
  ZATHURA_ANNOTATION_TEXT_ICON_HELP,
  ZATHURA_ANNOTATION_TEXT_ICON_NEW_PARAGRAPH,
  ZATHURA_ANNOTATION_TEXT_ICON_PARAGRAPH,
  ZATHURA_ANNOTATION_TEXT_ICON_INSERT,
  ZATHURA_ANNOTATION_TEXT_ICON_CROSS,
  ZATHURA_ANNOTATION_TEXT_ICON_CIRCLE
} zathura_annotation_text_icon_t;

/**
 * Returns the icon name of this text annotation
 *
 * @param[in] annotation The annotation
 * @param[in] icon_name The attachment
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_text_set_icon_name(zathura_annotation_t*
    annotation, const char* icon_name);

/**
 * Returns the icon name of this text annotation
 *
 * @param[in] annotation The annotation
 * @param[out] icon_name The attachment
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_text_get_icon_name(zathura_annotation_t*
    annotation, char** icon_name);

/**
 * Sets a flag specifying whether the text annotation should initially be
 * displayed open.
 *
 * @param[in] annotation The annotation
 * @param[in] is_open If the annotation should initially be displayed open
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_text_set_open(zathura_annotation_t* annotation, bool is_open);

/**
 * Returns a flag specifying whether the text annotation should initially be
 * displayed open.
 *
 * @param[in] annotation The annotation
 * @param[out] is_open If the annotation should initially be displayed open
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_text_is_open(zathura_annotation_t* annotation, bool* is_open);

/**
 * Sets the text state of this text annotation
 *
 * @param[in] annotation The annotation
 * @param[in] state The text state
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t
zathura_annotation_text_set_state(zathura_annotation_t* annotation,
    zathura_annotation_text_state_t state);

/**
 * Returns the text state of this text annotation
 *
 * @param[in] annotation The annotation
 * @param[out] state The text state
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t
zathura_annotation_text_get_state(zathura_annotation_t* annotation,
    zathura_annotation_text_state_t* state);

#ifdef __cplusplus
}
#endif

#endif // ANOTATION_TEXT_H

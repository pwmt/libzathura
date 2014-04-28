/* See LICENSE file for license and copyright information */

#ifndef ANNOTATION_TEXT_H
#define ANNOTATION_TEXT_H

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

#endif // ANOTATION_TEXT_H

/* See LICENSE file for license and copyright information */

#ifndef ANNOTATION_FLAGS_H
#define ANNOTATION_FLAGS_H

/**
 * The value of the annotation flags entry is an unsigned 32-bit integer
 * containing flags specifying various characteristics of the annotation. Bit
 * positions within the flag word are numbered from 1 (low-order) to 32
 * (high-order). All undefined flag bits are reserved and must be set to 0.
 */
typedef enum zathura_annotation_flag_s {
  /**
   * Undefined flags
   */
  ZATHURA_ANNOTATION_FLAG_UNDEFINED = 0,

  /**
   * f set, do not display the annotation if it does not belong to one of the
   * standard annotation types and no annotation handler is available. If clear,
   * display such an unknown annotation using an appearance stream specified by
   * its appearance dictionary, if any.
   */
  ZATHURA_ANNOTATION_FLAG_INVISIBLE = 1 << 0,

  /**
   * If set, do not display or print the annotation or allow it to interact with
   * the user, regardless of its annotation type or whether an annotation
   * handler is available. In cases where screen space is limited, the ability
   * to hide and show annotations selectively can be used in combination with
   * appearance streams to display auxiliary pop-up information similar in
   * function to online help systems.
   */
  ZATHURA_ANNOTATION_FLAG_HIDDEN = 1 << 1,

  /**
   * If set, print the annotation when the page is printed. If clear, never
   * print the annotation, regardless of whether it is displayed on the screen.
   * This can be useful, for example, for annotations representing interactive
   * pushbuttons, which would serve no meaningful purpose on the printed page.
   */
  ZATHURA_ANNOTATION_FLAG_PRINT = 1 << 2,

  /**
   * If set, do not scale the annotation’s appearance to match the magnification
   * of the page. The location of the annotation on the page (defined by the
   * upper-left corner of its annotation rectangle) remains fixed, regardless of
   * the page magnification.
   */
  ZATHURA_ANNOTATION_FLAG_NO_ZOOM = 1 << 3,

  /**
   * If set, do not rotate the annotation’s appearance to match the rotation of
   * the page. The upper-left corner of the annotation rectangle remains in a
   * fixed location on the page, regardless of the page rotation.
   */
  ZATHURA_ANNOTATION_FLAG_NO_ROTATE = 1 << 4,

  /**
   * If set, do not display the annotation on the screen or allow it to interact
   * with the user. The annotation may be printed (depending on the setting of
   * the Print flag) but should be considered hidden for purposes of on-screen
   * display and user interaction.
   */
  ZATHURA_ANNOTATION_FLAG_NO_VIEW = 1 << 5,

  /**
   * If set, do not allow the annotation to interact with the user. The
   * annotation may be displayed or printed (depending on the settings of the
   * NoView and Print flags) but should not respond to mouse clicks or change
   * its appearance in response to mouse motions.
   */
  ZATHURA_ANNOTATION_FLAG_READ_ONLY = 1 << 6,

  /**
   * If set, do not allow the annotation to be deleted or its properties
   * (including position and size) to be modified by the user. However, this
   * flag does not restrict changes to the annotation’s contents, such as the
   * value of a form field.
   */
  ZATHURA_ANNOTATION_FLAG_LOCKED = 1 << 7,

  /**
   * If set, invert the interpretation of the NoView flag for certain events. A
   * typical use is to have an annotation that appears only when a mouse cursor
   * is held over it.
   */
  ZATHURA_ANNOTATION_FLAG_TOGGLE_NO_VIEW = 1 << 8,

  /**
   * If set, do not allow the contents of the annotation to be modified by the
   * user. This flag does not restrict deletion of the annotation or changes to
   * other annotation properties, such as position and size.
   */
  ZATHURA_ANNOTATION_FLAG_LOCKED_CONTENTS = 1 << 9,
} zathura_annotation_flag_t;

#endif // ANNOTATION_FLAGS_H

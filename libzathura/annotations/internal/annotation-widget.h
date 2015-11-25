/* See LICENSE file for license and copyright information */

#ifndef LIBZATHURA_INTERNAL_ANNOTATION_WIDGET_H
#define LIBZATHURA_INTERNAL_ANNOTATION_WIDGET_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../annotation-widget.h"
#include "../types.h"
#include "../../form-fields.h"

/**
 * Interactive forms use widget annotations to represent the appearance of
 * fields and to manage user interactions.  As a convenience, when a field has
 * only a single associated widget annotation, the contents of the field
 * dictionary and the annotation dictionary can be merged into a single
 * dictionary containing entries that pertain to both a field and an annotation.
 */
typedef struct zathura_annotation_widget_s {
  /**
   * The associated form field.
   */
  zathura_form_field_t* form_field;

  /**
   * The annotation’s highlighting mode, the visual effect to be used when
   * the mouse button is pressed or held down inside its active area.
   */
  zathura_annotation_highlighting_mode_t highlighting_mode;

  /**
   * An action to be performed when the link annotation is activated.
   */
  zathura_action_t* action;

  /**
   * An additional-actions list defining the annotation’s behavior in
   * response to various trigger events.
   */
  zathura_list_t* additional_actions;

  /**
   * The width and dash pattern to be used in drawing the annotation’s border
   */
  zathura_annotation_border_t border;

  /**
   * The color of the widget annotation’s background.
   */
  zathura_annotation_color_t background_color;

  /**
   * The number of degrees by which the widget annotation is rotated
   * counterclockwise relative to the page. The value must be a multiple of 90.
   *
   * Default value: 0.
   */
  int rotation;

  /**
   * (Optional; button fields only) The widget annotation’s normal caption,
   * displayed when it is not interacting with the user.
   */
  char* caption;

  /**
   * (Optional; pushbutton fields only) The widget annotation’s rollover
   * caption, displayed when the user rolls the cursor into its active area
   * without pressing the mouse button.
   */
  char* rollover_caption;

  /**
   * (Optional; pushbutton fields only) The widget annotation’s alternate (down)
   * caption, displayed when the mouse button is pressed within its active area.
   */
  char* alternate_caption;

  /**
   * (Optional; pushbutton fields only) A code indicating where to position the
   * text ofthe widget annotation’s caption relative to its icon.
   */
  zathura_annotation_widget_caption_position_t caption_position;
} zathura_annotation_widget_t;

/**
 * Initializes the annotation as a text annotation
 *
 * @param annotation The annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_widget_init(zathura_annotation_t* annotation);

/**
 * Clear the annotation as a text annotation
 *
 * @param annotation The annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_widget_clear(zathura_annotation_t* annotation);

#ifdef __cplusplus
}
#endif

#endif // INTERNAL_ANNOTATION_WIDGET_H

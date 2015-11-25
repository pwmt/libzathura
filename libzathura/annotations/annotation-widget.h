/* See LICENSE file for license and copyright information */

#ifndef LIBZATHURA_ANNOTATION_WIDGET_H
#define LIBZATHURA_ANNOTATION_WIDGET_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../annotations.h"
#include "../error.h"
#include "../form-fields.h"
#include "color.h"

/**
 * A code indicating where to position the text of the widget annotation’s
 * caption relative to its icon.
 */
typedef enum zathura_annotation_widget_caption_position_e {
  /**
   * No icon; caption only
   */
  ZATHURA_ANNOTATION_WIDGET_CAPTION_POSITION_NO_ICON_CAPTION_ONLY = 0,

  /**
   * No caption; icon only
   */
  ZATHURA_ANNOTATION_WIDGET_CAPTION_POSITION_NO_CAPTION_ICON_ONLY = 1,

  /**
   * Caption below the icon
   */
  ZATHURA_ANNOTATION_WIDGET_CAPTION_POSITION_CAPTION_BELOW_ICON = 3,

  /**
   * Caption above the icon
   */
  ZATHURA_ANNOTATION_WIDGET_CAPTION_POSITION_CAPTION_ABOVE_ICON = 4,

  /**
   * Caption to the right of the icon
   */
  ZATHURA_ANNOTATION_WIDGET_CAPTION_POSITION_CAPTION_RIGHT_OF_ICON = 5,

  /**
   * Caption to the left of the icon
   */
  ZATHURA_ANNOTATION_WIDGET_CAPTION_POSITION_CAPTION_LEFT_OF_ICON = 6,

  /**
   * Caption overlaid directly on the icon
   */
  ZATHURA_ANNOTATION_WIDGET_CAPTION_POSITION_CAPTION_OVERLAID = 7,
} zathura_annotation_widget_caption_position_t;

/**
 * Sets the form field associated with this annotation.
 *
 * @param[in] annotation The annotation
 * @param[in] form_field The form_field
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t
zathura_annotation_widget_set_form_field(zathura_annotation_t* annotation,
    zathura_form_field_t* form_field);

/**
 * Returns the form field associated with this annotation.
 *
 * @param[in] annotation The annotation
 * @param[out] form_field The form field
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t
zathura_annotation_widget_get_form_field(zathura_annotation_t* annotation,
    zathura_form_field_t** form_field);

/**
 * Sets the annotation’s highlighting mode, the visual effect to be used when
 * the mouse button is pressed or held down inside its active area.
 *
 * @param[in] annotation The annotation
 * @param[in] highlighting_mode The highlighting mode
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t
zathura_annotation_widget_set_highlighting_mode(zathura_annotation_t* annotation,
    zathura_annotation_highlighting_mode_t highlighting_mode);

/**
 * Returns the  annotation’s highlighting mode, the visual effect to be used
 * when the mouse button is pressed or held down inside its active area.
 *
 * @param[in] annotation The annotation
 * @param[out] highlighting_mode The highlighting mode
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t
zathura_annotation_widget_get_highlighting_mode(zathura_annotation_t*
    annotation, zathura_annotation_highlighting_mode_t* highlighting_mode);

/**
 * Sets an action to be performed when the widget annotation is activated.
 *
 * @param[in] annotation The annotation
 * @param[in] action The action
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t
zathura_annotation_widget_set_action(zathura_annotation_t* annotation,
    zathura_action_t* action);

/**
 * Returns an action to be performed when the widget annotation is activated.
 *
 * @param[in] annotation The annotation
 * @param[out] action The action
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t
zathura_annotation_widget_get_action(zathura_annotation_t* annotation,
    zathura_action_t** action);

/**
 * Sets an additional-actions list defining the annotation’s behavior in
 * response to various trigger events.
 *
 * @param[in] annotation The annotation
 * @param[in] additional_actions The list of points
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_widget_set_additional_actions(zathura_annotation_t* annotation, zathura_list_t* additional_actions);

/**
 * Returns an additional-actions list defining the annotation’s behavior in
 * response to various trigger events.
 *
 * @param[in] annotation The annotation
 * @param[out] additional_actions The list of quad points
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_widget_get_additional_actions(zathura_annotation_t* annotation, zathura_list_t** additional_actions);

/**
 * Sets the border of this widget annotation
 *
 * @param[in] annotation The annotation
 * @param[in] border The border
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_widget_set_border(zathura_annotation_t*
    annotation, zathura_annotation_border_t border);

/**
 * Returns the border of this widget annotation
 *
 * @param[in] annotation The annotation
 * @param[out] border The border
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_widget_get_border(zathura_annotation_t*
    annotation, zathura_annotation_border_t* border);

/**
 * Sets the background color of the widget annotation
 *
 * @param[in] annotation The annotation
 * @param[in] background_color The background color
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_widget_set_background_color(zathura_annotation_t*
    annotation, zathura_annotation_color_t background_color);

/**
 * Returns the background color of the widget annotation
 *
 * @param[in] annotation The annotation
 * @param[out] background_color The background color
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_widget_get_background_color(zathura_annotation_t*
    annotation, zathura_annotation_color_t* background_color);

/**
 * Sets the number of degrees by which the widget annotation is rotated
 * counterclockwise relative to the page. The value must be a multiple of 90.
 *
 * @param[in] annotation The annotation
 * @param[in] rotation The rotation 
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_widget_set_rotation(zathura_annotation_t*
    annotation, int rotation);

/**
 * Returns the number of degrees by which the widget annotation is rotated
 * counterclockwise relative to the page. The value must be a multiple of 90.
 *
 * @param[in] annotation The annotation
 * @param[out] rotation The rotation 
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_widget_get_rotation(zathura_annotation_t*
    annotation, int* rotation);

/**
 * Returns the caption of this widget annotation
 *
 * @param[in] annotation The annotation
 * @param[in] caption The caption
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_widget_set_caption(zathura_annotation_t*
    annotation, char* caption);

/**
 * Returns the caption of this widget annotation
 *
 * @param[in] annotation The annotation
 * @param[out] caption The caption
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_widget_get_caption(zathura_annotation_t*
    annotation, char** caption);

/**
 * Returns the rollover caption of this widget annotation
 *
 * @param[in] annotation The annotation
 * @param[in] rollover_caption The caption
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_widget_set_rollover_caption(zathura_annotation_t*
    annotation, char* rollover_caption);

/**
 * Returns the rollover caption of this widget annotation
 *
 * @param[in] annotation The annotation
 * @param[out] rollover_caption The caption
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_widget_get_rollover_caption(zathura_annotation_t*
    annotation, char** rollover_caption);

/**
 * Returns the alternate caption of this widget annotation
 *
 * @param[in] annotation The annotation
 * @param[in] alternate_caption The caption
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_widget_set_alternate_caption(zathura_annotation_t*
    annotation, char* alternate_caption);

/**
 * Returns the alternate caption of this widget annotation
 *
 * @param[in] annotation The annotation
 * @param[out] alternate_caption The caption
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_widget_get_alternate_caption(zathura_annotation_t*
    annotation, char** alternate_caption);

/**
 * Sets the actual caption position of this widget annotation
 *
 * @param[in] annotation The annotation
 * @param[in] caption_position The caption position object
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_widget_set_caption_position(zathura_annotation_t*
    annotation, zathura_annotation_widget_caption_position_t caption_position);

/**
 * Returns the actual caption position of this widget annotation
 *
 * @param[in] annotation The annotation
 * @param[out] caption_position The caption position object
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_widget_get_caption_position(zathura_annotation_t*
    annotation, zathura_annotation_widget_caption_position_t* caption_position);

#ifdef __cplusplus
}
#endif

#endif // ANNOTATION_WIDGET_H

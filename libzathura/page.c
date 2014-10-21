/* See LICENSE file for license and copyright information */

#include <stdlib.h>
#include <string.h>

#include "page.h"
#include "plugin-api.h"
#include "internal.h"
#include "macros.h"

#define CHECK_IF_IMPLEMENTED(page, function) \
  if ((page)->document == NULL || \
      (page)->document->plugin == NULL || \
      (page)->document->plugin->functions.function == NULL) { \
    return ZATHURA_ERROR_PLUGIN_NOT_IMPLEMENTED; \
  }

zathura_error_t
zathura_page_new(zathura_page_t** page)
{
  if (page == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  if ((*page = calloc(1, sizeof(zathura_page_t))) == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_page_free(zathura_page_t* page)
{
  if (page == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  if (page->document != NULL &&
      page->document->plugin != NULL &&
      page->document->plugin->functions.page_clear != NULL) {
    page->document->plugin->functions.page_clear(page);
  }

  free(page);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_page_set_index(zathura_page_t* page, unsigned int index)
{
  if (page == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  page->index = index;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_page_get_index(zathura_page_t* page, unsigned int* index)
{
  if (page == NULL || index == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *index = page->index;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_page_set_width(zathura_page_t* page, unsigned int width)
{
  if (page == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  page->width = width;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_page_get_width(zathura_page_t* page, unsigned int* width)
{
  if (page == NULL || width == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *width = page->width;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_page_set_height(zathura_page_t* page, unsigned int height)
{
  if (page == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  page->height = height;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_page_get_height(zathura_page_t* page, unsigned int* height)
{
  if (page == NULL || height == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *height = page->height;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_page_set_label(zathura_page_t* page, const char* label)
{
  if (page == NULL || label == NULL || strlen(label) == 0) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  size_t len = strlen(label);

  if (page->label != NULL) {
    free(page->label);
    page->label = NULL;
  }

  page->label = calloc(sizeof(char), len + 1);
  if (page->label == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  if (page->label != strncpy(page->label, label, strlen(label))) {
    free(page->label);
    page->label = NULL;

    return ZATHURA_ERROR_UNKNOWN;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_page_get_label(zathura_page_t* page, const char** label)
{
  if (page == NULL || label == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *label = page->label;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_page_set_transition(zathura_page_t* page, zathura_page_transition_t* transition)
{
  if (page == NULL || transition == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  page->transition = transition;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_page_get_transition(zathura_page_t* page, zathura_page_transition_t** transition)
{
  if (page == NULL || transition == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *transition = page->transition;

  return ZATHURA_ERROR_UNKNOWN;
}

zathura_error_t
zathura_page_set_crop_box(zathura_page_t* page, zathura_rectangle_t crop_box)
{
  if (page == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  page->crop_box = crop_box;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_page_get_crop_box(zathura_page_t* page, zathura_rectangle_t* crop_box)
{
  if (page == NULL || crop_box == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *crop_box = page->crop_box;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_page_set_duration(zathura_page_t* page, unsigned int duration)
{
  if (page == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  page->duration = duration;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_page_get_duration(zathura_page_t* page, unsigned int* duration)
{
  if (page == NULL || duration == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *duration = page->duration;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_page_search_text(zathura_page_t* page, const char* text,
    zathura_list_t** results)
{
  if (page == NULL || results == NULL || text == NULL || strlen(text) == 0) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_IF_IMPLEMENTED(page, page_search_text)

  return page->document->plugin->functions.page_search_text(page, text, results);
}

zathura_error_t
zathura_page_get_text(zathura_page_t* page, char** text,
    zathura_rectangle_t rectangle)
{
  if (page == NULL || text == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_IF_IMPLEMENTED(page, page_get_text)

  return page->document->plugin->functions.page_get_text(page, text, rectangle);
}

zathura_error_t
zathura_page_get_links(zathura_page_t* page, zathura_list_t** links)
{
  if (page == NULL || links == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_IF_IMPLEMENTED(page, page_get_links)

  return page->document->plugin->functions.page_get_links(page, links);
}

zathura_error_t
zathura_page_get_form_fields(zathura_page_t* page, zathura_list_t** form_fields)
{
  if (page == NULL || form_fields == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_IF_IMPLEMENTED(page, page_get_form_fields)

  return page->document->plugin->functions.page_get_form_fields(page, form_fields);
}

zathura_error_t
zathura_page_get_images(zathura_page_t* page, zathura_list_t** images)
{
  if (page == NULL || images == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_IF_IMPLEMENTED(page, page_get_images)

  return page->document->plugin->functions.page_get_images(page, images);
}

zathura_error_t
zathura_page_get_annotations(zathura_page_t* page, zathura_list_t** annotations)
{
  if (page == NULL || annotations == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_IF_IMPLEMENTED(page, page_get_annotations)

  return page->document->plugin->functions.page_get_annotations(page, annotations);
}

zathura_error_t
zathura_page_render(zathura_page_t* page, zathura_image_buffer_t** buffer,
    double scale, int rotation, int flags)
{
  if (page == NULL || buffer == NULL || scale <= 0.0) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_IF_IMPLEMENTED(page, page_render)

  return page->document->plugin->functions.page_render(page, buffer, scale, rotation, flags);
}

#ifdef HAVE_CAIRO
zathura_error_t
zathura_page_render_cairo(zathura_page_t* page, cairo_t* cairo, double scale,
    int rotation, int flags)
{
  if (page == NULL || cairo == NULL || scale <= 0.0) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  CHECK_IF_IMPLEMENTED(page, page_render_cairo)

  return page->document->plugin->functions.page_render_cairo(page, cairo, scale, rotation, flags);
}
#endif

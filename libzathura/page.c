/* See LICENSE file for license and copyright information */

#include <stdlib.h>
#include <string.h>

#include "page.h"
#include "plugin-api.h"
#include "internal.h"

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

  free(page);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_page_get_index(zathura_page_t* page, unsigned int* index)
{
  if (page == NULL || index == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

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
zathura_page_set_width(zathura_page_t* page, unsigned int width)
{
  if (page == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  page->width = width;

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
zathura_page_set_height(zathura_page_t* page, unsigned int height)
{
  if (page == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  page->height = height;

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

  memcpy(&(page->transition), transition, sizeof(zathura_page_transition_t));

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_page_get_transition(zathura_page_t* page, zathura_page_transition_t* transition)
{
  if (page == NULL || transition == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  return ZATHURA_ERROR_UNKNOWN;
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
zathura_page_search_text(zathura_page_t* page, const char* text,
    zathura_list_t** results)
{
  if (page == NULL || results == NULL || text == NULL || strlen(text) == 0) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_page_get_text(zathura_page_t* page, char** text, zathura_rectangle_t
    rectangle)
{
  if (page == NULL || text == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_page_get_links(zathura_page_t* page, zathura_list_t** links)
{
  if (page == NULL || links == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_page_get_form_fields(zathura_page_t* page, zathura_list_t** form_fields)
{
  if (page == NULL || form_fields == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_page_get_images(zathura_page_t* page, zathura_list_t** images)
{
  if (page == NULL || images == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_page_get_annotations(zathura_page_t* page, zathura_list_t** annotations)
{
  if (page == NULL || annotations == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_page_get_crop_box(zathura_page_t* page, zathura_rectangle_t* crop_box)
{
  if (page == NULL || crop_box == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_page_get_duration(zathura_page_t* page, unsigned int* duration)
{
  if (page == NULL || duration == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_page_render(zathura_page_t* page, zathura_image_buffer_t** buffer,
    double scale, int rotation, int flags)
{
  if (page == NULL || buffer == NULL || scale <= 0.0) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  return ZATHURA_ERROR_OK;
}

#ifdef HAVE_CAIRO
zathura_error_t
zathura_page_render_cairo(zathura_page_t* page, cairo_t* cairo, double scale,
    int rotation, int flags)
{
  if (page == NULL || cairo == NULL || scale <= 0.0) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  return ZATHURA_ERROR_OK;
}
#endif

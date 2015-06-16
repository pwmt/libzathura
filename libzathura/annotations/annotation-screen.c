/* See LICENSE file for license and copyright information */

#include <stdlib.h>

#include "annotation-screen.h"
#include "../action.h"
#include "../annotations.h"
#include "internal.h"

#define ANNOTATION_SCREEN_CHECK_TYPE() \
  if (annotation->type != ZATHURA_ANNOTATION_SCREEN) { \
    return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE; \
  }

#define ANNOTATION_SCREEN_CHECK_DATA() \
  if (annotation->data.screen == NULL) { \
    return ZATHURA_ERROR_UNKNOWN; \
  }

#define ANNOTATION_SCREEN_CHECK_TYPE_AND_DATA() \
  ANNOTATION_SCREEN_CHECK_TYPE() \
  ANNOTATION_SCREEN_CHECK_DATA()

zathura_error_t
zathura_annotation_screen_init(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_SCREEN_CHECK_TYPE()

  if (annotation->data.screen != NULL) {
    free(annotation->data.screen);
  }

  annotation->data.screen = calloc(1, sizeof(zathura_annotation_screen_t));
  if (annotation->data.screen == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_screen_clear(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_SCREEN_CHECK_TYPE()

  if (annotation->data.screen != NULL) {
    free(annotation->data.screen->title);
    annotation->data.screen->title = NULL;

    free(annotation->data.screen);
    annotation->data.screen = NULL;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t 
zathura_annotation_screen_set_title(zathura_annotation_t* annotation, const char* title)
{
  if (annotation == NULL || title == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_SCREEN_CHECK_TYPE_AND_DATA()

  if (annotation->data.screen->title != NULL) {
    g_free(annotation->data.screen->title);
  }

  annotation->data.screen->title = g_strdup(title);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_screen_get_title(zathura_annotation_t* annotation, char** title)
{
  if (annotation == NULL || title == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_SCREEN_CHECK_TYPE_AND_DATA()

  *title = annotation->data.screen->title;

  return ZATHURA_ERROR_OK;
}


zathura_error_t
zathura_annotation_screen_set_action(zathura_annotation_t* annotation,
    zathura_action_t* action)
{
  if (annotation == NULL || action == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_SCREEN_CHECK_TYPE()

  annotation->data.screen->action = action;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_screen_get_action(zathura_annotation_t* annotation,
    zathura_action_t** action)
{
  if (annotation == NULL || action == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_SCREEN_CHECK_TYPE()

  *action = annotation->data.screen->action;

  return ZATHURA_ERROR_OK;
}

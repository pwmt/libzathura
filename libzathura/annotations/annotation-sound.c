/* See LICENSE file for license and copyright information */

#include <stdlib.h>

#include "annotation-sound.h"
#include "../sound.h"
#include "../annotations.h"
#include "internal.h"

#define ANNOTATION_SOUND_CHECK_TYPE() \
  if (annotation->type != ZATHURA_ANNOTATION_SOUND) { \
    return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE; \
  }

#define ANNOTATION_SOUND_CHECK_DATA() \
  if (annotation->data.sound == NULL) { \
    return ZATHURA_ERROR_UNKNOWN; \
  }

#define ANNOTATION_SOUND_CHECK_TYPE_AND_DATA() \
  ANNOTATION_SOUND_CHECK_TYPE() \
  ANNOTATION_SOUND_CHECK_DATA()

zathura_error_t
zathura_annotation_sound_init(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_SOUND_CHECK_TYPE()

  if (annotation->data.sound != NULL) {
    free(annotation->data.sound);
  }

  annotation->data.sound = calloc(1, sizeof(zathura_annotation_sound_t));
  if (annotation->data.sound == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_sound_clear(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_SOUND_CHECK_TYPE()

  if (annotation->data.sound != NULL) {
    g_free(annotation->data.sound->icon_name);

    free(annotation->data.sound);
    annotation->data.sound = NULL;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_sound_set_sound(zathura_annotation_t* annotation, zathura_sound_t* sound)
{
  if (annotation == NULL || sound == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_SOUND_CHECK_TYPE_AND_DATA()

  annotation->data.sound->sound = sound;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_sound_get_sound(zathura_annotation_t* annotation, zathura_sound_t** sound)
{
  if (annotation == NULL || sound == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_SOUND_CHECK_TYPE_AND_DATA()

  *sound = annotation->data.sound->sound;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_sound_set_icon_name(zathura_annotation_t*
    annotation, char* icon_name)
{
  if (annotation == NULL || icon_name == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_SOUND_CHECK_TYPE_AND_DATA()

  if (annotation->data.sound->icon_name != NULL) {
    g_free(annotation->data.sound->icon_name);
  }

  annotation->data.sound->icon_name = g_strdup(icon_name);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_sound_get_icon_name(zathura_annotation_t*
    annotation, char** icon_name)
{
  if (annotation == NULL || icon_name == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_SOUND_CHECK_TYPE_AND_DATA()

  *icon_name = annotation->data.sound->icon_name;

  return ZATHURA_ERROR_OK;
}

/* See LICENSE file for license and copyright information */

#include <stdbool.h>
#include <stdlib.h>

#include "annotation-movie.h"
#include "../movie.h"
#include "../annotations.h"
#include "internal.h"

#define ANNOTATION_MOVIE_CHECK_TYPE() \
  if (annotation->type != ZATHURA_ANNOTATION_MOVIE) { \
    return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE; \
  }

#define ANNOTATION_MOVIE_CHECK_DATA() \
  if (annotation->data.movie == NULL) { \
    return ZATHURA_ERROR_UNKNOWN; \
  }

#define ANNOTATION_MOVIE_CHECK_TYPE_AND_DATA() \
  ANNOTATION_MOVIE_CHECK_TYPE() \
  ANNOTATION_MOVIE_CHECK_DATA()

zathura_error_t
zathura_annotation_movie_init(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_MOVIE_CHECK_TYPE()

  if (annotation->data.movie != NULL) {
    free(annotation->data.movie);
  }

  annotation->data.movie = calloc(1, sizeof(zathura_annotation_movie_t));
  if (annotation->data.movie == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  annotation->data.movie->title = NULL;
  annotation->data.movie->movie = NULL;
  annotation->data.movie->play_if_activated = true;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_movie_clear(zathura_annotation_t* annotation)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_MOVIE_CHECK_TYPE()

  free(annotation->data.movie);
  annotation->data.movie = NULL;

  return ZATHURA_ERROR_OK;
}

zathura_error_t 
zathura_annotation_movie_set_title(zathura_annotation_t* annotation, const char* title)
{
  if (annotation == NULL || title == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_MOVIE_CHECK_TYPE_AND_DATA()

  if (annotation->data.movie->title != NULL) {
    g_free(annotation->data.movie->title);
  }

  annotation->data.movie->title = g_strdup(title);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_movie_get_title(zathura_annotation_t* annotation, char** title)
{
  if (annotation == NULL || title == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_MOVIE_CHECK_TYPE_AND_DATA()

  *title = annotation->data.movie->title;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_movie_set_movie(zathura_annotation_t* annotation, zathura_movie_t* movie)
{
  if (annotation == NULL || movie == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_MOVIE_CHECK_TYPE_AND_DATA()

  annotation->data.movie->movie = movie;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_movie_get_movie(zathura_annotation_t* annotation, zathura_movie_t** movie)
{
  if (annotation == NULL || movie == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_MOVIE_CHECK_TYPE_AND_DATA()

  *movie = annotation->data.movie->movie;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_movie_set_movie_activation(zathura_annotation_t* annotation, zathura_movie_activation_t* activation)
{
  if (annotation == NULL || activation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_MOVIE_CHECK_TYPE_AND_DATA()

  annotation->data.movie->movie_activation = activation;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_movie_get_movie_activation(zathura_annotation_t* annotation, zathura_movie_activation_t** activation)
{
  if (annotation == NULL || activation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_MOVIE_CHECK_TYPE_AND_DATA()

  *activation = annotation->data.movie->movie_activation;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_movie_set_play_if_activated(zathura_annotation_t* annotation, bool play_if_activated)
{
  if (annotation == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_MOVIE_CHECK_TYPE_AND_DATA()

  annotation->data.movie->play_if_activated = play_if_activated;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_annotation_movie_play_if_activated(zathura_annotation_t* annotation, bool* play_if_activated)
{
  if (annotation == NULL || play_if_activated == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  ANNOTATION_MOVIE_CHECK_TYPE_AND_DATA()

  *play_if_activated = annotation->data.movie->play_if_activated;

  return ZATHURA_ERROR_OK;
}

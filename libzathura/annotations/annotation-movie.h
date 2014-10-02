/* See LICENSE file for license and copyright information */

#ifndef ANNOTATION_MOVIE_H
#define ANNOTATION_MOVIE_H

#include "../annotations.h"
#include "types.h"

/**
 * Sets the title of this movie annotation
 *
 * @param[in] annotation The annotation
 * @param[in] title The title
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_movie_set_title(zathura_annotation_t*
    annotation, const char* title);

/**
 * Returns the title of this movie annotation
 *
 * @param[in] annotation The annotation
 * @param[out] title The title
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_movie_get_title(zathura_annotation_t*
    annotation, char** title);

/**
 * Sets the actual movie of this movie annotation
 *
 * @param[in] annotation The annotation
 * @param[in] movie The movie object
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_movie_set_movie(zathura_annotation_t*
    annotation, zathura_movie_t* movie);

/**
 * Returns the actual movie of this movie annotation
 *
 * @param[in] annotation The annotation
 * @param[out] movie The movie object
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_movie_get_movie(zathura_annotation_t*
    annotation, zathura_movie_t** movie);

/**
 * Sets the movie activation of this movie annotation
 *
 * @param[in] annotation The annotation
 * @param[in] activation The movie activation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t
zathura_annotation_movie_set_movie_activation(zathura_annotation_t* annotation,
    zathura_movie_activation_t* activation);

/**
 * Returns the movie activation of this movie annotation
 *
 * @param[in] annotation The annotation
 * @param[out] activation The movie activation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t
zathura_annotation_movie_get_movie_activation(zathura_annotation_t* annotation,
    zathura_movie_activation_t** activation);

/**
 * Set if and how to play the movie when the annotation is activated. If this
 * flag is set and the movie activation is set to NULL, the movie should be
 * played using default activation parameters. If the value is false, the movie
 * should not be played.
 *
 * @param[in] annotation The annotation
 * @param[in] play_if_activated If the movie should be played if activated.
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t
zathura_annotation_movie_set_play_if_activated(zathura_annotation_t* annotation,
    bool play_if_activated);

/**
 * Returns if and how to play the movie when the annotation is activated. If this
 * flag is set and the movie activation is set to NULL, the movie should be
 * played using default activation parameters. If the value is false, the movie
 * should not be played.
 *
 * @param[in] annotation The annotation
 * @param[out] play_if_activated If the movie should be played if activated.
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_ANNOTATION_INVALID_TYPE Mismatching type of annotation passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_movie_play_if_activated(zathura_annotation_t*
    annotation, bool* play_if_activated);

#endif // ANNOTATION_MOVIE_H

/* See LICENSE file for license and copyright information */

#ifndef INTERNAL_ANNOTATION_MOVIE_H
#define INTERNAL_ANNOTATION_MOVIE_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * A movie annotation contains animated graphics and sound to be presented
 * on the computer screen and through the speakers. When the annotation is
 * activated, the movie is played.
 */
typedef struct zathura_annotation_movie_s {
  /**
   * The title of the movie annotation. Movie actions can use
   * this title to reference the movie annotation.
   */
  char* title;

  /**
   * The movie itself
   */
  zathura_movie_t* movie;

  /**
   * Movie activation
   *
   * If this is set the movie should be played with this specification and
   * the value of @a play_if_activated has to be ignored.
   */
  zathura_movie_activation_t* movie_activation;

  /**
   * A flag or dictionary specifying whether and how to play the movie when
   * the annotation is activated. If this value is a dictionary, it is a
   * movie activation dictionary specifying how to play the movie. If the
   * value is the boolean true, the movie should be played using default
   * activation parameters. If the value is false, the movie should not be
   * played.
   */
  bool play_if_activated;
} zathura_annotation_movie_t;

/**
 * Initializes the annotation as a movie annotation
 *
 * @param annotation The annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_movie_init(zathura_annotation_t* annotation);

/**
 * Clear the annotation as a movie annotation
 *
 * @param annotation The annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_movie_clear(zathura_annotation_t* annotation);

#ifdef __cplusplus
}
#endif

#endif // INTERNAL_ANNOTATION_MOVIE_H

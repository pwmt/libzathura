/* See LICENSE file for license and copyright information */

#include <stdbool.h>

#include "../movie.h"

/**
 * A movie annotation contains animated graphics and sound to be presented
 * on the computer screen and through the speakers. When the annotation is
 * activated, the movie is played.
 */
struct zathura_annotation_movie_s {
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
};

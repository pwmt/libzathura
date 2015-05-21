/* See LICENSE file for license and copyright information */

#ifndef MOVIE_H
#define MOVIE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "image.h"
#include "attachment.h"
#include "types.h"

/**
 * Some documents includes the ability to embed movies within a document by
 * means of movie annotations Despite the name, a movie may consist entirely of
 * sound with no visible images to be displayed on the screen.
 */
typedef struct zathura_movie_s {
  /**
   * A file specification identifying a self-describing movie file.
   */
  zathura_attachment_t* file;

  /**
   * The width and height of the movie’s bounding box, in pixels, specified as [
   * width height ]. This entry should be omitted for a movie consisting
   * entirely of sound with no visible images.
   */
  struct {
    unsigned int width;
    unsigned int height;
  } aspect;

  /**
   * The number of degrees by which the movie is rotated clockwise
   * relative to the page. The value must be a multiple of 90.
   */
  int rotate;

  /**
   * A flag or stream specifying whether and how to display a poster image
   * representing the movie. If this value is a stream, it contains an image to
   * be displayed as the poster. If it is the boolean value true, the poster
   * image should be retrieved from the movie file; if it is false, no poster
   * should be displayed.
   */
  struct {
    zathura_image_t* image; /**< The image */
    bool display; /**< Display the poster */
  } poster;
} zathura_movie_t;

/**
 * The play mode for playing the movie.
 */
typedef enum zathura_movie_play_mode_e {
  /**
   * Play once and stop.
   */
  ZATHURA_MOVIE_PLAY_MODE_ONCE,

  /**
   * Play and leave the movie controller bar open.
   */
  ZATHURA_MOVIE_PLAY_MODE_OPEN,

  /**
   * Play repeatedly from beginning to end until stopped.
   */
  ZATHURA_MOVIE_PLAY_MODE_REPEAT,

  /**
   * Play continuously forward and backward until stopped.
   */
  ZATHURA_MOVIE_PLAY_MODE_PALINDROME,
} zathura_movie_play_mode_t;

/**
 * The movie activation object specifies how the movie should be presented.
 */
typedef struct zathura_movie_activation_s {
  /**
   * The starting time of the movie segment to be played.
   */
  int start;

  /**
   * The duration of the movie segment to be played.
   */
  int duration;

  /**
   * The initial speed at which to play the movie. If the value of this entry
   * is negative, the movie is played backward with respect to @a start and
   * @a duration.
   */
  float rate;

  /**
   * The initial sound volume at which to play the movie, in the range
   * −1.0 to 1.0. Higher values denote greater volume; negative values mute the
   * sound.
   */
  float volumne;

  /**
   * A flag specifying whether to display a movie controller bar while
   * playing the movie.
   */
  bool show_controls;

  /**
   * The play mode for playing the movie.
   */
  zathura_movie_play_mode_t play_mode;

  /**
   * A flag specifying whether to play the movie synchronously or
   * asynchronously. If this value is true, the movie player retains control
   * until the movie is completed or dismissed by the user. If the value is
   * false, the player returns control to the viewer application immediately
   * after starting the movie.
   */
  bool synchronous;

  /**
   * Floating window
   */
  struct {
    /**
     * The magnification (zoom) factor at which to play the movie. The presence
     * of this entry implies that the movie is to be played in a floating win-
     * dow. If the entry is absent, the movie is played in the annotation
     * rectangle.
     *
     * The value of the entry is an array of two positive integers, [ numerator
     * denominator ], denoting a rational magnification factor for the movie.
     * The final window size, in pixels, is
     *
     *    ( numerator ÷ denominator ) × Aspect
     *
     * where the value of Aspect is taken from the movie dictionary.
     */
    struct {
      unsigned int numerator; /**< Numerator */
      unsigned int denominator; /**< Denominator */
    } scale;

    /**
     * For floating play windows, the relative position of the window on the
     * screen. The value is an array of two numbers [ horizontal vertical ] each
     * in the range 0.0 to 1.0, denoting the relative horizontal and vertical
     * position of the movie window with respect to the screen. For example, the
     * value [ 0.5 0.5 ] centers the window on the screen.
     */
    struct {
      float horizontal; /**< Horizontal value */
      float vertical; /**< Vertical value */
    } position;
  } floating_window;
} zathura_movie_activation_t;

#ifdef __cplusplus
}
#endif

#endif /* MOVIE_H */

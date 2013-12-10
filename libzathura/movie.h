/* See LICENSE file for license and copyright information */

#ifndef MOVIE_H
#define MOVIE_H

typedef enum zathura_movie_play_mode_e {
  ZATHURA_MOVIE_PLAY_MODE_ONCE,
  ZATHURA_MOVIE_PLAY_MODE_OPEN,
  ZATHURA_MOVIE_PLAY_MODE_REPEAT,
  ZATHURA_MOVIE_PLAY_MODE_PALINDROME,
} zathura_movie_play_mode_t;

typedef struct zathura_movie_s {
  zathura_attachment_t* file;
  struct {
    unsigned int width;
    unsigned int height;
  } aspect;
  int rotate;
  bool poster;
} zathura_movie_t;

typedef struct zathura_movie_activation_s {
  int start;
  int duration;
  float rate;
  float volumne;
  bool show_controls;
  zathura_movie_play_mode_t play_mode;
  bool synchronous;
  struct {
    struct {
      unsigned int numerator;
      unsigned int denomnator;
    } scale;
    struct {
      float horizontal;
      float vertical;
    } position;
  } floating_window;
} zathura_movie_activation_t;

#endif /* MOVIE_H */

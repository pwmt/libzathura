/* See LICENSE file for license and copyright information */

#include "../sound.h"

/**
 * A sound annotation is analogous to a text annotation except that instead
 * of a text note, it contains sound recorded from the computer’s microphone
 * or imported from a file. When the annotation is activated, the sound is
 * played.  The annotation behaves like a text annotation in most ways, with
 * a different icon (by default, a speaker) to indicate that it represents a
 * sound.
 */
struct zathura_annotation_sound_s {
  /**
   * A sound object defining the sound to be played when the annotation
   * is activated
   */
  zathura_sound_t* sound;

  /**
   * The name of an icon to be used in displaying the annotation. Viewer
   * applications should provide predefined icon appearances for at least
   * the following standard names:
   *
   * * Speaker
   * * Mic
   *
   * Additional names may be supported as well.
   */
  char* icon_name;
};

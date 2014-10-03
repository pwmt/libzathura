/* See LICENSE file for license and copyright information */

#ifndef INTERNAL_ANNOTATION_SOUND_H
#define INTERNAL_ANNOTATION_SOUND_H

/**
 * A sound annotation is analogous to a text annotation except that instead
 * of a text note, it contains sound recorded from the computer’s microphone
 * or imported from a sound. When the annotation is activated, the sound is
 * played.  The annotation behaves like a text annotation in most ways, with
 * a different icon (by default, a speaker) to indicate that it represents a
 * sound.
 */
typedef struct zathura_annotation_sound_s {
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
} zathura_annotation_sound_t;

/**
 * Initializes the annotation as a sound annotation
 *
 * @param annotation The annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_sound_init(zathura_annotation_t* annotation);

/**
 * Clear the annotation as a sound annotation
 *
 * @param annotation The annotation
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_annotation_sound_clear(zathura_annotation_t* annotation);

#endif // INTERNAL_ANNOTATION_SOUND_H

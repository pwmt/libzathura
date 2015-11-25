/* See LICENSE file for license and copyright information */

#ifndef LIBZATHURA_SOUND_H
#define LIBZATHURA_SOUND_H

#ifdef __cplusplus
extern "C" {
#endif

#include "attachment.h"

/**
 * A sound object is a stream containing sample values that define a sound to be
 * played through the computer’s speakers. The Sound entry in a sound annotation
 * or sound action dictionary identifies a sound object representing the sound
 * to be played when the annotation is activated.
 *
 * Since a sound object is a stream, it can contain any of the standard entries
 * common to all streams. In particular, if it contains an @a file entry, the
 * sound is defined in an external file. This sound file must be
 * self-describing, containing all information needed to render the sound; no
 * additional information need be present in the document.
 *
 * If no @a file entry is present, the sound object itself contains the sample data
 * and all other information needed to define the sound.
 *
 * NOTE: Only files are supported at the moment.
 */
typedef struct zathura_sound_s {
  /**
   * The attachment that represents the audio file.
   */
  zathura_attachment_t* file;
} zathura_sound_t;

#ifdef __cplusplus
}
#endif

#endif /* SOUND_H */

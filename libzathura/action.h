/* See LICENSE file for license and copyright information */

#ifndef LIBZATHURA_ACTION_H
#define LIBZATHURA_ACTION_H

#ifdef __cplusplus
extern "C" {
#endif

#include "error.h"

/**
 * Instead of simply jumping to a destination in the document, an annotation or
 * outline item can specify an action for the viewer application to perform,
 * such as launching an application, playing a sound, or changing an
 * annotation’s appearance state
 */
typedef struct zathura_action_s zathura_action_t;

typedef enum zathura_action_type_e
{
  ZATHURA_ACTION_UNKNOWN, /**< Invalid type */
  ZATHURA_ACTION_NONE, /**< No action */
  ZATHURA_ACTION_GOTO, /**< actions to a page */
  ZATHURA_ACTION_GOTO_REMOTE, /**< actions to a page */
  ZATHURA_ACTION_GOTO_EMBEDDED, /**< actions to an embedded file (PDF 1.6) */
  ZATHURA_ACTION_LAUNCH, /**< actions to an external source */
  ZATHURA_ACTION_THREAD, /**< Begin reading an article */
  ZATHURA_ACTION_URI, /**< actions to an external source */
  ZATHURA_ACTION_SOUND, /**< Play a sound (PDF 1.2) */
  ZATHURA_ACTION_MOVIE, /*<< Play a movie (PDF 1.2) */
  ZATHURA_ACTION_HIDE_ANNOTATIONS, /**< Set an annotation's hidden flag (PDF 1.2) */
  ZATHURA_ACTION_NAMED, /**< actions to an external source (PDF 1.2) */
  ZATHURA_ACTION_SUBMIT_FORM, /**< Send data to a uniform resource locator (PDF 1.2) */
  ZATHURA_ACTION_RESET_FORM, /**< Set fields to their default values (PDF 1.2) */
  ZATHURA_ACTION_IMPORT_DATA, /**< Import field values from a file (PDF 1.2) */
  ZATHURA_ACTION_JAVASCRIPT, /**< Execute a JavaScript scrip (PDF 1.3)t */
  ZATHURA_ACTION_SET_OCG_STATE, /**< Sets the states of optional content groups (PDF 1.5) */
  ZATHURA_ACTION_RENDITION, /**< Controls the playing of multimedia content. (PDF 1.5) */
  ZATHURA_ACTION_TRANSITION, /**< Updates the display of a document, using a transition diary (PDF 1.5) */
  ZATHURA_ACTION_GOTO_3D_VIEW /**< Set the current view of a 3d annotation (PDF 1.6) */
} zathura_action_type_t;

typedef enum zathura_destination_type_e
{
  ZATHURA_LINK_DESTINATION_UNKNOWN,
  ZATHURA_LINK_DESTINATION_XYZ,
  ZATHURA_LINK_DESTINATION_FIT,
  ZATHURA_LINK_DESTINATION_FITH,
  ZATHURA_LINK_DESTINATION_FITV,
  ZATHURA_LINK_DESTINATION_FITR,
  ZATHURA_LINK_DESTINATION_FITB,
  ZATHURA_LINK_DESTINATION_FITBH,
  ZATHURA_LINK_DESTINATION_FITBV
} zathura_destination_type_t;

/**
 * Returns the type of the given action
 *
 * @param[in] action The action
 * @param[out] type The type of the action
 *
 * @return ZATHURA_ERROR_OK No error occurred
 * @return ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been passed
 * @return ZATHURA_ERROR_UNKNOWN An unspecified error occurred
 */
zathura_error_t zathura_action_get_type(zathura_action_t* action,
    zathura_action_type_t* type);

typedef struct zathura_destination_s
{
  zathura_destination_type_t destination_type;
  unsigned int page_number; /**< Page number */
  double left; /**< Left coordinate */
  double right; /**< Right coordinate */
  double top; /**< Top coordinate */
  double bottom; /**< Bottom coordinate */
  double scale; /**< Scale */
} zathura_destination_t;

#include "actions/action-goto-3d-view.h"
#include "actions/action-goto-embedded.h"
#include "actions/action-goto.h"
#include "actions/action-goto-remote.h"
#include "actions/action-hide-annotations.h"
#include "actions/action-launch.h"
#include "actions/action-movie.h"
#include "actions/action-named.h"
#include "actions/action-rendition.h"
#include "actions/action-set-ocg-state.h"
#include "actions/action-sound.h"
#include "actions/action-thread.h"
#include "actions/action-transition.h"
#include "actions/action-uri.h"
#include "actions/internal.h"

#ifdef __cplusplus
}
#endif

#endif /* ACTION_H */

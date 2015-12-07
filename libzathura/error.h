/* See LICENSE file for license and copyright information */

#ifndef LIBZATHURA_ERROR_H
#define LIBZATHURA_ERROR_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum zathura_error_e {
  ZATHURA_ERROR_OK = 0, /**< No error occurred */
  ZATHURA_ERROR_UNKNOWN, /**< Unspecified error occurred */
  ZATHURA_ERROR_OUT_OF_MEMORY, /**< Out of memory */
  ZATHURA_ERROR_INVALID_ARGUMENTS, /**< Invalid arguments have been passed */

  ZATHURA_ERROR_PLUGIN_RESOLVE_SYMBOL, /**< Could not resolve symbol */
  ZATHURA_ERROR_PLUGIN_VERSION, /**< Miss-matching version number */
  ZATHURA_ERROR_PLUGIN_NOT_IMPLEMENTED, /**< The requested feature is not implemented by the plugin */

  ZATHURA_ERROR_DOCUMENT_DOES_NOT_EXIST, /**< The file does not exist */
  ZATHURA_ERROR_DOCUMENT_OPEN, /**< Could not open document */
  ZATHURA_ERROR_DOCUMENT_WRONG_PASSWORD, /**< Wrong or none password has been passed */
  ZATHURA_ERROR_DOCUMENT_UNKNOWN_TYPE, /**< Document type is unknown */
  ZATHURA_ERROR_DOCUMENT_INVALID_INDEX, /**< Invalid index */
  ZATHURA_ERROR_DOCUMENT_INVALID_LABEL, /**< Invalid label */
  ZATHURA_ERROR_DOCUMENT_OUTLINE_DOES_NOT_EXIST, /**< Document does not have an outline */
  ZATHURA_ERROR_DOCUMENT_HAS_NO_ATTACHMENTS, /**< Document does not have attachments */
  ZATHURA_ERROR_SEARCH_NO_RESULTS, /**< No search results */

  ZATHURA_ERROR_PAGE_TRANSITION_STYLE_INVALID_ACTION, /**< The style of the transition is not valid for this action */

  ZATHURA_ERROR_FORM_FIELD_CHOICE_INVALID_INDEX, /**< The given index does not exist */

  ZATHURA_ERROR_ANNOTATION_INVALID_TYPE, /**< The given annotation does not
                                           match the type that this function
                                           requires */

  ZATHURA_ERROR_ACTION_INVALID_TYPE, /**< The given action does not
                                           match the type that this function
                                           requires */

  ZATHURA_ERROR_OPTIONS_ALREADY_EXISTS, /**< Option of the given name already
                                             exists */
  ZATHURA_ERROR_OPTIONS_DOES_NOT_EXIST, /**< Option of the given name does not
                                             exist */
  ZATHURA_ERROR_OPTIONS_INVALID_TYPE,   /**< Types do not match */
  ZATHURA_ERROR_OPTIONS_READONLY,       /**< Option is read-only */
  ZATHURA_ERROR_OPTIONS_NOT_SET,        /**< Option is not set */
} zathura_error_t;

#ifdef __cplusplus
}
#endif

#endif /* LIBZATHURA_ERROR_H */

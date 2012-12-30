/* See LICENSE file for license and copyright information */

#ifndef ERROR_H
#define ERROR_H

typedef enum zathura_error_e {
  ZATHURA_ERROR_OK = 0, /**< No error occurred */
  ZATHURA_ERROR_UNKNOWN, /**< Unspecified error occurred */
  ZATHURA_ERROR_OUT_OF_MEMORY, /**< Out of memory */
  ZATHURA_ERROR_INVALID_ARGUMENTS, /**< Invalid arguments have been passed */

  ZATHURA_ERROR_PLUGIN_RESOLVE_SYMBOL, /**< Could not resolve symbol */
  ZATHURA_ERROR_PLUGIN_VERSION, /**< Miss-matching version number */
  ZATHURA_ERROR_PLUGIN_NOT_IMPLEMENTED, /**< The requested feature is not implemented by the plugin */

  ZATHURA_ERROR_DOCUMENT_INVALID_INDEX, /**< Invalid index */
  ZATHURA_ERROR_DOCUMENT_INVALID_LABEL, /**< Invalid label */
} zathura_error_t;

#endif /* ERROR_H */

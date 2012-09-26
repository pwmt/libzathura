/* See LICENSE file for license and copyright information */

#ifndef ERROR_H
#define ERROR_H

typedef enum zathura_error_e {
  ZATHURA_ERROR_OK = 0, /**< No error occured */
  ZATHURA_ERROR_OUT_OF_MEMORY,
  ZATHURA_ERROR_INVALID_ARGUMENTS,
} zathura_error_t;

#endif /* ERROR_H */

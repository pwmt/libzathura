/* See LICENSE file for license and copyright information */

#include <stdlib.h>

#include "page.h"
#include "plugin-api.h"
#include "internal.h"

zathura_error_t
zathura_page_new(zathura_page_t** page)
{
  if (page == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  if ((*page = calloc(1, sizeof(zathura_page_t))) == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_page_free(zathura_page_t* page)
{
  if (page == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  free(page);

  return ZATHURA_ERROR_OK;
}

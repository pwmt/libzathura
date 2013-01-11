/* See LICENSE file for license and copyright information */

#include "libzathura/plugin-api.h"
#include <stdio.h>

/* forward declarations */
void register_functions(zathura_plugin_functions_t* functions);

/* register plugin */
ZATHURA_PLUGIN_REGISTER(
  "plugin",
  0,
  0,
  0,
  register_functions,
  ZATHURA_PLUGIN_MIMETYPES({
    "application/pdf",
  })
)

/* functions implementation */
void
register_functions(zathura_plugin_functions_t* functions)
{
}

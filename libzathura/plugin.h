/* See LICENSE file for license and copyright information */

#ifndef PLUGIN_H
#define PLUGIN_H

#include "error.h"

typedef struct zathura_plugin_s zathura_plugin_t;
typedef struct zathura_plugin_functions_s zathura_plugin_functions_t;

typedef struct zathura_plugin_version_s {
  unsigned int major; /**< Major version of the plugin */
  unsigned int minor; /**< Minor version of the plugin */
  unsigned int rev; /**< Revision of the plugin */
} zathura_plugin_version_t;

zathura_error_t zathura_plugin_get_name(zathura_plugin_t* plugin);
zathura_error_t zathura_plugin_get_path(zathura_plugin_t* plugin);
zathura_error_t zathura_plugin_get_version(zathura_plugin_t* plugin, zathura_plugin_version_t* version);
zathura_error_t zathura_plugin_get_functions(zathura_plugin_t* plugin, zathura_plugin_functions_t* functions);

#endif /* PLUGIN_H */

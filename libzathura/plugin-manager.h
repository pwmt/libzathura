/* See LICENSE file for license and copyright information */

#ifndef PLUGIN_MANAGER_H
#define PLUGIN_MANAGER_H

#include "error.h"
#include "list.h"

typedef struct zathura_plugin_manager_s zathura_plugin_manager_t;

zathura_error_t zathura_plugin_manager_new(zathura_plugin_manager_t** plugin_manager);
zathura_error_t zathura_plugin_manager_free(zathura_plugin_manager_t* plugin_manager);

zathura_error_t zathura_plugin_manager_load(zathura_plugin_manager_t* plugin_manager, const char* path);
zathura_error_t zathura_plugin_manager_load_dir(zathura_plugin_manager_t* plugin_manager, const char* directory);
zathura_error_t zathura_plugin_manager_get_plugins(zathura_plugin_manager_t* plugin_manager, zathura_list_t** plugins);

#endif /* PLUGIN_MANAGER_H */

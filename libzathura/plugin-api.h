/* See LICENSE file for license and copyright information */

#ifndef PLUGIN_API_H
#define PLUGIN_API_H

#include "error.h"
#include "plugin.h"
#include "page.h"

/* plugin */
typedef void (*zathura_plugin_register_function_t)(zathura_plugin_functions_t* functions);

zathura_error_t zathura_plugin_set_name(zathura_plugin_t* plugin, const char* name);
zathura_error_t zathura_plugin_set_register_function(zathura_plugin_t* plugin, zathura_plugin_register_function_t function);
zathura_error_t zathura_plugin_add_mimetype(zathura_plugin_t* plugin, const char* mime_type);

/* page */
zathura_error_t zathura_page_new(zathura_page_t** page);

#endif /* PLUGIN_API_H */

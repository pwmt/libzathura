/* See LICENSE file for license and copyright information */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "plugin.h"
#include "error.h"
#include "internal.h"
#include "version.h"

zathura_error_t
zathura_plugin_get_name(zathura_plugin_t* plugin, const char** name)
{
  if (plugin == NULL || name == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *name = plugin->name;

  if (*name != NULL) {
    return ZATHURA_ERROR_OK;
  }

  return ZATHURA_ERROR_UNKNOWN;
}

zathura_error_t
zathura_plugin_get_path(zathura_plugin_t* plugin, const char** path)
{
  if (plugin == NULL || path == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *path = plugin->path;

  if (*path != NULL) {
    return ZATHURA_ERROR_OK;
  }

  return ZATHURA_ERROR_UNKNOWN;
}

zathura_error_t
zathura_plugin_get_version(zathura_plugin_t* plugin, zathura_plugin_version_t*
    version)
{
  if (plugin == NULL || version == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  version->major = plugin->version.major;
  version->minor = plugin->version.minor;
  version->rev   = plugin->version.rev;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_plugin_get_functions(zathura_plugin_t* plugin,
    zathura_plugin_functions_t** functions)
{
  if (plugin == NULL || functions == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_plugin_open_document(zathura_plugin_t* plugin, zathura_document_t**
    document, const char* path, const char* password)
{
  if (plugin == NULL || document == NULL || path == NULL || strlen(path) == 0) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  /* Check if open document function is set */
  if (plugin->functions.document_open == NULL) {
    return ZATHURA_ERROR_PLUGIN_NOT_IMPLEMENTED;
  }

  /* Check if file exists */
  if (g_file_test(path, G_FILE_TEST_EXISTS) == FALSE) {
    return ZATHURA_ERROR_DOCUMENT_DOES_NOT_EXIST;
  }

  zathura_error_t error = ZATHURA_ERROR_OK;

  /* Determine real path */
  char* real_path;
  if ((error = zathura_realpath(path, &real_path)) != ZATHURA_ERROR_OK) {
    return error;
  }

  /* Create document */
  if ((error = zathura_document_new(document)) != ZATHURA_ERROR_OK) {
    free(real_path);
    return error;
  }

  /* Initialize document */
  (*document)->path     = real_path;
  (*document)->password = (password != NULL) ? g_strdup(password) : NULL;
  (*document)->plugin   = plugin;

  /* Open document */
  error = plugin->functions.document_open(*document);
  if (error != ZATHURA_ERROR_OK) {
    zathura_document_free(*document);
    *document = NULL;
    return error;
  }

  /* Allocate pages */
  (*document)->pages = calloc((*document)->number_of_pages, sizeof(*((*document)->pages)));
  if ((*document)->pages == NULL) {
    zathura_document_free(*document);
    *document = NULL;
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  for (unsigned int pid = 0; pid < (*document)->number_of_pages; pid++) {
    zathura_error_t error = zathura_document_get_page(*document, pid, &((*document)->pages[pid]));
    if (error != ZATHURA_ERROR_OK) {
      zathura_document_free(*document);
      *document = NULL;
      return error;
    }
  }

  return ZATHURA_ERROR_OK;
}

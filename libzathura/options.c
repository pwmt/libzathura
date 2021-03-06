/* See LICENSE file for license and copyright information */

#define _XOPEN_SOURCE 500

#include <stdlib.h>
#include <string.h>
#include <glib.h>

#include "options.h"
#include "list.h"

struct zathura_options_s
{
  GHashTable* options; /*< hash table of all options */
  zathura_list_t* callbacks; /*< callbacks */
};

struct option_s
{
  char* description; /*< optional description of an option */
  zathura_options_value_t value;
  zathura_option_type_t value_type; /*< value type of the option */
  bool is_set   : 1; /* option has been set once */
  bool readonly : 1; /* option is read only */
};

struct callback_s
{
  zathura_options_callback_t callback; /*< The callback */
  void* data; /*< User supplied data */
};

typedef struct option_s option_t;
typedef struct callback_s callback_t;

static zathura_error_t
option_new(option_t** option, zathura_option_type_t type)
{
  if (option == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  option_t* new_option = calloc(1, sizeof(**option));
  if (new_option == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  new_option->value_type  = type;
  new_option->is_set      = false;
  new_option->readonly    = false;

  *option = new_option;

  return ZATHURA_ERROR_OK;
}

static void
option_free(void* data)
{
  if (data == NULL) {
    return;
  }

  option_t* option = data;
  free(option->description);
  if (option->value_type == ZATHURA_OPTION_STRING) {
    free(option->value.string);
  }
  free(option);
}

zathura_error_t
zathura_options_new(zathura_options_t** options)
{
  if (options == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  zathura_options_t* new_options = calloc(1, sizeof(**options));
  if (new_options == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  new_options->options = g_hash_table_new_full(g_str_hash, g_str_equal, free,
      option_free);
  if (new_options->options == NULL) {
    free(new_options);
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  *options = new_options;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_options_free(zathura_options_t* options)
{
  if (options == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  if (options->options) {
    g_hash_table_unref(options->options);
  }
  if (options->callbacks) {
    zathura_list_free_full(options->callbacks, free);
  }
  free(options);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_options_add(zathura_options_t* options, const char* name,
    zathura_option_type_t type)
{
  if (options == NULL || name == NULL || *name == '\0') {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  option_t* option = g_hash_table_lookup(options->options, name);
  if (option != NULL) {
    return ZATHURA_ERROR_OPTIONS_ALREADY_EXISTS;
  }

  char* name_dup = strdup(name);
  if (name_dup == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  const zathura_error_t error = option_new(&option, type);
  if (error != ZATHURA_ERROR_OK) {
    free(name_dup);
    return error;
  }

  g_hash_table_insert(options->options, name_dup, option);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_options_get_type(zathura_options_t* options, const char* name,
    zathura_option_type_t* type)
{
  if (options == NULL || name == NULL || type == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  option_t* option = g_hash_table_lookup(options->options, name);
  if (option == NULL) {
    return ZATHURA_ERROR_OPTIONS_DOES_NOT_EXIST;
  }

  *type = option->value_type;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_options_set_description(zathura_options_t* options, const char* name,
    const char* description)
{
  if (options == NULL || name == NULL || description == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  option_t* option = g_hash_table_lookup(options->options, name);
  if (option == NULL) {
    return ZATHURA_ERROR_OPTIONS_DOES_NOT_EXIST;
  }

  char* new_description = strdup(description);
  if (new_description == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  free(option->description);
  option->description = new_description;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_options_get_description(zathura_options_t* options, const char* name,
    const char** description)
{
  if (options == NULL || name == NULL || description == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  option_t* option = g_hash_table_lookup(options->options, name);
  if (option == NULL) {
    return ZATHURA_ERROR_OPTIONS_DOES_NOT_EXIST;
  }

  *description = option->description;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_options_is_set(zathura_options_t* options,
    const char* name, bool* is_set)
{
  if (options == NULL || name == NULL || is_set == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  option_t* option = g_hash_table_lookup(options->options, name);
  if (option == NULL) {
    return ZATHURA_ERROR_OPTIONS_DOES_NOT_EXIST;
  }

  *is_set = option->is_set;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_options_set_readonly(zathura_options_t* options, const char* name)
{
  if (options == NULL || name == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  option_t* option = g_hash_table_lookup(options->options, name);
  if (option == NULL) {
    return ZATHURA_ERROR_OPTIONS_DOES_NOT_EXIST;
  }

  option->readonly = true;

  return ZATHURA_ERROR_OK;
}

static void
call_callbacks(zathura_options_t* options, const char* name, option_t* option)
{
  if (options->callbacks == NULL) {
    return;
  }

  callback_t* callback_info = NULL;
  ZATHURA_LIST_FOREACH(callback_info, options->callbacks) {
    callback_info->callback(options, name, &option->value, callback_info->data);
  }
}

zathura_error_t
zathura_options_set_value_int(zathura_options_t* options, const char* name,
    int value)
{
  if (options == NULL || name == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  option_t* option = g_hash_table_lookup(options->options, name);
  if (option == NULL) {
    return ZATHURA_ERROR_OPTIONS_DOES_NOT_EXIST;
  } else if (option->value_type != ZATHURA_OPTION_INT) {
    return ZATHURA_ERROR_OPTIONS_INVALID_TYPE;
  } else if (option->readonly == true) {
    return ZATHURA_ERROR_OPTIONS_READONLY;
  }

  option->value.s_int = value;
  option->is_set      = true;

  call_callbacks(options, name, option);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_options_get_value_int(zathura_options_t* options, const char* name,
    int* value)
{
  if (options == NULL || name == NULL || value == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  option_t* option = g_hash_table_lookup(options->options, name);
  if (option == NULL) {
    return ZATHURA_ERROR_OPTIONS_DOES_NOT_EXIST;
  } else if (option->value_type != ZATHURA_OPTION_INT) {
    return ZATHURA_ERROR_OPTIONS_INVALID_TYPE;
  } else if (option->is_set == false) {
    return ZATHURA_ERROR_OPTIONS_NOT_SET;
  }

  *value = option->value.s_int;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_options_set_value_uint(zathura_options_t* options, const char* name,
    unsigned int value)
{
  if (options == NULL || name == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  option_t* option = g_hash_table_lookup(options->options, name);
  if (option == NULL) {
    return ZATHURA_ERROR_OPTIONS_DOES_NOT_EXIST;
  } else if (option->value_type != ZATHURA_OPTION_UINT) {
    return ZATHURA_ERROR_OPTIONS_INVALID_TYPE;
  } else if (option->readonly == true) {
    return ZATHURA_ERROR_OPTIONS_READONLY;
  }

  option->value.u_int = value;
  option->is_set      = true;

  call_callbacks(options, name, option);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_options_get_value_uint(zathura_options_t* options, const char* name,
    unsigned int* value)
{
  if (options == NULL || name == NULL || value == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  option_t* option = g_hash_table_lookup(options->options, name);
  if (option == NULL) {
    return ZATHURA_ERROR_OPTIONS_DOES_NOT_EXIST;
  } else if (option->value_type != ZATHURA_OPTION_UINT) {
    return ZATHURA_ERROR_OPTIONS_INVALID_TYPE;
  } else if (option->is_set == false) {
    return ZATHURA_ERROR_OPTIONS_NOT_SET;
  }

  *value = option->value.u_int;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_options_set_value_float(zathura_options_t* options, const char* name,
    float value)
{
  if (options == NULL || name == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  option_t* option = g_hash_table_lookup(options->options, name);
  if (option == NULL) {
    return ZATHURA_ERROR_OPTIONS_DOES_NOT_EXIST;
  } else if (option->value_type != ZATHURA_OPTION_FLOAT) {
    return ZATHURA_ERROR_OPTIONS_INVALID_TYPE;
  } else if (option->readonly == true) {
    return ZATHURA_ERROR_OPTIONS_READONLY;
  }

  option->value.f = value;
  option->is_set  = true;

  call_callbacks(options, name, option);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_options_get_value_float(zathura_options_t* options, const char* name,
    float* value)
{
  if (options == NULL || name == NULL || value == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  option_t* option = g_hash_table_lookup(options->options, name);
  if (option == NULL) {
    return ZATHURA_ERROR_OPTIONS_DOES_NOT_EXIST;
  } else if (option->value_type != ZATHURA_OPTION_FLOAT) {
    return ZATHURA_ERROR_OPTIONS_INVALID_TYPE;
  } else if (option->is_set == false) {
    return ZATHURA_ERROR_OPTIONS_NOT_SET;
  }

  *value = option->value.f;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_options_set_value_bool(zathura_options_t* options, const char* name,
    bool value)
{
  if (options == NULL || name == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  option_t* option = g_hash_table_lookup(options->options, name);
  if (option == NULL) {
    return ZATHURA_ERROR_OPTIONS_DOES_NOT_EXIST;
  } else if (option->value_type != ZATHURA_OPTION_BOOL) {
    return ZATHURA_ERROR_OPTIONS_INVALID_TYPE;
  } else if (option->readonly == true) {
    return ZATHURA_ERROR_OPTIONS_READONLY;
  }

  option->value.b = value;
  option->is_set  = true;

  call_callbacks(options, name, option);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_options_get_value_bool(zathura_options_t* options, const char* name,
    bool* value)
{
  if (options == NULL || name == NULL || value == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  option_t* option = g_hash_table_lookup(options->options, name);
  if (option == NULL) {
    return ZATHURA_ERROR_OPTIONS_DOES_NOT_EXIST;
  } else if (option->value_type != ZATHURA_OPTION_BOOL) {
    return ZATHURA_ERROR_OPTIONS_INVALID_TYPE;
  } else if (option->is_set == false) {
    return ZATHURA_ERROR_OPTIONS_NOT_SET;
  }

  *value = option->value.b;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_options_set_value_pointer(zathura_options_t* options, const char* name,
    void* value)
{
  if (options == NULL || name == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  option_t* option = g_hash_table_lookup(options->options, name);
  if (option == NULL) {
    return ZATHURA_ERROR_OPTIONS_DOES_NOT_EXIST;
  } else if (option->value_type != ZATHURA_OPTION_POINTER) {
    return ZATHURA_ERROR_OPTIONS_INVALID_TYPE;
  } else if (option->readonly == true) {
    return ZATHURA_ERROR_OPTIONS_READONLY;
  }

  option->value.pointer = value;
  option->is_set        = true;

  call_callbacks(options, name, option);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_options_get_value_pointer(zathura_options_t* options, const char* name,
    void** value)
{
  if (options == NULL || name == NULL || value == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  option_t* option = g_hash_table_lookup(options->options, name);
  if (option == NULL) {
    return ZATHURA_ERROR_OPTIONS_DOES_NOT_EXIST;
  } else if (option->value_type != ZATHURA_OPTION_POINTER) {
    return ZATHURA_ERROR_OPTIONS_INVALID_TYPE;
  } else if (option->is_set == false) {
    return ZATHURA_ERROR_OPTIONS_NOT_SET;
  }

  *value = option->value.pointer;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_options_set_value_string(zathura_options_t* options, const char* name,
    const char* value)
{
  if (options == NULL || name == NULL || value == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  option_t* option = g_hash_table_lookup(options->options, name);
  if (option == NULL) {
    return ZATHURA_ERROR_OPTIONS_DOES_NOT_EXIST;
  } else if (option->value_type != ZATHURA_OPTION_STRING) {
    return ZATHURA_ERROR_OPTIONS_INVALID_TYPE;
  } else if (option->readonly == true) {
    return ZATHURA_ERROR_OPTIONS_READONLY;
  }

  char* new_value = strdup(value);
  if (new_value == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  free(option->value.string);
  option->value.string = new_value;
  option->is_set       = true;

  call_callbacks(options, name, option);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_options_get_value_string(zathura_options_t* options, const char* name,
    const char** value)
{
  if (options == NULL || name == NULL || value == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  option_t* option = g_hash_table_lookup(options->options, name);
  if (option == NULL) {
    return ZATHURA_ERROR_OPTIONS_DOES_NOT_EXIST;
  } else if (option->value_type != ZATHURA_OPTION_STRING) {
    return ZATHURA_ERROR_OPTIONS_INVALID_TYPE;
  } else if (option->is_set == false) {
    return ZATHURA_ERROR_OPTIONS_NOT_SET;
  }

  *value = option->value.string;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_options_register_callback(zathura_options_t* options,
    zathura_options_callback_t callback, void* data, void** callback_handle)
{
  if (options == NULL || callback == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  callback_t* callback_info = calloc(1, sizeof(callback_t));
  if (callback_info == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  callback_info->callback = callback;
  callback_info->data     = data;

  options->callbacks = zathura_list_append(options->callbacks, callback_info);
  if (options->callbacks == NULL) {
    free(callback_info);
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  if (callback_handle != NULL) {
    *callback_handle = callback_info;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_options_unregister_callback(zathura_options_t* options,
    void* callback_handle)
{
  if (options == NULL || callback_handle == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  if (zathura_list_find(options->callbacks, callback_handle) != NULL) {
    options->callbacks = zathura_list_remove(options->callbacks,
        callback_handle);
    free(callback_handle);
  }

  return ZATHURA_ERROR_OK;
}

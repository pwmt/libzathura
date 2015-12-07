/* See LICENSE file for license and copyright information */

#ifndef LIBZATHURA_OPTIONS_H
#define LIBZATHURA_OPTIONS_H

#include "error.h"
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct zathura_options_s zathura_options_t;

/**
 * Possible types for an option.
 */
typedef enum zathura_option_type_e {
  /**
   * An unsigned integer.
   */
  ZATHURA_OPTION_UINT,
  /**
   * An signed integer.
   */
  ZATHURA_OPTION_INT,
  /**
   * A single precision floating point number.
   */
  ZATHURA_OPTION_FLOAT,
  /**
   * A null terminated string.
   */
  ZATHURA_OPTION_STRING,
  /**
   * A pointer.
   */
  ZATHURA_OPTION_POINTER,
  /**
   * A boolean.
   */
  ZATHURA_OPTION_BOOL
} zathura_option_type_t;

/**
 * Creates a new options instance.
 *
 * @param[out] options The options.
 *
 * @return @ref ZATHURA_ERROR_OK No error occurred
 * @return @ref ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been
 *  passed
 * @return @ref ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 */
zathura_error_t zathura_options_new(zathura_options_t** options);

/**
 * Free a options instance.
 *
 * @param[in] options The options.
 *
 * @return @ref ZATHURA_ERROR_OK No error occurred
 * @return @ref ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been
 *  passed
 */
zathura_error_t zathura_options_free(zathura_options_t* options);

/**
 * Add a new option of name @a name and type @a type.
 *
 * @param[in] options The options.
 * @param[in] name The name of the new option.
 * @param[in] type The type of the new option.
 *
 * @return @ref ZATHURA_ERROR_OK No error occurred
 * @return @ref ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been
 *  passed
 * @return @ref ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return @ref ZATHURA_ERROR_OPTIONS_ALREADY_EXISTS Option with given name
 *  already exists.
 */
zathura_error_t zathura_options_add(zathura_options_t* options,
    const char* name, zathura_option_type_t type);

/**
 * Query type of the option with name @a name.
 *
 * @param[in] options The options.
 * @param[in] name The name of the option.
 * @param[out] type The type of the option.
 *
 * @return @ref ZATHURA_ERROR_OK No error occurred
 * @return @ref ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been
 *  passed
 * @return @ref ZATHURA_ERROR_OPTIONS_DOES_NOT_EXIST Option with given name
 *  does not exist.
 */
zathura_error_t zathura_options_get_type(zathura_options_t* options,
    const char* name, zathura_option_type_t* type);

/**
 * Set description of the option with name @a name.
 *
 * @param[in] options The options.
 * @param[in] name The name of the option.
 * @param[in] description The description of the option.
 *
 * @return @ref ZATHURA_ERROR_OK No error occurred
 * @return @ref ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been
 *  passed
 * @return @ref ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return @ref ZATHURA_ERROR_OPTIONS_DOES_NOT_EXIST Option with given name
 *  does not exist.
 */
zathura_error_t zathura_options_set_description(zathura_options_t* options,
    const char* name, const char* description);

/**
 * Get description of the option with name @a name.
 *
 * @param[in] options The options.
 * @param[in] name The name of the option.
 * @param[in] description The description of the option.
 *
 * @return @ref ZATHURA_ERROR_OK No error occurred
 * @return @ref ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been
 *  passed
 * @return @ref ZATHURA_ERROR_OPTIONS_DOES_NOT_EXIST Option with given name
 *  does not exist.
 */
zathura_error_t zathura_options_get_description(zathura_options_t* options,
    const char* name, const char** description);

/**
 * Check if value of the option with name @a name has been set.
 *
 * @param[in] options The options.
 * @param[in] name The name of the option.
 * @param[out] is_set The status of the option.
 *
 * @return @ref ZATHURA_ERROR_OK No error occurred
 * @return @ref ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been
 *  passed
 * @return @ref ZATHURA_ERROR_OPTIONS_DOES_NOT_EXIST Option with given name
 *  does not exist.
 */
zathura_error_t zathura_options_is_set(zathura_options_t* options,
    const char* name, bool* is_set);

/**
 * Set the value of the option with name @a name to be readonly.
 *
 * @param[in] options The options.
 * @param[in] name The name of the option.
 *
 * @return @ref ZATHURA_ERROR_OK No error occurred
 * @return @ref ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been
 *  passed
 * @return @ref ZATHURA_ERROR_OPTIONS_DOES_NOT_EXIST Option with given name
 *  does not exist.
 */
zathura_error_t zathura_options_set_readonly(zathura_options_t* options,
    const char* name);

/**
 * Set the value of the option with name @a name to @a value.
 *
 * @param[in] options The options.
 * @param[in] name The name of the option.
 * @param[in] value The new value of the option.
 *
 * @return @ref ZATHURA_ERROR_OK No error occurred
 * @return @ref ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been
 *  passed
 * @return @ref ZATHURA_ERROR_OPTIONS_DOES_NOT_EXIST Option with given name
 *  does not exist.
 * @return @ref ZATHURA_ERROR_OPTIONS_INVALID_TYPE Type of the option does not
 *  match.
 * @return @ref ZATHURA_ERROR_OPTIONS_READONLY Options is readonly.
 */
zathura_error_t zathura_options_set_value_int(zathura_options_t* options,
    const char* name, int value);

/**
 * Obtain the value of the option with name @a name.
 *
 * @param[in] options The options.
 * @param[in] name The name of the option.
 * @param[out] value The value of the option.
 *
 * @return @ref ZATHURA_ERROR_OK No error occurred
 * @return @ref ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been
 *  passed
 * @return @ref ZATHURA_ERROR_OPTIONS_DOES_NOT_EXIST Option with given name
 *  does not exist.
 * @return @ref ZATHURA_ERROR_OPTIONS_INVALID_TYPE Type of the option does not
 *  match.
 * @return @ref ZATHURA_ERROR_OPTIONS_NOT_SET Option has not been set.
 */
zathura_error_t zathura_options_get_value_int(zathura_options_t* options,
    const char* name, int* value);

/**
 * Set the value of the option with name @a name to @a value.
 *
 * @param[in] options The options.
 * @param[in] name The name of the option.
 * @param[in] value The new value of the option.
 *
 * @return @ref ZATHURA_ERROR_OK No error occurred
 * @return @ref ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been
 *  passed
 * @return @ref ZATHURA_ERROR_OPTIONS_DOES_NOT_EXIST Option with given name
 *  does not exist.
 * @return @ref ZATHURA_ERROR_OPTIONS_INVALID_TYPE Type of the option does not
 *  match.
 * @return @ref ZATHURA_ERROR_OPTIONS_READONLY Options is readonly.
 */
zathura_error_t zathura_options_set_value_uint(zathura_options_t* options,
    const char* name, unsigned int value);

/**
 * Obtain the value of the option with name @a name.
 *
 * @param[in] options The options.
 * @param[in] name The name of the option.
 * @param[out] value The value of the option.
 *
 * @return @ref ZATHURA_ERROR_OK No error occurred
 * @return @ref ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been
 *  passed
 * @return @ref ZATHURA_ERROR_OPTIONS_DOES_NOT_EXIST Option with given name
 *  does not exist.
 * @return @ref ZATHURA_ERROR_OPTIONS_INVALID_TYPE Type of the option does not
 *  match.
 * @return @ref ZATHURA_ERROR_OPTIONS_NOT_SET Option has not been set.
 */
zathura_error_t zathura_options_get_value_uint(zathura_options_t* options,
    const char* name, unsigned int* value);

/**
 * Set the value of the option with name @a name to @a value.
 *
 * @param[in] options The options.
 * @param[in] name The name of the option.
 * @param[in] value The new value of the option.
 *
 * @return @ref ZATHURA_ERROR_OK No error occurred
 * @return @ref ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been
 *  passed
 * @return @ref ZATHURA_ERROR_OPTIONS_DOES_NOT_EXIST Option with given name
 *  does not exist.
 * @return @ref ZATHURA_ERROR_OPTIONS_INVALID_TYPE Type of the option does not
 *  match.
 * @return @ref ZATHURA_ERROR_OPTIONS_READONLY Options is readonly.
 */
zathura_error_t zathura_options_set_value_float(zathura_options_t* options,
    const char* name, float value);

/**
 * Obtain the value of the option with name @a name.
 *
 * @param[in] options The options.
 * @param[in] name The name of the option.
 * @param[out] value The value of the option.
 *
 * @return @ref ZATHURA_ERROR_OK No error occurred
 * @return @ref ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been
 *  passed
 * @return @ref ZATHURA_ERROR_OPTIONS_DOES_NOT_EXIST Option with given name
 *  does not exist.
 * @return @ref ZATHURA_ERROR_OPTIONS_INVALID_TYPE Type of the option does not
 *  match.
 * @return @ref ZATHURA_ERROR_OPTIONS_NOT_SET Option has not been set.
 */
zathura_error_t zathura_options_get_value_float(zathura_options_t* options,
    const char* name, float* value);

/**
 * Set the value of the option with name @a name to @a value.
 *
 * @param[in] options The options.
 * @param[in] name The name of the option.
 * @param[in] value The new value of the option.
 *
 * @return @ref ZATHURA_ERROR_OK No error occurred
 * @return @ref ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been
 *  passed
 * @return @ref ZATHURA_ERROR_OPTIONS_DOES_NOT_EXIST Option with given name
 *  does not exist.
 * @return @ref ZATHURA_ERROR_OPTIONS_INVALID_TYPE Type of the option does not
 *  match.
 * @return @ref ZATHURA_ERROR_OPTIONS_READONLY Options is readonly.
 */
zathura_error_t zathura_options_set_value_bool(zathura_options_t* options,
    const char* name, bool value);

/**
 * Obtain the value of the option with name @a name.
 *
 * @param[in] options The options.
 * @param[in] name The name of the option.
 * @param[out] value The value of the option.
 *
 * @return @ref ZATHURA_ERROR_OK No error occurred
 * @return @ref ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been
 *  passed
 * @return @ref ZATHURA_ERROR_OPTIONS_DOES_NOT_EXIST Option with given name
 *  does not exist.
 * @return @ref ZATHURA_ERROR_OPTIONS_INVALID_TYPE Type of the option does not
 *  match.
 * @return @ref ZATHURA_ERROR_OPTIONS_NOT_SET Option has not been set.
 */
zathura_error_t zathura_options_get_value_bool(zathura_options_t* options,
    const char* name, bool* value);

/**
 * Set the value of the option with name @a name to @a value.
 *
 * @param[in] options The options.
 * @param[in] name The name of the option.
 * @param[in] value The new value of the option.
 *
 * @return @ref ZATHURA_ERROR_OK No error occurred
 * @return @ref ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been
 *  passed
 * @return @ref ZATHURA_ERROR_OPTIONS_DOES_NOT_EXIST Option with given name
 *  does not exist.
 * @return @ref ZATHURA_ERROR_OPTIONS_INVALID_TYPE Type of the option does not
 *  match.
 * @return @ref ZATHURA_ERROR_OPTIONS_READONLY Options is readonly.
 */
zathura_error_t zathura_options_set_value_pointer(zathura_options_t* options,
    const char* name, void* value);
zathura_error_t zathura_options_get_value_pointer(zathura_options_t* options,
    const char* name, void** value);

/**
 * Set the value of the option with name @a name to @a value.
 *
 * @param[in] options The options.
 * @param[in] name The name of the option.
 * @param[in] value The new value of the option.
 *
 * @return @ref ZATHURA_ERROR_OK No error occurred
 * @return @ref ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been
 *  passed
 * @return @ref ZATHURA_ERROR_OPTIONS_DOES_NOT_EXIST Option with given name
 *  does not exist.
 * @return @ref ZATHURA_ERROR_OPTIONS_INVALID_TYPE Type of the option does not
 *  match.
 * @return @ref ZATHURA_ERROR_OUT_OF_MEMORY Out of memory
 * @return @ref ZATHURA_ERROR_OPTIONS_READONLY Options is readonly.
 */
zathura_error_t zathura_options_set_value_string(zathura_options_t* options,
    const char* name, const char* value);

/**
 * Obtain the value of the option with name @a name.
 *
 * @param[in] options The options.
 * @param[in] name The name of the option.
 * @param[out] value The value of the option.
 *
 * @return @ref ZATHURA_ERROR_OK No error occurred
 * @return @ref ZATHURA_ERROR_INVALID_ARGUMENTS Invalid arguments have been
 *  passed
 * @return @ref ZATHURA_ERROR_OPTIONS_DOES_NOT_EXIST Option with given name
 *  does not exist.
 * @return @ref ZATHURA_ERROR_OPTIONS_INVALID_TYPE Type of the option does not
 *  match.
 * @return @ref ZATHURA_ERROR_OPTIONS_NOT_SET Option has not been set.
 */
zathura_error_t zathura_options_get_value_string(zathura_options_t* options,
    const char* name, const char** value);

#ifdef __cplusplus
}
#endif

#endif /* LIBZATHURA_OPTIONS_H */

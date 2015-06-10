/* See LICENSE file for license and copyright information */

#include <stdlib.h>

#include "outline.h"
#include "plugin-api/outline.h"
#include "plugin-api/action.h"

struct zathura_outline_element_s {
  char* title;
  zathura_action_t* action;
};

zathura_error_t zathura_outline_element_new(zathura_outline_element_t** element,
    const char* title, zathura_action_t* action)
{
  if (element == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *element = calloc(1, sizeof(**element));
  if (*element == NULL) {
    return ZATHURA_ERROR_OUT_OF_MEMORY;
  }

  if (title != NULL) {
    (*element)->title = g_strdup(title);
  }

  (*element)->action = action;

  return ZATHURA_ERROR_OK;
}

zathura_error_t zathura_outline_element_free(zathura_outline_element_t*
    element)
{
  if (element == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  if (element->title != NULL) {
    g_free(element->title);
  }

  if (element->action != NULL) {
    zathura_action_free(element->action);
  }

  free(element);

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_outline_element_get_title(zathura_outline_element_t* element, const char** title)
{
  if (element == NULL || title == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *title = element->title;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_outline_element_get_action(zathura_outline_element_t* element, zathura_action_t** action)
{
  if (element == NULL || action == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  *action = element->action;

  return ZATHURA_ERROR_OK;
}

zathura_error_t
zathura_outline_free(zathura_node_t* outline)
{
  if (outline == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  unsigned int number_of_children = zathura_node_get_number_of_children(outline);
  for (unsigned int i = 0; i < number_of_children; i++) {
    zathura_outline_free(zathura_node_get_nth_child(outline, i));
  }

  zathura_outline_element_t* outline_element = zathura_node_get_data(outline);
  zathura_outline_element_free(outline_element);

  return ZATHURA_ERROR_OK;
}

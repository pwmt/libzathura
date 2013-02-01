/* See LICENSE file for license and copyright information */

#ifndef LIST_H
#define LIST_H

#include <glib.h>

typedef GList zathura_list_t;

#define zathura_list_alloc g_list_alloc
#define zathura_list_free(list) g_list_free((list))
#define zathura_list_free_full(list, free_func) g_list_free_full((list), (free_func))
#define zathura_list_append(list, data) (zathura_list_t*) g_list_append((list), (data))
#define zathura_list_prepend(list, data) (zathura_list_t*) g_list_prepend((list), (data))
#define zathura_list_nth(list, n) (zathura_list_t*) g_list_nth((list), (n))
#define zathura_list_nth_data(list, n) g_list_nth_data((list), (n))
#define zathura_list_length(list) g_list_length((list))

#endif /* LIST_H */

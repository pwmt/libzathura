/* See LICENSE file for license and copyright information */

#ifndef LIBZATHURA_LIST_H
#define LIBZATHURA_LIST_H

#include <glib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef GList zathura_list_t;

#define ZATHURA_LIST_FOREACH(item, list) for(zathura_list_t *__glist = (list); __glist && ((item) = __glist->data, true); __glist = __glist->next)

#define zathura_list_alloc g_list_alloc
#define zathura_list_free(list) g_list_free((list))
#define zathura_list_free_full(list, free_func) g_list_free_full((list), (free_func))
#define zathura_list_append(list, data) (zathura_list_t*) g_list_append((list), (data))
#define zathura_list_prepend(list, data) (zathura_list_t*) g_list_prepend((list), (data))
#define zathura_list_nth(list, n) (zathura_list_t*) g_list_nth((list), (n))
#define zathura_list_nth_data(list, n) g_list_nth_data((list), (n))
#define zathura_list_length(list) g_list_length((list))
#define zathura_list_copy(list) g_list_copy((list))
#define zathura_list_reverse(list) g_list_reverse((list))
#define zathura_list_foreach(list, func, user_data) g_list_foreach((list), (func), (user_data))
#define zathura_list_find(list, data) g_list_find((list), (data))
#define zathura_list_remove(list, data) g_list_remove((list), (data))

#ifdef __cplusplus
}
#endif

#endif /* LIBZATHURA_LIST_H */

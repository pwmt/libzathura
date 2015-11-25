/* See LICENSE file for license and copyright information */

#ifndef LIBZATHURA_NODE_H
#define LIBZATHURA_NODE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <glib.h>

typedef GNode zathura_node_t;

#define zathura_node_new(data) g_node_new((data))
#define zathura_node_free(root) g_node_destroy((root))
#define zathura_node_append(parent, node) g_node_append((parent), (node))
#define zathura_node_append_data(parent, data) g_node_append_data((parent), (data))
#define zathura_node_prepend(parent, node) g_node_prepend((parent), (node))
#define zathura_node_prepend_data(parent, data) g_node_prepend_data((parent), (data))
#define zathura_node_get_number_of_children(node) g_node_n_children((node))
#define zathura_node_get_nth_child(node, n) g_node_nth_child((node), (n))
#define zathura_node_get_data(node) ((node)->data)

#ifdef __cplusplus
}
#endif

#endif /* NODE_H */

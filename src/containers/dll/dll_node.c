#include "../../../includes/containers.h"

t_dll_node *new_node(char *data)
{
  t_dll_node *node;

  node = malloc(sizeof(t_dll_node));
  node->data = data;
  node->next = NULL;
  node->prev = NULL;
  return (node);
}

void free_node(t_dll_node *node)
{
  free(node->data);
  free(node);
}

#include "../../../includes/containers.h"

t_dll *dll_init()
{
  t_dll *dll;

  dll = malloc(sizeof(t_dll));
  if (!dll)
    return (NULL);
  dll->head = NULL;
  dll->tail = NULL;
  dll->len = 0;
  return (dll);
}

void *dll_append(t_dll *dll, void *data)
{
  if (!dll->head || !dll->tail)
  {
    dll->len = 1;
    dll->head = new_node(data);
    if (!dll->head)
      return (NULL);
    dll->tail = dll->head;
  }
  else
  {
    dll->len += 1;
    dll->tail->next = new_node(data);
    if (!dll->tail->next)
      return (NULL);
    dll->tail->next->prev = dll->tail;
    dll->tail = dll->tail->next;
  }
  return (dll);
}

void *dll_prepend(t_dll *dll, void *data)
{
  t_dll_node *temp;

  if (!dll->head || !dll->tail)
  {
    dll->len = 1;
    dll->head = new_node(data);
    if (!dll->head)
      return (NULL);
    dll->tail = dll->head;
  }
  else
  {
    dll->len += 1;
    temp = new_node(data);
    if (!temp)
      return (NULL);
    temp->next = dll->head;
    dll->head->prev = temp;
    dll->head = temp;
  }
  return (dll);
}

void dll_remove(t_dll *dll, t_dll_node *node)
{
  t_dll_node *temp;

  if (dll->head == node)
  {
    node->next->prev = NULL;
    dll->head = node->next;
    free(node);
  }
  else if (dll->tail == node)
  {
    node->prev->next = NULL;
    dll->tail = node->prev;
    free(node);
  }
  else
  {
    temp = node;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(temp);
  }
}

t_dll_node	*dll_find(t_dll *dll, void *target, int (*cmp)(void *, void *))
{
	t_dll_node	*temp;

	if (!dll->head || !dll->tail)
		return (NULL);
	temp = dll->head;
	while (temp)
	{
		if (cmp(temp->data, target))
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

void print_dll(t_dll *dll)
{
  t_dll_node *itr;

  // printf("dll_addr -> %p\n", dll);
  // printf("dllhead_addr -> %p\n", dll->head);
  // printf("dlltail_addr -> %p\n", dll->tail);
  // printf("dlltail_len -> %u\n", dll->len);
  itr = dll->head;
  while (itr)
  {
    // printf("current: %p\n", itr);
    printf("data: %s\n", (char *)itr->data);
    // printf("next: %p\n", itr->next);
    // printf("prev: %p\n", itr->prev);
    itr = itr->next;
  }
}

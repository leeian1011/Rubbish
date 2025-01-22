#include "../../../includes/containers.h"
#include <stdio.h>

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

void *dll_append(t_dll *dll, char *data)
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

void *dll_prepend(t_dll *dll, char *data)
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

void print_dll(t_dll *dll)
{
  t_dll_node *itr;

  printf("dll_addr -> %p\n", dll);
  printf("dllhead_addr -> %p\n", dll->head);
  printf("dlltail_addr -> %p\n", dll->tail);
  printf("dlltail_len -> %u\n", dll->len);
  itr = dll->head;
  while (itr)
  {
    printf("current: %p\n", itr);
    printf("data: %s\n", itr->data);
    printf("next: %p\n", itr->next);
    printf("prev: %p\n", itr->prev);
    itr = itr->next;
  }
}
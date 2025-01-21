#ifndef CONTAINERS_H
# define CONTAINERS_H
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_dll_node {
  char *data;
  struct s_dll_node *next;
  struct s_dll_node *prev;
} t_dll_node;

typedef struct s_dll 
{
  t_dll_node *head;
  t_dll_node *tail;
  unsigned int len;
} t_dll;

void print_dll(t_dll *dll);

t_dll_node *new_node(char *data);
void free_node(t_dll_node *node);

t_dll *dll_init();
void *dll_append(t_dll *dll, char *data);
void *dll_prepend(t_dll *dll, char *data);

#endif

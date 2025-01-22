#ifndef CONTAINERS_H
# define CONTAINERS_H
# include <stdlib.h>
# include <stdbool.h>
# include "../src/libft/libft.h"

typedef struct s_dll_node {
  void *data;
  struct s_dll_node *next;
  struct s_dll_node *prev;
} t_dll_node;

typedef struct s_dll 
{
  t_dll_node *head;
  t_dll_node *tail;
  unsigned int len;
} t_dll;

typedef struct s_hashcontent
{
	char	*key;
	char	*value;
}		t_hashcontent;

typedef struct s_hashmap
{
	int		elem_num;
	int		capacity;
	t_dll	**arr;
}		t_hashmap;

void print_dll(t_dll *dll);

t_dll_node *new_node(void *data);
void free_node(t_dll_node *node);

t_dll *dll_init();
void *dll_append(t_dll *dll, void *data);
void *dll_prepend(t_dll *dll, void *data);
void dll_remove(t_dll *dll, t_dll_node *node);
t_dll_node	*dll_find(t_dll *dll, void *target, int (*cmp)(void *, void *));

int		hashing(t_hashmap *hashmap, char *key);
int		cmp(void *value, void *target);
void	init_hashmap(t_hashmap *hashmap);
void	insert(t_hashmap *hashmap, char *key, char *value);
void	delete(t_hashmap *hashmap, char *key);
char	*search(t_hashmap *hashmap, char *key);

#endif

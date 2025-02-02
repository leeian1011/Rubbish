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

typedef struct s_tree
{
	t_dll			*childs;
	void			*item;

}			t_tree;


// doubly linked list
void print_dll(t_dll *dll);

t_dll_node *new_node(void *data);
void free_node(t_dll_node *node);

t_dll *dll_init();
void *dll_append(t_dll *dll, void *data);
void *dll_prepend(t_dll *dll, void *data);
void dll_remove(t_dll *dll, t_dll_node *node, void *(f)(void *));
void dll_clear(t_dll* dll);
t_dll_node	*dll_find(t_dll *dll, void *target, int (*cmp)(void *, void *));

// hashmap
int		hashing(t_hashmap *hashmap, char *key);
int		cmp(void *value, void *target);
void	init_hashmap(t_hashmap *hashmap);
void	hash_insert(t_hashmap *hashmap, char *key, char *value);
void	hash_delete(t_hashmap *hashmap, char *key);
char	*hash_search(t_hashmap *hashmap, char *key);
char	**hash_get_all_keys(t_hashmap *hashmap);
int		hash_count(t_hashmap *hashmap);

// general tree
t_tree	*tree_create_node(void *item);
void	tree_make_child(t_tree **root, void *item);
void	tree_make_child_reversed(t_tree **head, void *item);
void	tree_postorder_traversal(t_tree *head);
void	execute_tree_node(t_tree *head);

#endif

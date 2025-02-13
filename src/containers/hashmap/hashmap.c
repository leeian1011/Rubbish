/* ************************************************************************** */
/*                                                                            */ /*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:49:30 by jianwong          #+#    #+#             */
/*   Updated: 2025/02/02 23:11:55 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/containers.h"

void	init_hashmap(t_hashmap *hashmap)
{
	int	i;

	i = 0;
	hashmap->elem_num = 100;
	hashmap->capacity = 0;
	hashmap->arr = ft_calloc(sizeof(t_dll *), hashmap->elem_num);
	if (!hashmap->arr)
		return ;
	while (i < hashmap->elem_num)
		hashmap->arr[i++] = dll_init();
}

void	hash_insert(t_hashmap *hashmap, char *key, char *value)
{
	int	index;
	t_dll	*nodes;
	t_hashcontent	*content;
	t_dll_node	*node;

	index = hashing(hashmap, key);
	nodes = hashmap->arr[index];
	node = dll_find(nodes, key, cmp);
	if (!node)
	{
		content = malloc(sizeof(t_hashcontent));
		if (!content)
			return ;
		content->key = key;
		content->value = value;
		dll_append(nodes, content);
	}
	else
		((t_hashcontent *)node->data)->value = value;
}

void	hash_delete(t_hashmap *hashmap, char *key)
{
	int	index;
	t_dll	*nodes;
	t_dll_node	*node;

	index = hashing(hashmap, key);
	nodes = hashmap->arr[index];
	node = dll_find(nodes, key, cmp);
	if (node)
		dll_remove(nodes, node, NULL);
}

char	*hash_search(t_hashmap *hashmap, char *key)
{
	int	index;
	t_dll	*nodes;
	t_dll_node	*node;

	index = hashing(hashmap, key);
	nodes = hashmap->arr[index];
	node = dll_find(nodes, key, cmp);
	if (!node)
		return (ft_strdup(""));
	return (((t_hashcontent *)node->data)->value);
}

int		hash_count(t_hashmap *hashmap)
{
	int		i;
	int		count;
	t_dll	*dll;
	t_dll_node	*temp;

	count	= 0;
	i = 0;
	while (i < hashmap->elem_num)
	{
		dll = hashmap->arr[i];
		if (dll)
		{
			temp = dll->head;
			while (temp)
			{
				count++;
				temp = temp->next;
			}
		}
		i++;
	}
	return (count);
}

char	**hash_get_all_keys(t_hashmap *hashmap)
{
	char	**keys;
	t_dll	*dll;
	t_dll_node	*temp;
	int	i;
	int	key_idx;

	keys = ft_calloc(sizeof(char *), hash_count(hashmap) + 1);
	if (!keys)
		return (NULL);
	i = 0;
	key_idx = 0;
	while (i < hashmap->elem_num)
	{
		dll = hashmap->arr[i];
		if (dll)
		{
			temp = dll->head;
			while (temp)
			{
				keys[key_idx++] = ((t_hashcontent *)temp->data)->key;
				temp = temp->next;
			}
		}
		i++;
	}
	return (keys);
}

// int	main(void)
// {
// 	t_hashmap hashmap;
//
// 	init_hashmap(&hashmap);
// 	hash_insert(&hashmap, "indian", "Joshua");
// 	hash_insert(&hashmap, "shoe", "Nike");
// 	hash_insert(&hashmap, "indain", "man");
// 	hash_insert(&hashmap, "nndaii", "man");
// 	hash_insert(&hashmap, "shoe", "Adidas");
// 	hash_insert(&hashmap, "Chinese", "Rights");
// 	hash_delete(&hashmap, "indian");
// 	printf("%s\n", hash_search(&hashmap, "indian"));
// 	printf("%s\n", hash_search(&hashmap, "shoe"));
// 	printf("%s\n", hash_search(&hashmap, "indain"));
// 	printf("%s\n", hash_search(&hashmap, "nndaii"));
// 	printf("%s\n", hash_search(&hashmap, "Chinese"));
// }

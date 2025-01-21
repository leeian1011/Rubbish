/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:49:30 by jianwong          #+#    #+#             */
/*   Updated: 2025/01/21 21:40:42 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../..//includes/containers.h"

t_dll	*create_node(char *key, char *value)
{
	t_dll	*result;
	t_hashcontent	*content;

	content = malloc(sizeof(t_hashcontent));
	if (!content)
	{
		free(result);
		return (NULL);
	}
	content->key = key;
	content->value = value;
	dll_append(result, content);
	result->tail->data = content;
	return (result);
}

void	init_hashmap(t_hashmap *hashmap)
{
	hashmap->elem_num = 100;
	hashmap->capacity = 0;
	hashmap->arr = ft_calloc(hashmap->elem_num, sizeof(t_dll *));
	if (!hashmap->arr)
		return ;
}

int		hashing(t_hashmap *hashmap, char *key)
{
	int	index;

	index = 0;
	while (*key)
		index += *key++;
	index = index % hashmap->capacity;
	return (index);
}

void	insert(t_hashmap *hashmap, char *key, char *value)
{
	int	index;
	t_dll	*nodes;
	t_hashcontent	*content;

	index = hashing(hashmap, key);
	content = malloc(sizeof(t_hashcontent));
	if (!content)
		return ;
	content->key = key;
	content->value = value;
	hashmap->arr[index] = dll_append(nodes, content);
}

int	main(void)
{
	t_hashmap hashmap;

	init_hashmap(&hashmap);

}

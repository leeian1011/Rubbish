/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:06:17 by jianwong          #+#    #+#             */
/*   Updated: 2025/01/27 12:05:12 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/containers.h"
#include <stdio.h>

int		hashing(t_hashmap *hashmap, char *key)
{
	int	index;

	index = 0;
	while (*key)
		index += *key++;
	index = index % hashmap->elem_num;
	return (index);
}

int	cmp(void *value, void *target)
{
	t_hashcontent		*t_value;
	char *t_target;

	t_value = (t_hashcontent *)value;
	t_target = (char *)target;
	if (!ft_strncmp(t_value->key, t_target, -1))
		return (1);
	return (0);
}

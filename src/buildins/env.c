/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:47:02 by jianwong          #+#    #+#             */
/*   Updated: 2025/02/02 23:51:20 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buildins.h"

int		env(t_hashmap *hashmap)
{
	char	**temp;
	int		i;

	i = -1;
	temp = hash_get_all_keys(hashmap);
	while (temp[++i])
		printf("%s=%s\n", temp[i], hash_search(hashmap, temp[i]));
	return (0);
}

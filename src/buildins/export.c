/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:13:25 by jianwong          #+#    #+#             */
/*   Updated: 2025/01/27 12:19:59 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buildins.h"
#include <stdio.h>

void	process_temp(char **temp)
{
	char	*str_temp;

	if (!temp[1])
		temp[1] = ft_strdup("");
	str_temp = ft_strjoin("\"", temp[1]);
	free(temp[1]);
	temp[1] = ft_strjoin(str_temp, "\"");
	free(str_temp);
}

int	export(t_hashmap *hashmap, char *str)
{
	char	**temp;

	if (!str)
	{
		hash_print(hashmap, "declare -x");
		return (0);
	}
	temp = ft_split(str, '=');
	printf("%p\n", temp[1]);
	process_temp(temp);
	hash_insert(hashmap, temp[0], temp[1]);
	free(temp);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_hashmap hashmap;

	init_hashmap(&hashmap);
	while (*envp)
		export(&hashmap, *envp++);
	export(&hashmap, NULL);
}

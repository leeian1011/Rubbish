/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:13:25 by jianwong          #+#    #+#             */
/*   Updated: 2025/02/02 23:52:50 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buildins.h"

static int	str_cmp(const void *data1, const void *data2)
{
	return (ft_strncmp(*(char **)data1, *(char **)data2, -1));
}

int	export(t_hashmap *hashmap, char *str)
{
	char	**temp;
	int		i;

	i = -1;
	if (!str)
	{
		temp = hash_get_all_keys(hashmap);
		ft_qsort(temp, hash_count(hashmap), sizeof(char *), str_cmp);
		while (temp[++i])
			printf("declare -x \"%s=%s\"\n",temp[i], hash_search(hashmap, temp[i]));
		free(temp);
		return (0);
	}
	temp = ft_split(str, '=');
	hash_insert(hashmap, temp[0], temp[1]);
	free(temp);
	return (0);
}

/*int		env(t_hashmap *hashmap)*/
/*{*/
/*	char	**temp;*/
/*	int		i;*/
/**/
/*	i = -1;*/
/*	temp = hash_get_all_keys(hashmap);*/
/*	while (temp[++i])*/
/*		printf("%s=%s\n", temp[i], hash_search(hashmap, temp[i]));*/
/*	return (0);*/
/*}*/
/*int		unset(t_hashmap *hashmap, char *key)*/
/*{*/
/*	if (!key)*/
/*		return (0);*/
/*	hash_delete(hashmap, key);*/
/*	return (0);*/
/*}*/
/**/
/*int	main(int argc, char **argv, char **envp)*/
/*{*/
/*	t_hashmap hashmap;*/
/**/
/*	init_hashmap(&hashmap);*/
/*	while (*envp)*/
/*		export(&hashmap, *envp++);*/
	/*env(&hashmap);*/
/*	unset(&hashmap, NULL);*/
/*	export(&hashmap, NULL);*/
/*	printf("+++++++++++++++++++++\n");*/
/*	unset(&hashmap, "HOME");*/
/*	export(&hashmap, NULL);*/
/*	printf("+++++++++++++++++++++\n");*/
/*	unset(&hashmap, "NON");*/
/*	export(&hashmap, NULL);*/
/*}*/

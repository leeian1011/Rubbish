/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 01:09:36 by jianwong          #+#    #+#             */
/*   Updated: 2025/02/06 14:58:30 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buildins.h"
#include "../../includes/containers.h"

/// takes in path string and potentially env var to fill in empty with HOME
int	cd(char *path, t_hashmap *hashmap)
{
	char	cwd[PATH_MAX];

	if (!path)
		path = hash_search(hashmap, "HOME");
	if (chdir(path) == -1)
	{
		perror("cd");
		return (1);
	}
	return (0);
}

// int	pwd(void)
// {
// 	char	cwd[PATH_MAX];
//
// 	if (!getcwd(cwd, PATH_MAX))
// 	{
// 		perror("pwd");
// 		return (1);
// 	}
// 	printf("%s\n", cwd);
// 	return (0);
// }
//
// int	main(int argc, char **argv, char **envp)
// {
// 	t_hashmap hashmap;
//
// 	char **temp;
// 	init_hashmap(&hashmap);
// 	while (*envp)
// 		ft_export(&hashmap, *envp++);
// 	// {
// 	// 	temp = ft_split(*envp++, '=');
// 	// 	hash_insert(&hashmap, temp[0], temp[1]);
// 	// }
// /*	init_hashmap(&hashmap);*/
// /*	while (*envp)*/
// /*		export(&hashmap, *envp++);*/
// 	cd("/bin", &hashmap);
// 	pwd();
// 	cd("..", &hashmap);
// 	pwd();
// 	cd(NULL, &hashmap);
// 	pwd();
// 	return 0; 
// }

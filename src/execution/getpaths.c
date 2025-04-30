/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpaths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:03:20 by jianwong          #+#    #+#             */
/*   Updated: 2025/04/30 21:23:11 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rubbish.h"

static int	check_slash(char *str)
{
	int	i;
	int	slash;

	slash = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			slash++;
		i++;
	}
	return (slash);
}

static char	**get_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5))
			return (ft_split(env[i] + 5, ':'));
		i++;
	}
	return (NULL);
}

// Helper function: Search command in PATH
static char	*search_in_path(char **env_path, char *cmd)
{
	int		i;
	char	*aux;
	char	*path_and_cmd;

	i = 0;
	while (env_path[i])
	{
		aux = ft_strjoin(env_path[i++], "/");
		path_and_cmd = ft_strjoin(aux, cmd);
		free(aux);
		if (access(path_and_cmd, F_OK) == 0)
			return (path_and_cmd);
		free(path_and_cmd);
	}
	return (NULL);
}

// Main function: Get command or path
char	*gcop(char **env, char *str)
{
	char	**env_path;
	char	*result;

	if (check_slash(str) > 0 && !access(str, F_OK))
		return (ft_strdup(str));
	else if (check_slash(str) == 0)
	{
		env_path = get_path(env);
		if (env_path)
		{
			result = search_in_path(env_path, str);
			ft_free_split(env_path);
			return (result);
		}
	}
	return (NULL);
}

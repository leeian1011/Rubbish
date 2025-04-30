/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:13:25 by jianwong          #+#    #+#             */
/*   Updated: 2025/04/30 18:27:44 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rubbish.h"
#include <unistd.h>

int	find_equal(char *var, int *found)
{
	int	i;

	i = 0;
	*found = 0;
	while (var[i])
	{
		if (var[i] == '=')
			*found = i;
		i++;
	}
	return (*found);
}

static void	export_declare(char **env)
{
	int	i;
	int	j;
	int	first_eq;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "_=", 2) == 0)
			i++;
		else
		{
			j = 0;
			ft_putstr_fd("declare -x ", STDOUT_FILENO);
			while (env[i][j])
			{
				write(1, &env[i][j], STDOUT_FILENO);
				if (j == find_equal(env[i], &first_eq))
					write(1, "\"", STDOUT_FILENO);
				j++;
			}
			ft_putendl_fd("\"", STDOUT_FILENO);
			i++;
		}
	}
}

static char	**export_del(char **env, char **cmdargs, int i, int found)
{
	char	*var_only;

	var_only = ft_substr(cmdargs[i], 0, found);
	env = del_var(env, var_only);
	free(var_only);
	return (env);
}

static char	**handle_export(char **env, char **cmdargs)
{
	int		i;
	int		j;
	int		found;

	i = 1;
	found = 0;
	while (cmdargs[i])
	{
		if (find_equal(cmdargs[i], &found) == 0)
		{
			i++;
			continue ;
		}
		j = 0;
		while (env[++j])
		{
			if (ft_strncmp(cmdargs[i], env[j], found + 1) == 0)
			{
				env = export_del(env, cmdargs, i, found);
				j--;
			}
		}
		i++;
	}
	return (env);
}

int	rbsh_export(t_cmd *cmd)
{
	int		i;

	g_ecode = 0;
	if (!cmd->full_cmd[1])
	{
		export_declare(cmd->info->envcp);
		return (0);
	}
	cmd->info->envcp = handle_export(cmd->info->envcp, cmd->full_cmd);
	i = 1;
	while (cmd->full_cmd[i])
	{
		if (ft_strchr(cmd->full_cmd[i], '='))
			cmd->info->envcp = add_var(cmd->info->envcp, cmd->full_cmd[i]);
		i++;
	}
	return (0);
}

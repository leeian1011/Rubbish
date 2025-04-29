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

#include "../../includes/rubbish.h"

static int	is_dir(const char *name)
{
	DIR	*dir;

	dir = opendir(name);
	if (dir)
	{
		closedir(dir);
		return (0);
	}
	if (errno == ENOTDIR)
		return (1);
	return (-1);
}

static char	**cd_update_env(char **env, char *path)
{
	char	*var;
	char	*pwd;
	char	**envcpy;

	pwd = getcwd(NULL, 0);
	envcpy = del_var(env, "OLDPWD");
	var = ft_strjoin("OLDPWD=", pwd);
	envcpy = add_var(envcpy, var);
	free(var);
	free(pwd);
	chdir(path);
	envcpy = del_var(envcpy, "PWD");
	pwd = getcwd(NULL, 0);
	var = ft_strjoin("PWD=", pwd);
	envcpy = add_var(envcpy, var);
	free(var);
	free(pwd);
	return (envcpy);
}

void	cd_home(t_cmd *cmd, char ***envcpy)
{
	char	*path;
	int		found;

  (void)envcpy;
	found = found_in_env("HOME=", cmd->info->envcp, &path);
	if (found && is_dir(path) == -1)
		error(NDIR, path, 1);
	else if (found)
		cmd->info->envcp = cd_update_env(cmd->info->envcp, path);
	else
		builtin_error(HOMSET, "cd:", 1);
	if (found)
		free(path);
}

static void	cd_oldpwd(t_cmd *cmd, char ***envcpy)
{
	char	*path;

  (void)envcpy;
	if (found_in_env("OLDPWD=", cmd->info->envcp, &path) == 1)
	{
		cmd->info->envcp = cd_update_env(cmd->info->envcp, path);
		pwd();
		free(path);
	}
	else
		builtin_error(OPWDSET, "cd:", 1);
}

static void	cd_tilde(t_cmd *cmd, char ***envcpy)
{
	int		found;
	char	*path;

  (void)envcpy;
	found = found_in_env("HOME=", cmd->info->envcp, &path);
	if (found && !is_dir(path))
		cmd->info->envcp = cd_update_env(cmd->info->envcp, path);
	else if (found && is_dir(path) == -1)
		error(NDIR, path, 1);
	else
		cmd->info->envcp = cd_update_env(cmd->info->envcp, cmd->info->homepath);
	if (found)
		free(path);
}


int	cd(t_cmd *cmd)
{
	char	**envcpy;

	envcpy = cmd->info->envcp;
	if (cmd->full_cmd[1] == NULL || ft_strcmp(cmd->full_cmd[1], "--") == 0)
		cd_home(cmd, &envcpy);
	else if (ft_strcmp(cmd->full_cmd[1], "~") == 0)
		cd_tilde(cmd, &envcpy);
	else if (ft_strcmp(cmd->full_cmd[1], "-") == 0)
		cd_oldpwd(cmd, &envcpy);
	else
	{
		if (access(cmd->full_cmd[1], F_OK) == 0 && !is_dir(cmd->full_cmd[1]))
			cmd->info->envcp = cd_update_env(cmd->info->envcp, cmd->full_cmd[1]);
		else if (is_dir(cmd->full_cmd[1]) == 1)
			error(NOT_DIR, cmd->full_cmd[1], 1);
		else
			error(NDIR, cmd->full_cmd[1], 1);
	}
	g_ecode = 0;
	return (0);
}

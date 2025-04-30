/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rubbish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:27:31 by jianwong          #+#    #+#             */
/*   Updated: 2025/04/30 21:53:45 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rubbish.h"

int	g_ecode;

static int	validate_env(char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
		i++;
	if (i == 0)
		return (0);
	else
		return (1);
}

//Function to free all the content in INFO
void	free_info(t_info *info)
{
	if (info->envcp)
		ft_free_split(info->envcp);
	free (info);
}

int	main(int argc, char **argv, char **env)
{
	t_info	*info;

	(void)argv;
	g_ecode = 0;
	if (!validate_env(env))
		return (ft_printf("Invalid env\n"), -1);
	if (argc != 1)
		return (ft_printf("Invalid arguments\n"), -2);
	info = malloc(sizeof(t_info));
	if (!info)
		return (error(MEM, NULL, 2), 2);
	info->envcp = clone_env(env);
	info->envcp = del_var(info->envcp, "_");
	info->envcp = add_var(info->envcp, "_=/usr/bin/env");
	info->envcp = del_var(info->envcp, "OLDPWD");
	info->homepath = getenv("HOME");
	if (!info->homepath)
	{
		ft_printf("Invalid Home\n");
		return (-1);
	}
	prompt_loop(info);
	free_info(info);
	return (g_ecode);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:58:24 by jianwong          #+#    #+#             */
/*   Updated: 2025/04/30 17:00:49 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rubbish.h"

static t_cmd	*ft_init_cmds(t_info *info)
{
	t_cmd	*cmds;
	int		i;

	i = 0;
	cmds = malloc(sizeof(t_cmd) * info->cmd_amount);
	if (!cmds)
		return (error(MEM, NULL, 2));
	while (i < info->cmd_amount)
	{
		cmds[i].full_cmd = NULL;
		cmds[i].path = NULL;
		cmds[i].infile = NULL;
		cmds[i].outfile = NULL;
		cmds[i].limit = NULL;
		cmds[i].in_flag = 0;
		cmds[i].out_flag = 0;
		cmds[i].type = 0;
		cmds[i].info = info;
		cmds[i].cmd_num = 0;
		i++;
	}
	return (cmds);
}

static void	node_cmd_count(t_cmd *cmds)
{
	int	i;
	int	i_init;
	int	cnt;

	i = 0;
	while (i < cmds->info->cmd_amount)
	{
		cnt = 0;
		if (cmds[i].type == CMD || cmds[i].type == BUILTIN)
		{
			i_init = i;
			while (i < cmds->info->cmd_amount && (cmds[i].type == CMD
					|| cmds[i].type == BUILTIN || cmds[i].type == T_PIPE))
				if (cmds[i++].type != T_PIPE)
					cnt++;
			i = i_init;
			while (i < cmds->info->cmd_amount && (cmds[i].type == CMD
					|| cmds[i].type == BUILTIN || cmds[i].type == T_PIPE))
			{
				cmds[i].cmd_real_num = 2 * cnt - 1;
				cmds[i++].cmd_num = cnt;
			}
		}
		i++;
	}
}

//Returns the node quantity tto be allocated for the parsing of str
static int	node_count(char **str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (*str)
	{
		if (ft_strncmp(*str, "|", 2) && ft_strncmp(*str, "&&", 3)
			&& ft_strncmp(*str, "||", 3) && ft_strncmp(*str, "(", 2)
			&& ft_strncmp(*str, ")", 2))
		{
			if (!flag)
			{
				flag = 1;
				i++;
			}
		}
		else
		{
			flag = 0;
			i++;
		}
		str++;
	}
	return (i);
}

//Returns the str info into an array of t_cmd
//Mallocs space for array of t_cmd and for the general info
//It does not free the str
t_cmd	*parse_cmd(char **str, t_info *info)
{
	t_cmd	*cmds;
	int		i;

	i = 0;
	info->cmd_amount = node_count(str);
	info->fd = NULL;
	cmds = ft_init_cmds(info);
	if (!cmds)
	{
		free_info(info);
		return (NULL);
	}
	while (i < info->cmd_amount)
	{
		str = parse_cmd_loop(&cmds[i], str, info->envcp);
		handle_wildcard(&cmds[i]);
		i++;
	}
	node_cmd_count(cmds);
	return (cmds);
}

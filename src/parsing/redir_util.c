/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:58:28 by jianwong          #+#    #+#             */
/*   Updated: 2025/04/30 16:58:40 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rubbish.h"

static char	**get_redir_file(t_cmd *cmd, char **s, int *f)
{
	if (*s && (!ft_strncmp(*s, ">", 2) || !ft_strncmp(*s, ">>", 3)
			|| !ft_strncmp("<", *s, 2) || !ft_strncmp(*s, "<<", 3)) && ++(*f))
	{
		if (!ft_strncmp("<", *s, 2))
			cmd->in_flag = 1;
		else if (!ft_strncmp(*s, ">", 2))
			cmd->out_flag = 1;
		else if (!ft_strncmp(*s, ">>", 3))
			cmd->out_flag = 2;
		else
			cmd->in_flag = 2;
		s++;
		if (*s && !ft_strchr("<|>", **s))
		{
			if (cmd->out_flag)
				cmd->outfile = ft_strdup(*s);
			else if (cmd->in_flag == 1)
				cmd->infile = ft_strdup(*(s));
			else if (cmd->in_flag == 2)
				cmd->limit = ft_strdup(*(s));
		}
		if (*s)
			s++;
	}
	return (s);
}

char	**redir_file(t_cmd *cmd, char **str)
{
	int	flag;

	flag = 0;
	str = get_redir_file(cmd, str, &flag);
	if (flag)
		str = redir_file(cmd, str);
	return (str);
}

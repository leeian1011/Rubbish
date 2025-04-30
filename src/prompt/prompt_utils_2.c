/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:43:23 by jianwong          #+#    #+#             */
/*   Updated: 2025/04/30 16:44:43 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rubbish.h"

void	open_outfiles(t_cmd *cmds)
{
	int	i;
	int	fd;

	i = 0;
	while (i < cmds->info->cmd_amount)
	{
		if (cmds[i].outfile)
		{
			fd = open(cmds[i].outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
			close(fd);
		}
		i++;
	}
}

int	advance_to_last_r_par(t_cmd *cmds, int *idx)
{
	int		count;
	int		r_count;

	count = 1;
	r_count = 0;
	while (*idx < cmds->info->cmd_amount)
	{
		if (cmds[*idx].type == L_PAR)
			count++;
		else if (cmds[*idx].type == R_PAR)
		{
			r_count++;
			if (r_count == count)
				break ;
		}
		(*idx)++;
	}
	if (*idx < cmds->info->cmd_amount)
		(*idx)++;
	return (count);
}

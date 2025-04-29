/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:15:36 by jianwong          #+#    #+#             */
/*   Updated: 2025/01/20 01:49:38 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rubbish.h"

int	echo(t_cmd *cmd)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	if (cmd->full_cmd[1] != NULL && !ft_strcmp(cmd->full_cmd[1], "-n"))
	{
		cmd->full_cmd++;
		flag++;
	}
	while (cmd->full_cmd[i])
	{
		if (i > 1)
			write(1, " ", 1);
		ft_putstr_fd(cmd->full_cmd[i], 1);
		i++;
	}
	if (flag == 0)
		write(1, "\n", 1);
	return (0);
}

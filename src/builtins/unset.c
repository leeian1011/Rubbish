/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:18:16 by jianwong          #+#    #+#             */
/*   Updated: 2025/02/02 23:52:52 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rubbish.h"

int	unset(t_cmd *cmd)
{
	int		i;

	i = 1;
	while (cmd->full_cmd[i])
	{
		cmd->info->envcp = del_var(cmd->info->envcp, cmd->full_cmd[i]);
		i++;
	}
	g_ecode = 0;
	return (0);
}

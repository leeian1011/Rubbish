/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:56:26 by jianwong          #+#    #+#             */
/*   Updated: 2025/02/04 00:10:00 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rubbish.h"

static int	atoi_exit(const char *str, long *nbr)
{
	unsigned int	i;
	int				sign;

	i = 0;
	sign = 1;
	*nbr = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		*nbr = *nbr * 10 + str[i] - '0';
		i++;
	}
	if (!str[i])
	{
		return (*nbr *= sign, 0);
	}
	return (-1);
}

int	rbsh_exit(t_cmd *cmd)
{
	long	nbr;

	ft_printf("exit\n");
	if (!cmd->full_cmd[1])
	{
		g_ecode = 0;
		return (1);
	}
	if (atoi_exit(cmd->full_cmd[1], &nbr) < 0)
	{
		ft_printf("rbsh: exit: %s: numeric argument required\n", \
			cmd->full_cmd[1]);
		g_ecode = 255;
	}
	else if (cmd->full_cmd[2])
	{
		ft_printf("rbsh: exit: too many arguments\n");
		g_ecode = 1;
		return (0);
	}
	else
		g_ecode = nbr % 256;
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:32:20 by jianwong          #+#    #+#             */
/*   Updated: 2025/04/30 21:48:30 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rubbish.h"

static void	set_signals(t_cmd *cmd, int i)
{
	struct sigaction	sa;

	if (cmd[i].in_flag == 2)
	{
		sa.sa_handler = SIG_IGN;
		sigaction(SIGQUIT, &sa, NULL);
		sigemptyset(&sa.sa_mask);
	}
}

static int	handle_buildins(t_cmd *cmd, int i)
{
	if (cmd[i].type == BUILTIN && (\
!ft_strncmp(cmd[i].full_cmd[0], "export", 7) \
|| !ft_strncmp(cmd[i].full_cmd[0], "exit", 5) \
|| !ft_strncmp(cmd[i].full_cmd[0], "unset", 6) \
|| !ft_strncmp(cmd[i].full_cmd[0], "cd", 3)))
	{
		if (execute_builtin(&cmd[i]))
			exit(g_ecode);
		return (1);
	}
	return (0);
}

int	execution_loop(t_cmd *cmd)
{
	pid_t				pid;
	int					i;

	i = 0;
	while (i < cmd->cmd_real_num)
	{
		set_signals(cmd, i);
		if (handle_buildins(cmd, i))
		{
			i++;
			continue ;
		}
		if (cmd[i].type != T_PIPE)
		{
			pid = fork();
			if (pid < 0)
				return (error(FORKERR, NULL, 4), 1);
			fork_execution(cmd, i, pid);
		}
		else if (cmd[i].type != T_PIPE)
			pipe_fd_close(cmd, i);
		i++;
	}
	return (0);
}

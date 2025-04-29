#include "../../includes/rubbish.h"

static void	fork_execution(t_cmd *cmd, int i, pid_t pid)
{
	struct sigaction	sa;

	if (pid == 0)
		child_execution(&cmd[i], i);
	pipe_fd_close(cmd, i);
	waitpid(pid, &g_ecode, 0);
	if (WIFSIGNALED(g_ecode))
	{
		if (WTERMSIG(g_ecode) == 2)
			g_ecode = 130;
		else if (WTERMSIG(g_ecode) == 3)
			g_ecode = 131;
	}
	else
		g_ecode = WEXITSTATUS(g_ecode);
	sa.sa_handler = &sig_forked_handler;
	sigaction(SIGQUIT, &sa, NULL);
  sigemptyset(&sa.sa_mask);
}

static int	execution_loop(t_cmd *cmd)
{
	pid_t				pid;
	int					i;
	struct sigaction	sa;

	i = 0;
	while (i < cmd->cmd_real_num)
	{
		if (cmd[i].in_flag == 2)
		{
			sa.sa_handler = SIG_IGN;
			sigaction(SIGQUIT, &sa, NULL);
      sigemptyset(&sa.sa_mask);
		}
    if (cmd[i].type == BUILTIN && (!ft_strncmp(cmd[i].full_cmd[0], "export", 7)
      || !ft_strncmp(cmd[i].full_cmd[0], "exit", 5)
      || !ft_strncmp(cmd[i].full_cmd[0], "unset", 6)
      || !ft_strncmp(cmd[i].full_cmd[0], "cd", 3))) {
      if (execute_builtin(&cmd[i]))
        exit(g_ecode);
      i++;
      continue;
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

static void	pipe_init(t_cmd *cmd)
{
	int	i;

	i = 0;
	cmd->info->fd = malloc(sizeof(int *) * (cmd->cmd_num - 1));
	if (!cmd->info->fd)
		return ;
	while (i < cmd->cmd_num - 1)
	{
		cmd->info->fd[i] = malloc(sizeof(int) * 2);
		pipe(cmd->info->fd[i]);
		i++;
	}
}

static void	free_fd(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (i < cmd->cmd_num - 1)
		free(cmd->info->fd[i++]);
	free(cmd->info->fd);
}

void	execute(t_cmd *cmd)
{
	struct sigaction	sa;

	sa.sa_handler = &sig_forked_handler;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
  sigemptyset(&sa.sa_mask);
	pipe_init(cmd);
	if (!cmd->info->fd)
		return ;
	if (execution_loop(cmd))
		return ;
	free_fd(cmd);
}

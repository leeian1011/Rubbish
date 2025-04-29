#include "../../includes/rubbish.h"

static void	handle_pipes(t_cmd *cmd, int n)
{
	n = (n / 2) + (n % 2);
	if (n == 0 && cmd->out_flag == 0)
	{
		if (dup2(cmd->info->fd[n][1], STDOUT_FILENO) < 0)
			error(DUPERR, NULL, 5);
	}
	else if (n == cmd->cmd_num - 1 && cmd->in_flag == 0)
	{
		if (dup2(cmd->info->fd[n - 1][0], STDIN_FILENO) < 0)
			error(DUPERR, NULL, 5);
	}
	else if (n > 0 && n < cmd->cmd_num - 1)
	{
		if (cmd->out_flag == 0)
		{
			if (dup2(cmd->info->fd[n][1], STDOUT_FILENO) < 0)
				error(DUPERR, NULL, 5);
		}
		if (cmd->in_flag == 0)
		{
			if (dup2(cmd->info->fd[n - 1][0], STDIN_FILENO) < 0)
				error(DUPERR, NULL, 5);
		}
	}
}

static void	handle_in_redirect(t_cmd *cmd)
{
	int	fd_in;

	if (cmd->in_flag == 1)
	{
		fd_in = open(cmd->infile, O_RDONLY);
		if (dup2(fd_in, STDIN_FILENO) < 0)
			error(DUPERR, NULL, 5);
		close(fd_in);
	}
	if (cmd->in_flag == 2)
	{
		write_heredoc_tmp(cmd);
		fd_in = open(".tmp", O_RDONLY);
		if (dup2(fd_in, STDIN_FILENO) < 0)
			error(DUPERR, NULL, 5);
		unlink(".tmp");
		close(fd_in);
	}
}

static void	handle_out_redirect(t_cmd *cmd)
{
	int	fd_out;

	if (cmd->out_flag == 1)
	{
		fd_out = open(cmd->outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (dup2(fd_out, STDOUT_FILENO) < 0)
			error(DUPERR, NULL, 5);
		close(fd_out);
	}
	if (cmd->out_flag == 2)
	{
		fd_out = open(cmd->outfile, O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (dup2(fd_out, STDOUT_FILENO) < 0)
			error(DUPERR, NULL, 5);
		close(fd_out);
	}
}

void	pipe_fd_close(t_cmd *cmd, int qj)
{
	int	i;
	int	j;

	i = 0;
	j = (qj / 2) + (qj % 2);
	while (i < j)
	{
		close(cmd->info->fd[i][0]);
		close(cmd->info->fd[i][1]);
		i++;
	}
}

void	child_execution(t_cmd *cmd, int n)
{
	struct sigaction	sa;

  (void)n;
	sa.sa_handler = SIG_DFL;
	sigaction(SIGINT, &sa, NULL);
	if (cmd->cmd_num > 1)
		handle_pipes(cmd, n);
	if (cmd->in_flag > 0)
		handle_in_redirect(cmd);
	if (cmd->out_flag > 0)
		handle_out_redirect(cmd);
	pipe_fd_close(cmd, cmd->cmd_real_num - 1);
	sa.sa_handler = SIG_DFL;
	sigaction(SIGQUIT, &sa, NULL);
  sigemptyset(&sa.sa_mask);
  if (cmd->type == BUILTIN)
  {
    execute_builtin(cmd);
    exit(g_ecode);
  }
	execve(cmd->path, cmd->full_cmd, NULL);
}

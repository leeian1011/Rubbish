/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_operator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:13:09 by jianwong          #+#    #+#             */
/*   Updated: 2025/01/14 15:59:40 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipe_operator.h"

static int	call_process(int *input_fds, int *output_fds, char **cmd)
{
	char	*mod_path;

	mod_path = NULL;
	dup2(input_fds[0], STDIN_FILENO);
	dup2(output_fds[1], STDOUT_FILENO);
	close(input_fds[0]);
	close(input_fds[1]);
	close(output_fds[0]);
	close(output_fds[1]);
	if (execve(cmd[0], cmd, NULL) == -1)
	{
		mod_path = ft_strjoin("/bin/", cmd[0]);
		if (execve(mod_path, cmd, NULL) == -1)
			perror("execve");
		free(mod_path);
		return (1);
	}
	return (0);
}

static	int create_child(int *input, int *output, char **cmd)
{
	int	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (1);
	}
	if (pid == 0)
		if (call_process(input, output, cmd))
			exit(1);
	return (0);
}

/// accepts 2 cmds in char ** where the cmd and flags has been appropriately seperated
/// also require input pipe and output pipefds where input write end will close
/// return non zero on error
/// child will exit on error
int	pipe_operator(char	**cmd1, char **cmd2, \
									int *input_fds, int *output_fds)
{
	int	pipefd[2];

	if (pipe(pipefd) != 0)
	{
		perror("pipefd");
		return (1);
	}
	if (create_child(input_fds, pipefd, cmd1))
		return (2);
	if (create_child(pipefd, output_fds, cmd2))
		return (3);
	close(input_fds[0]);
	close(pipefd[0]);
	close(pipefd[1]);
	close(output_fds[1]);
	return (0);
}

// int	main(void)
// {
// 	int	inputfds[2];
// 	int	outputfds[2];
// 	char *cmd1[3] = {"ls", "-la", NULL};
// 	char *cmd2[2] = {"cat", NULL};
//
// 	pipe(inputfds);
// 	pipe(outputfds);
// 	close(inputfds[1]);
// 	pipe_operator(cmd1, cmd2, inputfds, outputfds);
// 	wait(NULL);
// 	char *line = get_next_line(outputfds[0]);
// 	while (line)
// 	{
// 		printf("%s", line);
// 		line = get_next_line(outputfds[0]);
// 	}
// }

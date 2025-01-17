/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */ /*   input_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:34:38 by jianwong          #+#    #+#             */
/*   Updated: 2025/01/14 15:51:33 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipe_operator.h"

static char	*get_stdin(char *keyword)
{
	char	*buffer;
	char	*line;
	char	*temp;

	buffer = ft_calloc(1, 1);
	if (!buffer)
		return (NULL);
	ft_printf("heredoc> ");
	line = get_next_line(0);
	while (line && (ft_strncmp(line, keyword, ft_strlen(keyword)) \
		|| line[ft_strlen(keyword)] != '\n'))
	{
		temp = ft_strjoin(buffer, line);
		free(buffer);
		free(line);
		buffer = temp;
		ft_printf("heredoc> ");
		line = get_next_line(0);
	}
	free(line);
	return (buffer);
}

/// takes in a input pipe and reads either a file or heredoc into it
/// will close the write end of pipe
/// either file or heredoc must be NULL
/// undefine behaviour if both file and heredoc is entered
int	input_redirection(int *input_pipe, void *file, void *heredoc)
{
	int		fd;
	char	*line;

	fd = -1;
	if (file)
	{
		fd = open((char *)file, O_RDONLY);
		if (fd < 0)
			return (1);
		line = get_next_line(fd);
	}
	else if (heredoc)
		line = get_stdin((char *)heredoc);
	while (line)
	{
		ft_putstr_fd(line, input_pipe[1]);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(input_pipe[1]);
	close(fd);
	return (0);
}

// int	main(void)
// {
// 	int	pipefd[2];
//
// 	pipe(pipefd);
	// input_redirection(pipefd, "text.txt", NULL);
	// char *line = get_next_line(pipefd[0]);
	// while (line)
	// {
	// 	printf("%s\n", line);
	// 	line = get_next_line(pipefd[0]);
	// }
	
	// input_redirection(pipefd, NULL, "EOF");
	// char *line = get_next_line(pipefd[0]);
	// while (line)
	// {
	// 	printf("%s\n", line);
	// 	line = get_next_line(pipefd[0]);
	// }
	// input_redirection(pipefd, "text.txt", "EOF");
	// char *line = get_next_line(pipefd[0]);
	// while (line)
	// {
	// 	printf("%s\n", line);
	// 	line = get_next_line(pipefd[0]);
	// }
// }

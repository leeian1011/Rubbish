/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:51:40 by jianwong          #+#    #+#             */
/*   Updated: 2025/01/14 16:02:52 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipe_operator.h"

/// takes a pipe that is receiving an input, the file to open/create 
/// and the type of output
/// returns non zero on error
int	output_redirection(int *output_pipe, char *file, int append_mode)
{
	int		fd;
	char	*line;

	if (!append_mode)
		fd = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0666);
	else
		fd = open(file, O_WRONLY | O_APPEND | O_CREAT, 0666);
	if (fd < 0)
	{
		perror("open cmd_to_output");
		return (1);
	}
	line = get_next_line(output_pipe[0]);
	while (line)
	{
		ft_putstr_fd(line, fd);
		free(line);
		line = get_next_line(output_pipe[0]);
	}
	close(output_pipe[0]);
	return (0);
}

// int	main(void)
// {
// 	int input[2];
//
// 	pipe(input);
// 	input_redirection(input, "text.txt", NULL);
// 	output_redirection(input, "output", 1);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_operator.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:17:35 by jianwong          #+#    #+#             */
/*   Updated: 2025/01/14 16:02:58 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_OPERATOR_H
# define PIPE_OPERATOR_H

# include "../src/libft/libft.h"
# include <sys/wait.h>

int	pipe_operator(char	**cmd1, char **cmd2, \
									int *input_fds, int *output_fds);

int	input_redirection(int *input_pipe, void *file, void *heredoc);
int	output_redirection(int *output_pipe, char *file, int append_mode);

#endif

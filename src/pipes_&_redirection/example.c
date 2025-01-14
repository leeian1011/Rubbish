/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:08:18 by jianwong          #+#    #+#             */
/*   Updated: 2025/01/14 16:43:23 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../includes/pipe_operator.h"
// #include <unistd.h>
//
// /// create a input file "test.txt" to use
// int	main(void)
// {
// 	char *cmd1[3] = {"ls", "-la", NULL};
// 	char *cmd2[2] = {"cat", NULL};
// 	int input_pipe[2];
// 	int	output_pipe[2];
//
// 	pipe(input_pipe);
// 	pipe(output_pipe);
//
// 	input_redirection(input_pipe, "test.txt", NULL);
// 	pipe_operator(cmd1, cmd2, input_pipe, output_pipe);
// 	output_redirection(output_pipe, "output", 0);
// }
//

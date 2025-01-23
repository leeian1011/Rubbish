/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rubbish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:02:34 by jianwong          #+#    #+#             */
/*   Updated: 2025/01/23 17:17:27 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/containers.h"
#include "../includes/buildins.h"
#include "../includes/parsing.h"
#include "../includes/pipe_operator.h"

int	main(int argc, char **argv, char **env)
{
	char	*line;
	t_dll	*dll;

	dll = dll_init();
	while (true)
	{
		ft_putstr_fd("rbsh-prototype: ", 0);
		line = get_next_line(0);
		if (!line)
			break ;
		if (!parse_line(dll, line))
		{
			printf("parsing error\n");
			continue ;
		}
		print_dll(dll);
	}
}

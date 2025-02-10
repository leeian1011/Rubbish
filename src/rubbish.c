/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rubbish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:02:34 by jianwong          #+#    #+#             */
/*   Updated: 2025/02/10 14:10:53 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/containers.h"
#include "../includes/buildins.h"
#include "../includes/parsing.h"
#include "../includes/pipe_operator.h"
#include "libft/libft.h"

void	free_str(void *data)
{
	free(data);
}

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
		// if (ft_strncmp(line, "exit", 5)
		// {
		//
		// }
		if (!parse_line(dll, line))
		{
			printf("parsing error\n");
			continue ;
		}
		/*print_dll(dll);*/
		if (!ast_build(dll))
			continue ;
		while (dll->head)
			dll_remove(dll, dll->head, free_str);
		dll->tail = NULL;
	}

}

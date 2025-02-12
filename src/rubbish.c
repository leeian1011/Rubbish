/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rubbish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:27:31 by jianwong          #+#    #+#             */
/*   Updated: 2025/02/12 14:27:35 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/containers.h"
#include "../includes/buildins.h"
#include "../includes/parsing.h"
#include "../includes/pipe_operator.h"
#include "libft/libft.h"
#include "../includes/readline.h"
#include <readline/readline.h>

int	main(int argc, char **argv, char **env)
{
	t_tree	*root;
	char	*line;
	t_dll	*dll;

	while (true)
	{
		dll = dll_init();
		line = readline("rbsh: ");
		if (!line)
			break ;
		add_history(line);
		if (!parse_line(dll, line))
		{
			while (dll->head)
				dll_remove(dll, dll->head, free_str);
			printf("parsing error\n");
			continue ;
		}
		free(line);
		root = ast_build(dll);
		if (!root)
		{
			printf("parsing error\n");
			continue ;
		}
		print_tree(root, 0);
		tree_postorder_traversal(root, free_tree);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rubbish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */ /*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:02:34 by jianwong          #+#    #+#             */
/*   Updated: 2025/02/10 15:30:00 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/containers.h"
#include "../includes/buildins.h"
#include "../includes/parsing.h"
#include "../includes/pipe_operator.h"
#include "libft/libft.h"

void	free_str(void *node)
{
	t_dll_node	*n;

	n = (t_dll_node *)node;
	printf("%s\n", (char *)n->data);
	free(n->data);
	n->data = NULL;
}

int	main(int argc, char **argv, char **env)
{
	t_tree	*root;
	char	*line;
	t_dll	*dll;

	while (true)
	{
		dll = dll_init();
		ft_putstr_fd("rbsh-prototype: ", 0);
		line = get_next_line(0);
		if (!line)
			break ;
		if (!parse_line(dll, line))
		{
			printf("parsing error\n");
			continue ;
		}
		free(line);
		root = ast_build(dll);
		if (!root)
			continue ;
		print_tree(root, 0);
		printf("pre len -> %i\n", dll->len);
		while (dll->head)
			dll_remove(dll, dll->head, free_str);
		printf("post len -> %i\n", dll->len);
		tree_postorder_traversal(root, free_tree);
	}
}

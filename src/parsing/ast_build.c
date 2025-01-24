/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:10:59 by jianwong          #+#    #+#             */
/*   Updated: 2025/01/24 22:00:16 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/containers.h"
#include "../../includes/parsing.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


t_tree	*init_list(t_dll *expression)
{
	t_ast	*data;

	data = ft_calloc(1, sizeof(t_ast));
	if (!data)
		return (NULL);
	data->type = LIST;
	data->delimiter = NULL;
	data->tokens = expression;
	return (tree_create_node(data));
}

int	pipe_cmp(void *value, void *target)
{
	char	*t_value;
	char	*t_target;

	t_value = (char *)value;
	t_target = (char *)target;
	if (ft_strnstr(t_target, t_value, ft_strlen(t_target)))
		 return (1);
	return (0);
}

t_dll	*split_dll(t_dll *tokens, char *delimeter)
{
	t_dll	*child_tokens;
	t_dll	*working_dll;
	t_dll_node	*current;

	child_tokens = dll_init();
	current = tokens->head;
	dll_append(child_tokens, dll_init());
	working_dll = child_tokens->head->data;
	while (current)
	{
		if (pipe_cmp(current->data, delimeter))
		{
			dll_append(child_tokens, dll_init());
			working_dll = child_tokens->tail->data;
		}
		dll_append(working_dll, current->data);
		current = current->next;
	}
	return (child_tokens);
}

void	create_pipelines(t_tree *root)
{
	t_dll	*child_tokens;
	t_dll	*tokens;
	t_dll *childs;
	t_dll_node	*temp;
	t_ast	*data;

	tokens = ((t_ast *)root->item)->tokens;
	childs = root->childs;
	child_tokens = split_dll(tokens, AND OR);
	temp = child_tokens->head;
	while (temp)
	{
		data = ft_calloc(1, sizeof(t_ast));
		if (!data)
			return ;
		data->tokens = temp->data;
		data->type = PIPELINE;
		tree_make_child(&root, data);
		temp = temp->next;
	}
}

t_tree	*ast_build(t_dll *expression)
{
	t_tree	*root;

	root = init_list(expression);
	create_pipelines(root);
	tree_postorder_traversal(root);
	return (root);
}

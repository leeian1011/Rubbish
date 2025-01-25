/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:10:59 by jianwong          #+#    #+#             */
/*   Updated: 2025/01/25 16:49:34 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/containers.h"
#include "../../includes/parsing.h"
#include <stdio.h>

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

int	pipe_cmp(void *value)
{
	char	*t_value;

	t_value = (char *)value;
	if (!ft_strncmp(t_value, AND, 3))
		 return (1);
	if (!ft_strncmp(t_value, OR, 3))
		 return (1);
	return (0);
}

int	simple_cmd_cmp(void *value)
{
	char	*t_value;

	t_value = (char *)value;
	if (!ft_strncmp(t_value, PIPE, 2))
		 return (1);
	return (0);
}

t_dll	*split_dll(t_dll *tokens, int (*cmp)(void *))
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
		if (cmp(current->data))
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
	child_tokens = split_dll(tokens, pipe_cmp);
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

void	create_simple_cmds(t_tree *pipeline)
{
	t_dll	*child_tokens;
	t_dll	*tokens;
	t_dll *childs;
	t_dll_node	*temp;
	t_ast	*data;

	tokens = ((t_ast *)pipeline->item)->tokens;
	childs = pipeline->childs;
	if (pipe_cmp(tokens->head->data))
	{
		((t_ast *)pipeline->item)->delimiter = tokens->head->data;
		dll_remove(tokens, tokens->head);
	}
	child_tokens = split_dll(tokens, simple_cmd_cmp);
	temp = child_tokens->head;
	while (temp)
	{
		data = ft_calloc(1, sizeof(t_ast));
		if (!data)
			return ;
		data->tokens = temp->data;
		data->type = SIMPLE_COMMAND;
		tree_make_child(&pipeline, data);
		temp = temp->next;
	}
}

void	create_base_executables(t_tree *simple_cmd)
{

}

t_tree	*ast_build(t_dll *expression)
{
	t_tree	*root;
	t_dll_node		*pipelines;
	t_dll_node		*simple_cmds;

	root = init_list(expression);
	create_pipelines(root);
	pipelines = root->childs->head;
	while (pipelines)
	{
		create_simple_cmds(pipelines->data);
		simple_cmds = ((t_tree *)pipelines->data)->childs->head;
		while (simple_cmds)
		{
			create_base_executables(simple_cmds);
			simple_cmds = simple_cmds->next;
		}
		pipelines = pipelines->next;
	}
	tree_postorder_traversal(root);
	return (root);
}

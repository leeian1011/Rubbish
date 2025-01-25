/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:10:59 by jianwong          #+#    #+#             */
/*   Updated: 2025/01/26 00:35:44 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

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
		data = ast_data_init();
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
		data = ast_data_init();
		data->tokens = temp->data;
		data->type = SIMPLE_COMMAND;
		tree_make_child(&pipeline, data);
		temp = temp->next;
	}
}

void	extract_redirections(t_dll *tokens, t_dll **redirections, t_dll **temp)
{
	t_dll_node	*current;

	current = tokens->head;
	*temp = dll_init();
	*redirections = dll_init();
	while (current)
	{
		if (redirection_cmp(current->data))
		{
			dll_append(*redirections, current->data);
			current = current->next;
			dll_append(*redirections, current->data);
		}
		else
			dll_append(*temp, current->data);
		current = current->next;
	}
}

void	base_executables_helper(t_tree *simple_cmd, bool is_arg)
{
	t_ast	*data;
	t_dll	*redirections;
	t_dll	*arg_group;
	t_dll	*tokens;

	tokens = ((t_ast *)simple_cmd->item)->tokens;
	extract_redirections(tokens, &redirections, &arg_group);
	data = ast_data_init();
	data->tokens = redirections;
	data->type = REDIRECTIONS;
	tree_make_child(&simple_cmd, data);
	data = ast_data_init();
	data->tokens = arg_group;
	if (is_arg)
	{
		data->type = ARGUMENTS;
		tree_make_child(&simple_cmd, data);
	}
	else
	{
		data->type = GROUPING;
		tree_make_child_reversed(&simple_cmd, data);
	}
}

void	create_base_executables(t_tree *simple_cmd)
{
	t_dll	*tokens;

	tokens = ((t_ast *)simple_cmd->item)->tokens;
	if (simple_cmd_cmp(tokens->head->data))
	{
		((t_ast *)simple_cmd->item)->delimiter = tokens->head->data;
		dll_remove(tokens, tokens->head);
	}
	if (ft_strncmp(OB, tokens->head->data, 2))
		base_executables_helper(simple_cmd, true);
	else
		base_executables_helper(simple_cmd, false);
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
			create_base_executables(simple_cmds->data);
			simple_cmds = simple_cmds->next;
		}
		pipelines = pipelines->next;
	}
	tree_postorder_traversal(root);
	return (root);
}

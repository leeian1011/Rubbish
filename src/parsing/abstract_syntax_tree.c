/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abstract_syntax_tree.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:22:31 by jianwong          #+#    #+#             */
/*   Updated: 2025/01/20 22:41:40 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include <cstdlib>
#include <iterator>
#include <stdlib.h>

// add input output pipes to allow childs to talk to each other
int	add_pipes(t_tokens *token, t_tokens **childs)
{
	int	*pipefd;

	pipefd = malloc(sizeof(int) * 2);
	if (!pipefd)
		return (1);
	if (pipe(pipefd) == -1)
		return (2);
	childs[LEFT]->inputfds = token->inputfds;
	childs[LEFT]->outputfds = pipefd;
	childs[RIGHT]->inputfds = pipefd;
	childs[RIGHT]->outputfds = token->outputfds;
	return (0);
}

int	setup_redirection(t_tokens *token, t_tokens **child_tokens)
{
	char	*line;
	int		word_idx;
	int		op_idx;
	int		fd;

	if (!child_tokens[0] || !child_tokens[1])
		return (1);
	word_idx = 1;
	op_idx = 0;
	if (child_tokens[0]->type == WORD)
	{
		word_idx = 0;
		op_idx = 1;
	}
	if (!ft_strncmp(child_tokens[op_idx]->str, OA, 3))
		input_redirection(token->outputfds, child_tokens[word_idx]->str, NULL);
	else if (!ft_strncmp(child_tokens[op_idx]->str, DOA, 5))
		input_redirection(token->outputfds, NULL, child_tokens[word_idx]->str);
	else if (!ft_strncmp(child_tokens[op_idx]->str, CA, 3))
		output_redirection(token->inputfds, child_tokens[word_idx]->str, 0);
	else if (!ft_strncmp(child_tokens[op_idx]->str, DCA, 5))
		output_redirection(token->inputfds, child_tokens[word_idx]->str, 1);
	else
		return (2);
	return (0);
}

int	run_command(t_tokens *token, t_tokens **child_tokens)
{
	
}

void	execute_node(t_tokens *token, t_tokens **child_tokens)
{
	if (token->type == REDIRECTION)
		setup_redirection(token, child_tokens);
	else if (token->type == SIMPLE_COMMAND)
		run_command(token, child_tokens);
}

void	abstract_syntax_tree(t_btree *node)
{
	split_token(node);
	abstract_syntax_tree(node->left);
	abstract_syntax_tree(node->right);
}

int main (int argc, char **argv)
{
	t_btree	*root;
	t_tokens *metadata;

	metadata = malloc(sizeof(t_tokens));
	if (!metadata)
		return (1);
	metadata->type = EXPRESSION;
	metadata->str = argv[1];
	metadata->delimeter = NULL;
	root = btree_create_node(metadata);
	abstract_syntax_tree(root);
}

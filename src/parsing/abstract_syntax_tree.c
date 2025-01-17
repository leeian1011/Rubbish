/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abstract_syntax_tree.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:22:31 by jianwong          #+#    #+#             */
/*   Updated: 2025/01/17 18:37:21 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	split_and_or(int i, char **list, char *expression)
{
	int		j;
	int		size;
	char	*str;

	j = -1;
	size = ft_strlen(expression);
	str = calloc(i + 1, sizeof(char));
	if (!str)
		return ;
	while (++j < i)
		str[j] = expression[j];
	list[0] = str;
	str = calloc(size - (i + 2), sizeof(char));
	if (!str)
		return ;
	j += 2;
	i = 0;
	while (j++ < size)
		str[i++] = expression[j];
	list[1] = str;
}

char	**ft_split_expression(char *expression)
{
	char	**list;
	int		len;
	int		i;

	list = calloc(sizeof(char *), 3);
	if (!list)
		return (NULL);
	len = ft_strlen(expression);
	i = 0;
	while (++i < len)
	{
		if ((expression[i - 1] == '&' && expression[i] == '&') || \
			(expression[i - 1] == '|' && expression[i] == '|'))
		{
			split_and_or(i - 1, list, expression);
			break ;
		}
	}
	if (!*list)
		list[0] = ft_strdup(expression);
	return (list);
}

// anything below simple commands like redirection and words will manually do
void	split_token(t_tokens *token, t_tokens **childs)
{
	if (token.type == LIST || token.type == LIST_TAIL)
		childs = ft_split_list(token);
	else if (token.type == PIPELINE || token.type == PIPELINE_TAIL)
		childs = ft_split_pipeline(token);
	else if (token.type == SIMPLE_COMMAND)
		childs = ft_split_cmd(token);
	else if (token.type == SIMPLE_COMMAND_TAIL)
		childs = ft_split_cmd_tail(token);
	else  if (token.type == REDIRECTION)
		childs = ft_split_redirection(token);
	else
		ft_bzero(childs, sizeof(t_tokens *) * 2);
}

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
}

int	setup_redirection(t_tokens token, t_tokens **child_tokens)
{
	char	*line;
	int		word_idx;
	int		op_idx;
	int		fd;

	if (!child_tokens[0] || !child_tokens[1])
		return (1);
	if (child_tokens[0]->type == WORD)
	{
		word_idx = 0;
		op_idx = 1;
	}
	else
	{
		word_idx = 1;
		op_idx = 0;
	}
	if (!ft_strncmp(child_tokens[op_idx]->str, OA, 2))
		input_redirection(token.outputfds, child_tokens[word_idx]->str, NULL);
	else
		input_redirection(token.outputfds, NULL, child_tokens[word_idx]->str);
}

void	execute_node(t_tokens *token)
{
	if (token->type == REDIRECTION)
		setup_redirection(token);
}

void	abstract_syntax_tree(t_tokens *token)
{
	t_tokens	**child_tokens;

	if (!token)
		return ;
	split_token(token, child_tokens);
	add_pipes(token, child_tokens);
	abstract_syntax_tree(child_tokens[0]);
	abstract_syntax_tree(child_tokens[1]);
	closefds(child_tokens);
	free_all((void **)child_tokens, sizeof(t_tokens));
	execute_node(token);
}

// int main (void)
// {
// 	abstract_syntax_tree("hi");
// }

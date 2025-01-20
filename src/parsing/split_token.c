/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:30:02 by jianwong          #+#    #+#             */
/*   Updated: 2025/01/20 19:43:30 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	split_and_or(int i, char **list, char *expression)
{
	int		j;
	int		size;
	char	*str;

	j = -1;
	size = ft_strlen(expression);
	str = ft_calloc(i + 1, sizeof(char));
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
void	split_token(t_btree *node)
{
	t_tokens	*token;
	char			**childs;

	token = (t_tokens *)node->item;
	if (token->type == LIST || token->type == LIST_TAIL)
		ft_split_list(node);
	else if (token->type == PIPELINE || token->type == PIPELINE_TAIL)
		ft_split_pipeline(node);
	else if (token->type == SIMPLE_COMMAND)
		ft_split_cmd(token);
	else if (token->type == SIMPLE_COMMAND_TAIL)
		ft_split_cmd_tail(node);
	else if (token->type == REDIRECTIONS)
		ft_split_redirections(node);
	else if (token.type == REDIRECTION) childs = ft_split_redirection(token);
	else
		ft_bzero(childs, sizeof(t_tokens *) * 2);
}

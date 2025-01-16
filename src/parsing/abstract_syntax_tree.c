/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abstract_syntax_tree.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:22:31 by jianwong          #+#    #+#             */
/*   Updated: 2025/01/16 15:13:47 by jianwong         ###   ########.fr       */
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

void	abstract_syntax_tree(char *expression)
{
	ft_split_expression(expression);
}

// int main (void)
// {
// 	abstract_syntax_tree("hi");
// }

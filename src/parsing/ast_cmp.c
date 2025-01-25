/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:56:37 by jianwong          #+#    #+#             */
/*   Updated: 2025/01/25 20:57:08 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

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

int		redirection_cmp(void *value)
{
	char	*t_value;

	t_value = (char *)value;
	if (!ft_strncmp(OA, value, 2))
		return (1);
	if (!ft_strncmp(CA, value, 2))
		return (1);
	if (!ft_strncmp(DOA, value, 3))
		return (1);
	if (!ft_strncmp(DCA, value, 3))
		return (1);
	return (0);
}

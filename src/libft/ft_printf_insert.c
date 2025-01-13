/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:01:57 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/26 13:07:50 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*insert_char(char *str, char *buffer, char *order)
{
	int	buffer_size;

	if (!buffer)
		return (str);
	buffer_size = (int)ft_strlen(buffer) - 1;
	if (order)
		buffer[0] = *str;
	else
		buffer[buffer_size] = *str;
	free(str);
	return (buffer);
}

static void	insert_logic(char *str, char *buffer, char *order, int *index)
{
	while (index[0] <= index[1] && order)
	{
		buffer[index[0]] = str[index[0]];
		index[0]++;
	}
	if (*str == '-' && *buffer == '0')
	{
		while (index[0] < index[1] && !order)
			buffer[index[2]--] = str[index[1]--];
		buffer[0] = '-';
	}
	else
	{
		while (index[0] <= index[1] && !order)
			buffer[index[2]--] = str[index[1]--];
	}
}

char	*insert_var(char *str, char *buffer, char *order)
{
	int	index[3];

	index[0] = 0;
	if (!str && !buffer)
		return (NULL);
	if (!str)
		return (buffer);
	if (!buffer)
		return (str);
	index[1] = (int)ft_strlen(str) - 1;
	index[2] = (int)ft_strlen(buffer) - 1;
	if (index[1] >= index[2])
	{
		free(buffer);
		return (str);
	}
	insert_logic(str, buffer, order, index);
	free(str);
	return (buffer);
}

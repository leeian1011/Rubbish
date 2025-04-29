/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:59:45 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/26 13:04:03 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*extract_flags(const char *str, int *i)
{
	char	*flags;
	char	*result;
	int		size;
	int		j;
	int		z;

	j = *i;
	z = -1;
	size = 0;
	flags = "#0- +";
	while (ft_strchr(flags, str[*i]))
	{
		size++;
		(*i)++;
	}
	if (*i == j)
		return (ft_strdup(""));
	result = ft_calloc(size + 1, 1);
	if (!result)
		return (NULL);
	while (++z + j < *i)
		result[z] = str[z + j];
	return (result);
}

int	get_min_width(const char *str, int *i)
{
	int		size;

	size = 0;
	while ('0' <= str[*i] && str[*i] <= '9')
	{
		size *= 10;
		size += (str[*i] - '0');
		(*i)++;
	}
	return (size);
}

int	get_significant(const char *str, int *i, char **flags)
{
	int		size;
	char	*temp;
	int		is_nega;

	size = 0;
	is_nega = 0;
	if (str[*i] != '.')
		return (size);
	if (str[(*i)++] == '-')
	{
		is_nega = 1;
		(*i)++;
	}
	while ('0' <= str[*i] && str[*i] <= '9')
	{
		size *= 10;
		size += str[(*i)++] - '0';
	}
	if (!is_nega)
	{
		temp = ft_strjoin(*flags, ".");
		free(*flags);
		*flags = temp;
	}
	return (size);
}

static char	*get_variable_2(va_list ptr, const char *str, int *i)
{
	void	*temp;

	if (str[*i] == 'p')
	{
		temp = va_arg(ptr, void *);
		if (temp == (void *)0)
			return (ft_strdup("(nil)"));
		else
			return (ft_tomemory(temp));
	}
	if (str[*i] == 'd' || str[*i] == 'i')
		return (ft_itoa(va_arg(ptr, int)));
	if (str[*i] == 'u')
		return (ft_uitoa(va_arg(ptr, unsigned int)));
	if (str[*i] == 'x' || str[*i] == 'X')
		return (ft_itohex(va_arg(ptr, long), str[*i]));
	if (str[*i] == '%')
		return (ft_strdup("%"));
	return (NULL);
}

char	*get_variable(va_list ptr, const char *str, int	*i)
{
	char	*result;

	if (str[*i] == 'c')
	{
		result = ft_calloc(2, 1);
		if (!result)
			return (NULL);
		*result = (char)va_arg(ptr, int);
		return (result);
	}
	if (str[*i] == 's')
	{
		result = va_arg(ptr, char *);
		if (result)
			return (ft_strdup(result));
		else
			return (NULL);
	}
	return (get_variable_2(ptr, str, i));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:57:00 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/13 15:57:18 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	write_var(char *result, int size, char convert)
{
	int	len;

	if (!result)
		return (0);
	len = ft_strlen(result);
	if (convert == 'c' && size < 2)
	{
		ft_putchar_fd(*result, 1);
		free(result);
		return (1);
	}
	if (len >= size)
	{
		write(1, result, len);
		free(result);
		return (len);
	}
	write(1, result, size);
	free(result);
	return (size);
}

// 0: flags, 1: variable, 2: result
static int	handle_special(const char *str, va_list ptr, int *i)
{
	char	*params[3];
	int		sig_no;
	int		size;

	params[2] = NULL;
	(*i)++;
	params[0] = extract_flags(str, i);
	size = get_min_width(str, i);
	sig_no = get_significant(str, i, &params[0]);
	params[1] = get_variable(ptr, str, i);
	if (size)
		params[2] = init_buffer(params[0], size, str[*i]);
	params[2] = make_var(params, str[*i], sig_no);
	size = write_var(params[2], size, str[*i]);
	free(params[0]);
	return (size);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		result;
	va_list	ptr;

	i = 0;
	result = 0;
	va_start(ptr, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			result += handle_special(str, ptr, &i);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i++], 1);
			result++;
		}
	}
	va_end(ptr);
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:01:12 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/26 13:06:04 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*init_buffer(char	*flags, int size, char convert)
{
	char	*buffer;

	buffer = malloc(sizeof(char) * (size + 1));
	if (!buffer)
		return (NULL);
	if (ft_strchr(flags, '0') && ft_strchr("iduxX", convert) \
		&& !ft_strchr(flags, '.'))
		ft_memset(buffer, '0', size);
	else
		ft_memset(buffer, ' ', size);
	buffer[size] = '\0';
	return (buffer);
}

static char	*handle_posi_sign(char *str, char *flags, char convert)
{
	char	*result;

	if (ft_strchr("idu", convert) && *str != '-')
	{
		if (ft_strchr(flags, '+'))
		{
			result = ft_strjoin("+", str);
			free(str);
			return (result);
		}
		else if (ft_strchr(flags, ' '))
		{
			result = ft_strjoin(" ", str);
			free(str);
			return (result);
		}
	}
	return (str);
}

static char	*handle_prefix(char *str, char *flags, char convert)
{
	char	*result;

	if (ft_strchr(flags, '#') && !(ft_strlen(str) == 1 && *str == '0'))
	{
		if (convert == 'x')
			result = ft_strjoin("0x", str);
		if (convert == 'X')
			result = ft_strjoin("0X", str);
		free(str);
		str = result;
	}
	return (str);
}

// 0: flags, 1: variable, 2: result
char	*make_var(char **params, char convert, int sig_no)
{
	if (!params[1])
	{
		if (convert == 's')
		{
			if (ft_strchr(params[0], '.'))
				params[1] = precision_handling(params[1], sig_no, convert);
			else
				params[1] = ft_strdup("(null)");
		}
		return (insert_var(params[1], params[2], ft_strchr(params[0], '-')));
	}
	params[1] = handle_prefix(params[1], params[0], convert);
	if (ft_strchr(params[0], '.'))
		params[1] = precision_handling(params[1], sig_no, convert);
	if (!params[1])
		return (insert_var(params[1], params[2], ft_strchr(params[0], '-')));
	params[1] = handle_posi_sign(params[1], params[0], convert);
	if (convert == 'c')
		return (insert_char(params[1], params[2], ft_strchr(params[0], '-')));
	return (insert_var(params[1], params[2], ft_strchr(params[0], '-')));
}

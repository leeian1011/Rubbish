/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:06:29 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/26 13:06:52 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*string_sitter(char *str, int sig_no, char convert, int *size)
{
	char	*temp;

	if (!str && convert == 's')
	{
		if (sig_no > 5)
			str = ft_strdup("(null)");
		else
			return (NULL);
	}
	*size = ft_strlen(str);
	if (convert == 's' && *size > sig_no)
	{
		temp = ft_substr(str, 0, sig_no);
		free(str);
		return (temp);
	}
	return (str);
}

static char	*specialized_handling(int size, int sig_no, char *str)
{
	char	*temp;

	if (size < sig_no)
	{
		temp = malloc(sig_no + 1);
		if (!temp)
			return (NULL);
		ft_memset(temp, '0', sig_no);
		temp[sig_no] = '\0';
		if (*str == '-')
		{
			while (size > 0)
				temp[sig_no--] = str[size--];
			temp[0] = '-';
		}
		else
			while (size > -1)
				temp[sig_no--] = str[size--];
		free(str);
		return (temp);
	}
	return (str);
}

char	*precision_handling(char *str, int sig_no, char convert)
{
	int		size;

	str = string_sitter(str, sig_no, convert, &size);
	if (ft_strchr("iduxX", convert))
	{
		if (!sig_no && (ft_strlen(str) == 1 && *str == '0'))
		{
			free(str);
			return (NULL);
		}
		if (*str == '-')
			sig_no++;
		str = specialized_handling(size, sig_no, str);
	}
	return (str);
}

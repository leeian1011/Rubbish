/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:02:34 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/26 13:02:40 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itohex(unsigned int n, char c)
{
	unsigned int	num;
	int				size;
	char			*result;

	num = n / 16;
	size = 1;
	while (num && size++ > 0)
		num /= 16;
	result = malloc(size + 1);
	if (!result)
		return (NULL);
	result[size--] = '\0';
	while (size > -1)
	{
		if ((n % 16) > 9)
			result[size--] = (n % 16) - 10 + (c - 23);
		else
			result[size--] = (n % 16) + '0';
		n /= 16;
	}
	return (result);
}

char	*ft_ltohex(unsigned long n, char c)
{
	unsigned long		num;
	int					size;
	char				*result;

	num = n / 16;
	size = 1;
	while (num && size++ > 0)
		num /= 16;
	result = malloc(size + 1);
	if (!result)
		return (NULL);
	result[size--] = '\0';
	while (size > -1)
	{
		if ((n % 16) > 9)
			result[size--] = (n % 16) - 10 + (c - 23);
		else
			result[size--] = (n % 16) + '0';
		n /= 16;
	}
	return (result);
}

char	*ft_uitoa(unsigned int n)
{
	unsigned int	num;
	int				size;
	char			*result;

	num = n / 10;
	size = 1;
	while (num && size++ > 0)
		num /= 10;
	result = malloc(size + 1);
	if (!result)
		return (NULL);
	result[size--] = '\0';
	while (size > -1)
	{
		result[size--] = (n % 10) + '0';
		n = n / 10;
	}
	return (result);
}

char	*ft_tomemory(void *ptr)
{
	char	*result;
	char	*prefix;
	char	*hex;

	prefix = ft_strdup("0x");
	hex = ft_ltohex((unsigned long)ptr, 'x');
	result = ft_strjoin(prefix, hex);
	free(prefix);
	free(hex);
	return (result);
}

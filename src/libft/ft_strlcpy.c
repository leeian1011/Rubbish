/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:32:21 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/07 20:22:08 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize < 1)
		return (ft_strlen(src));
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
#include <stdio.h>
int main(void)
{
	char *src = "Hello, World";
	char dest[20];

	printf("%zu\n", ft_strlcpy(dest, src, 0)); //no space
	printf("%s\n", dest);
	printf("%zu\n", ft_strlcpy(dest, src, 15)); //src null terminate
	printf("%s\n", dest);
	printf("%zu\n", ft_strlcpy(dest, src, 8)); //dest too small
	printf("%s\n", dest);
	printf("%zu\n", ft_strlcpy(dest, src, 12)); //no space for null terminate
	printf("%s\n", dest);
	return (0);
	}
*/

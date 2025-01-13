/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:55:05 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/12 15:00:25 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	append_size;
	size_t	dst_size;
	size_t	src_size;

	src_size = ft_strlen(src);
	if (size <= 0)
		return (src_size);
	dst_size = ft_strlen(dst);
	if (size <= dst_size)
		return (size + src_size);
	append_size = size - dst_size - 1;
	if ((dst_size + 1) >= size)
		return (dst_size + src_size);
	while (*dst)
		dst++;
	while (append_size-- && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (dst_size + src_size);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char *src = "Hello, World";
// 	char dest[19] = "Heheha";
// 	char dest1[19] = "Heheh1";
// 	char dest2[19] = "Heheh2";
// 	char dest3[19] = "Heheh3";
//
// 	printf("%zu\n", ft_strlcat(dest, src, 0));//no space
// 	printf("%s\n", dest);
// 	printf("%zu\n", ft_strlcat(dest1, src, 19));//src null terminate
// 	printf("%s\n", dest1);
// 	printf("%zu\n", ft_strlcat(dest2, src, 10));//dest too small
// 	printf("%s\n", dest2);
// 	printf("%zu\n", ft_strlcat(dest3, src, 18));//no space for null terminate
// 	printf("%s\n", dest3);
//
// 	printf("%zu\n", strlcat(dest, src, 0));//no space
// 	printf("%s\n", dest);
// 	printf("%zu\n", strlcat(dest1, src, 19));//src null terminate
// 	printf("%s\n", dest1);
// 	printf("%zu\n", strlcat(dest2, src, 10));//dest too small
// 	printf("%s\n", dest2);
// 	printf("%zu\n", strlcat(dest3, src, 18));//no space for null terminate
// 	printf("%s\n", dest3);
// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:56:54 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/12 13:57:27 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// To retrieve the address of the first instance of c by comparing byte by byte
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char) c)
			return (ptr + i);
		i++;
	}
	return (NULL);
}

// #include <string.h>
// int	main(void)
// {
// 	// char	*str = "Hello World";
// 	// int 	arr[5] = {1, 2, 3, 4, 5};
// 	// int tab[7] = {-49, 49, 1, 1, 0, -2, 2};
// 	char s[] = {0,1,2,3,4,5};
//
//
// 	// printf("%d\n", *(char *)memchr(tab, -1, 7 * 4));
// 	// printf("%d\n", *(char *)ft_memchr(tab, -1, 7 * 4));
// 	// printf("%s\n", (char *)ft_memchr(str, 'o', 5));//have
// 	// printf("%s\n", (char *)memchr(str, 'o', 5));//have
// 	// printf("%s\n", (char *)ft_memchr(str, 'o', 2));//no have
// 	// printf("%s\n", (char *)memchr(str, 'o', 2));//no have
// 	// printf("%d\n", *(int *)ft_memchr(arr, 3,12));// have
// 	// printf("%d\n", *(int *)memchr(arr, 3,12));// have
// 	// // printf("%d\n", *(int *)ft_memchr(arr, 2, 2));//no have
// 	// printf("%d\n", *(int *)memchr(arr, 2, 2));//no have
// 	return (0);
// }

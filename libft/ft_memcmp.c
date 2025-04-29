/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:09:58 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/11 12:08:20 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// compares memory areas byte by byte until 
/// the first instance of change
/// or n checks has been reached
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*a;
	const unsigned char	*b;

	a = (const unsigned char *) s1;
	b = (const unsigned char *) s2;
	while (n--)
	{
		if (*a != *b)
			return (*a - *b);
		a++;
		b++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	// char 	*str = "Hello, world";
// 	// char 	*str2 = "Hello, wod";
// 	int	arr[5] = {1234325234, 1235342532, 12345814} ;
// 	int	arr2[5] = {1234325234, 1235342532, 123458134} ;
// 	int num1 = 65024;
// 	int num2 = 65280;
//
// 	printf("%d\n", memcmp(&num1, &num2, 8));
// 	// printf("%d\n", ft_memcmp(str, str2, 10));
// 	// printf("%d\n", ft_memcmp(arr, arr2, 8));
// 	printf("%d\n", ft_memcmp(&num1, &num2, 8));
// 	return (0);
// }	

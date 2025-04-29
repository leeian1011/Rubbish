/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:34:20 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/07 20:22:08 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while ((*a || *b) && n--)
	{
		if (*a != *b)
			return ((int)(*a - *b));
		a++;
		b++;
	}
	return (0);
}
// #include <stdio.h>
// int   main(void)
// {
//   char *str = "Hello";
//   char *str1 = "Helyo";
//   char *str2 = "World";
//
//   printf("%d\n", ft_strncmp(str, str1, 2));
//   printf("%d\n", ft_strncmp(str2, str1, 6));
//   printf("%d\n", ft_strncmp(str, str1, 6));
//
//   return (0);
// }

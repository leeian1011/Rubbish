/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:19:49 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/12 15:15:12 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*little)
		return ((char *)big);
	while (j < len && big[j])
	{
		while (big[j + i] == little[i] && j + i < len)
		{
			i++;
			if (!little[i])
				return ((char *)&big[j]);
		}
		i = 0;
		j++;
	}
	return (NULL);
}

// #include <stdio.h>
// int main(void)
// {
// 	// char *str = "Hello World Hello";
// 	// char *substr = "World";
// 	// char *str = "HelloDworld";
// 	// char *substr = "D";
// 	char *str = "aaabcabcd";
// 	char *substr = "aabc";
// 	size_t num = -1;
//
// 	printf("%s\n",ft_strnstr(str,substr ,-1));
// 	printf("%s\n",ft_strnstr(str,"abcd" ,9));
// 	printf("%s\n",ft_strnstr(str,"abcd" ,4));
// 	printf("%s\n",ft_strnstr(str,substr ,20));
// 	printf("%s\n",ft_strnstr("","" ,-1));
// 	printf("%s\n",ft_strnstr("","" ,0));
// }

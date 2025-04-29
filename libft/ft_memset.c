/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:46:09 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/15 16:04:22 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// set a given memory address into c until n bytes is reached
void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *) s;
	i = 0;
	while (i < n)
	{
		str[i] = (char) c;
		i++;
	}
	return (s);
}
// #include <stdlib.h>
// #include <stdio.h>
// int 	main(void)
// {
// 	char 	*dest;
// 	int 	*dest2;
// 	int 	i;
//
// 	i = 0;
// 	dest = malloc(5);
// 	dest2 = malloc(4*5);
// 	dest[4] = '\0';
// 	printf("%s\n", (char *)ft_memset(dest, 'h', 4));
// 	ft_memset(dest2, 0, 16);
// 	while (i < 5)
// 	{
// 		printf("%d\n", dest2[i]);	
// 		i++;
// 	}
// 	return (0);
// }

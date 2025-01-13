/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:46:08 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/12 13:49:32 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// returns the address of where the first instance of c is
char	*ft_strchr(const char *s, int c)
{
	char	a;

	a = (char) c;
	while (*s)
	{
		if (*s == a)
			return ((char *)s);
		s++;
	}
	if (a == '\0')
		return ((char *)s);
	return (NULL);
}
/*
#include <stdio.h>
int	main(void)
{
	char *str = "Hello world";
	char *c = ft_strchr(str, 'o');
	if (!c)
	{
		printf("NULL");
		return (0);
	}
	printf("%s\n", c);
	return (0);
}
*/

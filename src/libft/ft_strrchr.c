/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:02:29 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/11 12:16:10 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*result;
	char	a;

	a = (char) c;
	result = NULL;
	while (*s)
	{
		if (*s == a)
			result = (char *) s;
		s++;
	}
	if (a == '\0')
		result = (char *) s;
	return (result);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*str = "Hello World";
	char	*result = ft_strrchr(str, 'o');

	if (!result)
	{
		printf("NULL");
		return (0);
	}
	printf("%s\n", result);
	return (0);
}
*/

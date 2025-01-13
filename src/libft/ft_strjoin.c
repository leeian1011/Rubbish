/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:55:49 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/07 23:56:29 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	if (s1)
	{
		while (*s1)
			ptr[i++] = *s1++;
	}
	if (s2)
	{
		while (*s2)
			ptr[i++] = *s2++;
	}
	ptr[i] = '\0';
	return (ptr);
}
//
// int main(void)
// {
// 	char *str = "Hello";
// 	char *str2 = "World";
//
// 	printf("%s\n",ft_strjoin(str, str2));
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:57:11 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/11 17:24:16 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*ptr;
	size_t		i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if ((start + len) >= ft_strlen(s))
		len = ft_strlen(s) - start;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// #include <stdio.h>
// int		main(void)
// {
// 	char *str = "Hello World";
//
// 	printf("ft_substr(str, 4, 7) = %s\n", ft_substr(str, 4, 7));
// 	printf("ft_substr(str, 4, 7) = %s\n", ft_substr(str, 11, 7));
// 	printf("ft_substr(str, 4, 7) = %s\n", ft_substr(str, 4, 3));
//
// }

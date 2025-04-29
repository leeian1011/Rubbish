/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:55:39 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/12 14:26:07 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*ptr;

	if (!s1 | !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	if (start >= end && end >= 0)
		return (NULL);
	while (is_set(s1[start], set))
		start++;
	while (is_set(s1[end], set))
		end--;
	if (start > end)
		return (ft_strdup(""));
	ptr = malloc(sizeof(char) * (end - start + 2));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1 + start, end - start + 2);
	return (ptr);
}

// #include <stdio.h>
// int main(void)
// {
// 	char *str = "HELLO";
// 	printf("%s\n", ft_strtrim(str, " "));
// }

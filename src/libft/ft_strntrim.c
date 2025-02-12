/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strntrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:30:52 by jianwong          #+#    #+#             */
/*   Updated: 2025/02/07 17:25:28 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

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

char	*ft_strntrim(char const *s1, char const *set, int count)
{
	int		start;
	int		end;
	int		i;
	char	*ptr;

	if (!s1 | !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	i = 0;
	if (start >= end && end >= 0)
		return (NULL);
	while (is_set(s1[start], set) && i++ < count)
		start++;
	i = 0;
	while (is_set(s1[end], set) && i++ < count)
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
// 	char *str = "(echo hi | (ls))";
// 	printf("%s\n", ft_strntrim(str, "()", 1));
// }

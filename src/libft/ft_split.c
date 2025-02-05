/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:16:14 by jianwong          #+#    #+#             */
/*   Updated: 2025/02/02 16:30:22 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	in_word;
	int	count;

	count = 0;
	in_word = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		if (!in_word && *s != c)
		{
			count++;
			in_word = 1;
		}
		if (in_word && *s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*make_str(char const *s, char c, int *i)
{
	char	*ptr;
	int		j;
	int		size;
	int		z;

	size = 0;
	j = *i;
	z = 0;
	while (s[j] && s[j] != c)
	{
		size++;
		j++;
	}
	ptr = malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	while (*i < j)
	{
		ptr[z++] = s[*i];
		*i += 1;
	}
	ptr[z] = '\0';
	return (ptr);
}

static char	**split_words(char **result, char const *s, char c)
{
	int	i;
	int	z;

	i = 0;
	z = -1;
	while (s[i])
	{
		if (s[i] != c)
		{
			result[++z] = make_str(s, c, &i);
			if (!result[z])
			{
				free_all((void **)result, sizeof(char *));
				return (NULL);
			}
		}
		else
			i++;
	}
	result[++z] = NULL;
	return (result);
}

/// split up a given string by c delimiter into a array of substrings
char	**ft_split(char const *s, char c)
{
	int		size;
	char	**result;

	size = count_words(s, c);
	result = ft_calloc(sizeof(char *), (size + 1));
	if (!result)
		return (NULL);
	result = split_words(result, s, c);
	return (result);
}

// #include <stdio.h>
// int		main(void)
// {
// 	char	*str = "Hello World Heheha";
// // 	// char	*str1 = "   Hello World Heheha   ";
// // 	// char	*str2 = ",,,,Hello, World, Heheha,";
// 	char	**result = ft_split(str, ' ');
// //
// // 	// result = ft_split("   lorem   ipsum dolor     sit amet, consectetur  
// // 	adipiscing elit. Sed non risus. Suspendisse   ", ' ');
// // 	while (*result)
// // 		printf("%s\n", *result++);
// 	free_all(result, 3);
// // 	return (0);
// }
// // }

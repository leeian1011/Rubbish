/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_ignore_qoutes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:50:38 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/27 17:37:28 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int		in_word;
	char	in_qoutes;
	int		count;

	count = 0;
	in_word = 0;
	in_qoutes = '\0';
	while (*s && *s == c)
		s++;
	while (*s)
	{
		if (*s == in_qoutes && in_qoutes)
			in_qoutes = '\0';
		else if (*s == '\'' || *s == '\"')
			in_qoutes = *s;
		if (!in_word && *s != c)
		{
			count++;
			in_word = 1;
		}
		if (in_word && *s == c && !in_qoutes)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*make_str(char const *s, char c, int *i, char *in_qoutes)
{
	char	*ptr;
	int		j;
	int		size;
	int		z;

	size = 0;
	j = *i + (*in_qoutes != '\0');
	z = 0;
	while (s[j] && (s[j] != c || *in_qoutes))
	{
		if (s[j] == *in_qoutes)
			*in_qoutes = '\0';
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
	int		i;
	int		z;
	char	in_qoutes;

	i = 0;
	z = -1;
	in_qoutes = '\0';
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '\"')
			in_qoutes = s[i];
		if (s[i] != c || in_qoutes)
		{
			result[++z] = make_str(s, c, &i, &in_qoutes);
			if (!result[z])
			{
				free_all((void **)result);
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
/// while ignoring quotes and their contents
/// if a qoute is used as a delimiter function will return NULL
char	**ft_split_ignore_qoutes(char const *s, char c)
{
	int		size;
	char	**result;

	if (c == '\'' || c == '\"')
		return (NULL);
	size = count_words(s, c);
	result = malloc(sizeof(char *) * (size + 1));
	if (!result)
		return (NULL);
	result = split_words(result, s, c);
	return (result);
}

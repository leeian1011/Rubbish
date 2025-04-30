/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unquote.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:28:14 by jianwong          #+#    #+#             */
/*   Updated: 2025/04/30 16:28:42 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/rubbish.h"

//Function to calc the new length of the string once quote-cleaned
static int	extracted_len(char *str, char *quote)
{
	int		j;
	int		cut;

	*quote = 0;
	j = 0;
	cut = 0;
	while (str[j])
	{
		if (*quote && str[j] == *quote)
		{
			cut += 2;
			*quote = 0;
		}
		else if (!*quote && (str[j] == '\'' || str[j] == '"'))
			*quote = str[j];
		j++;
	}
	return (j - cut);
}

static char	*extract_str(int len, char **str, char *quote)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (error(MEM, NULL, 2));
	while ((*str)[j])
	{
		if (*quote && (*str)[j] == *quote)
			*quote = 0;
		else if (!(*quote) && ((*str)[j] == '\'' || (*str)[j] == '"'))
			*quote = (*str)[j];
		else
			new[i++] = (*str)[j];
		j++;
	}
	new[i] = '\0';
	return (new);
}

int	unquote(char **str)
{
	char		*new;
	size_t		len;
	char		quote;

	while (*str)
	{
		quote = 0;
		len = extracted_len(*str, &quote);
		if (len != ft_strlen(*str))
		{
			quote = 0;
			new = extract_str(len, str, &quote);
			if (!new)
				return (1);
			free (*str);
			*str = new;
		}
		if (quote)
			return (error(QUOTE, NULL, 1), 0);
		str++;
	}
	return (1);
}

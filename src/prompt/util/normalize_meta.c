/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_meta.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:29:42 by jianwong          #+#    #+#             */
/*   Updated: 2025/04/30 16:29:43 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/rubbish.h"

static int	normalized_meta_len(char **str, char *spec)
{
	int	len;

	len = 1;
	if (!*str)
		return (0);
	while (str[0] && str[1])
	{
		if (ft_strchr(spec, str[0][0]) && (str[0][0] == str[1][0])
			&& ft_strlen(str[0]) == 1 && ft_strlen(str[1]) == 1)
		{
			str ++;
		}
		len++;
		str++;
	}
	return (len);
}

char	*ft_fill_wrd(char *str)
{
	char	*n_wrd;

	n_wrd = malloc(3);
	if (!n_wrd)
		return (NULL);
	*n_wrd = str[0];
	*(n_wrd + 1) = str[0];
	*(n_wrd + 2) = '\0';
	return (n_wrd);
}

static int	validate_meta(char **res, char ***str, char *spec, int *len)
{
	char	*n_wrd;

	if (ft_strchr(spec, (*str)[0][0]) && ((*str)[0][0] == (*str)[1][0])
			&& ft_strlen((*str)[0]) == 1 && ft_strlen((*str)[1]) == 1)
	{
		n_wrd = ft_fill_wrd((*str)[0]);
		if (!n_wrd)
			return (ft_free_split((*str)), 1);
		free((*str)[0]);
		free((*str)[1]);
		res[(*len)++] = n_wrd;
		(*str)++;
	}
	else
		res[(*len)++] = **str;
	return (0);
}

static int	fill_result(char **res, char **str, char *spec)
{
	int		len;
	char	**str_mem;

	len = 0;
	str_mem = str;
	if (!*str)
		return (0);
	while (str[0] && str[1])
	{
		if (validate_meta(res, &str, spec, &len))
			return (1);
		str++;
	}
	if (str)
		res[len++] = *str;
	free(str_mem);
	res[len] = NULL;
	return (0);
}

// str = "echo,|,|,ls" change to -> "echo,||,ls"
char	**normalize_meta(char **str, char *meta)
{
	int		n_len;
	char	**res;

	n_len = normalized_meta_len(str, meta);
	res = malloc(sizeof(char *) * (n_len + 1));
	if (!res)
		return (ft_free_split(str), error(MEM, NULL, 2));
	if (fill_result(res, str, meta))
		return (ft_free_split(res), error(MEM, NULL, 2));
	return (res);
}

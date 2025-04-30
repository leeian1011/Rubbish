/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env_var_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:29:52 by jianwong          #+#    #+#             */
/*   Updated: 2025/04/30 16:32:46 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/rubbish.h"

size_t	var_strlen(const char *s, int quote)
{
	size_t	i;
	char	ch[2];

	i = 0;
	if (quote)
	{
		ch[0] = '"';
		ch[1] = '\'';
	}
	else
	{
		ch[0] = ' ';
		ch[1] = ' ';
	}
	while (s[i] && s[i] != ' ' && (s[i] != ch[0] && s[i] != ch[1]))
		i++;
	return (i);
}

int	validate_var(char *env, char *str, int index, int quote)
{
	int		len_var;
	char	*ascii_gecode;

	if (env)
		len_var = ft_strlen(&env[var_strlen(&str[index + 1], quote)]);
	else if (str[index + 1] == '?')
	{
		ascii_gecode = ft_itoa(g_ecode);
		len_var = ft_strlen(ascii_gecode);
		free(ascii_gecode);
	}
	else
		len_var = 0;
	return (len_var);
}

char	*expand_concat(char *env, int len, char *res, char ch)
{
	char	*ascii_gecode;

	if (env)
	{
		while (*env != '=')
			env++;
		env++;
		ft_strlcat(res, env, len + 2);
	}
	else if (ch == '?')
	{
		ascii_gecode = ft_itoa(g_ecode);
		ft_strlcat(res, ascii_gecode, len + 2);
		free(ascii_gecode);
	}
	return (res);
}

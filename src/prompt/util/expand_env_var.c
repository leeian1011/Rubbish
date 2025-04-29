#include "../../../includes/rubbish.h"

char	*ft_fill_expand(char *env, char *str, int index, int quote)
{
	int		len_var;
	int		len_post;
	char	*res;
	int		i;

	i = 0;
	len_var = validate_var(env, str, index, quote);
	len_post = ft_strlen(&str[index + 1
			+ var_strlen(&str[index + 1], quote)]);
	if (len_var + len_post + index == 0)
		return (ft_calloc(1, 1));
	res = malloc(len_var + len_post + index + 2);
	if (!res)
		return (NULL);
	while (str[i] != '$')
	{
		res[i] = str[i];
		i++;
	}
	res[i++] = '\0';
	res = expand_concat(env, len_var + len_post + index, res,
			str[index + 1]);
	ft_strlcat(res, &str[index + 1 + var_strlen(&str[index + 1], quote)],
		len_var + len_post + index + 2);
	return (res);
}

//Searches if the 
static char	*ft_find_env(char **envp, char *str, int index, int quote)
{
	int		i;
	char	*res;

	i = 0;
	res = NULL;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], &str[index + 1],
				var_strlen(&str[index + 1], quote))
			&& envp[i][var_strlen(&str[index + 1], quote)] == '=')
		{
			res = ft_fill_expand(envp[i], str, index, quote);
			free(str);
			return (res);
		}
		i++;
	}
	return (res);
}

//Search the env var and changes de string
char	*ft_expand_var(char **envp, char *str, int index, int quote)
{
	char	*res;

	res = NULL;
	res = ft_find_env(envp, str, index, quote);
	if (res)
		return (res);
	if (!ft_strncmp("?", &str[index + 1],
			var_strlen(&str[index + 1], quote)))
	{
		res = ft_fill_expand(NULL, str, index, quote);
		free(str);
		return (res);
	}
	else
	{
		res = ft_fill_expand(NULL, str, index, quote);
		free(str);
		return (res);
	}
	return (str);
}

static int	ft_check_var_aux(char **env, char **str, int *i, int *quote)
{
	if ((*str)[*i] == '\'' && !(*quote))
	{
		(*i)++;
		while ((*str)[*i] != '\'' && (*str)[*i])
			(*i)++;
	}
	else if ((*str)[(*i)] == '$' && (*str)[(*i) + 1] != '\0')
	{
		*str = ft_expand_var(env, *str, *i, (*quote) % 2);
		if (!*str)
    {
      ft_free_split((str + 1));
      error(MEM, NULL, 2);
			return(0);
    }
		*i = -1;
	}
	else if ((*str)[*i] == '"' && (*quote))
		(*quote)--;
	return (0);
}

//Function to expand all the environmental variables in the 2D array
int	expand_env_var(char **str, char **env)
{
	int	i;
	int	quote;

	while (*str)
	{
		quote = 0;
		i = 0;
		while (*str && (*str)[i])
		{
			if ((*str)[i] == '"')
			{
				i++;
				quote++;
			}
			if (ft_check_var_aux(env, &(*str), &i, &quote))
				return (2);
			if (i == -1 || (*str)[i])
				i++;
		}
		str++;
	}
	return (0);
}

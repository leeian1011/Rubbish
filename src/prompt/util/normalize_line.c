#include "../../../includes/rubbish.h"

static int	normalized_len(char	*str, char *act)
{
	unsigned int	i;
	int				extra;

	i = 0;
	extra = 0;
	while (str[i])
	{
		ft_mtoq(str, &i);
		if (ft_strchr(act, str[i]))
			extra += 2;
		if (str[i])
			i++;
	}
	return (i + extra);
}

static void	handle_normalization(char *res, char *str, int *i, int *extra)
{
	char	quote;

	if (str[*i] == '\"' || str[*i] == '\'')
	{
		quote = str[*i];
		res[*i + *extra] = str[*i];
		(*i)++;
		while (str[*i])
		{
			res[*i + *extra] = str[*i];
			if (str[*i] == quote)
				break ;
			(*i)++;
		}
	}
	if (ft_strchr("<>|&()", str[*i]))
	{
		res[*i + *extra] = ' ';
		res[*i + *extra + 1] = str[*i];
		res[*i + *extra + 2] = ' ';
		(*extra) += 2;
	}
	else
		res[*i + *extra] = str[*i];
}

//Adds spaces into the string, separating the special characters
//To normalize inputs like: "ls|cat" to "ls | cat"
char	*normalize_line(char *str)
{
	char	*res;
	int		i;
	int		extra;

	i = 0;
	extra = 0;
	res = malloc(normalized_len(str, "<>|&()") + 1);
	if (!res)
		return (error(MEM, NULL, 2));
	while (str[i])
	{
		handle_normalization(res, str, &i, &extra);
		if (str[i])
			i++;
	}
	res[i + extra] = '\0';
	return (res);
}

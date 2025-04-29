#include "../../includes/rubbish.h"

// exp = expression
static char	**init_exp_cmdargs(char **cmdargs, int *size)
{
	char	**exp_cmdargs;

	*size = (cmd_count(cmdargs) * count_dir()) + 1;
	exp_cmdargs = malloc(sizeof(char *) * (*size));
	ft_bzero(exp_cmdargs, sizeof(char *) * (cmd_count(cmdargs) * count_dir()));
	exp_cmdargs[0] = ft_strdup(cmdargs[0]);
	return (exp_cmdargs);
}

//Returns 1 if there is a wildcard, 0 if not
static int	find_wild_match(char *pattern, char *str)
{
	while (*pattern)
	{
		if (*pattern == '*')
		{
			while (*pattern == '*')
				pattern++;
			if (*pattern == '\0')
				return (1);
			while (*str)
			{
				if (*str == *pattern && find_wild_match(pattern, str))
					return (1);
				str++;
			}
			return (0);
		}
		if (*str == '\0' || (*pattern != *str))
			return (0);
		pattern++;
		str++;
	}
	return (*str == '\0');
}

static void	fill_exp_cmdargs(char *pattern, char ***exp_cmdargs, int *j)
{
	DIR				*dir;
	struct dirent	*entry;

	dir = opendir(".");
	entry = readdir(dir);
	while (entry != NULL)
	{
		if (!ft_strcmp("*", pattern))
		{
			if (entry->d_name[0] != '.')
			{
				(*exp_cmdargs)[*j] = ft_strdup(entry->d_name);
				(*j)++;
			}
		}
		else if (find_wild_match(pattern, entry->d_name))
		{
			(*exp_cmdargs)[*j] = ft_strdup(entry->d_name);
			(*j)++;
		}
		entry = readdir(dir);
	}
	closedir(dir);
}

static char	**trim_excess(char **exp, int size)
{
	char	**trim;
	int		len;
	int		i;

	(void)size;
	len = cmd_count(exp);
	trim = malloc(sizeof(char *) * (len + 1));
	trim[len] = NULL;
	i = 0;
	while (i < len)
	{
		trim[i] = ft_strdup(exp[i]);
		i++;
	}
	ft_free_split(exp);
	return (trim);
}

void	handle_wildcard(t_cmd *cmd)
{
	int		i;
	int		size;
	char	**exp_cmdargs;
	int		j;

	i = 0;
	if (!cmd->full_cmd)
		return ;
	j = 1;
	exp_cmdargs = init_exp_cmdargs(cmd->full_cmd, &size);
	while ((cmd->full_cmd)[++i])
	{
		if (ft_strchr((cmd->full_cmd)[i], '*'))
			fill_exp_cmdargs((cmd->full_cmd)[i], &exp_cmdargs, &j);
		else
			exp_cmdargs[j++] = ft_strdup((cmd->full_cmd)[i]);
	}
	exp_cmdargs = trim_excess(exp_cmdargs, size);
	i = 0;
	while (exp_cmdargs[i])
	{
		i++;
	}
	ft_free_split(cmd->full_cmd);
	cmd->full_cmd = exp_cmdargs;
}

#include "../includes/rubbish.h"

char	**clone_env(char **env)
{
	int		i;
	char	**envcp;

	i = 0;
	while (env[i])
		i++;
	envcp = malloc(sizeof(char *) * (i + 1));
	envcp[i] = NULL;
	i = 0;
	while (env[i])
	{
		envcp[i] = ft_strdup(env[i]);
		i++;
	}
	return (envcp);
}

char	**add_var(char **env, char *var)
{
	int		len;
	int		i;
	char	**envcp;

	len = 0;
	while (env[len])
		len++;
	envcp = malloc(sizeof(char *) * (len + 2));
	envcp[len + 1] = NULL;
	i = 0;
	while (i < len)
	{
		envcp[i] = ft_strdup(env[i]);
		i++;
	}
	envcp[i] = ft_strdup(var);
	ft_free_split (env);
	return (envcp);
}

char	**del_var_helper(int found, char **env, char **envcpy)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (env[i])
	{
		if (i != found)
		{
			envcpy[j] = ft_strdup(env[i]);
			i++;
			j++;
		}
		else
			i++;
	}
	return (envcpy);
}

char	**del_var(char **env, char *var)
{
	int		found;
	int		len;
	char	**envcpy;
	char	*varok;

	found = 0;
	varok = ft_strjoin(var, "=");
	while (env[found])
	{
		if (ft_strncmp(varok, env[found], ft_strlen(varok)) == 0)
			break ;
		found++;
	}
	if (env[found] == NULL)
		return (free(varok), env);
	free(varok);
	len = 0;
	while (env[len])
		len++;
	envcpy = malloc(sizeof(char *) * (len));
	envcpy[len - 1] = NULL;
	del_var_helper(found, env, envcpy);
	ft_free_split(env);
	return (envcpy);
}

int	found_in_env(char *var, char **env, char **path)
{
	int	i;
	int	foundeq;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(var, env[i], ft_strlen(var)) == 0)
		{
			find_equal(env[i], &foundeq);
			*path = ft_substr(env[i], foundeq + 1, ft_strlen(env[i]) - foundeq);
			return (1);
		}
		i++;
	}
	return (0);
}

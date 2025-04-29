#include "../../includes/rubbish.h"

static int	check_slash(char *str)
{
	int	i;
	int	slash;

	slash = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			slash++;
		i++;
	}
	return (slash);
}

static char	**get_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5))
			return (ft_split(env[i] + 5, ':'));
		i++;
	}
	return (NULL);
}

// get cmd or path lmao
char	*gcop(char **env, char *str)
{
	int		i;
	char	**env_path;
	char	*aux;
	char	*path_and_cmd;

	env_path = NULL;
  i = 0;
	if (check_slash(str) > 0 && !access(str, F_OK))
		return (ft_strdup(str));
	else if (check_slash(str) == 0)
	{
		env_path = get_path(env);
    if (env_path)
    {
		  while (env_path[i])
		  {
			  aux = ft_strjoin(env_path[i++], "/");
			  path_and_cmd = ft_strjoin(aux, str);
			  free(aux);
			  if (access(path_and_cmd, F_OK) == 0)
        {
          ft_free_split(env_path);
				  return (path_and_cmd);
        }
			  free(path_and_cmd);
		  }
			ft_free_split(env_path);
    }
	}
	return (NULL);
}

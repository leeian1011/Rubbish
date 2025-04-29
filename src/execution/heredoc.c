#include "../../includes/rubbish.h"

static void	handle_buffer(char c, char **str)
{
	char	*aux;
	char	*tmp;

	aux = *str;
	tmp = malloc(2 * sizeof(char));
	tmp[0] = c;
	tmp[1] = 0;
	*str = ft_strjoin(*str, tmp);
	free(tmp);
	free(aux);
}

static char	*heredoc_getline(int fd)
{
	char	c;
	char	*str;
	int		re;

	str = malloc(1 * sizeof(char));
	str[0] = 0;
	re = read(fd, &c, 1);
	while (re >= 0)
	{
		if (!str[0] && re == 0)
			return (NULL);
		handle_buffer(c, &str);
		if (c == '\n')
			break ;
		c = 0;
		re = read(fd, &c, 1);
	}
	return (str);
}

void	write_heredoc_tmp(t_cmd *cmd)
{
	char	*line;
	char	*limit_n;
	int		fd;

	fd = open(".tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	while (1)
	{
		line = heredoc_getline(0);
		if (line == NULL)
			break ;
		limit_n = ft_strjoin(cmd->limit, "\n");
		if (ft_strcmp(limit_n, line) == 0)
		{
			free(limit_n);
			break ;
		}
		free(limit_n);
		ft_putstr_fd(line, fd);
		free(line);
	}
	free(line);
	close(fd);
}


#include "../../includes/rubbish.h"

static void	free_nodes(t_cmd *nodes)
{
	int	len;
	int	i;

	len = (*nodes).info->cmd_amount;
	i = 0;
	while (i < len)
	{
		if (nodes[i].full_cmd)
		{
			ft_free_split(nodes[i].full_cmd);
		}
		if (nodes[i].path)
			free(nodes[i].path);
		if (nodes[i].infile)
			free(nodes[i].infile);
		if (nodes[i].outfile)
			free(nodes[i].outfile);
		if (nodes[i].limit)
			free(nodes[i].limit);
		i++;
	}
	free(nodes);
}

static int	handle_processing(char *str, t_info *info, char ***res)
{
	str = normalize_line(str);
	if (!str)
		return (1);
	*res = ft_split_str(str, ' ');
	free (str);
	if (!(*res))
		return (2);
	if (expand_env_var(*res, info->envcp))
		return (ft_free_split(*res), 3);
	*res = normalize_meta(*res, "<>|&");
	if (!(*res))
		return (3);
	return (0);
}


static int	process_lines(char *str, t_info *info)
{
	char	**res;
	t_cmd	*nodes;
	int		i;

	if (handle_processing(str, info, &res))
		return (1);
	if (!unquote(res))
		return (ft_free_split(res), 1);
	if (validate_redir(res))
		return (ft_free_split(res), 2);
	nodes = parse_cmd(res, info);
	ft_free_split(res);
	if (!nodes)
		return (1);
	open_outfiles(nodes);
	i = 0;
	loop_and_execute(nodes, &i);
	free_nodes(nodes);
	return (0);
}

static char	*get_prompt(char **env)
{
	char	*user;
	char	*prompt;

  user = NULL;
  while (*env)
  {
    if (ft_strnstr(*env, "USER=", 5))
    {
      user = strdup(*env + 5);
      break ;
    }
    env++;
  }
	if (!user)
		return ft_strdup("rbsh: ");
	prompt = ft_strjoin(user, "-rbsh: ");
  free(user);
	return (prompt);
}

static void	ft_set_sig(void)
{
	struct sigaction	sa;

  ft_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = &sig_ctrlc_handler;
	sigaction(SIGINT, &sa, NULL);
	sa.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &sa, NULL);
  sigemptyset(&sa.sa_mask);
}

static void line_options(char *input)
{
	if (input)
		add_history(input);
	if (!ft_strcmp("clear", input))
		ft_printf("\033[H\033[2J");
}

void	prompt_loop(t_info *info)
{
	char				*line;
	char				*prompt;

	prompt = get_prompt(info->envcp);
  rl_catch_signals = 0;
	while (1)
	{
		ft_set_sig();
		line = readline(prompt);
		if (!line)
			break ;
		line_options(line);
		if (*line)
		{
			if (process_lines(line, info) == 4)
			{
				free(line);
				break ;
			}
		}
		free(line);
	}
	free(prompt);
}


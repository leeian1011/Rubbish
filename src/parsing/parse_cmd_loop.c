#include "../../includes/rubbish.h"

static int	fill_cmd(char *str, t_cmd *cmd)
{
	if (!str)
		return (1);
	if (!ft_strcmp(str, "export") || !ft_strcmp(str, "cd")
		|| !ft_strcmp(str, "unset") || !ft_strcmp(str, "exit")
		|| !ft_strcmp(str, "echo") || !ft_strcmp(str, "pwd")
		|| !ft_strcmp(str, "env"))
		return (cmd->type = BUILTIN, 1);
	else if (!ft_strcmp(str, "&&"))
		cmd->type = T_AND;
	else if (!ft_strcmp(str, "||"))
		cmd->type = T_OR;
	else if (!ft_strcmp(str, "|"))
		cmd->type = T_PIPE;
	else if (!ft_strcmp(str, "("))
		cmd->type = L_PAR;
	else if (!ft_strcmp(str, ")"))
		cmd->type = R_PAR;
	if (cmd->type != NONE)
		return (2);
	cmd->type = CMD;
	return (0);
}

static int	ft_num_args(char **str)
{
	int	i;

	i = 0;
	while (*str && ft_strncmp(*str, "|", 2) && ft_strncmp(*str, "&&", 3)
		&& ft_strncmp(*str, "||", 3) && ft_strncmp(*str, "(", 2)
		&& ft_strncmp(*str, ")", 2))
	{
		if (!ft_strncmp(*str, ">>", 3) || !ft_strncmp(*str, ">", 2)
			|| !ft_strncmp(*str, "<<", 3) || !ft_strncmp(*str, "<", 3))
		{
			if (*(str + 1))
				i -= 2;
			else
				i--;
		}
		i++;
		str++;
	}
	return (i);
}

static char	**fill_full_cmd(t_cmd *cmd, int num_arg, char **str)
{
	int	i;

	i = 0;
	cmd->full_cmd = malloc(sizeof(char *) * (num_arg + 1));
	if (cmd->full_cmd && cmd->path)
		cmd->full_cmd[i++] = ft_strdup(cmd->path);
	else if (cmd->full_cmd)
		cmd->full_cmd[i++] = ft_strdup(("null"));
	str++;
	while (i < num_arg && cmd->full_cmd)
	{
		str = redir_file(cmd, str);
		cmd->full_cmd[i] = ft_strdup(*str);
		i++;
		str++;
	}
	if (cmd->full_cmd)
		cmd->full_cmd[i] = NULL;
	return (str);
}

//Function to process and fill info of a single cmd
char	**parse_cmd_loop(t_cmd *cmd, char **str, char **env)
{
	int		num_arg;

	str = redir_file(cmd, str);
	if (!fill_cmd(*str, cmd))
		cmd->path = gcop(env, *str);
	else if (cmd->type == BUILTIN)
		cmd->path = ft_strdup(*str);
	else
		return (++str);
	num_arg = ft_num_args(str);
	str = fill_full_cmd(cmd, num_arg, str);
	if (*str)
		str = redir_file(cmd, str);
	return (str);
}

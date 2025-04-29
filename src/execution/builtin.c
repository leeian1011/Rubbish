#include "../../includes/rubbish.h"

int execute_builtin(t_cmd *cmd)
{
	if (!ft_strcmp(cmd->full_cmd[0], "echo"))
		g_ecode = echo(cmd);
	else if (!ft_strcmp(cmd->full_cmd[0], "pwd"))
		g_ecode = pwd();
	else if (!ft_strcmp(cmd->full_cmd[0], "env"))
		g_ecode = env(cmd->info->envcp);
	else if (!ft_strcmp(cmd->full_cmd[0], "cd"))
		g_ecode = cd(cmd);
	else if (!ft_strcmp(cmd->full_cmd[0], "unset"))
		g_ecode = unset(cmd);
	else if (!ft_strcmp(cmd->full_cmd[0], "export"))
    g_ecode = rbsh_export(cmd);
	else if (!ft_strcmp(cmd->full_cmd[0], "exit"))
    if (rbsh_exit(cmd))
      return (1);
	return (0);

}

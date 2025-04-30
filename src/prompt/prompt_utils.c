/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:37:00 by jianwong          #+#    #+#             */
/*   Updated: 2025/04/30 16:51:51 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rubbish.h"

//Function to advance i to the next possibly eectuable command
static void	advance_unused(t_cmd *cmds, int *i)
{
	int	par;

	par = 0;
	if (cmds[*i].type == L_PAR)
	{
		par = 1;
		(*i)++;
		while (*i < cmds->info->cmd_amount && par)
		{
			if (cmds[*i].type == L_PAR)
				par++;
			else if (cmds[*i].type == R_PAR)
				par--;
			(*i)++;
		}
		(*i)++;
	}
	else if (*i < cmds->info->cmd_amount)
		*i += cmds[*i].cmd_real_num;
}

//Check inapropriate node, returns 0 if OK
static int	err_node(t_cmd node)
{
	if (!node.path && (node.type == CMD || node.type == BUILTIN))
		return (error(NCMD, NULL, 127), 2);
	if (!node.full_cmd && (node.type == CMD || node.type == BUILTIN))
		return (1);
	if (node.out_flag && !node.outfile)
		return (error(SYNERR, NULL, 20), 4);
	else if (node.out_flag && access(node.outfile, F_OK) < 0)
		return (0);
	else if (node.out_flag && access(node.outfile, W_OK) < 0)
		return (error(NPERM, node.outfile, 126), 5);
	if (node.in_flag == 1 && !node.infile)
		return (error(SYNERR, NULL, 20), 4);
	else if (node.in_flag == 1 && access(node.infile, F_OK) < 0)
		return (error(NDIR, node.infile, 30), 6);
	else if (node.in_flag == 1 && access(node.infile, R_OK) < 0)
		return (error(NPERM, node.infile, 126), 5);
	if (node.in_flag == 2 && !node.limit)
		return (error(SYNERR, NULL, 20), 4);
	if (node.in_flag == 2 && (access(".tmp", F_OK) == 0
			&& access(".tmp", W_OK) < 0))
		return (error(NPERM, ".temp", 126), 5);
	return (0);
}

static int	ft_check_nodes(t_cmd *cmds)
{
	int	len;
	int	i;

	len = (*cmds).cmd_real_num;
	i = 0;
	while (i < len)
	{
		if (err_node(*(cmds + i)))
			return (1);
		i++;
	}
	return (0);
}

static void	loop_and_execute_part_2(t_cmd *cmds, int *i, t_type *tp)
{
	if ((*tp == T_AND && g_ecode == 0) || (*tp == T_OR && g_ecode != 0))
		return ;
	else if ((*tp == T_AND && g_ecode != 0) || (*tp == T_OR && g_ecode == 0)
		|| ft_check_nodes(&cmds[*i]))
	{
		advance_unused(cmds, i);
		return ;
	}
	execute(&cmds[*i]);
	*i += cmds[*i].cmd_real_num;
}

//Function to execute cmd repeatedly deppending on
//commands &&, || and ()
void	loop_and_execute(t_cmd *cmds, int *i)
{
	t_type	tp;
	int		pi;

	while (*i < cmds->info->cmd_amount)
	{
		tp = cmds[*i].type;
		if (tp == L_PAR || tp == R_PAR || tp == T_AND || tp == T_OR)
			(*i)++;
		if (tp == L_PAR)
		{
			pi = fork();
			if (pi == 0)
			{
				loop_and_execute(cmds, i);
				exit(g_ecode);
			}
			waitpid(pi, &g_ecode, 0);
			advance_to_last_r_par(cmds, i);
			continue ;
		}
		if (tp == R_PAR)
			return ;
		loop_and_execute_part_2(cmds, i, &tp);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:52:36 by jianwong          #+#    #+#             */
/*   Updated: 2025/04/30 21:52:37 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rubbish.h"

void	*error(t_ecode err_type, char *param, int err)
{
	g_ecode = err;
	if (err_type == QUOTE)
		ft_printf("rbsh: error while looking for matching quote\n");
	else if (err_type == NDIR)
		ft_printf("rbsh: No such file or directory: %s\n", param);
	else if (err_type == NPERM)
		ft_printf("rbsh: permission denied: %s\n", param);
	else if (err_type == NCMD)
		ft_printf("rbsh: command not found\n");
	else if (err_type == DUPERR)
		ft_printf("rbsh: dup2 failed\n");
	else if (err_type == FORKERR)
		ft_printf("rbsh: fork failed\n");
	else if (err_type == PIPERR)
		ft_printf("rbsh: error creating pipe\n");
	else if (err_type == SYNERR)
		ft_printf("rbsh: syntax error near unexpected token\n");
	else if (err_type == MEM)
		ft_printf("rbsh: no memory left on device\n");
	else if (err_type == IS_DIR)
		ft_printf("rbsh: Is a directory: %s\n", param);
	else if (err_type == NOT_DIR)
		ft_printf("rbsh: Not a directory: %s\n", param);
	return (NULL);
}

void	*builtin_error(t_ecode err_type, char *param, int err)
{
	g_ecode = err;
	if (err_type == HOMSET)
		ft_printf("rbsh: %s HOME not set\n", param);
	else if (err_type == OPWDSET)
		ft_printf("rbsh: %s OLDPWD not set\n", param);
	return (NULL);
}

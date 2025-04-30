/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:02:04 by jianwong          #+#    #+#             */
/*   Updated: 2025/04/30 21:53:33 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rubbish.h"

void	sig_ctrlc_handler(int sig)
{
	if (sig == SIGINT)
	{
		rl_replace_line("", 0);
		ft_printf("\n");
		rl_on_new_line();
		rl_redisplay();
		g_ecode = 1;
	}
}

void	sig_forked_handler(int sig)
{
	if (sig == SIGQUIT)
		ft_printf("Quit\n");
	else if (sig == SIGINT)
		ft_printf("\n");
}

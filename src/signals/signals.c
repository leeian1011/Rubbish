/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:02:04 by jianwong          #+#    #+#             */
/*   Updated: 2025/02/06 13:43:25 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/signals.h"

static void	set_sigaction(void *sa, void (*handler)(int, siginfo_t *, void *))
{
	struct sigaction *sigact;

	sigact = (struct sigaction *) sa;
	sigact->sa_sigaction = handler;
	sigaction(SIGINT, sigact, NULL);
	sigaction(SIGQUIT, sigact, NULL);
}

void	ignore_signal(int sig_no, siginfo_t *info, void *context)
{
	return ;
}

void	set_ignore(void *sa)
{
	set_sigaction(sa, ignore_signal);
}

void	signal_handler(int sig_no, siginfo_t *info, void *context)
{
	if (sig_no == SIGINT)
		printf("\n");
	else if (sig_no == SIGQUIT)
		exit(0);
}

void	set_default(void *sa)
{
	set_sigaction(sa, signal_handler);
}

void	init_signals(void *sa)
{
	struct sigaction *sigact;

	sigact = (struct sigaction *) sa;
	ft_memset(sigact, 0, sizeof(*sigact));
	sigact->sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sigact->sa_mask);
	set_default(sigact);
}

// how to use
// #include <sys/wait.h>
// int	main(void)
// {
// 	struct sigaction	sa;
//
// 	init_signals(&sa);
// 	int pid = fork();
// 	if (pid == 0)
// 	{
// 		char *strs[1] = {"cat"};
// 		execve("/bin/cat", strs, NULL);
// 		printf("hello\n");
// 	}
// 	else {
// 		set_ignore(&sa);
// 		wait(&pid);
// 		set_default(&sa);
// 		while (1)
// 		{
// 			printf("cringe\n");
// 			sleep(1);
// 		}
// 	}
// }

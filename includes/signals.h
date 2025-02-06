/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:37:31 by jianwong          #+#    #+#             */
/*   Updated: 2025/02/06 13:27:39 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include "../src/libft/libft.h"
# include <signal.h>


void	init_signals(void *sa);
void	set_default(void *sa);
void	signal_handler(int sig_no, siginfo_t *info, void *context);
void	set_ignore(void *sa);
void	ignore_signal(int sig_no, siginfo_t *info, void *context);

#endif

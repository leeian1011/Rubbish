/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:12:33 by jianwong          #+#    #+#             */
/*   Updated: 2025/02/06 17:00:45 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/readline.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>

// need to complie with -lreadline
int	main(void)
{
	char	*temp;
	int		i = 0;

	while (i < 10)
	{
		temp = readline("rbsh> ");
		add_history(temp);
		printf("%s\n", temp);
		free(temp);
		i++;
	}
	rl_clear_history();
	return (0);
}

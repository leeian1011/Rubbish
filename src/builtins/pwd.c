/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 01:42:05 by jianwong          #+#    #+#             */
/*   Updated: 2025/01/20 01:47:15 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rubbish.h"

int	pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
	{
		perror("pwd:");
		return (1);
	}
	ft_putendl_fd(cwd, 1);
	free(cwd);
	return (0);
}

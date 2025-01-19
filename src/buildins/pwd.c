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

#include "../../includes/buildins.h"

int	pwd(void)
{
	char	cwd[PATH_MAX];

	if (!getcwd(cwd, PATH_MAX))
	{
		perror("pwd");
		return (1);
	}
	printf("%s\n", cwd);
	return (0);
}
/**/
/*int	main(int argc, char **argv)*/
/*{*/
/*	pwd();*/
/*}*/

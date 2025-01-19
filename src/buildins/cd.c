/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 01:09:36 by jianwong          #+#    #+#             */
/*   Updated: 2025/01/20 01:41:40 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buildins.h"

// INCOMPLETE!!!! ENV NOT MADE YET SO NO $HOME

/// takes in path string and potentially env var to fill in empty with HOME
int	cd(char *path)
{
	char	cwd[PATH_MAX];

	if (chdir(path) == -1)
	{
		perror("cd");
		return (1);
	}
	return (0);
}

/*int	main(int argc, char **argv)*/
/*{*/
/*	cd(argv[1]);*/
/*	return 0; */
/*}*/

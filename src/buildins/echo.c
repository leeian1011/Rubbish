/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:15:36 by jianwong          #+#    #+#             */
/*   Updated: 2025/01/19 21:47:13 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buildins.h"

/// takes in all input [flags][string] as a single string input
int	echo(char *input)
{
	char	**args;
	int		nflag;

	nflag = 0;
	args = ft_split(input, ' ');
	if (!args)
		return (1);
	if (!ft_strncmp(*args, "-n", -1))
	{
		nflag = 1;
		args++;
	}
	printf("%s", *args++);
	while (*args)
		printf(" %s", *args++);
	if (!nflag)
		printf("\n");
	return (0);
}

/*int main(int argc, char **argv)*/
/*{*/
/*	echo(argv[1]);*/
/*}*/

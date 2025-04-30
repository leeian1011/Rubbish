/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:29:32 by jianwong          #+#    #+#             */
/*   Updated: 2025/04/30 16:29:33 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/rubbish.h"

//Return 1 in wrong check, 0 if all OK
int	validate_redir(char **str)
{
	int	flag;

	flag = 0;
	while (*str)
	{
		if (flag == 0 && (!ft_strncmp(*str, ">>", 3)
				|| !ft_strncmp(*str, ">", 2) || !ft_strncmp(*str, "<<", 3)
				|| !ft_strncmp(*str, "<", 2)))
			flag = 1;
		else if (flag == 1 && (!ft_strncmp(*str, ">>", 3)
				|| !ft_strncmp(*str, ">", 2) || !ft_strncmp(*str, "<<", 3)
				|| !ft_strncmp(*str, "<", 2)))
			return (error(SYNERR, NULL, 1), 1);
		else
			flag = 0;
		str++;
	}
	return (0);
}

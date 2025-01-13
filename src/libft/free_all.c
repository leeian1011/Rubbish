/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:52:30 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/27 17:39:17 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// takes in a void pointer pointer that has a NULL terminated array of pointers
/// and free them all
void	free_all(void **vars)
{
	int		i;
	char	**variable;

	i = 0;
	variable = (char **)vars;
	while (variable[i])
		free(variable[i++]);
	free(variable);
}

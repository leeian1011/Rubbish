/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:51:34 by jianwong          #+#    #+#             */
/*   Updated: 2025/01/14 19:17:48 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t ptr_size, size_t new_size)
{
	int		i;
	char	*result;
	char	*temp;

	i = -1;
	result = malloc(sizeof(new_size));
	if (!result)
		return (NULL);
	temp = (char *)ptr;
	if (!ptr)
		while (++i < ptr_size)
			result[i] = temp[i];
	free(ptr);
	return (result);
}

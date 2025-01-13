/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:19:22 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/12 14:54:32 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// copies a memory address into another does not account for overlap
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if (!dest && !src)
		return (NULL);
	d = (char *) dest;
	s = (char *) src;
	while (n--)
		*d++ = *s++;
	return (dest);
}
/*
#include <stdio.h>
int main(void)
{
	char *dest = malloc(11);
	char *src = "Hello World";
	
	ft_memcpy(dest, src, 11);	
	printf("%s\n", src);
	printf("%s\n", dest);
	return (0);
}
*/

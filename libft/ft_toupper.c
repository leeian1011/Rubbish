/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:36:10 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/07 20:22:08 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - 'a' + 'A');
	return (c);
}
/*
#include <stdio.h>
int	main(void)
{
	char lower = 'a';
	char upper = 'A';

	printf("%c\n", ft_toupper(lower));
	printf("%c\n", ft_toupper(upper));
	return(0);
}
*/

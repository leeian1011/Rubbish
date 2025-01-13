/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:52:39 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/07 20:22:03 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}
/*
#include <stdio.h>
int 	main(void)
{
	char c = 'a';
	char num = '1';

	printf("%d\n", ft_isdigit(c));
	printf("%d\n", ft_isdigit(num));
	return (0);
}
*/

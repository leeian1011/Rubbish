/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:07:18 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/07 20:22:03 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
	return (0);
}
/*
#include <ctype.h>
#include <stdio.h>
int 	main(void)
{		
	char c = 'a';
	char num = '1';
	int  out = 128;

	printf("%d\n", isascii(c));
	printf("%d\n", isascii(num));
	printf("%d\n", isascii(out));

	printf("%d\n", ft_isascii(c));
	printf("%d\n", ft_isascii(num));
	printf("%d\n", ft_isascii(out));
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:43:27 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/07 20:22:03 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
		return (1);
	return (0);
}

/*
#include <stdio.h>
int 	main(void)
{
	char c = 'a';
	char num = '1';

	printf("%d\n", isalpha(c));
	printf("%d\n", isalpha(num));
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:58:30 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/07 20:22:03 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// Checks if the int value 'c' is an alphabet or a number.
int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
/*
#include <stdio.h>
int main(void)
{
	char c = 'a';
	char num = '1';
	char special = '!';

	printf("%d\n", ft_isalnum(c));
	printf("%d\n", ft_isalnum(num));
	printf("%d\n", ft_isalnum(special));
}
*/

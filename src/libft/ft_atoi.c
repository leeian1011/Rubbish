/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:18:47 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/07 23:55:27 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// to turn a given string that has 
/// first myspace, a single sign - 
/// or + then numbers into integer
int	ft_atoi(const char *nptr)
{
	int	result;
	int	is_nega;

	is_nega = 0;
	result = 0;
	while ((9 <= *nptr && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			is_nega = 1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		result *= 10;
		result += (*nptr) - '0';
		nptr++;
	}
	if (is_nega)
		result *= -1;
	return (result);
}

//
// #include <stdio.h>
// int main(void) {
// 	printf("%d\n", atoi("1232"));
// 	printf("%d\n", ft_atoi("1232"));
// 	printf("%d\n", atoi("-1233"));
// 	printf("%d\n", ft_atoi("-1233"));
// 	printf("%d\n", atoi("2147483347"));
// 	printf("%d\n", ft_atoi("2147483347"));
// 	printf("%d\n", atoi("-2147483348"));
// 	printf("%d\n", ft_atoi("-2147483348"));
// 	printf("%d\n", atoi("			-+1233"));
// 	printf("%d\n", ft_atoi("			-+1233"));
// 	printf("%d\n", atoi("			-1233"));
// 	printf("%d\n", ft_atoi("			-1233"));
// }

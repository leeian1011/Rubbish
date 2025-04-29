/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:44:20 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/26 12:48:09 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		num[2];
	char	*result;

	num[0] = n / 10;
	num[1] = (n < 0) + 1;
	while (num[0] && num[1]++ > 0)
		num[0] /= 10;
	result = malloc(num[1] + 1);
	if (!result)
		return (NULL);
	result[num[1]--] = '\0';
	num[0] = n;
	while (num[1] > -1)
	{
		if (n < 0)
			result[num[1]--] = -(n % 10) + '0';
		else
			result[num[1]--] = (n % 10) + '0';
		n = n / 10;
	}
	if (num[0] < 0)
		result[0] = '-';
	return (result);
}

// #include <stdio.h>
// int main(void)
// {
// 	int num = 3123;
// 	int num1 = -12345;
// 	int num2 = 2147483647;
// 	int num3 = -2147483648;
// 	int num4 = 0;
//
// 	printf("%s\n", ft_itoa(num));
// 	printf("%s\n", ft_itoa(num1));
// 	printf("%s\n", ft_itoa(num2));
// 	printf("%s\n", ft_itoa(num3));
// 	printf("%s\n", ft_itoa(num4));
// }

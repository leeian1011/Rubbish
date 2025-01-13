/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:00:38 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/07 20:22:03 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// To set the given n number of bytes into 0
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
	return ;
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char str[6] = {'H', 'E', 'L', 'L', 'O', '\0'};
// 	int arr[5] = {1,2,3,4,5};
// 	char str1[6] = {'H', 'E', 'L', 'L', 'O', '\0'};
// 	int arr1[5] = {1,2,3,4,5};
// 	int i = 0;
//
// 	ft_bzero(arr, 20);
// 	ft_bzero(str, 6);
// 	bzero(arr1, 20);
// 	bzero(str1, 6);
//
// 	while (i < 5)
// 	{
// 		printf("%c\n", str[i]);
// 		printf("%d\n", arr[i]);
// 		printf("sep\n");
// 		printf("%c\n", str1[i]);
// 		printf("%d\n", arr1[i]);
// 		i++;
// 	}
// 	return (0);
// }

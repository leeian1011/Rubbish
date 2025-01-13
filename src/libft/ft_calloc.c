/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:39:17 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/07 23:53:54 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// To initialize a memory space in the heap with all 0 bytes
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (!nmemb || !size)
		return (malloc(0));
	if (nmemb > 4294967295 / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

// #include <stdio.h>
// int main (void)
// {
// 	if(!calloc(50000000, 50000000))
// 		printf("NULL1\n");
// 	if(!ft_calloc(50000000, 50000000))
// 		printf("NULL2\n");
// 	if(!calloc(0, 0))
// 			printf("NULL3\n");
// 	printf("%p\n", calloc(0,0));
// 	free(calloc(0,0));
// 	if(!ft_calloc(0, 0))
// 		printf("NULL4\n");
// 	printf("%p\n", ft_calloc(0,0));
//
// 	int *arr = calloc(4, sizeof(int));
// 	int *str = calloc(4, sizeof(char));
// 	int *arr1 = ft_calloc(4, sizeof(int));
// 	int *str1 = ft_calloc(4, sizeof(char));
//
// 	int i = 0;
// 	while (i < 4) {
// 		printf("start\n");
// 		printf("%d\n", arr[i]);
// 		printf("%c\n", str[i]);
// 		printf("==========\n");
// 		printf("%d\n", arr1[i]);
// 		printf("%c\n", str1[i]);
// 		printf("end\n");
// 		i++;
// 	}
// 	return (0);
// }

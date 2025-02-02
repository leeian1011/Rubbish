/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:26:25 by jianwong          #+#    #+#             */
/*   Updated: 2025/02/02 16:28:54 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*int	int_cmp(const void *a, const void *b)*/
/*{*/
/*	int	data_a;*/
/*	int data_b;*/
/**/
/*	data_a = *(int *)a;*/
/*	data_b = *(int *)b;*/
/*	return (data_a - data_b);*/
/*}*/
/**/
/*int	str_cmp(const void *data1, const void *data2)*/
/*{*/
/*	return (ft_strncmp(*(char **)data1, *(char **)data2, -1));*/
/*}*/

static void	swap_content(void *base1, void *base2, size_t size)
{
	char	*b1;
	char	*b2;
	char	temp;

	b1 = (char *)base1;
	b2 = (char *)base2;
	while (size--)
	{
		temp = *b1;
		*b1++ = *b2;
		*b2++ = temp;
	}
}

void	ft_qsort(void *base, size_t nmemb, \
							size_t size, int (*cmp)(const void *, const void *))
{
	void		*pivot;
	size_t		i;
	size_t		j;

	if (nmemb < 2)
		return ;
	i = 0;
	j = 0;
	pivot = base + ((nmemb - 1) * size);
	while (j < nmemb - 1)
	{
		if (cmp(base + (j * size), pivot) < 0)
		{
			swap_content(base + (i * size), base + (j * size), size);
			i++;
		}
		j++;
	}
	swap_content(base + (i * size), pivot, size);
	ft_qsort(base, i, size, cmp);
	ft_qsort(base + ((i + 1) * size), nmemb - (i + 1), size, cmp);
}

/*int	main(void)*/
/*{*/
	/*int *arr = malloc(sizeof(int) * 7);*/
	/*arr[0] = 3;*/
	/*arr[1] = 8;*/
	/*arr[2] = 10;*/
	/*arr[3] = 1;*/
	/*arr[4] = 3;*/
	/*arr[5] = 100;*/
	/*arr[6] = 2;*/
	// Array of strings
/*	const char *arr[] = {*/
/*			"banana",*/
/*			"apple",*/
/*			"cherry",*/
/*			"date",*/
/*			"blueberry",*/
/*			"fig",*/
/*			"elderberry"*/
/*	};*/
/*	ft_qsort(arr, 7, sizeof(char *), str_cmp);*/
/*	int		i = 0;*/
/*	while (i < 7)*/
/*		printf("%s\n", arr[i++]);*/
/*}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:26:25 by jianwong          #+#    #+#             */
/*   Updated: 2025/02/02 23:12:40 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	int_cmp(const void *a, const void *b)
{
	int	data_a;
	int data_b;

	data_a = *(int *)a;
	data_b = *(int *)b;
	return (data_a - data_b);
}

int	str_cmp(const void *data1, const void *data2)
{
	return (ft_strncmp(*(char **)data1, *(char **)data2, -1));
}

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

/*int main()*/
/*{*/
/*    int arr[] = {3, 6, 8, 10, 1, 2, 1};*/
/*    size_t nmemb = sizeof(arr) / sizeof(arr[0]);*/
/**/
/*    ft_qsort(arr, nmemb, sizeof(int), int_cmp);*/
/**/
/*    for (size_t i = 0; i < nmemb; i++)*/
/*    {*/
/*        printf("%d ", arr[i]);*/
/*    }*/
/*    printf("\n");*/
/**/
/*    return 0;*/
/*}*/

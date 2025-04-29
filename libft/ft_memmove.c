/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:44:40 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/12 13:51:05 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// copies src into dest memory space with account for overlap
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	d = (char *) dest;
	s = (char *) src;
	i = 0;
	if (dest < src)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (dest > src)
	{
		while (i < n)
		{
			d[(n - 1) - i] = s[(n - 1) - i];
			i++;
		}
	}
	return (dest);
}
/*
#include <stdio.h>
int main(void)
{
    char src1[] = "Hello, World!";
    char dest1[20];

    // Non-overlapping regions
    printf("Test 1 - Non-overlapping regions:\n");
    printf("Source before ft_memmove: %s\n", src1);
    ft_memmove(dest1, src1, ft_strlen(src1) + 1); 
    printf("Destination after ft_memmove: %s\n", dest1);

    // Overlapping regions - moving forward
    char src2[] = "OverlapTest";
    printf("\nTest 2 - Overlapping regions (forward):\n");
    printf("Source before ft_memmove: %s\n", src2);
    ft_memmove(src2 + 4, src2, ft_strlen(src2) + 1);
    printf("Source after ft_memmove: %s\n", src2);

    // Overlapping regions - moving backward
    char src3[] = "OverlapTest";
    printf("\nTest 3 - Overlapping regions (backward):\n");
    printf("Source before ft_memmove: %s\n", src3);
    ft_memmove(src3, src3 + 4, ft_strlen(src3 + 4) + 1); 
    printf("Source after ft_memmove: %s\n", src3);

    // Partial copy
    char src4[] = "PartialCopyExample";
    char dest2[20] = {0};
    printf("\nTest 4 - Partial copy:\n");
    printf("Source before ft_memmove: %s\n", src4);
    ft_memmove(dest2, src4, 7); // Copy only "Partial" part
    dest2[7] = '\0'; // Null-terminate for printing
    printf("Destination after ft_memmove: %s\n", dest2);
}
*/

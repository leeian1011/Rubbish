/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:34:20 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/08 15:00:38 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// applies a given function to all char in a string
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}
//
// void	displace(unsigned int i, char *s)
// {
// 	if (*s != ' ')
// 		*s = *s - 5;
// 	i++;
// }
//
// #include <stdio.h>
// int main(void)
// {
//     char *str1 = ft_strdup(str);
//     if (str1 == NULL)
//     {
//         perror("Failed to allocate memory");
//         return 1;
//     }
//     ft_striteri(str1, displace);
//     printf("%s\n", str1);bonus
//     free(str1);
//     return 0;
// }

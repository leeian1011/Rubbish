/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:40:46 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/07 20:22:08 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c - 'A' + 'a');
	return (c);
}
/*
#include <stdio.h>
int main(void)
{
    char lower = 'a';
    char upper = 'A';

    printf("%c\n", ft_tolower(lower));
    printf("%c\n", ft_tolower(upper));
    return(0);
}
*/

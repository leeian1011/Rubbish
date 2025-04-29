/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:53:55 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/15 12:13:13 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*num;

	num = ft_itoa(n);
	ft_putstr_fd(num, fd);
	free(num);
}
//
// int main(void)
// {
// 	ft_putnbr_fd(12345, 1);
// 	ft_putnbr_fd(-2147483648, 1);
// 	ft_putnbr_fd(2147483647, 1);
// 	ft_putnbr_fd(-12345, 1);
// }

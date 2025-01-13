/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:54:03 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/07 23:54:04 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

// #include <stdio.h>
// int main(void)
// {
// 	int data = 69;
// 	t_list *head = ft_lstnew(&data);
// 	int data2 = 420;
// 	ft_lstadd_back(&head, ft_lstnew(&data2));
// 	int data3 = 42;
// 	ft_lstadd_back(&head, ft_lstnew(&data3));
// 	printf("%d\n", ft_lstsize(head));
// 	return(0);
// }

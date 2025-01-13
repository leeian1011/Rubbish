/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:25:52 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/07 23:10:53 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = (lst->next);
	return (lst);
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
// 	printf("%d\n", *(int *)ft_lstlast(head)->content);
// 	return(0);
// }

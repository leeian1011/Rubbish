/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:30:53 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/07 22:55:24 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

// void	del(void *ptr)
// {
// 	free(ptr);
// }
//
// #include <stdio.h>
// int main(void)
// {
// 	t_list	*temp;
// 	t_list	*lst;
//
// 	int *data = malloc(sizeof(int));
// 	*data = 69;
// 	t_list *head = ft_lstnew(data);
// 	int *data2 = malloc(sizeof(int));
// 	*data2 = 420;
// 	int *data3 = malloc(sizeof(int));
// 	*data3 = 42;
// 	ft_lstadd_back(&head, ft_lstnew(data2));
// 	ft_lstadd_back(&head, ft_lstnew(data3));
// 	temp = ft_lstlast(head);
// 	printf("%d\n", ft_lstsize(head));
// 	ft_lstdelone(temp, del);
// 	lst = head;
// 	while (lst->next != temp)
// 		lst = lst->next;
// 	lst->next = NULL;
// 	printf("%d\n", ft_lstsize(head));
// 	return(0);
// }

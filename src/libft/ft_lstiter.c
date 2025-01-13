/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:37:50 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/07 23:42:22 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// #include <stdio.h>
// void print(void *ptr)
// {
// 	printf("%d\n", *(int *)ptr);
// }
//
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
// 	ft_lstiter(head, print);
// 	return(0);
// }

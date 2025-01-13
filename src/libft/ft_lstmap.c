/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:39:24 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/07 23:49:48 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*node;

	head = NULL;
	if (!lst)
		return (NULL);
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, node);
		lst = lst->next;
	}
	return (head);
}
//
// #include <stdio.h>
// void *addone(void *ptr)
// {
// 	int *data = malloc(sizeof(int));
//
// 	*data = *(int *) ptr + 1;
// 	return (data);
// }
//
// void del(void *ptr)
// {
// 	free(ptr);
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
// 	temp = head;
// 	while (temp)
// 	{
// 		printf("%d\n", *(int *)temp->content);
// 		temp = temp->next;
// 	}
// 	t_list *new_head = ft_lstmap(head, addone, del);
// 	while (new_head)
// 	{
// 		printf("%d\n", *(int *)new_head->content);
// 		new_head = new_head->next;
// 	}
// 	return(0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:45:21 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/07 23:41:14 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	while ((*lst)->next)
		lst = &(*lst)->next;
	(*lst)->next = new;
}

// #include <stdio.h>
// int main(void)
// {
// 	int data = 69;
// 	t_list *head = ft_lstnew(&data);
// 	// t_list *head = NULL;
// 	int data2 = 420;
// 	ft_lstadd_back(&head, ft_lstnew(&data2));
// 	printf("%d\n", *(int *)head->content);
// 	return(0);
// }

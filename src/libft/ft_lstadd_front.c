/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:23:52 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/07 22:59:40 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

// #include <stdio.h>
// int main(void)
// {
// 	int data = 69;
// 	// t_list *head = ft_lstnew(&data);
// 	t_list *head = NULL;
// 	int data2 = 420;
// 	ft_lstadd_front(&head, ft_lstnew(&data2));
// 	printf("%d\n", *(int *)head->content);
// 	return(0);
// }

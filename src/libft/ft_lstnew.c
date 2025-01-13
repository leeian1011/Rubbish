/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:38:53 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/07 23:46:14 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

// #include <stdio.h>
// int main(void)
// {
// 	int data = 69;
// 	t_list *head = ft_lstnew(&data);
// 	printf("data %d\n", *(int *)head->content);
// 	return(0);
// }

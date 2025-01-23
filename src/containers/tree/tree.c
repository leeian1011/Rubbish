/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 21:03:56 by jianwong          #+#    #+#             */
/*   Updated: 2025/01/22 23:59:33 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/containers.h"

t_tree	*tree_create_node(void *item)
{
	t_tree	*new_node;

	new_node = malloc(sizeof(t_tree));
	if (!new_node)
		return (NULL);
	new_node->childs = dll_init();
	new_node->item = item;
	return (new_node);
}

void	tree_make_child(t_tree **head, void *item)
{
	if (!head)
		return ;
	if (!*head)
	{
		tree_create_node(item);
		return ;
	}
	dll_append((*head)->childs, tree_create_node(item));
}

void	execute_tree_node(t_tree *head)
{
	printf("%s\n",(char *)head->item);
}

void	tree_postorder_traversal(t_tree *head)
{
	t_dll	*nodes;
	t_dll_node	*current_node;

	nodes = (t_dll *)head->childs;
	current_node = nodes->head;
	while (current_node)
	{
		tree_postorder_traversal((t_tree *)current_node->data);
		current_node = current_node->next;
	}
	printf("before :%s\n",(char *)head->item);
	// execute_node(head);
}

// int	main(void)
// {
// 	t_tree	*root;
// 	t_tree	*child;
// 	char	*str;
//
// 	root = tree_create_node(ft_strdup("1"));
// 	tree_make_child(&root, ft_strdup("2"));
// 	tree_make_child(&root, ft_strdup("3"));
// 	tree_make_child(&root, ft_strdup("4"));
// 	tree_make_child(&root, ft_strdup("5"));
// 	child = root->childs->head->data;
// 	tree_make_child(&child, ft_strdup("6"));
// 	tree_make_child(&child, ft_strdup("7"));
// 	tree_make_child(&child, ft_strdup("8"));
// 	tree_make_child(&child, ft_strdup("9"));
// 	tree_postorder_traversal(root);
// }

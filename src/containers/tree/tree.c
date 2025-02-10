/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 21:03:56 by jianwong          #+#    #+#             */
/*   Updated: 2025/02/11 01:20:00 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/containers.h"
#include "../../../includes/parsing.h"
#include <stdio.h>

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

void	tree_make_child_reversed(t_tree **head, void *item)
{
	if (!head)
		return ;
	if (!*head)
	{
		tree_create_node(item);
		return ;
	}
	dll_prepend((*head)->childs, tree_create_node(item));
}

void print_syntax(t_ast *syntax, int depth)
{
  int i = 0;
  while (i < depth * 4)
  {
    printf(" ");
    i++;
  }
  i = 0;
  printf("delimeter => %s\n", syntax->delimiter);
  while (i < depth * 4)
  {
    printf(" "); i++;
  }
	if (syntax->type == PIPELINE)
		printf("pipline\n");
	if (syntax->type == SIMPLE_COMMAND)
		printf("SIMPLE_COMMAND\n");
	if (syntax->type == LIST)
		printf("LIST\n");
	if (syntax->type == ARGUMENTS)
  {
    t_dll_node *itr = syntax->tokens->head;
		printf("ARGUMENTS\n");
    while (itr)
    {
      i = 0;
      while (i < depth * 4)
      {
        printf(" ");
        i++;
      }
      printf("argu token: %s\n", (char *)itr->data);
      itr = itr->next;
    }
  }
	if (syntax->type == GROUPING)
  {
    t_dll_node *itr = syntax->tokens->head;
		printf("GROUPING\n");
    while (itr)
    {
      i = 0;
      while (i < depth * 4)
      {
        printf(" ");
        i++;
      }
      printf("grouping token: %s\n", (char *)itr->data);
      itr = itr->next;
    }
  }
	if (syntax->type == REDIRECTIONS)
  {
    t_dll_node *itr = syntax->tokens->head;
		printf("REDIRECTIONS\n");
    while (itr)
    {
      i = 0;
      while (i < depth * 4)
      {
        printf(" ");
        i++;
      }
      printf("redirect token: %s\n", (char *)itr->data);
      itr = itr->next;
    }
  }
}

void	execute_tree_node(t_tree *head)
{
	// DO SOMETHING
}

void	free_tree(t_tree *head)
{
	dll_clear(((t_ast *)head->item)->tokens);
	free(((t_ast *)head->item)->tokens);
	free(head->item);
	dll_clear(head->childs);
	free(head->childs);
	free(head);
}

void print_tree(t_tree *tree, int depth)
{
  t_dll_node *itr = tree->childs->head;
  t_ast *syntax = (t_ast *)tree->item;
  if (depth == 0)
    printf("HEAD\n");
  print_syntax(syntax, depth);
  while (itr)
  {
    print_tree((t_tree *)itr->data, depth + 1);
    itr = itr->next;
  }
}

void	tree_postorder_traversal(t_tree *head, void (*exec)(t_tree *))
{
	t_dll	*nodes;
	t_dll_node	*current_node;

	nodes = head->childs;
	current_node = nodes->head;
	while (current_node)
	{
		tree_postorder_traversal((t_tree *)current_node->data, exec);
		current_node = current_node->next;
	}
	exec(head);
}

void	tree_preorder_traversal(t_tree *head, void (*exec)(t_tree *))
{
	t_dll	*nodes;
	t_dll_node	*current_node;

	nodes = head->childs;
	current_node = nodes->head;
	exec(head);
	while (current_node)
	{
		tree_postorder_traversal((t_tree *)current_node->data, exec);
		current_node = current_node->next;
	}
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_add_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:21:04 by jianwong          #+#    #+#             */
/*   Updated: 2025/01/16 15:07:48 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/binary_tree.h"

void	btree_add_right(t_btree **root, void *item)
{
	if (!root)
		return ;
	if (!*root)
		*root = btree_create_node(item);
	else
		(*root)->right = btree_create_node(item);
}

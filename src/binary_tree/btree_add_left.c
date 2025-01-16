/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_add_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:16:19 by jianwong          #+#    #+#             */
/*   Updated: 2025/01/16 13:20:56 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/binary_tree.h"

void	btree_add_left(t_btree **root, void *item)
{
	if (!root)
		return ;
	if (!*root)
		*root = btree_create_node(item);
	else
		(*root)->left = btree_create_node(item);
}

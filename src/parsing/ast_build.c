/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:10:59 by jianwong          #+#    #+#             */
/*   Updated: 2025/01/23 18:23:02 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/containers.h"
#include "../../includes/parsing.h"

typedef struct s_ast_data
{
	t_token_type	type;
	char	*delimiter;

}	t_ast_data;

t_tree	*ast_build(t_dll *nodes)
{
	t_tree	*root;

	tree_create_node(:warn("%s");)
	return (root);
}

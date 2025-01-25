/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:49:57 by jianwong          #+#    #+#             */
/*   Updated: 2025/01/25 21:07:14 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

t_ast	*ast_data_init(void)
{
	t_ast	*result;

	result = malloc(sizeof(t_ast));
	if (!result)
		return (NULL);
	result->tokens = NULL;
	result->type = UNSET;
	result->delimiter = NULL;
	return (result);
}

t_dll	*split_dll(t_dll *tokens, int (*cmp)(void *))
{
	t_dll	*child_tokens;
	t_dll	*working_dll;
	t_dll_node	*current;

	child_tokens = dll_init();
	current = tokens->head;
	dll_append(child_tokens, dll_init());
	working_dll = child_tokens->head->data;
	while (current)
	{
		if (cmp(current->data))
		{
			dll_append(child_tokens, dll_init());
			working_dll = child_tokens->tail->data;
		}
		dll_append(working_dll, current->data);
		current = current->next;
	}
	return (child_tokens);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:18:16 by jianwong          #+#    #+#             */
/*   Updated: 2025/02/02 23:52:52 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buildins.h"

int		unset(t_hashmap *hashmap, char *key)
{
	if (!key)
		return (0);
	hash_delete(hashmap, key);
	return (0);
}

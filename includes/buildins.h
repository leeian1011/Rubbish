/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:16:16 by jianwong          #+#    #+#             */
/*   Updated: 2025/02/06 15:01:55 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILDINS_H
# define BUILDINS_H

# include "../src/libft/libft.h"
# include "../includes/containers.h"

int		echo(char *input);
int		pwd(void);
void	exit(int exit_code);
int		cd(char *path, t_hashmap *hashmap);
int		env(t_hashmap *hashmap);
int		ft_export(t_hashmap *hashmap, char *str);
int		unset(t_hashmap *hashmap, char *key);

#endif

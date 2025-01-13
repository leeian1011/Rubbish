/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:40:40 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/09 15:15:21 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// duplicates the given string using malloc
char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// #include <stdio.h>
// int main(void)
// {
// 	char *str2 = ft_strdup(str);
// 	char *str3 = strdup(str);
// 	printf("%s\n",str2);
// 	printf("%s\n",str3);
// 	char *str0 = "";
// 	char *str20 = ft_strdup(str0);
// 	char *str30 = strdup(str0);
// 	printf("%s\n",str20);
// 	printf("%s\n",str30);
// 	printf("test\n");
// 	char *str00 = NULL;
// 	char *str300 = strdup(str00);
// 	char *str200 = ft_strdup(str00);
// 	printf("%s\n",str300);
// 	printf("%s\n",str200);
// }

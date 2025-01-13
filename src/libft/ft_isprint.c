/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:30:18 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/07 20:22:03 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (31 < c && c < 127)
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

void test_isprint(int value) {
    if (ft_isprint(value)) {
        printf("Value %d (0x%X) is printable.\n", value, value);
    } else {
        printf("Value %d (0x%X) is not printable.\n", value, value);
    }
}

int main() {
    // Test cases
    int test_values[] = {0, 31, 32, 65, 126, 127, 128, 255}; 
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);

    for (int i = 0; i < num_tests; i++) {
        test_isprint(test_values[i]);
    }

    return 0;
}
*/

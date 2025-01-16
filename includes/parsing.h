/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:22:46 by jianwong          #+#    #+#             */
/*   Updated: 2025/01/16 15:10:08 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "binary_tree.h"
# include "../src/libft/libft.h"

# define META BLANK PIPE OB CB OA CA
# define BLANK SPACE TAB
# define SPACE " "
# define TAB "\t"

# define OPERATOR CONTROL_OPERATOR REDIRECTION_OPERATOR

# define CONTROL_OPERATOR AND OR PIPE OB CB
# define AND "&&"
# define OR "||"
# define PIPE "|"
# define OB "("
# define CB ")"

# define REDIRECTION_OPERATOR OA CA DOA DCA
# define OA "<"
# define CA ">"
# define DOA OA OA
# define DCA CA CA

typedef enum b_token_type
{
	EXPRESSION,
	GROUPING,
	LIST,
	LIST_TAIL,
	PIPELINE,
	PIPELINE_TAIL,
	SIMPLE_COMMAND,
	SIMPLE_COMMAND_TAIL,
	ARGUMENTS,
	ARGUMENT,
	REDIRECTIONS,
	REDIRECTION
}	t_token_type;

typedef struct b_tokens
{
	t_token_type	type;
}		t_tokens;

#endif // !PARSING_H

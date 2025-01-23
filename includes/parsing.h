/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:22:46 by jianwong          #+#    #+#             */
/*   Updated: 2025/01/23 17:11:10 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "./pipe_operator.h"
# include "../src/libft/libft.h"
# include "../includes/containers.h"

# define META BLANK PIPE OB CB OA CA
# define BLANK SPACE TAB
# define SPACE " "
# define TAB "\t"

# define OPERATOR CONTROL_OPERATOR REDIRECTION_OPERATOR

# define METACHARACTER PIPE OA CA AMPERSAND
# define CONTROL_OPERATOR AND OR PIPE OB CB
# define AMPERSAND "&"
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

# define LEFT 0
# define RIGHT 1

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
	REDIRECTION,
	REDIRECTION_OP,
	WORD
}	t_token_type;

typedef struct b_tokens
{
	t_token_type	type;
	char		*str;
	char		*delimeter;
	int			*inputfds;
	int			*outputfds;
}		t_tokens;

bool parse_line(t_dll *dll, char *line);

#endif // !PARSING_H

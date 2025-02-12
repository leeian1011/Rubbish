/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:22:46 by jianwong          #+#    #+#             */
/*   Updated: 2025/02/12 14:04:18 by jianwong         ###   ########.fr       */
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
	PIPELINE,
	SIMPLE_COMMAND,
	ARGUMENTS,
	ARGUMENT,
	REDIRECTIONS,
	REDIRECTION_OP,
	UNSET
}	t_token_type;

typedef struct b_tokens
{
	t_token_type	type;
	char		*str;
	char		*delimeter;
	int			*inputfds;
	int			*outputfds;
}		t_tokens;

typedef struct s_ast
{
	t_token_type	type;
	char	*delimiter;
	t_dll	*tokens;

}	t_ast;

bool parse_line(t_dll *dll, char *line);
void	free_str(void *node);

t_tree	*ast_build(t_dll *expression);

t_dll	*split_dll(t_dll *tokens, int (*cmp)(void *));
t_ast	*ast_data_init(void);
  
int		pipe_cmp(void *value);
int		simple_cmd_cmp(void *value);
int		redirection_cmp(void *value);

#endif // !PARSING_H

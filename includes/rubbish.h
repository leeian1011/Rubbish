/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rubbish.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:12:15 by jianwong          #+#    #+#             */
/*   Updated: 2025/04/30 17:42:46 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUBBISH_H
# define RUBBISH_H

# include "../libft/libft.h"
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef enum e_ecode
{
	QUOTE = 1,
	NDIR = 2,
	NPERM = 3,
	NCMD = 6,
	DUPERR = 7,
	FORKERR = 8,
	PIPERR = 9,
	SYNERR = 10,
	MEM = 11,
	IS_DIR = 12,
	NOT_DIR = 13,
	NODE = 14,
	HOMSET,
	OPWDSET
}		t_ecode;

typedef enum s_type
{
	NONE,
	CMD,
	BUILTIN,
	T_PIPE,
	T_AND,
	T_OR,
	L_PAR,
	R_PAR
}		t_type;

typedef struct s_info
{
	int		cmd_amount;
	int		**fd;
	char	**envcp;
	char	*homepath;
}		t_info;

typedef struct s_cmd
{
	t_type	type;
	char	*path;
	char	**full_cmd;
	int		in_flag;
	int		out_flag;
	char	*infile;
	char	*outfile;
	char	*limit;
	t_info	*info;
	int		cmd_num;
	int		cmd_real_num;
}		t_cmd;

// Signals
void	sig_ctrlc_handler(int sig);
void	sig_forked_handler(int sig);
// Signals
// Parsing
/* Line splitting */
int		ft_nbr_wrd(char const *s, char c);
char	*ft_fill_word(char *wrd, char *str, int len);
void	ft_mtoq(char const *s, unsigned int *i);
int		ft_nxt_len(char const *s, char c);
char	**ft_split_str(char const *s, char c);
void	ft_free_split(char **str);
char	**redir_file(t_cmd *node, char **str);

/* Wildcard Utils */
int		cmd_count(char **mat);
int		count_dir(void);
void	handle_wildcard(t_cmd *node);

t_cmd	*parse_cmd(char **str, t_info *info);
char	**parse_cmd_loop(t_cmd *node, char **str, char **env);
// Parsing

// Error Handling
void	*error(t_ecode err_type, char *param, int err);
void	*builtin_error(t_ecode err_type, char *param, int err);
// Error Handling

// Execution
void	execute(t_cmd *cmds);
void	child_execution(t_cmd *cmds, int n);
char	*gcop(char **env, char *str);
void	pipe_fd_close(t_cmd *cmds, int j);
void	write_heredoc_tmp(t_cmd *cmds);
// Execution

// PROMPT
/* PROMPT UTILS */
size_t	var_strlen(const char *s, int quote);
char	*expand_concat(char *env, int len, char *res, char ch);
int		validate_redir(char **str);
int		validate_var(char *env, char *str, int index, int quote);
int		expand_env_var(char **str, char **env);
char	*normalize_line(char *str);
char	**normalize_meta(char **str, char *meta);
int		unquote(char **str);
/* PROMPT UTILS */

void	prompt_loop(t_info *info);
void	open_outfiles(t_cmd *nodes);
int		advance_to_last_r_par(t_cmd *cmds, int *idx);
void	loop_and_execute(t_cmd *nodes, int *i);
// PROMPT

void	ft_set_sig(void);
void	line_options(char *input);
// PROMPT2

// Env 
char	**clone_env(char **env);
char	**add_var(char **env, char *var);
char	**del_var(char **env, char *var);
int		find_equal(char *var, int *found);
int		found_in_env(char *var, char **env, char **path);
// Env

// Builtin
int		cd(t_cmd *cmds);
int		is_dir(const char *name);
int		pwd(void);
int		echo(t_cmd *cmds);
int		env(char **env);
int		unset(t_cmd *cmds);
int		rbsh_export(t_cmd *cmds);
int		rbsh_exit(t_cmd *node);
int		execute_builtin(t_cmd *cmds);
// Builtin

void	free_info(t_info *info);

extern int	g_ecode;
#endif

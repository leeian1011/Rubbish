NAME = rbsh
SRCS = ./src/parsing/line_splitter/split.c ./src/parsing/line_splitter/split_utils.c ./src/prompt/util/normalize_meta.c \
		./src/prompt/util/unquote.c ./src/prompt/util/validate_redir.c ./src/prompt/util/expand_env_var.c \
		./src/prompt/util/expand_env_var_utils.c ./src/prompt/util/normalize_line.c ./src/parsing/parse_cmd.c ./src/execution/execute.c ./src/execution/execute_helper.c\
		./src/execution/heredoc.c ./src/execution/getpaths.c ./src/execution/child_execution.c \
		./src/parsing/parse_cmd_loop.c ./src/parsing/redir_util.c ./src/parsing/wildcard.c ./src/parsing/wildcard_utils.c \
		./src/prompt/prompt_loop.c ./src/prompt/prompt_utils.c ./src/prompt/prompt_loop_2.c ./src/prompt/prompt_utils_2.c \
		./src/rubbish.c ./src/signal_handlers.c ./src/error.c \
		./src/env_utils.c ./src/builtins/export.c ./src/builtins/unset.c ./src/execution/builtin.c ./src/builtins/exit.c \
		./src/builtins/cd.c ./src/builtins/cd_helper.c ./src/builtins/pwd.c ./src/builtins/echo.c ./src/builtins/env.c

OBJ = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ) libft 
	cc $(FLAGS) $(OBJ) libft.a -lreadline -o $(NAME)

libft:
	$(MAKE) -C ./libft all
	cp ./libft/libft.a ./libft.a 

%.o: %.c
	cc -c $(FLAGS) $^ -o $@

clean:
	@$(MAKE) -C ./libft clean
	rm -rf $(OBJ) $(OBJBONUS)

fclean: clean
	@$(MAKE) -C ./libft fclean
	rm -rf $(NAME) $(LIBNAME)
	rm -rf ./libft.a

re: fclean all

.PHONY: all bonus clean fclean re libft

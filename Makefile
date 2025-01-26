NAME = minishell
DIR_LIBFT=src/libft
LIBFT=$(DIR_LIBFT)/libft.a
OBJ = $(SOURCE:.c=.o)
FLAGS = -Wall -Wextra -Werror
CC = cc

all: $(NAME)

rubbish:
	$(CC) $(SOURCE) -o rbsh

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $^ -I$(DIR_LIBFT) -o $(NAME)

%.o:%.c
	$(CC) $(FLAGS) -I$(DIR_LIBFT) -c $< -o $@

$(LIBFT):
	make -C $(DIR_LIBFT) bonus

test_lp:
	$(CC) src/containers/dll/dll.c src/containers/dll/dll_node.c src/parsing/line-parser.c \
		src/containers/tree/tree.c src/parsing/ast_build.c src/parsing/ast_utils.c src/rubbish.c \
		src/parsing/ast_cmp.c $(LIBFT)

test_dll:
	$(CC) $(FLAGS) src/containers/dll/dll_test.c src/containers/dll/dll.c src/containers/dll/dll_node.c


clean:
	rm -f src/*.o
	make -C $(DIR_LIBFT) clean

fclean: clean
	rm -f $(NAME)
	make -C $(DIR_LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re

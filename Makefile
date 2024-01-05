
NAME = pipex

CC = cc -Wall -Wextra -Werror

SRC = command_check.c  do_cmds.c  file_check.c  free_all.c \
	  ft_matrix_size.c open_files.c  pipex.c

OBJ = $(SRC:.c=.o)

FT_PRINTF = ft_printf

all: $(NAME)

$(NAME): $(OBJ)
	@make all -C $(FT_PRINTF)
	@$(CC) $(OBJ) ft_printf/libftprintf.a -o $(NAME)
	@echo "Compiled "$(NAME)" successfully!"

%.o: %.c
	@$(CC) -c $< -o $@

bonus : all

clean:
	@make clean -C $(FT_PRINTF)
	@rm -f $(OBJ)
	@echo "Cleaned objects successfully!"
	
fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(FT_PRINTF)
	@echo "Cleaned "$(NAME)" successfully!"
	
re: fclean all
	make re -C $(FT_PRINTF)

val:
	valgrind --leak-check=full --show-leak-kinds=all ./pipex $(file) cmd cmd2 $(file2)

replay:
	@rm -f $(NAME)
	@$(CC) $(SRC) ft_printf/libftprintf.a -o $(NAME)
	@echo "Let's  gooo!!"

.PHONY: all clean fclean bonus re replay
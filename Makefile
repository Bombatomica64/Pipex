
NAME = pipex

CC = cc -g -Wall -Wextra -Werror

SRC = close.c command_check.c  do_cmds.c  file_check.c  free_all.c \
	  ft_matrix_size.c open_files.c  pipex.c utils.c \
	  bonus_args.c bonus_pipe.c get_next_line2.c \

OBJ = $(SRC:.c=.o)

FT_PRINTF = ft_printf
LIBRARY = ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	@make all -C $(FT_PRINTF)
	@$(CC) $(OBJ) $(LIBRARY) -o $(NAME)
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


replay:
	@rm -f $(NAME)
	@$(CC) $(SRC) $(LIBRARY) -o $(NAME)
	@echo "Let's  gooo!!"

bonus : all
val:
	@read -p "Enter cmd: " cmd; \
	read -p "Enter cmd2: " cmd2; \
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
	./pipex "file1.txt" "$${cmd}" "$${cmd2}" "file2.txt"

bval:
	@read -p "Enter limiter: " limiter; \
	read -p "Enter cmd: " cmd; \
	read -p "Enter cmd2: " cmd2; \
	read -p "Enter cmd3: " cmd3; \
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s \
	./pipex "here_doc" "$${limiter}" "$${cmd}" "$${cmd2}" "$${cmd3}" "file2.txt"

.PHONY: all clean fclean bonus re replay
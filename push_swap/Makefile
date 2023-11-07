#------------MakeFile------------#
NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS_DIR = ./src/
SRCS =  main.c \
		checker_functions.c \
		mov_types.c \
		mov_printer.c \
		mov_printer2.c \
		sorter.c \
		utils.c

OBJS_DIR = ./obj/
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

all: obj lib $(NAME)

obj:
	mkdir obj

$(OBJS_DIR)%.o:$(SRCS_DIR)%.c
	$(CC) $(CFLAGS) -I ./includes/ -I ./libft/ -o $@ -c $< -g

lib:
	make -C ./libft/

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L ./libft/ -l ft -o $(NAME) -g

clean:
	rm -rf obj push_swap
	make clean -C ./libft/

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft/

re: clean all

.PHONY: all clean fclean re
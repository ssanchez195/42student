#------------MakeFile------------#
NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS_DIR = ./src/
SRCS =  main.c \
		checker_functions.c \
		mov_printer.c \
		mov_printer2.c \
		mov_types.c \
		sorter_max5.c \
		radix.c \
		utils.c

OBJS_DIR = ./obj/
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

all: obj lib $(NAME)

obj:
	mkdir obj

$(OBJS_DIR)%.o:$(SRCS_DIR)%.c
	$(CC) $(CFLAGS) -I ./includes/ -I ../libft/ -o $@ -c $< -g

lib:
	make -C ../libft/

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L ../libft/ -l ft -o $(NAME) -g

clean:
	rm -rf obj push_swap
	make clean -C ../libft/

fclean: clean
	rm -rf $(NAME)
	make fclean -C ../libft/

re: clean all

test_mov:
	./push_swap 4 3 2 1 | wc -l

test:
	./push_swap 2 65 3 457 8287 624 32

.PHONY: all clean fclean re
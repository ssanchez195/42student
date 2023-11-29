NAME = pipex
CC = gcc
CFLAGS = -Werror -Wall -Wextra

SRCS_DIR = src/
OBJS_DIR = obj/
INCLUDES_DIR = includes/

SRCS = $(SRCS_DIR)pipex.c $(SRCS_DIR)pipex_process.c
OBJS = $(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L ../libft/ -l ft -o $(NAME) -g

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -c $< -o $@

all: lib $(NAME)

lib:
	make -C ../libft/

clean:
	rm -rf $(OBJS_DIR)
	make clean -C ../libft/

fclean: clean
	rm -f $(NAME)
	make clean -C ../libft/
	
re: fclean all

CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCDIR = ./src/
OBJDIR = ./obj/
LIBDIR = ./lib/

SRCS =  $(SRCDIR)so_long_start.c \
		$(SRCDIR)read_file.c \
		$(SRCDIR)block_checker.c
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
LIB = ./MLX42/libmlx42.a ./libft/libft.a ./get_next_line/get_next_line.a ./ft_printf/ft_printf.a
NAME = so_long
TOTAL_FILES := $(words $(SRCS))
CURRENT_FILE := 0

.PHONY: all clean fclean

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -Iinclude -lglfw -L "/Users/sergisan/.brew/opt/glfw/lib/" -o $@ $(OBJS) $(LIB)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(eval CURRENT_FILE := $(shell echo $$(($(CURRENT_FILE) + 1))))
	@echo "Compilando archivos $(CURRENT_FILE)/$(TOTAL_FILES)"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)
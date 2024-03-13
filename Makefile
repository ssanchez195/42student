CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCDIR = ./src/
OBJDIR = ./obj/
LIBDIR = ./lib/

SRCS =  $(SRCDIR)so_long_start.c \
		$(SRCDIR)read_file.c \
		$(SRCDIR)block_checker.c
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
LIB = $(LIBDIR)/mlx.a
NAME = so_long
TOTAL_FILES := $(words $(SRCS))
CURRENT_FILE := 0

.PHONY: all clean fclean

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -L ./mlx/ -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c -o $@ $< 
	@$(eval CURRENT_FILE := $(shell echo $$(($(CURRENT_FILE) + 1))))
	@echo "Compilando archivos $(CURRENT_FILE)/$(TOTAL_FILES)"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)
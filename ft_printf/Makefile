SRCS = ft_printf.c \
       ft_printf_aux.c

OBJS = $(SRCS:.c=.o)
NAME = prueba_printf

all: $(NAME)
%.o: %.c
	gcc -c $<

$(NAME): $(OBJS)
	gcc -o $@ $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)


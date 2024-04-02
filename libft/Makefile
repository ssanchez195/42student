CC = cc

AR = ar

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

MY_SOURCES = ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_strlcpy.c \
			ft_strchr.c \
			ft_memcpy.c \
			ft_memcmp.c \
			ft_memmove.c \
			ft_memset.c \
			ft_strdup.c \
			ft_strlen.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putnbr_fd.c \
			ft_putendl_fd.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_memchr.c \
			ft_memcpy.c \
			ft_strlcat.c \
			ft_strncmp.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_atoi.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strcat.c \
			ft_strcpy.c

MY_SOURCES_BONUS = ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c
	
MY_OBJECTS = $(MY_SOURCES:.c=.o)

MY_OBJECTS_BONUS = $(MY_SOURCES_BONUS:.c=.o)

all : $(NAME)

$(NAME):$(MY_OBJECTS)
	$(AR) -rcs $(NAME) $(MY_OBJECTS)

bonus: $(MY_OBJECTS_BONUS)
	$(AR) -rcs $(NAME) $(MY_OBJECTS_BONUS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean
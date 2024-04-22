#  |  |  ___ \	\  |		 |
#  |  |	 ) |  |\/ |   _  |  |  /   _ 
# ___ __|  __/   |   |  (   |	<	__/ 
#	_|  _____| _|  _| \__,_| _|\_\ \___|
#							  by jcluzet
################################################################################
#									 CONFIG								   #
################################################################################

NAME		:= philo
CC		:= gcc
FLAGS	:= -fsanitize=thread -Wall -Wextra -Werror
#-fsanitize=thread  
################################################################################
#								 PROGRAM'S SRCS							   #
################################################################################

SRCS		:=		philo_start.c \
					utils.c \
						  
OBJS		:= $(SRCS:.c=.o)

COUNT	   := 1
TOTAL	   := $(words $(SRCS))

.c.o:
	@echo "Compiling file $(COUNT) of $(TOTAL)"
	-@${CC} ${FLAGS} -c $< -o ${<:.c=.o}
	@$(eval COUNT=$(shell echo $$(($(COUNT)+1))))

################################################################################
#								  Makefile  objs							  #
################################################################################


CLR_RMV		:= \033[0m
RED			:= \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM			:= rm -f

${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@${CC} ${FLAGS} -o ${NAME} ${OBJS} > /dev/null 2>&1
			@echo "$(GREEN)$(NAME) created ✔️"

all:		${NAME}

bonus:		all

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all
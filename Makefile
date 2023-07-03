# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 09:27:30 by hucorrei          #+#    #+#              #
#    Updated: 2023/07/03 10:58:56 by hucorrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME	= philo
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -pthread
#flags pendant test:
#CFLAGS	= -pthread -fsanitize=thread -g
OBJ_DIR			= .objs

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS	= 	./src/main.c \
			./src/ft_list.c \
			./src/ft_monit.c \
			./src/ft_mutex.c \
			./src/ft_routine.c \
			./src/ft_setups.c \
			./src/ft_tools.c \
			./src/philo.c \
			./src/ft_time.c \

OBJS	= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@${CC} ${FLAGS} -c $< -o $@ 

################################################################################
#                                  Makefile  objs                              #
################################################################################

CLR_RMV		= \033[0m
RED		    = \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
CYAN 		= \033[1;36m
RM			= rm -rf

${NAME}:	${OBJS}
		@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
		@${CC} ${CFLAGS} ${OBJS} -o ${NAME}
		@echo "$(GREEN)$(NAME) created[0m ✔️"
		@echo "$(RED)N'OUBLIE PAS DE CHANGER LES FLAGS!!! $(CLR_RMV)"

all:	${NAME}

clean:
			@${RM} -r $(OBJ_DIR)
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

git:
		git add .
		git commit -m "$m"
		git push
		@ echo "$(BLUE)ALL is on your $(CYAN)GIT $(CLR_RMV)✔️"

.PHONY:	all clean fclean re git
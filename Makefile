# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clorcery <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/09 10:54:25 by clorcery          #+#    #+#              #
#    Updated: 2022/07/25 11:39:58 by clorcery         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# /* ~~~~~~~ Colors ~~~~~~~ */
GREEN:="\033[1;32m"
YELLOW:="\033[1;33m"
EOC:="\033[0;0m"
# /* ~~~~~~~~~~~~~~ */

SRCS = Srcs/main.c \
	   Srcs/Utils/check_argc.c \
	   Srcs/Utils/check_argc_bis.c \
	   Srcs/Utils/recup_list.c \
	   Srcs/Utils/free_list.c \
	   Srcs/Utils/utils.c \
	   Srcs/Utils/utils_bis.c \
	   Srcs/Functions/swap_list.c \
	   Srcs/Functions/rotate_list.c \
	   Srcs/Functions/reverse_rotate_list.c \
	   Srcs/Functions/push_list.c \
	   Srcs/Algo/push_swap_min.c \
	   Srcs/Algo/push_swap_moy.c \
	   Srcs/Algo/push_swap_max.c \

OBJS = ${SRCS:.c=.o}

NAME = push_swap

LIBFT = ./Libft/libft.a

FLAGS = -Wall -Wextra -Werror -g 

RM = rm -rf

all: ${NAME}

.c.o:
		@gcc ${FLAGS} -c $< -o $@

${LIBFT}:
		@make -C ./Libft --no-print-directory

${NAME}: ${OBJS} ${LIBFT}
		@gcc ${FLAGS} ${OBJS} ${LIBFT} -o ${NAME}
		@echo ${GREEN}"compilation complete"${EOC}

clean:
		@make -C ./Libft/ clean --no-print-directory
		@${RM} ${OBJS}
		@echo ${YELLOW}"clean ok"

fclean:	clean
		@${RM} ${LIBFT}
		@${RM} ${NAME}
		@echo "fclean ok"${EOC}

re: fclean all

.PHONY: all clean fclean re

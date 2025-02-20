# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: radaoudi <radaoudi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/23 19:21:02 by radaoudi          #+#    #+#              #
#    Updated: 2022/06/23 19:32:10 by radaoudi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.c utils.c
OBJS	= ${SRCS:.c=.o}

NAME	= pipex

CC		= gcc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
		make -C libft
		${CC}	${CFLAGS} -o ${NAME} ${OBJS} libft/libft.a

all:		${NAME}

clean:
			make clean -C libft
			${RM} ${OBJS}

fclean:		clean
			make fclean -C libft
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bschwitz <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 14:31:51 by bschwitz          #+#    #+#              #
#    Updated: 2022/02/16 17:01:47 by bschwitz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minitalk.a

SRCS		= server.c client.c libft_utils.c

OBJS		= ${SRCS:.c=.o}

CC			= gcc

UTILS		= libft_utils.c

CFLAGS		= -Wall -Werror -Wextra

${NAME}:	${OBJS}
	@ar -rc ${NAME} ${OBJS}
	@ranlib ${NAME}
	${CC} ${CFLAGS} -fsanitize=address server.c ${UTILS} -o server
	${CC} ${CFLAGS} -fsanitize=address client.c ${UTILS} -o client

all:	${NAME}

clean:
	@rm -rf ${OBJS} a.out server client

fclean: clean
	rm -rf ${NAME}

re:		fclean all

.PHONY:	all clean fclean re

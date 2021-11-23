# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/25 13:55:54 by prodrigo          #+#    #+#              #
#    Updated: 2020/12/25 13:58:53 by prodrigo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	srcs/ft_put.c \
		srcs/ft_printf.c \
		srcs/check_flags.c \
		srcs/put_fnbr.c \
		srcs/put_uint.c \
		srcs/put_fchr.c \
		srcs/put_fstr.c \
		srcs/put_fhex.c \
		srcs/put_fptr.c \
		srcs/utils_ft.c \
		srcs/utils.c

OBJS = ${SRCS:.c=.o}

HEADERF = includes

HEADER = ft_printf.h

NAME = libftprintf.a

CC = gcc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

%.o:	%.c ${HEADERF}/${HEADER}
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I${HEADERF}

$(NAME):	${OBJS}
			ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS} ${OBJBONUS}

fclean:		clean
			${RM} ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re

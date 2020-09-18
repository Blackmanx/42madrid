# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/03 04:22:05 by prodrigo          #+#    #+#              #
#    Updated: 2020/03/03 04:47:07 by prodrigo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_bzero.c \
ft_bzero.c \
ft_memset.c \
ft_memcpy.c \
ft_memccpy.c \
ft_memmove.c \
ft_memchr.c \
ft_memcmp.c \
ft_strlen.c \
ft_isalpha.c \
ft_isdigit.c \
ft_isalnum.c ft_isascii.c \
ft_isprint.c \
ft_toupper.c \
ft_tolower.c \
ft_strchr.c \
ft_strrchr.c \
ft_strncmp.c \
ft_strlcpy.c \
ft_strlcat.c \
ft_strnstr.c \
ft_atoi.c \
ft_calloc.c \
ft_strdup.c \
ft_substr.c \
ft_strjoin.c \
ft_strtrim.c \
ft_split.c \
ft_itoa.c \
ft_strmapi.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c

OBJ = ${SRC:.c=.o}

INCLUDES = ./
NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I. -c
RM	= rm -f
.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJ}
			ar rc ${NAME} ${OBJ}

all: $(NAME)

clean:
		${RM} ${OBJ}
fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/03 04:22:05 by prodrigo          #+#    #+#              #
#    Updated: 2023/04/18 23:05:03 by prodrigo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


INCLUDES = libft.h
NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I. -c
RM	= rm -f

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
fd_error.c \
ft_putnbr_fd.c \
ft_striter.c \
ft_swap.c \
ft_getlen.c \
get_next_line.c

OBJ = ${SRC:.c=.o}

all:  libft $(NAME)

libft:
$(NAME): $(OBJ) $(INCLUDES)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
		${RM} ${OBJ}
fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

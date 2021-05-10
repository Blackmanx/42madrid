# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/10 17:24:30 by prodrigo          #+#    #+#              #
#    Updated: 2021/05/10 19:11:55 by prodrigo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = cub3D

SRCS = cub3D.c
# TODO: Rest of C files.
OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIBS = -L./inc/libft/ -lft -L -lmlx

FRAMES = -framework OpenGl -framework AppKit

MLX = libmlx.dylib

$(NAME): $(OBJS)
	make -C ./inc/libft/
	make -C ./inc/lib/
	cp ./inc/lib/$(MLX) .
	$(CC) $(CFLAGS) $(LIBS) $(FRAMES) $(OBJS) -o $(NAME)

all:	$(NAME)

clean:
	make clean -C ./inc/libft/
	make clean -C ./inc/lib/
	rm -f $(OBJS)

fclean:		clean
	make fclean -C ./inc/libft/
	rm -f $(NAME) $(MLX)


re:			fclean $(NAME)

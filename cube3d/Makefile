# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/10 17:24:30 by prodrigo          #+#    #+#              #
#    Updated: 2021/05/23 14:58:35 by prodrigo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = cub3D

SRCS = cub3d.c \
src/bmp_bg.c\
src/check_wall.c\
src/draw_sprites.c\
src/exit.c\
src/keys.c\
src/lib.c\
src/map_utils.c\
src/map.c\
src/movement.c\
src/player.c\
src/raycasting.c\
src/sets_extra.c\
src/sets.c\
src/sprite_utils.c\
src/win.c\
inc/get_next_line_utils.c\
inc/get_next_line.c\
inc/libft/*.c

LIB = lib-$(OS)/libmlx.a

OBJ = $(SRC:.c=.o)

OS  = $(shell uname -s)

ifeq ($(OS), Darwin)
    MINILIB = -framework OpenGL -framework AppKit
else
    MINILIB = -lm -lz -lXext -lX11 -L ./minilibx-Linux -pthread
endif

ifeq ($(OS), Darwin)
    SYSTEM = -D MAC_OS_DETECTED=1
else
    SYSTEM = -D XUBUNTU_DETECTED=1
endif

%.o: %.c
	gcc $(SYSTEM) -Wall -Werror -Wextra -g -I /usr/local/include -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
		$(MAKE) -C lib-$(OS)/
		gcc -Wall -Werror -Wextra -g $(OBJ) -I /usr/local/include $(LIB) $(MINILIB) -o $(NAME)

clean:
		make -C lib-$(OS) clean
		rm -rf $(OBJ)

fclean: clean
		make -C lib-$(OS) clean
		rm -rf $(NAME)

re : fclean all

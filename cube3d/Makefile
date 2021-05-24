# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/06 15:29:03 by prodrigo          #+#    #+#              #
#    Updated: 2021/05/24 21:02:12 by prodrigo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC = cub3d.c				\
	  src/read_map.c	\
	  src/init.c		\
	  src/init_mlx.c	\
	  src/save_info.c	\
	  src/read_textures.c	\
	  src/save_map.c	\
	  src/handler.c		\
	  src/move.c		\
	  src/raycaster.c	\
	  src/window.c		\
	  src/save_dt.c	\
	  src/sprites.c		\
	  src/check_info.c	\
	  src/check_elements.c \
	  src/aux_read.c \
	  src/cb_split.c \
	  src/get_next_line.c \
	  src/utils.c	\
	  src/utils_aux.c	\
	  src/utils_aux_aux.c

LIB = lib-$(OS)/libmlx.a

OS  = $(shell uname -s)

OBJ = $(SRC:.c=.o)

ifeq ($(OS), Darwin)
    MINILIB = -framework OpenGL -framework AppKit
else
    MINILIB = -lm -lz -lXext -lX11 -L ./lib-Linux -pthread
endif

ifeq ($(OS), Darwin)
    SYSTEM = -D MAC_SYSTEM=1
else
    SYSTEM = -D LINUX_SYSTEM=1
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

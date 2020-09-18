# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/23 13:19:21 by prodrigo          #+#    #+#              #
#    Updated: 2019/10/23 22:10:04 by prodrigo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	bsq
CFLAGS	=	-Wall -Werror -Wextra
CC		=	gcc
src		=	matrixutils.c algorithm.c bsq.c utils_one.c utils_two.c
obj		=	$(src:.c=.o)



all: $(NAME)

$(NAME): $(obj)
	$(CC) $(CFLAGS) -o $(NAME) $(src)

.PHONY: clean fclean re
clean:
		rm -f $(obj)

fclean: clean
		rm -rf $(NAME)

re: fclean all

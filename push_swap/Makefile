# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/20 12:59:57 by prodrigo          #+#    #+#              #
#    Updated: 2021/09/20 13:28:00 by prodrigo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
SRCS = src/push_swap.c \

NAME = push_swap
OBJS = $(SRCS:c=.o)
CFLAGS = -Wall -Wextra -Werror
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INC) -o $(NAME)
all: *.h
	@$(MAKE) $(NAME)
clean:
	rm -rf *.o
	rm -rf src/*.o
fclean: clean
	rm -rf $(NAME)
re: fclean all

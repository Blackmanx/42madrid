# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/21 17:37:34 by prodrigo          #+#    #+#              #
#    Updated: 2020/12/25 02:32:07 by prodrigo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

LIBFT_A		= libft.a

INC_PATH	= inc/
SRCS_PATH	= src
OBJ_PATH	= obj/
LIBFT_PATH	= ./libft/

CC		= gcc
FLAGS		= -Wall -Werror -Wextra


FTPRINTF_H	= -I ./inc/
LIBFT_H		= -I ./$(LIBFT_PATH)

SRCS_NAME	=	ft_printf.c \
				check_flags.c\
				conversors.c\
				identify.c\
				put_hex.c\
				put_nums.c\
				put_pointer.c\
				put_text.c

OBJ		= $(addprefix $(OBJ_PATH)/, $(SRCS_NAME:%.c=%.o))


LIBFT		= $(LIBFT_PATH) -lft


all:	$(NAME)

$(NAME):	$(OBJ)
		@make all -C $(LIBFT_PATH)/
		@ar rc $(NAME) $(OBJ) $(LIBFT_PATH)/*.o
		@ranlib $(NAME)

$(OBJ_PATH)/%.o: $(SRCS_PATH)/%.c
	@mkdir	-p $(OBJ_PATH)
	@$(CC) $(FLAGS) -I $(INC_PATH) -o $@ -c $<

clean	:
	@make -C $(LIBFT_PATH)/ clean
	@/bin/rm -rf $(OBJ_PATH)

fclean	: clean
	@make -C $(LIBFT_PATH)/ fclean
	@/bin/rm -rf $(NAME)

re:	fclean all

.PHONY:	all, clean, fclean, re

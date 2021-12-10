# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/20 12:59:57 by prodrigo          #+#    #+#              #
#    Updated: 2021/12/03 15:51:35 by prodrigo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= push_swap.a
OBJF	= push_swap

SRCS 	= src/init.c src/push_swap.c src/memory.c \
		src/p_ops.c src/r_ops.c src/rr_ops.c \
		src/s_ops.c src/sort_algo.c src/sort_fhundred.c \
		src/sort_hundred.c src/sort_utils.c src/choose_sort.c \
		src/stack_utils.c src/utils.c
OBJS 	= ${SRCS:.c=.o}
MAIN	= src/push_swap.c

HEADER	= -I ./inc/

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -g

.c.o:		%.o : %.c
					@gcc ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)

$(NAME):	${OBJS}
					@make re -C ./src/libft
					@cp ./src/libft/libft.a ./$(NAME)
					@ar -rcs ${NAME} ${OBJS}
					@$(CC) $(NAME) -o ${OBJF}

all: 		${NAME}

clean:
					@make clean -C ./src/libft
					@rm -f ${OBJS} ${OBJS_B}

fclean: 	clean
					@make fclean -C ./src/libft
					@rm -f $(NAME)
					@rm -f ${OBJF}

re:			fclean all


.PHONY: all clean fclean re

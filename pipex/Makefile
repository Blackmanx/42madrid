NAME 	= pipex.a
OBJF	= pipex

SRCS 	= src/pipex.c src/path_utils.c src/process.c
OBJS 	= ${SRCS:.c=.o}
MAIN	= src/pipex.c

HEADER	= -I./inc/

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -g

.c.o:		%.o : %.c
					@gcc ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)

$(NAME):	${OBJS}
					@make re -C ./libft
					@cp ./libft/libft.a ./$(NAME)
					@ar -rcs ${NAME} ${OBJS}
					@$(CC) $(NAME) ${MAIN} -o ${OBJF}

all: 		${NAME}

clean:
					@make clean -C ./libft
					@rm -f ${OBJS} ${OBJS_B}

fclean: 	clean
					@make fclean -C ./libft
					@rm -f $(NAME)
					@rm -f ${OBJF}

re:			fclean all


.PHONY: all clean fclean re
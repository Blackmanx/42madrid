OUT	= pipex
BONUS_OUT  = pipex_bonus

SRCS 	= src/pipex.c src/process.c src/path_utils.c
OBJS 	= ${SRCS:.c=.o}

SRCS_B	= src/pipex_bonus.c src/process_bonus.c src/path_utils_bonus.c
OBJS_BONUS	= ${SRCS_B:.c=.o}

HEADER	= -Iincludes

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -g

.c.o:		%.o : %.c
					@gcc ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)

all: 		${OUT}

${OUT}:	${OBJS}
					@make re -C ./libft
					@echo "Compiled libft"
					@$(CC) ${OBJS} -Llibft -lft -o ${OUT}
					@echo "Compiled pipex"
					@touch infile


bonus:		${BONUS_OUT}

${BONUS_OUT}:	${OBJS_BONUS}
					@make re -C ./libft
					@echo "Compiled libft"
					@$(CC) ${OBJS_BONUS} -Llibft -lft -o ${OUT}
					@echo "Compiled bonus: usage: pipex_bonus"
					@touch infile

clean:
					@make clean -C ./libft
					@rm -f ${OBJS} ${OBJS_BONUS}

fclean: 	clean
					@make fclean -C ./libft
					@rm -f $(OUT)
					@rm -f infile || true
					@echo "Cleaning all files"
					@ls | grep -vw -E "Makefile|src|inc|libft" | tr '\n' '\0' | xargs -I{} rm {}

re:			fclean all

re_bonus:	fclean bonus

.PHONY: all clean fclean re re_bonus bonus

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I. -c

SRC =	ft_printf.c\
		src/ft_printf_utils.c\
		src/ft_check_arg.c\
		src/ft_info_flags.c\
		src/ft_put_flag_char.c\
		src/ft_putchar.c\
		src/ft_put_flag_nbr.c\
		src/ft_putnbr.c\
		src/ft_put_flag_str.c\
		src/ft_putstr.c\
		src/ft_putnbr_abs.c\
		src/ft_put_flag_hex.c\
		src/ft_puthex.c\
		src/ft_put_flag_mem.c\
		src/ft_putmem.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

bonus: $(OBJB)
	ar rc $(NAME) $(OBJB)

clean:
	rm -f $(OBJ) $(OBJB)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
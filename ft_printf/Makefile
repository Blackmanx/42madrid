# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/21 17:37:34 by prodrigo          #+#    #+#              #
#    Updated: 2020/12/23 02:17:56 by prodrigo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = ft_printf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

OBJDIR = objs

LIBPATH = Libft/Libft

LIB = $(LIBPATH)/libft.a

DIR = srcs

SRCS =		fminus_handle.c			fempty_handle.c				\
			identifyers.c			ll_itoa.c					\
			fpoint_handle.c			fzero_handle.c				\
			handle_char.c			handle_float.c				\
			handle_empty.c			handle.c					\
			handle_pointer.c		handle_string.c				\
			hex_itoa.c				l_itoa.c					\
			handle_align.c			handle_unsigned.c

MAINSRC = ft_printf.c

SRC = $(addprefix $(DIR)/,$(SRCS))

SRCS_LIB =	ft_putstr_fd.c		ft_putchar_fd.c		ft_strdup.c		\
			ft_strlen.c			ft_itoa.c			ft_atoi.c		\
			ft_isdigit.c		ft_strjoin.c		ft_strncmp.c

CSRCS = $(addprefix $(OBJDIR)/,$(MAINSRC:.c=.o))

OBJ = $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))

OBJ_LIB = $(addprefix $(OBJDIR)/,$(SRCS_LIB:.c=.o))

HEADERS = -I ./ -I $(LIBPATH)

all: $(NAME)

$(LIB):
	-@make -C $(LIBPATH)
	-@mkdir -p $(OBJDIR) $(OBJPR)
	-@cd objs && ar -x ../$(LIBPATH)/libft.a

$(NAME): $(LIB) $(OBJ) $(CSRCS)
	-@ar rcs $(NAME) $(OBJ) $(CSRCS) $(OBJ_LIB)

bonus: $(LIB) $(OBJ) $(CSRCS)
	-@ar rcs $(NAME) $(OBJ) $(CSRCS) $(OBJ_LIB)

$(OBJDIR)/%.o: $(DIR)/%.c Makefile
	-@$(CC) -o $@ -c $< $(HEADERS) $(CFLAGS)

$(OBJDIR)/%.o: %.c Makefile
	-@$(CC) -o $@ -c $< $(HEADERS) $(CFLAGS)

clean:
	-@rm -rf $(OBJDIR)
	-@make -s -C $(LIBPATH) clean

fclean: clean
	-@rm -f $(NAME) test
	-@make -s -C $(LIBPATH) fclean

re: fclean all

a:
	-@rm -f a.out

.PHONY: all, clean, fclean, re, test

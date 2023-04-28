### COMPILATION ###
CC      = gcc -O3
FLAGS  = -Wall -Wextra -Werror
MLX_FLAGS = -lft -lmlx libmlx.a -framework OpenGL -framework AppKit

### EXECUTABLE ###
NAME   = fdf

### INCLUDES ###
LIBFT  = src/libft
HEADER = inc
MLX = mlx
### SOURCE FILES ###
SOURCES = fdf.c \
		  src/init.c \
		  src/draw.c \
		  src/exit.c \
		  src/parser.c \
		  src/view.c \
		  src/line.c \

SOURCES_BONUS = fdf.c \
		  src/bonus/init_bonus.c \
		  src/bonus/draw_bonus.c \
		  src/bonus/exit_bonus.c \
		  src/bonus/parser_bonus.c \
		  src/bonus/view_bonus.c \
		  src/bonus/line_bonus.c \
		  src/bonus/mov_bonus.c

### OBJECTS ###

OBJS = $(SOURCES:.c=.o)
OBJS_BONUS = $(SOURCES_BONUS:.c=.o)
### RULES ###

all: lib tmp copylib $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -L $(LIBFT) -L $(MLX) -o $@ $^ $(MLX_FLAGS)
	@echo "FDF has been compiled successfully."

lib:
	@echo "Creating lib files."
	@make -C $(LIBFT)
	@make -C $(MLX)

tmp:
	@mkdir -p objs

copylib:
	@cp $(MLX)/libmlx.a ./
	@echo "Copied MLX lib to folder."

bonus: $(OBJS_BONUS)
	$(CC) $(FLAGS) -L $(LIBFT) -L $(MLX) -o $@ $^ $(MLX_FLAGS)
	@echo "FDF has been compiled successfully."

clean:
	@echo "Cleaning everything except compiled FDF."
	@make clean -C $(LIBFT)
	@make clean -C $(MLX)
	@rm -rf $(OBJS) $(OBJS_BONUS)

fclean:
	@echo "Cleaning everything."
	@rm -rf $(OBJS) $(OBJS_BONUS)
	@rm -f $(NAME)
	@make clean -C $(MLX)
	@rm -rf $(MLX)/libmlx.a
	@rm -rf $(MLX)/*.swiftsourceinfo
	@make fclean -C $(LIBFT)
	@rm -rf libmlx.a

re: fclean all

.PHONY: all, re, fclean, clean

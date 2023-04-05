### COMPILATION ###
CC      = gcc -O2
FLAGS  = -Wall -Wextra -Werror
MLX_FLAGS = -lft -lmlx -lm -framework OpenGL -framework AppKit

### EXECUTABLE ###
NAME   = fdf

### INCLUDES ###
LIBFT  = src/libft
OBJ_PATH  = objs
HEADER = inc
SRC_PATH  = src
MLX = mlx

### SOURCE FILES ###
SOURCES = fdf.c \
		  init.c \
		  draw.c \
		  exit.c \
		  parser.c

### OBJECTS ###

SRCS = $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))

### RULES ###

all: lib tmp copylib $(NAME)

lib:
	@echo "Creating lib files."
	@make -C $(LIBFT)
	@make -C $(MLX)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -L $(LIBFT) -L $(MLX) -o $@ $^ $(MLX_FLAGS)
	@echo "FDF has been compiled successfully."

tmp:
	@mkdir -p objs

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)/$(NAME).h
	@$(CC) $(FLAGS) -c -o $@ $<

copylib:
	@cp $(MLX)/libmlx.dylib ./
	@echo "Copied MLX lib to folder."

clean:
	@echo "Cleaning everything except compiled FDF."
	@make clean -C $(LIBFT)
	@make clean -C $(MLX)
	@rm -rf $(OBJ_PATH)

fclean:
	@echo "Cleaning everything."
	@rm -rf $(OBJ_PATH)
	@rm -f $(NAME)
	@make clean -C $(MLX)
	@rm -rf $(MLX)/libmlx.dylib
	@make fclean -C $(LIBFT)
	@rm -rf libmlx.dylib

re: fclean all

.PHONY: all, re, fclean, clean

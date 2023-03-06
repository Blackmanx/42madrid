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
		  init.c 

### OBJECTS ###

SRCS = $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))

### RULES ###

all: lib tmp $(NAME)

lib:
	@echo "$(GREEN)Creating lib files$(CYAN)"
	@make -C $(LIBFT)
	@make -C $(MLX)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -L $(LIBFT) -L $(MLX) -o $@ $^ $(MLX_FLAGS)
	@echo "amogus1"

tmp:
	@mkdir -p objs

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)/$(NAME).h
	@$(CC) $(FLAGS) -c -o $@ $<
	@echo "amogus2"

clean:
	@echo "Sus clean"
	@make clean -C $(LIBFT)
	@rm -rf $(OBJ_PATH)

fclean:
	@echo "Sus fclean"
	@rm -rf $(OBJ_PATH)
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean
	@$(MAKE) all -j

.PHONY: temporary, re, fclean, clean
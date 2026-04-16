# Compilateur et flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
# Repertoires
SRC_DIR = sources
OBJ_DIR = obj
# Minilibx
MLX_REPO = https://github.com/42Paris/minilibx-linux.git
MLX_PATH = minilibx-linux/
MLX_NAME = libmlx.a
MLX = $(MLX_PATH)$(MLX_NAME)
# Libft
LIBFT_PATH = libft/
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_PATH)$(LIBFT_NAME)
# Nom de l'executable
NAME = fractol
BONUS_NAME = checker
# Fichiers sources du projet principal
SRCS = $(SRC_DIR)/event_inits.c \
       $(SRC_DIR)/event.c \
       $(SRC_DIR)/init_color.c \
       $(SRC_DIR)/init_color_2.c \
       $(SRC_DIR)/init.c \
       $(SRC_DIR)/main.c \
       $(SRC_DIR)/math_utils.c \
       $(SRC_DIR)/render.c \
       $(SRC_DIR)/render_2.c \
       $(SRC_DIR)/print.c \
       $(SRC_DIR)/print_2.c \
       $(SRC_DIR)/event_2.c \
       $(SRC_DIR)/printf/ft_printf.c \
       $(SRC_DIR)/free_utils.c \
       $(SRC_DIR)/printf/ft_utils.c \
       $(SRC_DIR)/printf/ft_utils_2.c
# Conversion des chemins sources en chemins objets
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
# Regle par defaut
all: $(NAME)
# Clone et compilation de la minilibx
$(MLX_PATH):
	@git clone $(MLX_REPO) $(MLX_PATH)
$(MLX): $(MLX_PATH)
	@make -C $(MLX_PATH)
# Compilation de la libft
$(LIBFT):
	@make -C $(LIBFT_PATH)
# Compilation de l'executable principal
$(NAME): $(OBJS) $(MLX) $(LIBFT)
	$(CC) $(OBJS) $(MLX) $(LIBFT) -lXext -lX11 -lm -o $(NAME)
# Regle pour compiler les fichiers .c de sources/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(MLX_PATH)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
# Nettoyage des fichiers objets
clean:
	@rm -rf $(OBJ_DIR)
	@if [ -d $(MLX_PATH) ]; then make -C $(MLX_PATH) clean; fi
	@make -C $(LIBFT_PATH) clean
# Nettoyage complet
fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)
	@rm -rf $(MLX_PATH)
	@make -C $(LIBFT_PATH) fclean
# Recompilation complete
re: fclean all
# Marque ces cibles comme non-fichiers
.PHONY: all clean fclean re


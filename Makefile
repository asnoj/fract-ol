# Compilateur et flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Repertoires
SRC_DIR = sources
BONUS_DIR = bonus
OBJ_DIR = obj

# Nom de l'executable
NAME = push_swap
BONUS_NAME = checker

# Fichiers sources du projet principal
SRCS = $(SRC_DIR)/ft_libft/ft_isdigit.c \
		$(SRC_DIR)/ft_libft/ft_putendl_fd.c \
		$(SRC_DIR)/ft_libft/ft_split.c \
		$(SRC_DIR)/ft_libft/ft_strdup.c \
		$(SRC_DIR)/ft_libft/ft_strlen.c \
		$(SRC_DIR)/ft_libft/ft_strncmp.c \
		$(SRC_DIR)/ft_libft/ft_atoi.c \
		$(SRC_DIR)/operations/operations_push.c \
		$(SRC_DIR)/operations/operations_rotate.c \
		$(SRC_DIR)/operations/operations_rrotate.c \
		$(SRC_DIR)/operations/operations_swap.c \
		$(SRC_DIR)/costs_0.c \
		$(SRC_DIR)/costs_1.c \
		$(SRC_DIR)/ft_free.c \
		$(SRC_DIR)/ft_utils.c \
		$(SRC_DIR)/main.c \
		$(SRC_DIR)/move.c \
		$(SRC_DIR)/parsing_valid.c \
		$(SRC_DIR)/push_swap.c \
		$(SRC_DIR)/sort_small.c \
		$(SRC_DIR)/stack_creat.c \
		$(SRC_DIR)/stack_utils.c \
		$(SRC_DIR)/stack_utils_2.c \
		$(BONUS_DIR)/printf/ft_utils.c \
		$(BONUS_DIR)/printf/ft_printf.c \
		$(BONUS_DIR)/printf/ft_utils_2.c \

# Fichiers sources du bonus
BONUS_SRCS = $(BONUS_DIR)/get_next_line/get_next_line.c \
			$(BONUS_DIR)/get_next_line/get_next_line_utils.c \
			$(BONUS_DIR)/checker_bonus.c \
			$(BONUS_DIR)/checker_free_bonus.c \
			$(BONUS_DIR)/checker_op_bonus.c \
			$(BONUS_DIR)/checker_opp_bonus.c \
			$(SRC_DIR)/ft_libft/ft_atoi.c \
			$(SRC_DIR)/stack_creat.c \
			$(SRC_DIR)/stack_utils.c \
			$(SRC_DIR)/ft_libft/ft_strdup.c \
			$(SRC_DIR)/ft_libft/ft_strlen.c \
			$(SRC_DIR)/ft_libft/ft_strncmp.c \
			$(SRC_DIR)/ft_libft/ft_putendl_fd.c \
			$(SRC_DIR)/ft_free.c \
			$(BONUS_DIR)/checker_parsing_valid_bonus.c \
			$(SRC_DIR)/ft_libft/ft_split.c \
			$(SRC_DIR)/ft_libft/ft_isdigit.c \
			$(SRC_DIR)/ft_utils.c \
			$(BONUS_DIR)/checker_utils_bonus.c \
			$(BONUS_DIR)/printf/ft_utils.c \
			$(BONUS_DIR)/printf/ft_printf.c \
			$(BONUS_DIR)/printf/ft_utils_2.c \

# Conversion des chemins sources en chemins objets
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
BONUS_OBJS = $(BONUS_SRCS:$(BONUS_DIR)/%.c=$(OBJ_DIR)/bonus_%.o)

# Regle par defaut
all: $(NAME)

# Compilation de l'executable principal
$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

# Compilation du bonus
bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(BONUS_OBJS) -g -o $(BONUS_NAME)

# Regle pour compiler les fichiers .c de sources/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Regle pour compiler les fichiers .c de bonus/
$(OBJ_DIR)/bonus_%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	@rm -rf $(OBJ_DIR)

# Nettoyage complet
fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)

# Recompilation complete
re: fclean all

# Marque ces cibles comme non-fichiers
.PHONY: all bonus clean fclean re
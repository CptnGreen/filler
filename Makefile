.PHONY: all re clean fclean libft 

MAIN_RAW = main.c
MAIN = $(addprefix $(SRC_DIR)/,$(MAIN_RAW))

CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = fcatina.filler

SRC_DIR = src
OBJ_DIR = obj

SRC_RAW = \
	init_players.c \
	get_piece.c \
	get_map.c \
	wipe_piece.c \
	wipe_map.c \
	get_heat_map.c \
	get_piece_coordinates.c

SRC = $(addprefix $(SRC_DIR)/,$(SRC_RAW))
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC_RAW:.c=.o))


all: $(NAME)

$(NAME): libft $(OBJ_DIR) $(OBJ)
	@ $(CC) -o $(NAME) $(OBJ) $(MAIN) -I "includes/" -I "libft/includes/" -L "libft/" -lft
libft:
	@ make -C libft/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@ $(CC) $(CFLAGS) -I "includes/" -I "libft/includes/" -c $< -o $@
$(OBJ_DIR):
	@ mkdir -p $(OBJ_DIR)


clean:
	@ rm -rf $(OBJ_DIR)
	@ make -C libft/ clean
fclean: clean
	@ rm -rf $(NAME)
	@ make -C libft/ fclean
re: fclean all

#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slisandr <slisandr@student.21-sch...>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/28 00:07:33 by slisandr          #+#    #+#              #
#    Updated: 2020/03/12 06:35:11 by slisandr         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY: all re clean fclean test memcheck libft debug

MAIN_RAW = main.c
MAIN = $(addprefix $(SRC_DIR)/,$(MAIN_RAW))

TEST = test

CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = slisandr.filler

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


test: $(NAME)
	cp $(NAME) resources/players/
	./resources/filler_vm -f resources/maps/map00 -p2 resources/players/$(NAME) -p1 resources/players/slisandr_heatmap.filler

memcheck: $(NAME)
	cp $(NAME) resources/players/
	./resources/filler_vm -f resources/maps/map02 -p2 resources/players/grati.filler -p1 resources/players/$(NAME) | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./$(NAME)
	vim valgrind-out.txt

debug: all
	lldb $(NAME)

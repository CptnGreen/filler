#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slisandr <slisandr@student.21-sch...>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/28 00:07:33 by slisandr          #+#    #+#              #
#    Updated: 2020/02/08 00:02:38 by slisandr         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all re clean fclean test memcheck libft debug

MAIN_RAW = main.c
MAIN = $(addprefix $(SRC_DIR)/,$(MAIN_RAW))

TEST = test

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

NAME = slisandr.filler

SRC_DIR = src
OBJ_DIR = obj

SRC_RAW = \
	get_piece.c \
	get_map.c \
	wipe_piece.c \
	wipe_map.c \
	wipe_opt.c \
	get_opts_lst.c \
	put_piece_in_mstr.c \
	get_fresh_opt.c \
	print_opts.c

SRC = $(addprefix $(SRC_DIR)/,$(SRC_RAW))
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC_RAW:.c=.o))


all: $(NAME)

$(NAME): libft $(OBJ_DIR) $(OBJ)
	@ echo "$(NAME): $(GREEN)object files were created$(RESET)"
	@ $(CC) -o $(NAME) $(OBJ) $(MAIN) -I "includes/" -I "libft/includes/" -L "libft/" -lft
	@ echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"
libft:
	@ make -C libft/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@ $(CC) $(CFLAGS) -I "includes/" -I "libft/includes/" -c $< -o $@
$(OBJ_DIR):
	@ mkdir -p $(OBJ_DIR)
	@ echo "$(NAME): $(GREEN)$(OBJ_DIR) folder was created$(RESET)"


clean:
	@ rm -rf $(OBJ_DIR)
	@ echo "$(NAME): $(RED)object files were deleted$(RESET)"
	@ echo "$(NAME): $(RED)$(OBJ_DIR) folder was deleted$(RESET)"
	@ make -C libft/ clean
fclean: clean
	@ rm -rf $(NAME)
	@ echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"
	@ make -C libft/ fclean
re: fclean all


test: re
	clear
	./$(NAME) $(TEST)

memcheck: re
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./$(NAME) $(TEST)
	vim valgrind-out.txt

debug: all
	lldb $(NAME)

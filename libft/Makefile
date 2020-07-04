# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slisandr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/12 21:31:09 by slisandr          #+#    #+#              #
#    Updated: 2020/03/10 23:04:10 by slisandr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re norm

CFLAGS = -Wall -Werror -Wextra

NAME = libft.a

TEST_FILE = ./test

SRC_DIR = src
OBJ_DIR = obj

SRC_RAW = \
			ft_putchar.c \
			ft_putstr.c \
			ft_putendl.c \
			ft_putnbr.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_atoi.c \
			ft_itoa.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_isupper.c \
			ft_islower.c \
			ft_bzero.c \
			ft_memset.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_strdup.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_memcmp.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_memchr.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_memalloc.c \
			ft_strnew.c \
			ft_memdel.c \
			ft_strdel.c \
			ft_strclr.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strsub.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strsplit.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \
			get_matrix_of_char.c \
			get_mtab_of_dots.c \
			get_mstr_h.c \
			get_mstr_w.c \
			join_matrices_str.c \
			print_mstr.c \
			print_mtab.c \
			wipe_mstr.c \
			wipe_mtab.c \
			ft_mstr_to_str.c \
			ft_strdup_int.c \
			ft_tabnew.c \
			ft_tabint.c \
			ft_tabdup.c \
			mtab_dup.c \
			mstr_dup.c \
			get_next_line.c

SRC = $(addprefix $(SRC_DIR)/,$(SRC_RAW))
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC_RAW:.c=.o))


EXEC = program


all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@ ar rc $(NAME) $(OBJ)
	@ ranlib $(NAME)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@ gcc $(CFLAGS) -I "includes/" -c $< -o $@
$(OBJ_DIR):
	@ mkdir -p $(OBJ_DIR)


clean:
	@ rm -rf $(OBJ_DIR)
fclean: clean
	@ rm -f $(NAME)
re: fclean all



exec: $(NAME)
	@ gcc -I "includes/" main.c -L . -lft -o $(EXEC)
norm:
	@ norminette $(SRC_DIR) includes

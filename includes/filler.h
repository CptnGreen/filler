#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include <stdio.h> // remove later!

typedef struct	s_map{
	size_t	h;
	size_t	w;
	char	c_us;
	char	c_enemy;
	char	**mstr;
	char	**mstr_tmp;
}				t_map;

typedef struct	s_piece{
	size_t	h;
	size_t	w;
	char	**mstr;
}				t_piece;

typedef struct		s_opt{
	struct s_opt	*u;
	struct s_opt	*d;
	struct s_opt	*z;
	char			*str;
	int				n;
	int				sq_side;
	int				n_intersecs;
	int				sum;
}					t_opt;

t_map	*get_map(int const fd);
t_piece	*get_piece(int const fd);
void	wipe_map(t_map **map);
void	wipe_piece(t_piece **piece);

#endif

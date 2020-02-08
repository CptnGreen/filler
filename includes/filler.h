/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:47:33 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/08 05:53:48 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include <stdio.h> // remove later!

typedef struct		s_piece{
	char			**mstr;
	size_t			h;
	size_t			w;
	size_t			x;
	size_t			y;
	size_t			best_x;
	size_t			best_y;
	size_t			sum;
	size_t			best_sum;
	size_t			n_intersecs;
}					t_piece;

typedef struct		s_opt{
	struct s_opt	*u;
	struct s_opt	*d;
	struct s_opt	*z;
	char			*str;
	int				n;
	size_t			h;
	size_t			w;
	int				n_intersecs;
	int				sum;
}					t_opt;

typedef struct		s_map{
	size_t			h;
	size_t			w;
	char			c_us;
	char			c_enemy;
	char			num;
	char			**mstr;
	char			**mstr_tmp;
	t_opt			*opts;
}					t_map;

t_map				*get_map(int const fd);
t_piece				*get_piece(int const fd);
void				wipe_map(t_map **map);
void				wipe_piece(t_piece **piece);
int					get_opts_lst(t_map *m, t_piece *p);
int					put_piece_in_mstr(t_map *m, t_piece *p, int x, int y);
t_opt				*get_fresh_opt(size_t h, size_t w, int n_opt);
int					print_opts(t_map *map);
void				wipe_opt(t_opt **opt);
void				get_heat_map(t_map *m, int *found_dot, int x, int y);
void				get_piece_coordinates(t_map *m, t_piece *p);

#endif

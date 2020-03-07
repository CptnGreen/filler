/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:47:33 by slisandr          #+#    #+#             */
/*   Updated: 2020/03/07 17:05:34 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define NUM_BASE 200
# define INT_MAX 2147483647

# define FD 0

# include "libft.h"

typedef struct		s_players{
	char			c_us;
	char			c_enemy;
}					t_players;

typedef struct		s_piece{
	char			**mstr;
	int				h;
	int				w;
	int				row;
	int				col;
	int				best_row;
	int				best_col;
	int				sum;
	int				best_sum;
	int				n_intersecs;
}					t_piece;

typedef struct		s_map{
	int				h;
	int				w;
	char			c_us;
	char			c_enemy;
	int				num;
	int				**mtab;
	int				**mtab_tmp;
}					t_map;

int					init_players(int const fd, t_players *pl);
int					get_map(int const fd, t_players *pl, t_map *map);
int					get_piece(int const fd, t_piece *p);
void				wipe_map(t_map *map);
void				wipe_piece(t_piece *piece);
void				wipe_players(t_players **pl);
int					put_piece_in_mstr(t_map *m, t_piece *p, int x, int y);
void				get_heat_map(t_map *m, int *found_dot);
void				get_piece_coordinates(t_map *m, t_piece *p);

#endif

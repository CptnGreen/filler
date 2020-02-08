/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:47:33 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/08 22:10:31 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define NUM_BASE 200

# include "libft.h"
# include <stdio.h> // remove later!

typedef struct		s_piece{
	char			**mstr;
	int				h;
	int				w;
	int				x;
	int				y;
	int				best_x;
	int				best_y;
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

t_map				*get_map(int const fd);
t_piece				*get_piece(int const fd);
void				wipe_map(t_map **map);
void				wipe_piece(t_piece **piece);
int					put_piece_in_mstr(t_map *m, t_piece *p, int x, int y);
void				get_heat_map(t_map *m, int *found_dot, int x, int y);
void				get_piece_coordinates(t_map *m, t_piece *p);

#endif

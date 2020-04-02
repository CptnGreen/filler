/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece_coordinates.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 05:12:24 by slisandr          #+#    #+#             */
/*   Updated: 2020/03/12 05:50:25 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_connection_with_enemy(t_map *m, t_piece *p, int i, int j)
{
	if (ft_toupper(m->mtab[p->row + i][p->col + j]) == m->c_enemy)
		return (1);
	return (0);
}

int		check_connection_with_base(t_map *m, t_piece *p, int *i, int *j)
{
	if (ft_toupper(m->mtab[p->row + (*i)][p->col + (*j)]) == m->c_us)
	{
		p->n_intersecs += 1;
		(*j) += 1;
		return (1);
	}
	return (0);
}

int		try_piece(t_map *m, t_piece *p)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < p->h)
	{
		if (p->n_intersecs > 1)
			return (0);
		if (j == p->w)
		{
			j = 0;
			i += 1;
			continue ;
		}
		if (p->mstr[i][j] != '.')
		{
			if (check_connection_with_enemy(m, p, i, j))
				return (0);
			if (check_connection_with_base(m, p, &i, &j))
				continue ;
			p->sum += (m->mtab_tmp[p->row + i][p->col + j] - NUM_BASE);
		}
		j += 1;
	}
	return ((p->n_intersecs == 1) ? (1) : (0));
}

void	compare_with_best(t_map *m, t_piece *p)
{
	if (try_piece(m, p) && p->sum <= p->best_sum)
	{
		p->best_sum = p->sum;
		p->best_row = p->row;
		p->best_col = p->col;
	}
	p->n_intersecs = 0;
	p->sum = 0;
}

/*
** p->row and p->col - coordinates of piece's upper left corner
** when it is put into the matrix
*/

void	get_piece_coordinates(t_map *m, t_piece *p)
{
	while (p->row + p->h <= m->h)
	{
		if (p->col + p->w > m->w)
		{
			p->col = 0;
			p->row += 1;
			continue ;
		}
		compare_with_best(m, p);
		p->col += 1;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece_coordinates.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 18:31:57 by fcatina           #+#    #+#             */
/*   Updated: 2020/02/03 05:04:41 by fcatina          ###   ########.fr       */
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
		if (j == p->w)
		{
			j = 0;
			i += 1;
			continue ;
		}
		if (p->mstr[i][j] != '.')
		{
			if (check_connection_with_enemy(m, p, i, j) || p->n_intersecs > 1)
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

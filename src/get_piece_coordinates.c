/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece_coordinates.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 05:12:24 by slisandr          #+#    #+#             */
/*   Updated: 2020/03/04 22:29:00 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_try(t_map *m, t_piece *p, int i, int j)
{
	if (p->row + i > m->h || \
		p->col + j > m->w || \
		ft_toupper(m->mtab[p->row + i][p->col + j]) == m->c_enemy ||	\
		p->n_intersecs > 1)
	{
		p->n_intersecs = 0;
		p->sum = 0;
		return (0);
	}
	return (1);
}

int		check_connection(t_map *m, t_piece *p, int *i, int *j)
{
	if (ft_toupper(m->mtab[p->row + (*i)][p->col + (*j)]) == m->c_us)
	{
		p->n_intersecs += 1;
		(*j) += 1;
		return (1);
	}
	return (0);
}

void	handle_piece(t_map *m, t_piece *p)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < p->h)
	{
		if (p->mstr[i][j] != '.')
		{
			if (j == p->w)
			{
				j = 0;
				i += 1;
				continue ;
			}
			if (!check_try(m, p, i, j))
				return ;
			if (check_connection(m, p, &i, &j))
				continue ;
			p->sum += (m->mtab_tmp[p->row + i][p->col + j] - NUM_BASE);
		}
		j += 1;
	}
}

void	try_coordinates(t_map *m, t_piece *p)
{
	handle_piece(m, p);
	if (p->n_intersecs == 1 && p->sum < p->best_sum)
	{
		p->best_sum = p->sum;
		p->best_row = p->row;
		p->best_col = p->col;
	}
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
		try_coordinates(m, p);
		p->col += 1;
	}
}

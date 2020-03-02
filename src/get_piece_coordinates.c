/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece_coordinates.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 05:12:24 by slisandr          #+#    #+#             */
/*   Updated: 2020/03/02 09:50:23 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_try(t_map *m, t_piece *p, int i, int j)
{
	if (m->mtab[p->x + i][p->y + j] == m->c_enemy || p->n_intersecs > 1)
	{
		p->n_intersecs = 0;
		p->sum = 0;
		return (0);
	}
	return (1);
}

int		check_connection(t_map *m, t_piece *p, int *i, int *j)
{
	if (m->mtab[p->x + (*i)][p->y + (*j)] == m->c_us)
	{
		p->n_intersecs += 1;
		(*j) += 1;
		return (0);
	}
	return (1);
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
			if (!check_connection(m, p, &i, &j))
				continue ;
			p->sum += (m->mtab_tmp[p->x + i][p->y + j] - NUM_BASE);
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
		p->best_x = p->x;
		p->best_y = p->y;
	}
}

void	get_piece_coordinates(t_map *m, t_piece *p)
{
	while (p->x + p->h <= m->h)
	{
		if (p->y + p->w > m->w)
		{
			p->y = 0;
			p->x += 1;
			continue ;
		}
		try_coordinates(m, p);
		p->y += 1;
	}
}

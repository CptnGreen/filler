/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece_coordinates.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 05:12:24 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/08 22:51:36 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	try_coordinates(t_map *m, t_piece *p)
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
		if (p->mstr[i][j] == m->c_us || p->mstr[i][j] == ft_tolower(m->c_us))
		{
			p->n_intersecs += 1;
			j += 1;
			continue ;
		}
		if (p->mstr[i][j] == m->c_enemy || p->n_intersecs > 1)
			return ;
		p->sum += m->mtab[p->x + i][p->y + j];
		j += 1;
	}
	if (p->n_intersecs == 1 && p->sum > p->best_sum)
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
		if (p->y + p->h > m->w)
		{
			p->y = 0;
			p->x += 1;
			continue ;
		}
		try_coordinates(m, p);
		p->y += 1;
	}
}

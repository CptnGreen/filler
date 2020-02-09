/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece_in_mstr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 21:45:31 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/09 02:28:46 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		put_piece_in_mstr(t_map *m, t_piece *p, int x, int y)
{
	int		i;
	int		j;

	if (y + p->w <= m->w && x + p->h <= m->h)
	{
		/* if (!(m->mtab_tmp = get_mtab_of_dots(m->h, m->w))) */
		/* 	return (0); */
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
				m->mtab[x + i][y + j] = ft_tolower(m->c_us);
			j += 1;
		}
		return (1);
	}
	return (0);
}

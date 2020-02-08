/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heat_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 02:05:59 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/08 05:53:48 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	look_around(t_map *m, int x, int y)
{
	if (x + 1 < (int)(m->h) && m->mstr[x + 1][y] == '.')
		m->mstr[x + 1][y] = m->num;
	if (x - 1 >= 0 && m->mstr[x - 1][y] == '.')
		m->mstr[x - 1][y] = m->num;
	if (y + 1 < (int)(m->w) && m->mstr[x][y + 1] == '.')
		m->mstr[x][y + 1] = m->num;
	if (y - 1 >= 0 && m->mstr[x][y - 1] == '.')
		m->mstr[x][y - 1] = m->num;
}

void	get_heat_map(t_map *m, int *found_dot, int x, int y)
{
	*found_dot = ((m->mstr[x][y] == '.') ? (1) : (*found_dot));
	if (m->mstr[x][y] == m->num - 1 || \
		m->mstr[x][y] == m->c_enemy || \
		m->mstr[x][y] == ft_tolower(m->c_enemy))
		look_around(m, x, y);
	if (x == (int)(m->h) - 1 && y == (int)(m->w) - 1)
	{
		if ((*found_dot == 1) ? ((*found_dot)--) : (*found_dot))
		{
			m->num += 1;
			get_heat_map(m, found_dot, 0, 0);
		}
		return ;
	}
	else if (y + 1 == (int)(m->w))
		get_heat_map(m, found_dot, x + 1, 0);
	else
		get_heat_map(m, found_dot, x, y + 1);
}

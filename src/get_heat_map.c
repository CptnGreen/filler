/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heat_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 02:05:59 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/08 04:30:15 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_heat_map(t_map *m, int *found_dot, int x, int y)
{
	*found_dot = ((m->mstr[x][y] == '.') ? (1) : (*found_dot));
	if (m->mstr[x][y] == m->c_num - 1 || m->mstr[x][y] == m->c_enemy)
	{
		if (x + 1 < (int)(m->h) && m->mstr[x + 1][y] == '.')
			m->mstr[x + 1][y] = m->c_num;
		if (x - 1 >= 0 && m->mstr[x - 1][y] == '.')
			m->mstr[x - 1][y] = m->c_num;
		if (y + 1 < (int)(m->w) && m->mstr[x][y + 1] == '.')
			m->mstr[x][y + 1] = m->c_num;
		if (y - 1 >= 0 && m->mstr[x][y - 1] == '.')
			m->mstr[x][y - 1] = m->c_num;
	}
	if (x == (int)(m->h) - 1 && y == (int)(m->w) - 1)
	{
		if ((*found_dot == 1) ? ((*found_dot)--) : (*found_dot))
		{
			m->c_num += 1;
			get_heat_map(m, found_dot, 0, 0);
		}
		return ;
	}
	else if (y + 1 == (int)(m->w))
		get_heat_map(m, found_dot, x + 1, 0);
	else
		get_heat_map(m, found_dot, x, y + 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heat_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 02:05:59 by slisandr          #+#    #+#             */
/*   Updated: 2020/03/04 21:12:15 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	look_around(t_map *m, int row, int col)
{
	if (row + 1 < m->h && \
		(m->mtab_tmp[row + 1][col] == '.' || m->mtab_tmp[row + 1][col] == m->c_us))
		m->mtab_tmp[row + 1][col] = m->num;
	if (row - 1 >= 0 && \
		(m->mtab_tmp[row - 1][col] == '.' || m->mtab_tmp[row - 1][col] == m->c_us))
		m->mtab_tmp[row - 1][col] = m->num;
	if (col + 1 < m->w && \
		(m->mtab_tmp[row][col + 1] == '.' || m->mtab_tmp[row][col + 1] == m->c_us))
		m->mtab_tmp[row][col + 1] = m->num;
	if (col - 1 >= 0 && \
		(m->mtab_tmp[row][col - 1] == '.' || m->mtab_tmp[row][col - 1] == m->c_us))
		m->mtab_tmp[row][col - 1] = m->num;
}

void	get_heat_map(t_map *m, int *found_dot, int row, int col)
{
	*found_dot = ((m->mtab_tmp[row][col] == '.') ? (1) : (*found_dot));
	if (m->mtab_tmp[row][col] == m->num - 1 || \
		m->mtab_tmp[row][col] == m->c_enemy || \
		m->mtab_tmp[row][col] == ft_tolower(m->c_enemy))
		look_around(m, row, col);
	if (row == (int)(m->h) - 1 && col == (int)(m->w) - 1)
	{
		if (*found_dot == 1)
		{
			*found_dot = 0;
			m->num += 1;
			get_heat_map(m, found_dot, 0, 0);
		}
		return ;
	}
	else if (col + 1 == (int)(m->w))
		get_heat_map(m, found_dot, row + 1, 0);
	else
		get_heat_map(m, found_dot, row, col + 1);
}

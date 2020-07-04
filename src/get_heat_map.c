/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heat_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 18:31:57 by fcatina           #+#    #+#             */
/*   Updated: 2020/02/03 05:04:41 by fcatina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#define MULT 1

void	look_around(t_map *m, int row, int col)
{
	if (row + 1 < m->h && \
		(m->mtab_tmp[row + 1][col] == '.' || \
		ft_toupper(m->mtab_tmp[row + 1][col]) == m->c_us))
	{
		m->mtab_tmp[row + 1][col] = m->num * MULT;
	}
	if (row - 1 >= 0 && \
		(m->mtab_tmp[row - 1][col] == '.' || \
		ft_toupper(m->mtab_tmp[row - 1][col]) == m->c_us))
	{
		m->mtab_tmp[row - 1][col] = m->num * MULT;
	}
	if (col + 1 < m->w && \
		(m->mtab_tmp[row][col + 1] == '.' || \
		ft_toupper(m->mtab_tmp[row][col + 1]) == m->c_us))
	{
		m->mtab_tmp[row][col + 1] = m->num * MULT;
	}
	if (col - 1 >= 0 && \
		(m->mtab_tmp[row][col - 1] == '.' || \
		ft_toupper(m->mtab_tmp[row][col - 1]) == m->c_us))
	{
		m->mtab_tmp[row][col - 1] = m->num * MULT;
	}
}

void	check_if_found_dot(t_map *m, int *found_dot)
{
	if (*found_dot == 1)
	{
		*found_dot = 0;
		m->num += 1;
		get_heat_map(m, found_dot);
	}
}

void	get_heat_map(t_map *m, int *found_dot)
{
	int		row;
	int		col;

	row = 0;
	col = 0;
	while (1)
	{
		*found_dot = ((m->mtab_tmp[row][col] == '.') ? (1) : (*found_dot));
		if (m->mtab_tmp[row][col] == (m->num - 1) * MULT || \
			ft_toupper(m->mtab_tmp[row][col]) == m->c_enemy)
			look_around(m, row, col);
		if (row == (int)(m->h) - 1 && col == (int)(m->w) - 1)
			break ;
		if (col + 1 == (int)(m->w))
		{
			col = 0;
			row += 1;
		}
		else
			col += 1;
	}
	check_if_found_dot(m, found_dot);
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 22:29:56 by slisandr          #+#    #+#             */
/*   Updated: 2020/03/10 23:17:53 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		print_coordinates(t_piece *p)
{
	if (p->best_row == -1 || p->best_col == -1)
	{
		ft_putnbr(0);
		ft_putchar(' ');
		ft_putnbr(0);
		ft_putchar('\n');
		wipe_piece(p);
		return (0);
	}
	ft_putnbr(p->best_row);
	ft_putchar(' ');
	ft_putnbr(p->best_col);
	ft_putchar('\n');
	return (1);
}

int		get_map_and_piece(int fd, t_map *m, t_piece *p, t_players *pl)
{
	if (!(get_map(FD, pl, m)))
	{
		wipe_map(m);
		return (0);
	}
	if (!(get_piece(FD, p)))
	{
		wipe_map(m);
		wipe_piece(p);
		return (0);
	}
	return (1);
}

int		main(void)
{
	t_map		m;
	t_piece		p;
	t_players	pl;

	if (init_players(FD, &pl))
	{
		while (1)
		{
			if (!(get_map_and_piece(FD, &m, &p, &pl)))
				break ;
			get_piece_coordinates(&m, &p);
			wipe_map(&m);
			if (!(print_coordinates(&p)))
				return (0);
			wipe_piece(&p);
		}
	}
	return (1);
}

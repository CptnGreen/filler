/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 22:29:56 by slisandr          #+#    #+#             */
/*   Updated: 2020/03/06 02:03:11 by slisandr         ###   ########.fr       */
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
		wipe_piece(&p);
		return (0);
	}
	ft_putnbr(p->best_row);
	ft_putchar(' ');
	ft_putnbr(p->best_col);
	ft_putchar('\n');
	return (1);
}

int		main(void)
{
	t_map		*m;
	t_piece		*p;
	t_players	pl;

	m = NULL;
	p = NULL;
	if (init_players(FD, &pl))
	{
		while (1)
		{
			if (!(m = get_map(FD, &pl)))
				break ;
			if (!(p = get_piece(FD)))
				break ;
			get_piece_coordinates(m, p);
			if (!(p->best_row == -1 || p->best_col == -1))
				put_piece_in_mstr(m, p, p->best_row, p->best_col);
			wipe_map(&m);
			if (!(print_coordinates(p)))
				return (0);
			wipe_piece(&p);
		}
	}
	return (1);
}

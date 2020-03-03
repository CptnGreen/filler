/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 22:29:56 by slisandr          #+#    #+#             */
/*   Updated: 2020/03/02 13:24:32 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_map		*m;
	t_piece		*p;
	t_players	*pl;

	m = NULL;
	p = NULL;
	pl = NULL;
	if ((pl = init_players(FD)))
	{
		while (1)
		{
			if (!(m = get_map(FD, pl)))
				break ;
			if (!(p = get_piece(FD)))
				break ;
			get_piece_coordinates(m, p);
			if (!(p->best_row == -1 || p->best_col == -1))
				put_piece_in_mstr(m, p, p->best_row, p->best_col);
			ft_putnbr(p->best_row);
			ft_putchar(' ');
			ft_putnbr(p->best_col);
			ft_putchar('\n');
			if (p->best_row == -1 || p->best_col == -1)
				break ;
			wipe_map(&m);
			wipe_piece(&p);
		}
	}
	/* wipe_map(&m); */
	/* wipe_piece(&p); */
	/* wipe_players(&pl); */
	return (0);
}

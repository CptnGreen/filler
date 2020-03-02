/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 22:29:56 by slisandr          #+#    #+#             */
/*   Updated: 2020/03/02 09:52:14 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	int			fd;
	t_map		*m;
	t_piece		*p;
	t_players	*pl;
	char		*line;

	fd = 0;
	line = NULL;
	if (!(pl = init_players(fd, &line)))
		return (1);
	ft_strdel(&line);
	while (1)
	{
		if (!(m = get_map(fd, pl)))
			return (1);
		if (!(p = get_piece(fd)))
			return (1);
		get_piece_coordinates(m, p);
		put_piece_in_mstr(m, p, p->best_x, p->best_y);
		ft_putnbr(p->best_x);
		ft_putchar(' ');
		ft_putnbr(p->best_y);
		ft_putchar('\n');
	}
	return (0);
}

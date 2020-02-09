/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 22:29:56 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/09 03:33:52 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	int			fd;
	t_map		*m;
	t_piece		*p;

	setbuf(stdout, NULL); // remove later!
	fd = open(TEST_FILE, O_RDONLY);
	/* fd = FD; */
	if (!(m = get_map(fd)))
		return (1);
	if (!(p = get_piece(fd)))
		return (1);
	get_piece_coordinates(m, p);
	put_piece_in_mstr(m, p, p->best_x, p->best_y);
	print_mtab(m->mtab, m->h, m->w);
	close(fd);
	return (0);
}

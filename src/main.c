/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 22:29:56 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/08 05:50:11 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#define FD 0
#define FILE "test"

int		main(void)
{
	int			fd;
	t_map		*m;
	t_piece		*p;

	fd = open(FILE, O_RDONLY);
	if (!(m = get_map(fd)))
		return (1);
	if (!(p = get_piece(fd)))
		return (1);
	get_piece_coordinates(m, p);
	put_piece_in_mstr(m, p, p->best_x, p->best_y);
	print_mstr(m->mstr);
	close(fd);
	return (0);
}

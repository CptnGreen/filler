/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 22:29:56 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/09 05:19:01 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	int			fd;
	int			fd_output;
	t_map		*m;
	t_piece		*p;

	/* setbuf(stdout, NULL); // remove later! */
	/* fd_output = open(TEST_FILE, O_RDONLY); */
	/* ft_putendl_fd("HELP!\n", fd_output); */
	/* printf("main: I'm here!\n"); */
	while (1)
	{
		fd = 0;
		if (!(m = get_map(fd)))
			return (1);
		if (!(p = get_piece(fd)))
			return (1);
		get_piece_coordinates(m, p);
		put_piece_in_mstr(m, p, p->best_x, p->best_y);
		/* print_mtab(m->mtab, m->h, m->w); */
		ft_putnbr(p->best_x);
		ft_putchar(' ');
		ft_putnbr(p->best_y);
		ft_putchar('\n');
		exit();
	}
	return (0);
}

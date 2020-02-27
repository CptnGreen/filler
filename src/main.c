/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 22:29:56 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/27 14:26:30 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	int			fd;
	t_map		*m;
	t_piece		*p;
	int			fd_output;
	t_players	*pl;
	char		*line;

	fd_output = open(TEST_FILE, O_WRONLY|O_APPEND);
	/* setbuf(stdout, NULL); // remove later! */
	/* ft_putendl_fd("HELP!\n", fd_output); */
	/* printf("main: I'm here!\n"); */
	line = NULL;
	if (!(pl = init_players(fd, &line)))
		return (1);
	ft_strdel(&line);
	fd = 0;
	while (1)
	{
		if (!(m = get_map(fd, pl)))
			return (1);
		ft_putstr_fd("AFTER GET_MAP()\n", fd_output);
		if (!(p = get_piece(fd)))
			return (1);
		ft_putstr_fd("AFTER GET_PIECE()\n", fd_output);
		get_piece_coordinates(m, p);
		put_piece_in_mstr(m, p, p->best_x, p->best_y);
		/* print_mtab(m->mtab, m->h, m->w); */
		ft_putstr_fd("m->c_us = ", fd_output);
		ft_putchar_fd(m->c_us, fd_output);
		ft_putchar_fd('\n', fd_output);
		ft_putstr_fd("m->c_enemy = ", fd_output);
		ft_putchar_fd(m->c_enemy, fd_output);
		ft_putchar_fd('\n', fd_output);
		ft_putstr_fd("p->best_x = ", fd_output);
		ft_putnbr_fd(p->best_x, fd_output);
		ft_putchar_fd('\n', fd_output);
		ft_putstr_fd("p->best_y = ", fd_output);
		ft_putnbr_fd(p->best_y, fd_output);
		ft_putchar_fd('\n', fd_output);
		ft_putnbr(p->best_x);
		ft_putchar(' ');
		ft_putnbr(p->best_y);
		ft_putchar('\n');
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:06:17 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/27 14:32:06 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		init_map(t_map *map, t_players *pl)
{
	map->h = 0;
	map->w = 0;
	map->c_us = pl->c_us;
	map->c_enemy = pl->c_enemy;
	map->mtab = NULL;
	map->mtab_tmp = NULL;
	map->num = NUM_BASE;
	return (1);
}

int		get_map_dimensions(int const fd, t_map *map, char **line)
{
	char	**split;
	int			fd_output;

	fd_output = open(TEST_FILE, O_WRONLY|O_APPEND);
	ft_putstr_fd("ENTERED GET_MAP_DIMENSIONS()\n", fd_output);
	while (get_next_line(fd, line))
	{
		split = ft_strsplit(*line, ' ');
		if (ft_strcmp(split[0], "Plateau") == 0)
		{
			map->h = ft_atoi(split[1]);
			map->w = ft_atoi(split[2]);
			break ;
		}
		wipe_mstr(split);
	}
	ft_putnbr_fd(map->h, fd_output);
	ft_putchar_fd('\n', fd_output);
	ft_putnbr_fd(map->w, fd_output);
	return ((map->h == 0 || map->w == 0) ? (0) : (1));
}

int		get_map_rows(int const fd, t_map *map, char **line)
{
	char	**split;
	int		n_row;
	int			fd_output;

	fd_output = open(TEST_FILE, O_WRONLY|O_APPEND);
	if (!(map->mtab = (int **)ft_memalloc(sizeof(int *) * (map->h))))
		return (0);
	get_next_line(fd, line);
	n_row = -1;
	/* exit(0); */
	while (++n_row < map->h && get_next_line(fd, line) > 0)
	{
		ft_putstr_fd(*line, fd_output);
		ft_putchar_fd('\n', fd_output);
		split = ft_strsplit(*line, ' ');
		map->mtab[n_row] = ft_strdup_int(split[1]);
		ft_putchar_fd('Z', fd_output);
		ft_putchar_fd('\n', fd_output);
		/* if (map->c_us == 0 && ft_tabint(map->mtab[n_row], map->w, 'o')) */
		/* { */
		/* 	ft_putchar_fd(map->c_us, fd_output); */
		/* 	ft_putchar_fd('\n', fd_output); */
		/* 	ft_putchar_fd(map->c_enemy, fd_output); */
		/* 	map->c_us = 'X'; */
		/* 	map->c_enemy = 'O'; */
		/* } */
		wipe_mstr(split);
	}
	/* map->c_us = ((map->c_us == 0) ? ('O') : (map->c_us)); */
	/* map->c_enemy = ((map->c_us == 'O') ? ('X') : ('O')); */
	map->mtab[n_row] = NULL;
	map->mtab_tmp = mtab_dup(map->mtab, map->h, map->w);
	ft_putstr_fd("Y\n", fd_output);
	/* ft_putchar_fd(map->c_us, fd_output); */
	/* ft_putchar_fd('\n', fd_output); */
	/* ft_putchar_fd(map->c_enemy, fd_output); */
	close(fd_output);
	return ((n_row == -1) ? (0) : (1));
}

t_map	*get_map(int const fd, t_players *pl)
{
	t_map	*map;
	char	*line;
	int		found_dot;

	line = NULL;
	if ((map = (t_map *)ft_memalloc(sizeof(t_map))) && \
		init_map(map, pl) && \
		get_map_dimensions(fd, map, &line) && \
		get_map_rows(fd, map, &line))
		{
			found_dot = 0;
			/* printf("before: map->c_enemy = %c\n", map->c_enemy); */
			/* print_mtab(map->mtab_tmp, map->h, map->w); */
			get_heat_map(map, &found_dot, 0, 0);
			/* printf("after:\n"); */
			/* print_mtab(map->mtab_tmp, map->h, map->w); */
			ft_strdel(&line);
			return (map);
		}
	ft_strdel(&line);
	wipe_map(&map);
	return (NULL);
}

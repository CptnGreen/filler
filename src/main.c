/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 22:29:56 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/08 03:31:25 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#define FD 0
#define FILE "test"

int		main(void)
{
	int		fd;
	t_map	*map;
	t_piece	*piece;
	int		found_dot;

	fd = open(FILE, O_RDONLY);
	if (!(map = get_map(fd)))
		return (1);
	map->c_enemy = 'O';
	map->c_num = '1';
	found_dot = 0;
	print_mstr(map->mstr);
	get_heat_map(map, &found_dot, 0, 0);
	printf("main: I'm here! c = %c\n", map->c_enemy);
	print_mstr(map->mstr);
	/* if (!(piece = get_piece(fd))) */
	/* 	return (1); */
	/* if (!(get_opts_lst(map, piece))) */
	/* 	return (1); */
	close(fd);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 22:29:56 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/07 22:52:05 by slisandr         ###   ########.fr       */
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

	fd = open(FILE, O_RDONLY);
	if (!(map = get_map(fd)))
		return (1);
	if (!(piece = get_piece(fd)))
		return (1);
	if (!(get_opts_lst(map, piece)))
		return (1);
	close(fd);
	return (0);
}

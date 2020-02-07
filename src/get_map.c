/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:06:17 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/07 16:43:59 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_map	*init_map(int const fd)
{
	t_map	*map;

	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		return (NULL);
	map->h = 0;
	map->w = 0;
	map->c_us = 0;
	map->c_enemy = 0;
	map->mstr = NULL;
	map->mstr_tmp = NULL;
	return (map);
}

int		get_map_dimensions(int const fd, t_map *map, char **line)
{
	char	**split;

	while (get_next_line(fd, line))
	{
		split = ft_strsplit(*line, ' ');
		if (ft_strcmp(split[0], "Plateau") == 0)
		{
			map->h = ft_atoi(split[1]);
			map->w = ft_atoi(split[2]);
			break ;
		}
	}
	wipe_mstr(split);
	return ((map->h == 0 || map->w == 0) ? (0) : (1));
}

int		get_map_rows(int const fd, t_map *map, char **line)
{
	char	**split;
	int		n_row;

	if (!(map->mstr = (char **)ft_memalloc(sizeof(char *) * (map->h + 1))))
		return (0);
	get_next_line(fd, line);
	n_row = 0;
	while (n_row < map->h && get_next_line(fd, line))
	{
		split = ft_strsplit(*line, ' ');
		map->mstr[n_row] = ft_strdup(split[1]);
		n_row += 1;
	}
	map->mstr[n_row] = NULL;
	wipe_mstr(split);
	return ((n_row == -1) ? (0) : (1));
}

t_map	*get_map(int const fd)
{
	t_map	*map;
	char	**line;

	if ((map = init_map(fd)) && \
		(line = (char **)ft_memalloc(sizeof(char *))) && \
		get_map_dimensions(fd, map, line) && \
		get_map_rows(fd, map, line))
	{
		ft_strdel(line);
		return (map);
	}
	ft_strdel(line);
	wipe_map(&map);
	return (NULL);
}

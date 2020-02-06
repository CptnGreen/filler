#include "filler.h"

int		get_map_dimensions(int const fd, t_map *map)
{
	char	**line;
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

int		get_map_rows(int const fd, t_map *map)
{
	char	**line;
	char	**split;
	int		n_row;

	get_next_line(fd, line);
	/* printf("get_map_rows: line = %s!\n", *line); */
	n_row = -1;
	while (get_next_line(fd, line))
	{
		printf("get_map_rows: n_row = %d\n", n_row);
		split = ft_strsplit(*line, ' ');
		map->mstr[++n_row] = ft_strdup(split[1]);
		if (ft_atoi(split[0]) >= map->h - 1)
			break ;
	}
	wipe_mstr(split);
	return ((n_row == -1) ? (0) : (1));
}

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
	printf("init_map: map->h = %ld\n", map->h);
	return (map);
}

t_map	*get_map(int const fd)
{
	t_map	*map;

	if ((map = init_map(fd)) && \
		get_map_dimensions(fd, map) && \
		get_map_rows(fd, map))
		return (map);
	wipe_map(&map);
	return (NULL);
}

#include "filler.h"

#define FD 0
#define FILE "test"

int		main(void)
{
	int		fd;
	t_map	*map;
	t_piece	*piece;
	t_opt	*opts;
	int		i;

	//fd = FD;
	fd = open(FILE, O_RDONLY);
	if (!(map = get_map(fd)))
		return (1);
	if (!(piece = get_piece(fd)))
		return (1);


	opts = get_fresh_opt(map->h, map->w, 0);
	if (!(get_opts_lst(map, piece, opts)))
		printf("Something wrong!\n");

	printf("main: So far so good!\n");

	i = 0;
	while (opts)
	{
		printf("opt %2d: %s\n", i, opts->str);
		opts = opts->d;
		i += 1;
	}

	close(fd);
	return (0);
}

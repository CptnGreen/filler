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
	print_mstr(map->mstr);


	printf("main: So far so good!\n");


	if (!(piece = get_piece(fd)))
		return (1);
	print_mstr(piece->mstr);


	opts = NULL;
	if (!(get_opts_lst(map, piece, opts)))
		printf("Something wrong!\n");

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

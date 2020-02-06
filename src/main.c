#include "filler.h"

#define FD 0
#define FILE "test"

int		main(void)
{
	int		fd;
	t_map	*map;
	t_piece	*piece;

	//fd = FD;
	fd = open(FILE, O_RDONLY);
	if (!(map = get_map(fd)))
		return (1);
	print_mstr(map->mstr);
	if (!(piece = get_piece(fd)))
		return (1);
	print_mstr(piece->mstr);
	close(fd);
	return (0);
}

#include "filler.h"

void	wipe_map(t_map **map)
{
	wipe_mstr((*map)->mstr);
	wipe_mstr((*map)->mstr_tmp);
	*map = NULL;
}

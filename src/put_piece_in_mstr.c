#include "filler.h"

int		put_piece_in_mstr(t_map *m, t_piece *p, int x, int y)
{
	int		i;
	int		j;
	
	if (y + p->w < m->w && x + p->h < m->h)
	{
		if (!(m->mstr_tmp = get_matrix_of_dots(m->h, m->w)))
			return (0);
		i = 0;
		j = 0;
		while (i < p->h)
		{
			if (j == p->w)
			{
				j = 0;
				i += 1;
				continue ;
			}
			m->mstr_tmp[x + i][y + j] = m->c_us;
			j += 1;
		}
		return (1);
	}
	return (0);
}

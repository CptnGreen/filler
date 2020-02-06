#include "filler.h"

t_opt	*get_fresh_opt(int sq_side, int n_opt)
{
	t_opt	*opt;

	if (!(opt = (t_opt *)malloc(sizeof(t_opt))))
		return (NULL);
	if (!(opt->str = ft_strnew(sq_side * sq_side)))
		return (NULL);
	opt->u = NULL;
	opt->d = NULL;
	opt->z = NULL;
	opt->n = n_opt;
	opt->sq_side = sq_side;
	opt->n_intersecs = 0;
	opt->sum = 0;
}

t_opt	*get_opt_from_mstr(t_map *m, int n_opt)
{
	t_opt	*opt;
	int		i;

	opt = get_fresh_opt(m->sq_side, n_opt);
	i = -1;
	while (m->mstr_tmp[++i])
		opt->str = ft_strncat(opt->str, m->mstr_tmp[i], m->sq_side);
	return (opt);
}

int		get_opts_lst(t_map *m, t_piece *p, t_opt *o)
{
	int		x;
	int		y;
	char	**m_str;

	x = 0;
	y = 0;
	while (x + p->h < m->h)
	{
		if (y + p->w == m->w)
		{
			y = 0;
			x += 1;
			continue ;
		}
		put_piece_in_mstr(m, p, x, y);
		o->d = (tmp = get_opt_from_mstr(m->mstr_tmp, m->));
		o = o->d;
		y += 1;
	}
	o->d = NULL;
	return (1);
}

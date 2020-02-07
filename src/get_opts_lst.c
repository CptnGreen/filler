/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opts_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:31:56 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/07 16:21:40 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_opt	*get_fresh_opt(size_t h, size_t w, int n_opt)
{
	t_opt	*opt;

	if (!(opt = (t_opt *)ft_memalloc(sizeof(t_opt))) || \
		!(opt->str = ft_strnew(h * w)))
		return (NULL);
	printf("h = %ld, w = %ld\n", h, w);
	opt->u = NULL;
	opt->d = NULL;
	opt->z = NULL;
	opt->n = n_opt;
	opt->h = h;
	opt->w = w;
	opt->n_intersecs = 0;
	opt->sum = 0;
	return (opt);
}

t_opt	*get_opt_from_mstr(t_map *m, int n_opt)
{
	t_opt	*opt;
	int		i;

	if (!(opt = get_fresh_opt(m->h, m->w, n_opt)))
		return (NULL);
	i = -1;
	while (m->mstr_tmp[++i])
	{
		opt->str = ft_strncat(opt->str, m->mstr_tmp[i], m->w);
		printf("%2d: %s\n", n_opt, opt->str);
	}
	return (opt);
}

int		get_opts_lst(t_map *m, t_piece *p, t_opt *o)
{
	int		x;
	int		y;
	int		n_opt;
	char	**m_str;

	if (!m || !p)
		return (0);
	x = 0;
	y = 0;
	n_opt = 0;
	while (x + p->h < m->h)
	{
		if (y + p->w == m->w)
		{
			y = 0;
			x += 1;
			continue ;
		}
		printf("get_opts: x = %d, y = %d\n", x, y);
		put_piece_in_mstr(m, p, x, y);





		print_mstr(m->mstr_tmp);
		printf("Well done!\n");




		o->d = get_opt_from_mstr(m, n_opt);
		n_opt += 1;
		o = o->d;
		printf("opt[%d] = %s\n", n_opt, o->str);
		y += 1;
	}
	o->d = NULL;
	return (1);
}

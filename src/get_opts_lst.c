/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opts_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:31:56 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/08 00:01:19 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_opt	*get_header_opt(t_map *m)
{
	t_opt	*opt;

	if (!(opt = get_fresh_opt(m->h, m->w, 0)) || \
		!(opt->str = ft_mstr_to_str(m->mstr)))
	{
		wipe_opt(&opt);
		return (NULL);
	}
	return (opt);
}

t_opt	*get_opt_from_mstr(t_map *m, int n_opt)
{
	t_opt	*opt;
	int		i;

	if (!(opt = get_fresh_opt(m->h, m->w, n_opt)))
		return (NULL);
	i = -1;
	while (++i < (int)(m->h) && m->mstr_tmp[i])
		opt->str = ft_strncat(opt->str, m->mstr_tmp[i], m->w);
	return ((i == -1) ? (NULL) : (opt));
}

int		get_opts_lst(t_map *m, t_piece *p)
{
	int		x;
	int		y;
	int		n_opt;
	t_opt	*o;

	if (!m || !p)
		return (0);
	x = 0;
	y = 0;
	n_opt = 0;
	o = m->opts;
	o->d = get_header_opt(m);
	o = o->d;
	print_opts(m);
	while (x + p->h <= m->h)
	{
		if (y + p->w > m->w)
		{
			y = 0;
			x += 1;
			continue ;
		}
		put_piece_in_mstr(m, p, x, y);
		o->d = get_opt_from_mstr(m, n_opt);
		n_opt += 1;
		o = o->d;
		y += 1;
	}
	o->d = NULL;
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opts_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:31:56 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/08 04:10:25 by slisandr         ###   ########.fr       */
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

	if (!(opt = get_fresh_opt(m->h, m->w, n_opt)) || \
		!(opt->str = ft_mstr_to_str(m->mstr_tmp)))
	{
		wipe_opt(&opt);
		return (NULL);
	}
	return (opt);
}

/* void	get_n_intersecs(t_map *map) */
/* { */
/* 	t_opt	*o; */
/* 	int		i; */

/* 	o = (map->opts)->d; */
/* 	i = 0; */
/* 	while (o) */
/* 	{ */
/* 		if (!(o->str[i])) */
/* 		{ */
/* 			i = 0; */
/* 			o = o->d; */
/* 			continue ; */
/* 		} */
/* 		if ((o->str[i] == m->c_us && m->opts->str[i] != '.') && \ */
/* 			(++(o->n_intersecs) > 1)) */
/* 			return ; */
/* 		i += 1; */
/* 	} */
/* } */

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
	if (!(o->d = get_header_opt(m)))
		return (0);
	/* print_opts(m); */
	o = o->d;
	while (x + p->h <= m->h)
	{
		if (y + p->w > m->w)
		{
			y = 0;
			x += 1;
			continue ;
		}
		put_piece_in_mstr(m, p, x, y);
		if (!(o->d = get_opt_from_mstr(m, n_opt)))
			return (0);
		o = o->d;
		n_opt += 1;
		y += 1;
	}
	o->d = NULL;
	return (1);
}

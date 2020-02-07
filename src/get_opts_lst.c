/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opts_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:31:56 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/07 21:45:08 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_opt	*get_opt_from_mstr(t_map *m, int n_opt)
{
	t_opt	*opt;
	int		i;

	if (!(opt = get_fresh_opt(m->h, m->w, n_opt)))
		return (NULL);
	i = -1;
	while (++i < (int)(m->h) && m->mstr_tmp[i])
	{
		opt->str = ft_strncat(opt->str, m->mstr_tmp[i], m->w);
		printf("%2d: %s\n", i, opt->str);
	}
	printf("gofm: I'm here!\n");
	return ((i == -1) ? (NULL) : (opt));
}

int		get_opts_lst(t_map *m, t_piece *p, t_opt *o)
{
	int		x;
	int		y;
	int		n_opt;

	if (!m || !p)
		return (0);
	x = 0;
	y = 0;
	n_opt = 0;
	while (x + p->h <= m->h)
	{
		if (y + p->w > m->w)
		{
			y = 0;
			x += 1;
			continue ;
		}
		put_piece_in_mstr(m, p, x, y);
		print_mstr(m->mstr_tmp);
		o->d = get_opt_from_mstr(m, n_opt);
		printf("Well done !\n");
		n_opt += 1;
		o = o->d;
		printf("opt[%d] = %s\n", n_opt, o->str);
		y += 1;
	}
	o->d = NULL;
	return (1);
}

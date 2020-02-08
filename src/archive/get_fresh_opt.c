/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fresh_opt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:46:14 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/07 18:46:16 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_opt	*get_fresh_opt(size_t h, size_t w, int n_opt)
{
	t_opt	*opt;

	if (!(opt = (t_opt *)ft_memalloc(sizeof(t_opt))) || \
		!(opt->str = ft_strnew(h * w)))
		return (NULL);
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

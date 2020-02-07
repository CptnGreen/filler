/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_opts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 22:40:55 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/07 22:44:49 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		print_opts(t_map *map)
{
	t_opt	*o;

	if (map && map->opts)
	{
		o = map->opts;
		while (o)
		{
			ft_putendl(o->str);
			o = o->d;
		}
		return (1);
	}
	return (0);
}

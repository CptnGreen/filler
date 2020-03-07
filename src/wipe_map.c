/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wipe_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 23:53:30 by slisandr          #+#    #+#             */
/*   Updated: 2020/03/07 15:08:31 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	wipe_map(t_map *map)
{
	int		w;
	int		h;

	w = (map)->w;
	h = (map)->h;
	wipe_mtab((map)->mtab, h, w);
	map->mtab = NULL;
	wipe_mtab((map)->mtab_tmp, h, w);
	map->mtab = NULL;
	map = NULL;
}

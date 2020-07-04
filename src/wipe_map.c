/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wipe_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 18:31:57 by fcatina           #+#    #+#             */
/*   Updated: 2020/02/03 05:04:41 by fcatina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	wipe_map(t_map *map)
{
	int		w;
	int		h;

	if (map)
	{
		w = (map)->w;
		h = (map)->h;
		wipe_mtab((map)->mtab, h, w);
		map->mtab = NULL;
		wipe_mtab((map)->mtab_tmp, h, w);
		map->mtab = NULL;
		map = NULL;
	}
}

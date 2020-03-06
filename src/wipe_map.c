/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wipe_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 23:53:30 by slisandr          #+#    #+#             */
/*   Updated: 2020/03/06 04:52:00 by slisandr         ###   ########.fr       */
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
	wipe_mtab((map)->mtab_tmp, h, w);
	map = NULL;
}

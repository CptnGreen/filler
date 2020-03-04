/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:17:13 by slisandr          #+#    #+#             */
/*   Updated: 2020/03/04 21:31:33 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_players	*init_players(int const fd)
{
	char		**split;
	t_players	*pl;
	char		*line;

	if (!(pl = (t_players *)ft_memalloc(sizeof(t_players))))
		return (NULL);
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		split = ft_strsplit(line, ':');
		ft_strdel(&line);
		if (ft_strstr(split[0], "$$$ exec p2") != 0)
		{
			if (ft_strstr(split[1], "slisandr") != 0)
			{
				pl->c_us = 'X';
				pl->c_enemy = 'O';
			}
			else
			{
				pl->c_us = 'O';
				pl->c_enemy = 'X';
			}
			wipe_mstr(split);
			return ((pl->c_us == 0 || pl->c_enemy == 0) ? (NULL) : (pl));
		}
		wipe_mstr(split);
	}
	wipe_players(&pl);
	return (NULL);
}

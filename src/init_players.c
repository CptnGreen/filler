/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:17:13 by slisandr          #+#    #+#             */
/*   Updated: 2020/03/06 01:13:32 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		assign_letters(char *line, t_players *pl)
{
	if ((ft_strstr(line, "$$$ exec p1") != NULL && \
		ft_strstr(line, "slisandr") == NULL) || \
		(ft_strstr(line, "$$$ exec p2") != NULL && \
		ft_strstr(line, "slisandr") != NULL))
	{
		pl->c_us = 'X';
		pl->c_enemy = 'O';
	}
	else
	{
		pl->c_us = 'O';
		pl->c_enemy = 'X';
	}
}

t_players	*init_players(int const fd)
{
	t_players	*pl;
	char		*line;

	if (!(pl = (t_players *)ft_memalloc(sizeof(t_players))))
		return (NULL);
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strstr(line, "$$$ exec p") != NULL)
		{
			assign_letters(line, pl);
			ft_strdel(&line);
			return ((pl->c_us == 0 || pl->c_enemy == 0) ? (NULL) : (pl));
		}
		ft_strdel(&line);
	}
	wipe_players(&pl);
	return (NULL);
}

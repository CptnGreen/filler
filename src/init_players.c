/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:17:13 by fcatina           #+#    #+#             */
/*   Updated: 2020/03/06 02:45:42 by fcatina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		assign_letters(char *line, t_players *pl)
{
	if ((ft_strstr(line, "$$$ exec p1") != NULL && \
		ft_strstr(line, "fcatina") == NULL) || \
		(ft_strstr(line, "$$$ exec p2") != NULL && \
		ft_strstr(line, "fcatina") != NULL))
	{
		pl->c_us = 'X';
		pl->c_enemy = 'O';
		return (1);
	}
	else if ((ft_strstr(line, "$$$ exec p1") != NULL && \
		ft_strstr(line, "fcatina") != NULL) || \
		(ft_strstr(line, "$$$ exec p2") != NULL && \
		ft_strstr(line, "fcatina") == NULL))
	{
		pl->c_us = 'O';
		pl->c_enemy = 'X';
		return (1);
	}
	return (0);
}

int		init_players(int const fd, t_players *pl)
{
	char		*line;

	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strstr(line, "$$$ exec p") != NULL)
		{
			if (!(assign_letters(line, pl)))
				return (0);
			ft_strdel(&line);
			return ((pl->c_us == 0 || pl->c_enemy == 0) ? (0) : (1));
		}
		ft_strdel(&line);
	}
	return (0);
}

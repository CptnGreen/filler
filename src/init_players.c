/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:17:13 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/27 14:22:54 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_players	*init_players(int const fd, char **line)
{
	char		**split;
	int			fd_output;
	t_players	*pl;

	fd_output = open(TEST_FILE, O_WRONLY|O_APPEND);
	ft_putstr_fd("ENTERED INIT_PLAYERS()\n", fd_output);
	if (!(pl = (t_players *)ft_memalloc(sizeof(t_players))))
		return (NULL);
	while (get_next_line(fd, line) > 0)
	{
		ft_putstr_fd(*line, fd_output);
		ft_putchar_fd('\n', fd_output);
		split = ft_strsplit(*line, ':');
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
			break ;
		}
		wipe_mstr(split);
	}
	ft_putchar_fd(pl->c_us, fd_output);
	ft_putchar_fd('\n', fd_output);
	ft_putchar_fd(pl->c_enemy, fd_output);
	ft_putchar_fd('\n', fd_output);
	ft_putstr_fd("LEFT INIT_PLAYERS()\n", fd_output);
	return ((pl->c_us == 0 || pl->c_enemy == 0) ? (NULL) : (pl));
}

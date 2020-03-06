/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:02:26 by slisandr          #+#    #+#             */
/*   Updated: 2020/03/06 03:02:09 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		init_piece(t_piece *piece)
{
	piece->h = 0;
	piece->w = 0;
	piece->row = 0;
	piece->col = 0;
	piece->best_row = -1;
	piece->best_col = -1;
	piece->sum = 0;
	piece->best_sum = INT_MAX;
	piece->n_intersecs = 0;
	piece->mstr = NULL;
	return (1);
}

int		get_piece_dimensions(int const fd, t_piece *piece, char **line)
{
	char	**split;

	while (get_next_line(fd, line) > 0)
	{
		split = ft_strsplit(*line, ' ');
		ft_strdel(line);
		if (ft_strcmp(split[0], "Piece") == 0)
		{
			piece->h = ft_atoi(split[1]);
			piece->w = ft_atoi(split[2]);
			wipe_mstr(split);
			return ((piece->h == 0 || piece->w == 0) ? (0) : (1));
		}
		wipe_mstr(split);
	}
	return (0);
}

int		get_piece_rows(int const fd, t_piece *piece, char **line)
{
	int		n_row;

	if (!(piece->mstr = (char **)ft_memalloc(sizeof(char *) * (piece->h + 1))))
		return (0);
	n_row = -1;
	while (++n_row < piece->h && get_next_line(fd, line) > 0)
	{
		if ((int)ft_strlen(*line) != piece->w)
		{
			ft_strdel(line);
			return (0);
		}
		piece->mstr[n_row] = ft_strdup(*line);
		ft_strdel(line);
	}
	piece->mstr[n_row] = NULL;
	return ((n_row == -1) ? (0) : (1));
}

int		get_piece(int const fd, t_piece *p)
{
	char	*line;

	line = NULL;
	if (init_piece(p) && \
		get_piece_dimensions(fd, p, &line) && \
		get_piece_rows(fd, p, &line))
	{
		return (1);
	}
	return (0);
}

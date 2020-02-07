/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:02:26 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/07 16:19:03 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_piece	*init_piece(int const fd)
{
	t_piece	*piece;

	printf("init_piece: I'm here!\n");
	if (!(piece = (t_piece *)ft_memalloc(sizeof(t_piece))))
		return (NULL);
	piece->h = 0;
	piece->w = 0;
	piece->mstr = NULL;
	return (piece);
}

int		get_piece_dimensions(int const fd, t_piece *piece, char **line)
{
	char	**split;

	while (get_next_line(fd, line))
	{
		split = ft_strsplit(*line, ' ');
		if (ft_strcmp(split[0], "Piece") == 0)
		{
			piece->h = ft_atoi(split[1]);
			piece->w = ft_atoi(split[2]);
			break ;
		}
	}
	wipe_mstr(split);
	return ((piece->h == 0 || piece->w == 0) ? (0) : (1));
}

int		get_piece_rows(int const fd, t_piece *piece, char **line)
{
	int		n_row;

	if (!(piece->mstr = (char **)ft_memalloc(sizeof(char *) * piece->h)))
		return (0);
	n_row = 0;
	while (n_row < piece->h && get_next_line(fd, line))
	{
		piece->mstr[n_row] = ft_strdup(*line);
		printf("piece->mstr[%2d] = %s\n", n_row, piece->mstr[n_row]);
		n_row += 1;
	}
	return ((n_row == -1) ? (0) : (1));
}

t_piece	*get_piece(int const fd)
{
	t_piece	*piece;
	char	**line;

	if ((piece = init_piece(fd)) && \
		(line = (char **)ft_memalloc(sizeof(char *))) && \
		get_piece_dimensions(fd, piece, line) && \
		get_piece_rows(fd, piece, line))
	{
		ft_strdel(line);
		return (piece);
	}
	ft_strdel(line);
	wipe_piece(&piece);
	return (NULL);
}

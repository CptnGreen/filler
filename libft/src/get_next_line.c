/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 17:50:19 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/05 01:26:20 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		find_endline(char *tail)
{
	int		i;

	i = 0;
	while (tail[i] != '\n' && tail[i] != '\0')
		i++;
	if (tail[i] == '\n')
	{
		tail[i] = '\0';
		return (i);
	}
	else
		return (-1);
}

char	*increase_tail(char *tail, char *buff)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	j = 0;
	if (tail)
		i = ft_strlen(tail);
	if (buff)
		j = ft_strlen(buff);
	if (!(ptr = (char *)malloc(sizeof(*ptr) * (i + j + 1))))
		return (NULL);
	ft_memcpy(ptr, tail, i);
	ft_memcpy(ptr + i, buff, j);
	ptr[i + j] = '\0';
	ft_strdel(&tail);
	ft_bzero(buff, BUFF_SIZE + 1);
	return (ptr);
}

int		cut_off_line(char **tail, char **buff, char **line)
{
	int		endl_position;
	char	*leftover;

	*tail = increase_tail(*tail, *buff);
	endl_position = find_endline(*tail);
	if (endl_position > -1)
	{
		*line = ft_strdup(*tail);
		leftover = *tail;
		*tail = ft_strdup(*tail + endl_position + 1);
		ft_strdel(&leftover);
		return (1);
	}
	return (0);
}

int		handle_last_read_portion(char **tail, char **line, char **buff)
{
	if (cut_off_line(tail, buff, line))
	{
		ft_strdel(buff);
		return (1);
	}
	else if (ft_strlen(*tail) > 0)
	{
		*line = ft_strdup(*tail);
		ft_strdel(tail);
		return (1);
	}
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static char		*tail[12000];
	char			*buff;
	int				got_new_line;
	int				ret;

	buff = ft_strnew(BUFF_SIZE);
	if (line == 0 || BUFF_SIZE <= 0 || fd < 0 || (ret = read(fd, buff, 0)) < 0)
	{
		ft_strdel(&buff);
		return (-1);
	}
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		got_new_line = cut_off_line(&tail[fd], &buff, line);
		ft_strdel(&buff);
		if (got_new_line == 1)
			return (1);
		buff = ft_strnew(BUFF_SIZE);
	}
	if ((got_new_line = handle_last_read_portion(&tail[fd], line, &buff)))
		return (1);
	ft_strdel(&buff);
	ft_strdel(&tail[fd]);
	return (0);
}
